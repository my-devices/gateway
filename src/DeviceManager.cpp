//
// DeviceManager.cpp
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DeviceManager.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Util/LayeredConfiguration.h"
#include "Poco/Util/TimerTask.h"
#if defined(WEBTUNNEL_ENABLE_TLS)
#include "Poco/Net/SecureStreamSocket.h"
#endif
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/UUID.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


#if defined(WEBTUNNEL_ENABLE_TLS)


class TLSSocketFactory: public Poco::WebTunnel::SocketFactory
{
public:
	TLSSocketFactory(Poco::UInt16 tlsPort, Poco::Net::Context::Ptr pContext):
		_tlsPort(tlsPort),
		_pContext(pContext)
	{
	}

	~TLSSocketFactory()
	{
	}

	Poco::Net::StreamSocket createSocket(const Poco::Net::SocketAddress& addr)
	{
		if (addr.port() == _tlsPort)
		{
			Poco::Net::SecureStreamSocket streamSocket(_pContext);
			streamSocket.connectNB(addr);
			return streamSocket;
		}
		else
		{
			Poco::Net::StreamSocket streamSocket;
			streamSocket.connectNB(addr);
			return streamSocket;
		}
	}

private:
	Poco::UInt16 _tlsPort;
	Poco::Net::Context::Ptr _pContext;
};


#endif // defined(WEBTUNNEL_ENABLE_TLS)


class RestartTask: public Poco::Util::TimerTask
{
public:
	RestartTask(DeviceManager& dm):
		_dm(dm)
	{
	}

	void run()
	{
		_dm.reconfigureAgents();
	}

private:
	DeviceManager& _dm;
};


class StopTask: public Poco::Util::TimerTask
{
public:
	StopTask(WebTunnelAgent::Ptr pAgent):
		_pAgent(pAgent)
	{
	}

	void run()
	{
		_pAgent->stop();
	}

private:
	WebTunnelAgent::Ptr _pAgent;
};


#if defined(WEBTUNNEL_ENABLE_TLS)


DeviceManager::DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::Net::Context::Ptr pContext):
	_pConfig(&config, true),
	_pTimer(pTimer),
	_pContext(pContext),
	_pDispatcher(new Poco::WebTunnel::SocketDispatcher),
	_logger(Poco::Logger::get("DeviceManager"s))
{
	reconfigureAgents(5);
}


#endif


DeviceManager::DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer):
	_pConfig(&config, true),
	_pTimer(pTimer),
	_pDispatcher(new Poco::WebTunnel::SocketDispatcher),
	_logger(Poco::Logger::get("DeviceManager"s))
{
	reconfigureAgents(5);
}


DeviceManager::~DeviceManager()
{
	_pTimer->cancel(true);
}


void DeviceManager::reconfigureAgents(long delay)
{
	Poco::Clock clock;
	clock += 1000*delay;
	_pTimer->schedule(new RestartTask(*this), clock);
}


void DeviceManager::stopAgents()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	for (AgentMap::iterator it = _agents.begin(); it != _agents.end(); ++it)
	{
		_pTimer->schedule(new StopTask(it->second.pAgent), Poco::Clock());
	}
	_agents.clear();
}


void DeviceManager::reconfigureAgents()
{
	_logger.debug("Reconfiguring agents..."s);

	std::set<std::string> activeAgents;
	std::vector<std::string> devices(enumerateDevices());
	for (std::vector<std::string>::const_iterator it = devices.begin(); it != devices.end(); ++it)
	{
		try
		{
			std::string path = deviceConfigurationPath(*it);
			std::string hash = computeFileHash(path);

			AgentMap::iterator ita = _agents.find(*it);
			if (ita != _agents.end())
			{
				if (ita->second.configHash != hash)
				{
					_logger.debug("Reconfiguring %s due to configuration change..."s, *it);
					_pTimer->schedule(new StopTask(ita->second.pAgent), Poco::Clock());
					ita->second.configHash = hash;
					ita->second.pAgent = loadAgent(*it);
					if (ita->second.pAgent)
					{
						activeAgents.insert(*it);
					}
					else
					{
						_logger.debug("Removing inactive agent %s"s, *it);
						_agents.erase(ita);
					}
				}
				else
				{
					activeAgents.insert(*it);
				}
			}
			else
			{
				_logger.debug("Creating new agent %s..."s, *it);
				AgentEntry entry;
				entry.configHash = hash;
				entry.pAgent = loadAgent(*it);
				if (entry.pAgent)
				{
					_agents[*it] = entry;
					activeAgents.insert(*it);
				}
			}

		}
		catch (Poco::Exception& exc)
		{
			_logger.log(exc);
		}
	}

	AgentMap::iterator ita = _agents.begin();
	while (ita != _agents.end())
	{
		if (activeAgents.find(ita->first) == activeAgents.end())
		{
			_logger.debug("Removing deleted agent %s..."s, ita->first);
			_pTimer->schedule(new StopTask(ita->second.pAgent), Poco::Clock());
			ita = _agents.erase(ita);
		}
		else
		{
			++ita;
		}
	}
}


