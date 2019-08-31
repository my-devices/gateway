//
// WebTunnelAgent.h
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_WebTunnelAgent_INCLUDED
#define MyGateway_WebTunnelAgent_INCLUDED


#include "Poco/WebTunnel/SocketDispatcher.h"
#include "Poco/WebTunnel/RemotePortForwarder.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Util/Timer.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/URI.h"
#include "Poco/RefCountedObject.h"
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/Process.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/Random.h"
#include "Poco/Mutex.h"
#include "Poco/Logger.h"


namespace MyDevices {
namespace Gateway {


class WebTunnelAgent: public Poco::RefCountedObject
{
public:
	typedef Poco::AutoPtr<WebTunnelAgent> Ptr;

	enum Status
	{
		STATUS_DISCONNECTED,
		STATUS_CONNECTED,
		STATUS_ERROR
	};

	enum
	{
		MIN_RETRY_DELAY = 1000,
		MAX_RETRY_DELAY = 30000
	};

	WebTunnelAgent(const std::string& deviceId, Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> pDispatcher, Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig);
		/// Creates the WebTunnelAgent, using the given deviceId, Timer, SocketDispatcher and configuration.

	~WebTunnelAgent();
		/// Destroys the WebTunnelAgent.

	void stop();
		/// Stops the WebTunnelAgent.

	const std::string& id() const;
		/// Returns the agent's device ID.

	Status status() const;
		/// Returns the agent status.

	std::string lastError() const;
		/// Returns the last error message for this tunnel.

protected:
	void connect();
	void disconnect();
	void onClose(const int& reason);
	void reconnectTask(Poco::Util::TimerTask&);
	void disconnectTask(Poco::Util::TimerTask&);
	void init();
	void addProperties(Poco::Net::HTTPRequest& request, const std::map<std::string, std::string>& props);
	void updateProperties(Poco::Util::TimerTask&);
	void collectProperties(std::map<std::string, std::string>& props);
	void startPropertiesUpdateTask();
	void stopPropertiesUpdateTask();
	std::string formatPorts();
	std::string runCommand(const std::string& command);
	void statusChanged(Status status);
	void statusChanged(Status status, const std::string& error);
	void scheduleReconnect();
	void scheduleDisconnect();
	static std::string quoteString(const std::string& str);

	static const std::string SEC_WEBSOCKET_PROTOCOL;
	static const std::string WEBTUNNEL_PROTOCOL;
	static const std::string WEBTUNNEL_AGENT;

private:
	std::string _id;
	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pConfig;
	std::string _deviceName;
	Poco::Net::IPAddress _host;
	std::set<Poco::UInt16> _ports;
	Poco::URI _reflectorURI;
	Poco::URI _redirectURI;
	std::string _username;
	std::string _password;
	std::string _userAgent;
	std::string _httpPath;
	Poco::UInt16 _httpPort;
	Poco::UInt16 _sshPort;
	Poco::UInt16 _vncPort;
	Poco::UInt16 _rdpPort;
	bool _useProxy;
	std::string _proxyHost;
	Poco::UInt16 _proxyPort;
	std::string _proxyUsername;
	std::string _proxyPassword;
	Poco::Timespan _localTimeout;
	Poco::Timespan _connectTimeout;
	Poco::Timespan _remoteTimeout;
	Poco::Timespan _httpTimeout;
	Poco::Timespan _propertiesUpdateInterval;
	int _retryDelay;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
	Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> _pDispatcher;
	Poco::SharedPtr<Poco::WebTunnel::RemotePortForwarder> _pForwarder;
	Poco::SharedPtr<Poco::Net::HTTPClientSession> _pHTTPClientSession;
	Poco::Util::TimerTask::Ptr _pPropertiesUpdateTask;
	Poco::Event _stopped;
	Poco::Random _random;
	Status _status;
	std::string _lastError;
	mutable Poco::FastMutex _mutex;
	Poco::Logger& _logger;
};


//
// inlines
//


inline const std::string& WebTunnelAgent::id() const
{
	return _id;
}


} } // namespace MyDevices::Gateway


#endif // MyGateway_WebTunnelAgent_INCLUDED
