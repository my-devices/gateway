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
#include "Poco/Logger.h"


namespace MyDevices {
namespace Gateway {


class WebTunnelAgent: public Poco::RefCountedObject
{
public:
	typedef Poco::AutoPtr<WebTunnelAgent> Ptr;

	WebTunnelAgent(Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> pDispatcher, Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig);
		/// Creates the WebTunnelAgent, using the given Timer, SocketDispatcher and configuration.

	~WebTunnelAgent();
		/// Destroys the WebTunnelAgent.

	void stop();
		/// Stops the WebTunnelAgent.

protected:
	void connect();
	void disconnect();
	void onClose(const int& reason);
	void reconnect(Poco::Util::TimerTask&);
	void init(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig);

	static const std::string SEC_WEBSOCKET_PROTOCOL;
	static const std::string WEBTUNNEL_PROTOCOL;
	static const std::string WEBTUNNEL_AGENT;

private:
	std::string _deviceName;
	Poco::Net::IPAddress _host;
	std::set<Poco::UInt16> _ports;
	Poco::URI _reflectorURI;
	std::string _username;
	std::string _password;
	std::string _userAgent;
	Poco::UInt16 _httpPort;
	bool _useProxy;
	std::string _proxyHost;
	Poco::UInt16 _proxyPort;
	std::string _proxyUsername;
	std::string _proxyPassword;
	Poco::Timespan _localTimeout;
	Poco::Timespan _connectTimeout;
	Poco::Timespan _remoteTimeout;
	Poco::Timespan _httpTimeout;
	int _retryDelay;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
	Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> _pDispatcher;
	Poco::SharedPtr<Poco::WebTunnel::RemotePortForwarder> _pForwarder;
	Poco::SharedPtr<Poco::Net::HTTPClientSession> _pHTTPClientSession;
	bool _stopped;
	Poco::Logger& _logger;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_WebTunnelAgent_INCLUDED
