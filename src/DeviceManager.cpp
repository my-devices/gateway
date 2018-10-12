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
		_dm.restartAgents();
	}

private:
	DeviceManager& _dm;
};


DeviceManager::DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer):
	_pConfig(&config, true),
	_pTimer(pTimer),
	_logger(Poco::Logger::get("DeviceManager"))
{
	restartAgents();
}


DeviceManager::~DeviceManager()
{
}


void DeviceManager::restartAgents(long delay)
{
	Poco::Clock clock;
	clock += 1000*delay;
	_pTimer->schedule(new RestartTask(*this), clock);
}


void DeviceManager::restartAgents()
{
	stopAgents();

	int threads = _pConfig->getInt("webtunnel.threads", 8);
	_pDispatcher = new Poco::WebTunnel::SocketDispatcher(threads);

	std::vector<std::string> devices(enumerateDevices());
	for (std::vector<std::string>::const_iterator it = devices.begin(); it != devices.end(); ++it)
	{
		try
		{
			Poco::AutoPtr<Poco::Util::LayeredConfiguration> pLayeredConfig = new Poco::Util::LayeredConfiguration;
			pLayeredConfig->add(_pConfig, 1);
			pLayeredConfig->add(deviceConfiguration(*it), 0);
			if (pLayeredConfig->getBool("webtunnel.enable", true))
			{
				_agents.push_back(new WebTunnelAgent(_pTimer, _pDispatcher, pLayeredConfig));
			}
		}
		catch (Poco::Exception& exc)
		{
			_logger.log(exc);
		}
	}
}


void DeviceManager::stopAgents()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	for (std::vector<WebTunnelAgent::Ptr>::iterator it = _agents.begin(); it != _agents.end(); ++it)
	{
		(*it)->stop();
	}
	_agents.clear();
}


Poco::AutoPtr<Poco::Util::AbstractConfiguration> DeviceManager::createDevice()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Poco::UUID uuid = _uuidGenerator.createOne();
	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConfig = new Poco::Util::PropertyFileConfiguration;
	pConfig->setString("webtunnel.deviceName", "Unnamed Device");
	pConfig->setString("webtunnel.deviceId", uuid.toString());
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


} } // namespace MyDevices::Gateway
