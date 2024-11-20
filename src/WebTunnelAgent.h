//
// WebTunnelAgent.h
//
// Copyright (c) 2015-2020, Applied Informatics Software Engineering GmbH.
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
#include "Poco/BasicEvent.h"
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

	Poco::BasicEvent<const std::string> connected;
	Poco::BasicEvent<const std::string> disconnected;
	Poco::BasicEvent<const std::string> error;

	WebTunnelAgent(const std::string& deviceId, Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> pDispatcher, Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig, Poco::WebTunnel::SocketFactory::Ptr pSocketFactory);
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
	void stopReconnectTask();
	void init();
	void addProperties(Poco::Net::HTTPRequest& request, const std::map<std::string, std::string>& props);
	void addPortProperty(Poco::Net::HTTPRequest& request, const std::string& proto, Poco::UInt16 port);
	void propertiesUpdateTask(Poco::Util::TimerTask&);
	void collectProperties(std::map<std::string, std::string>& props);
	void startPropertiesUpdateTask();
	void stopPropertiesUpdateTask();
	Poco::UInt16 loadPort(const std::string& proto) const;
	std::string formatPorts();
	std::string runCommand(const std::string& command);
	void statusChanged(Status status);
	void statusChanged(Status status, const std::string& error);
	void scheduleReconnect();
	void scheduleDisconnect();
	void notifyConnected(const std::string&);
	void notifyDisconnected(const std::string&);
	void notifyError(const std::string& msg);
	void notify(const Poco::Process::Args& args);
	bool isStopping();
	static std::string quoteString(const std::string& str);

	static const std::string SEC_WEBSOCKET_PROTOCOL;
	static const std::string WEBTUNNEL_PROTOCOL;
	static const std::string WEBTUNNEL_AGENT;
	static const std::string X_PTTH_SET_PROPERTY;
	static const std::string X_PTTH_ERROR;
	static const std::string X_WEBTUNNEL_KEEPALIVE;

private:
	std::string _id;
	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pConfig;
	Poco::WebTunnel::SocketFactory::Ptr _pSocketFactory;
	std::string _deviceName;
	Poco::Net::IPAddress _host;
	std::set<Poco::UInt16> _ports;
	Poco::URI _reflectorURI;
	Poco::URI _redirectURI;
	std::string _username;
	std::string _password;
	std::string _tenant;
	std::string _userAgent;
	std::string _httpPath;
	Poco::UInt16 _httpPort = 0;
	bool _httpsRequired = false;
	Poco::UInt16 _sshPort = 0;
	Poco::UInt16 _vncPort = 0;
	Poco::UInt16 _rdpPort = 0;
	Poco::UInt16 _appPort = 0;
	bool _useProxy = false;
	std::string _proxyHost;
	Poco::UInt16 _proxyPort = 0;
	std::string _proxyUsername;
	std::string _proxyPassword;
	Poco::Timespan _localTimeout;
	Poco::Timespan _connectTimeout;
	Poco::Timespan _remoteTimeout;
	Poco::Timespan _httpTimeout;
	Poco::Timespan _propertiesUpdateInterval;
	int _retryDelay = MIN_RETRY_DELAY;
	std::string _notifyExec;
	bool _notifyEnable = false;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
	Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> _pDispatcher;
	Poco::SharedPtr<Poco::WebTunnel::RemotePortForwarder> _pForwarder;
	Poco::SharedPtr<Poco::Net::HTTPClientSession> _pHTTPClientSession;
	Poco::Util::TimerTask::Ptr _pReconnectTask;
	Poco::Util::TimerTask::Ptr _pPropertiesUpdateTask;
	Poco::Event _stopped;
	Poco::Random _random;
	Status _status = STATUS_DISCONNECTED;
	std::string _lastError;
	bool _stopping = false;
	mutable Poco::FastMutex _mutex;
	Poco::Logger& _logger;

	friend class ReconnectTask;
	friend class PropertiesUpdateTask;
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
