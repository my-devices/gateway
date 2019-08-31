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
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/UUID.h"


namespace MyDevices {
namespace Gateway {


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


DeviceManager::DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer):
	_pConfig(&config, true),
	_pTimer(pTimer),
	_pDispatcher(new Poco::WebTunnel::SocketDispatcher(_pConfig->getInt("webtunnel.threads", 8))),
	_logger(Poco::Logger::get("DeviceManager"))
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
	_logger.debug("Reconfiguring agents...");

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
					_logger.debug("Reconfiguring %s due to configuration change...", *it);
					_pTimer->schedule(new StopTask(ita->second.pAgent), Poco::Clock());
					ita->second.configHash = hash;
					ita->second.pAgent = loadAgent(*it);
					if (ita->second.pAgent)
					{
						activeAgents.insert(*it);
					}
					else
					{
						_logger.debug("Removing inactive agent %s", *it);
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
				_logger.debug("Creating new agent %s...", *it);
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
			_logger.debug("Removing deleted agent %s...", ita->first);
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
	_logger.debug("Loading agent %s...", id);

	Poco::AutoPtr<Poco::Util::LayeredConfiguration> pLayeredConfig = new Poco::Util::LayeredConfiguration;
	pLayeredConfig->add(_pConfig, 1);
	pLayeredConfig->add(deviceConfiguration(id), 0);
	if (pLayeredConfig->getBool("webtunnel.enable", true))
	{
		return new WebTunnelAgent(id, _pTimer, _pDispatcher, pLayeredConfig);
	}
	else return 0;
}


Poco::AutoPtr<Poco::Util::AbstractConfiguration> DeviceManager::createDevice()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Poco::UUID uuid = _uuidGenerator.createOne();
	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConfig = new Poco::Util::PropertyFileConfiguration;
	pConfig->setString("webtunnel.deviceName", "Unnamed Device");
	pConfig->setString("webtunnel.deviceId", uuid.toString());
	pConfig->setString("webtunnel.domain", _pConfig->getString("webtunnel.domain"));
	pConfig->setString("webtunnel.host", "127.0.0.1");
	pConfig->setString("webtunnel.ports", "80");
	pConfig->setString("webtunnel.httpPort", "80");
	pConfig->setString("webtunnel.password", "");
	pConfig->setBool("webtunnel.enable", false);
	pConfig->save(deviceConfigurationPath(uuid.toString()));

	return pConfig;
}


void DeviceManager::updateDevice(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	std::string deviceId = pConfig->getString("webtunnel.deviceId");
	pConfig->setBool("webtunnel.enable", true);
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
		if (p.getExtension() == "properties")
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
	path.setExtension("properties");
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
	std::string deviceConfigPath(_pConfig->getString("gateway.configDir", ""));
	if (deviceConfigPath.empty())
	{
		Poco::Path p(_pConfig->getString("application.configDir"));
		p.makeDirectory();
		p.pushDirectory("devices");
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