WebTunnelAgent::Ptr DeviceManager::loadAgent(const std::string& id)
{
	_logger.debug("Loading agent %s..."s, id);

	Poco::AutoPtr<Poco::Util::LayeredConfiguration> pLayeredConfig = new Poco::Util::LayeredConfiguration;
	pLayeredConfig->add(_pConfig, 1);
	pLayeredConfig->add(deviceConfiguration(id), 0);
	if (pLayeredConfig->getBool("webtunnel.enable"s, true))
	{
		Poco::WebTunnel::SocketFactory::Ptr pSocketFactory;

		Poco::UInt16 httpPort = static_cast<Poco::UInt16>(pLayeredConfig->getInt("webtunnel.httpPort"s, 0));
		bool httpsRequired = pLayeredConfig->getBool("webtunnel.https.enable"s, false);

#if defined(WEBTUNNEL_ENABLE_TLS)
		if (httpPort != 0 && httpsRequired)
		{
			_logger.debug("HTTPS enabled for agent %s."s, id);
			pSocketFactory = new TLSSocketFactory(httpPort, _pContext);
		}
#endif

		if (!pSocketFactory)
		{
			pSocketFactory = new Poco::WebTunnel::SocketFactory;
		}

		return new WebTunnelAgent(id, _pTimer, _pDispatcher, pLayeredConfig, pSocketFactory);
	}
	else return 0;
}


Poco::AutoPtr<Poco::Util::AbstractConfiguration> DeviceManager::createDevice(const std::string& id, const std::string& domain, const std::string& name)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConfig = new Poco::Util::PropertyFileConfiguration;
	pConfig->setString("webtunnel.deviceName"s, name);
	pConfig->setString("webtunnel.deviceId"s, id);
	pConfig->setString("webtunnel.domain"s, domain);
	pConfig->setString("webtunnel.host"s, "127.0.0.1"s);
	pConfig->setString("webtunnel.ports"s, "80"s);
	pConfig->setString("webtunnel.httpPort"s, "80"s);
	pConfig->setString("webtunnel.password"s, ""s);
	pConfig->setBool("webtunnel.enable"s, false);
	pConfig->save(deviceConfigurationPath(id));

	return pConfig;
}


void DeviceManager::updateDevice(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	std::string deviceId = pConfig->getString("webtunnel.deviceId"s);
	pConfig->setBool("webtunnel.enable"s, true);
	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pPropertyFileConfig = pConfig.cast<Poco::Util::PropertyFileConfiguration>();
	pPropertyFileConfig->save(deviceConfigurationPath(deviceId));
}


void DeviceManager::removeDevice(const std::string& deviceId)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Poco::File file(deviceConfigurationPath(deviceId));
	if (file.exists())
	{
		file.remove();
	}
}


std::vector<std::string> DeviceManager::enumerateDevices() const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	std::string basePath(deviceRepositoryPath());
	Poco::File directory(basePath);
	std::vector<std::string> files;
	directory.list(files);
	std::vector<std::string> devices;
	for (std::vector<std::string>::const_iterator it = files.begin(); it != files.end(); ++it)
	{
		Poco::Path p(*it);
		if (p.getExtension() == "properties"s)
		{
			devices.push_back(p.getBaseName());
		}
	}
	return devices;
}


Poco::AutoPtr<Poco::Util::AbstractConfiguration> DeviceManager::deviceConfiguration(const std::string& deviceId) const
{
	return new Poco::Util::PropertyFileConfiguration(deviceConfigurationPath(deviceId));
}


std::string DeviceManager::deviceConfigurationPath(const std::string& deviceId) const
{
	std::string basePath(deviceRepositoryPath());
	Poco::Path path(basePath, deviceId);
	path.setExtension("properties"s);
	return path.toString();
}


std::string DeviceManager::computeFileHash(const std::string& path) const
{
	Poco::FileInputStream stream(path);
	Poco::MD5Engine md5;
	Poco::DigestOutputStream md5Stream(md5);
	Poco::StreamCopier::copyStream(stream, md5Stream);
	md5Stream.close();
	return Poco::DigestEngine::digestToHex(md5.digest());
}


std::string DeviceManager::deviceRepositoryPath() const
{
	std::string deviceConfigPath(_pConfig->getString("gateway.configDir"s, ""s));
	if (deviceConfigPath.empty())
	{
		Poco::Path p(_pConfig->getString("application.configDir"s));
		p.makeDirectory();
		p.pushDirectory("devices"s);
		deviceConfigPath = p.toString();
	}
	Poco::File deviceConfigDir(deviceConfigPath);
	deviceConfigDir.createDirectories();
	return deviceConfigPath;
}


Poco::AutoPtr<Poco::Util::AbstractConfiguration> DeviceManager::config() const
{
	return _pConfig;
}


WebTunnelAgent::Ptr DeviceManager::agentForDevice(const std::string& deviceId) const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	AgentMap::const_iterator it = _agents.find(deviceId);
	if (it != _agents.end())
		return it->second.pAgent;
	else
		return 0;
}


} } // namespace MyDevices::Gateway
