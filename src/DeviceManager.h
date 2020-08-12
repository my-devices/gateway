//
// DeviceManager.h
//
// Copyright (c) 2015-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_DeviceManager_INCLUDED
#define MyGateway_DeviceManager_INCLUDED


#include "Poco/WebTunnel/SocketDispatcher.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/Timer.h"
#if defined(WEBTUNNEL_ENABLE_TLS)
#include "Poco/Net/Context.h"
#endif
#include "Poco/RefCountedObject.h"
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/Mutex.h"
#include "Poco/Logger.h"
#include "WebTunnelAgent.h"
#include "WebSessionManager.h"
#include <map>


namespace MyDevices {
namespace Gateway {


class DeviceManager: public Poco::RefCountedObject
{
public:
	typedef Poco::AutoPtr<DeviceManager> Ptr;

#if defined(WEBTUNNEL_ENABLE_TLS)
	DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::Net::Context::Ptr pContext);
		/// Creates the DeviceManager, using the given configuration, timer and context.
#endif

	DeviceManager(Poco::Util::AbstractConfiguration& config, Poco::SharedPtr<Poco::Util::Timer> pTimer);
		/// Creates the DeviceManager, using the given configuration and timer.

	~DeviceManager();
		/// Destroys the DeviceManager.

	void reconfigureAgents(long delay);
		/// Stops and restarts all agents, using the latest configuration values after
		/// the given delay in milliseconds.

	void stopAgents();
		/// Stops all agents.

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> createDevice(const std::string& id, const std::string& domain, const std::string& name);
		/// Creates a new device and returns the device's configuration.

	void updateDevice(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig);
		/// Updates a device configuration.

	void removeDevice(const std::string& deviceId);
		/// Removes a device configuration.

	std::vector<std::string> enumerateDevices() const;
		/// Returns a vector containing all device IDs.

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> deviceConfiguration(const std::string& deviceId) const;
		/// Returns the configuration for the device with the given deviceId.

	std::string deviceConfigurationPath(const std::string& deviceId) const;
		/// Returns the path for the device's configuration file.

	std::string computeFileHash(const std::string& path) const;
		/// Computes the hash of the given file.

	std::string deviceRepositoryPath() const;
		/// Returns the directory where device configurations are stored.

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> config() const;
		/// Returns the global configuration.

	WebTunnelAgent::Ptr agentForDevice(const std::string& deviceId) const;
		/// Returns the WebTunnelAgent for the device with the given deviceId.

	WebSessionManager& webSessionManager();
		/// Returns the WebSessionManager.

protected:
	void reconfigureAgents();
	WebTunnelAgent::Ptr loadAgent(const std::string& id);

private:
	struct AgentEntry
	{
		std::string configHash;
		WebTunnelAgent::Ptr pAgent;
	};
	typedef std::map<std::string, AgentEntry> AgentMap;

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pConfig;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
#if defined(WEBTUNNEL_ENABLE_TLS)
	Poco::Net::Context::Ptr _pContext;
#endif
	Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> _pDispatcher;
	AgentMap _agents;
	WebSessionManager _webSessionManager;
	mutable Poco::FastMutex _mutex;
	Poco::Logger& _logger;

	friend class RestartTask;
	friend class StopTask;
};


//
// inlines
//


inline WebSessionManager& DeviceManager::webSessionManager()
{
	return _webSessionManager;
}


} } // namespace MyDevices::Gateway


#endif // MyGateway_DeviceManager_INCLUDED
