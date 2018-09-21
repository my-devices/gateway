//
// WebTunnelAgent.cpp
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "WebTunnelAgent.h"
#include "Utility.h"
#include "Poco/Util/TimerTaskAdapter.h"
#include "Poco/Net/HTTPSessionFactory.h"
#include "Poco/Net/HTTPSessionInstantiator.h"
#include "Poco/Net/HTTPBasicCredentials.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/DNS.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberParser.h"
#include "Poco/Environment.h"
#include "Poco/Delegate.h"
#include "Poco/Buffer.h"


namespace MyDevices {
namespace Gateway {


const std::string WebTunnelAgent::SEC_WEBSOCKET_PROTOCOL("Sec-WebSocket-Protocol");
const std::string WebTunnelAgent::WEBTUNNEL_PROTOCOL("com.appinf.webtunnel.server/1.0");
const std::string WebTunnelAgent::WEBTUNNEL_AGENT("macchina.io Remote Manager Gateway");


WebTunnelAgent::WebTunnelAgent(Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> pDispatcher, Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig):
	_httpPort(0),
	_vncPort(0),
	_useProxy(false),
	_proxyPort(0),
	_retryDelay(1000),
	_pTimer(pTimer),
	_pDispatcher(pDispatcher),
	_stopped(false),
	_logger(Poco::Logger::get("WebTunnelAgent"))
{
	init(pConfig);
}


WebTunnelAgent::~WebTunnelAgent()
{
	try
	{
		stop();
	}
	catch (Poco::Exception&)
	{
		poco_unexpected();
	}
}


void WebTunnelAgent::stop()
{
	if (!_stopped)
	{
		_logger.debug("Stopping...");
		_stopped = true;
		disconnect();
	}
}


void WebTunnelAgent::connect()
{
	_logger.information("Connecting device %s to %s...", _deviceName, _reflectorURI.toString());

	_pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(_reflectorURI);
	_pHTTPClientSession->setTimeout(_httpTimeout);
	if (_useProxy && !_proxyHost.empty())
	{
		_pHTTPClientSession->setProxy(_proxyHost, _proxyPort);
		if (!_proxyUsername.empty())
		{
			_pHTTPClientSession->setProxyCredentials(_proxyUsername, _proxyPassword);
		}
	}

	std::string path(_reflectorURI.getPathEtc());
	if (path.empty()) path = "/";
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, path, Poco::Net::HTTPRequest::HTTP_1_1);
	request.set(SEC_WEBSOCKET_PROTOCOL, WEBTUNNEL_PROTOCOL);

	if (!_username.empty())
	{
		Poco::Net::HTTPBasicCredentials creds(_username, _password);
		creds.authenticate(request);
	}

	if (_httpPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;httpPort=%hu", _httpPort));
	}
	if (_vncPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;vncPort=%hu", _vncPort));
	}
	if (!_deviceName.empty())
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;name=\"%s\"", _deviceName));
	}
	request.set("User-Agent", _userAgent);

	Poco::Net::HTTPResponse response;
	bool reconnect = true;
	if (!_stopped)
	{
		_logger.debug("Entering reconnect loop...");
		try
		{
			Poco::Net::DNS::reload();
			_logger.debug("Creating WebSocket...");
			Poco::SharedPtr<Poco::Net::WebSocket> pWebSocket = new Poco::Net::WebSocket(*_pHTTPClientSession, request, response);
			if (response.get(SEC_WEBSOCKET_PROTOCOL, "") == WEBTUNNEL_PROTOCOL)
			{
				_logger.debug("WebSocket established. Creating RemotePortForwarder...");
				pWebSocket->setNoDelay(true);
				_retryDelay = 1000;
				_pForwarder = new Poco::WebTunnel::RemotePortForwarder(*_pDispatcher, pWebSocket, _host, _ports, _remoteTimeout);
				_pForwarder->setConnectTimeout(_connectTimeout);
				_pForwarder->setLocalTimeout(_localTimeout);
				_pForwarder->webSocketClosed += Poco::delegate(this, &WebTunnelAgent::onClose);
				_logger.information("WebTunnel connection established for device %s.", _deviceName);
				return;
			}
			else
			{
				_logger.error("The host at %s does not support the WebTunnel protocol.", _reflectorURI.toString());

				pWebSocket->shutdown(Poco::Net::WebSocket::WS_PROTOCOL_ERROR);
				// receive final frame from peer; ignore if none is sent.
				if (pWebSocket->poll(Poco::Timespan(2, 0), Poco::Net::Socket::SELECT_READ))
				{
					Poco::Buffer<char> buffer(1024);
					int flags;
					try
					{
						pWebSocket->receiveFrame(buffer.begin(), static_cast<int>(buffer.size()), flags);
					}
					catch (Poco::Exception&)
					{
					}
				}
				pWebSocket->close();
				reconnect = false;
			}
		}
		catch (Poco::Exception& exc)
		{
			_logger.error("Cannot connect device %s to reflector at %s: %s", _deviceName, _reflectorURI.toString(), exc.displayText());
			if (_retryDelay < 30000)
			{
				_retryDelay *= 2;
			}
			reconnect = !_stopped;
		}
		if (reconnect)
		{
			Poco::Timestamp ts;
			ts += _retryDelay*1000;
			_pTimer->schedule(new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::reconnect), ts);
		}
	}
}


void WebTunnelAgent::disconnect()
{
	if (_pForwarder)
	{
		_logger.information("Disconnecting device %s from reflector server", _deviceName);

		_pForwarder->webSocketClosed -= Poco::delegate(this, &WebTunnelAgent::onClose);
		_pForwarder->stop();
		_pForwarder = 0;
	}
	if (_pHTTPClientSession)
	{
		try
		{
			_pHTTPClientSession->abort();
		}
		catch (Poco::Exception&)
		{
		}
	}
}


void WebTunnelAgent::onClose(const int& reason)
{
	std::string message;
	switch (reason)
	{
	case Poco::WebTunnel::RemotePortForwarder::RPF_CLOSE_GRACEFUL:
		message = "WebTunnel connection gracefully closed";
		break;
	case Poco::WebTunnel::RemotePortForwarder::RPF_CLOSE_UNEXPECTED:
		message = "WebTunnel connection unexpectedly closed";
		break;
	case Poco::WebTunnel::RemotePortForwarder::RPF_CLOSE_ERROR:
		message = "WebTunnel connection closed due to error";
		break;
	case Poco::WebTunnel::RemotePortForwarder::RPF_CLOSE_TIMEOUT:
		message = "WebTunnel connection closed due to timeout";
		break;
	}
	_logger.information("%s for device %s.", message, _deviceName);

	Poco::Timestamp ts;
	ts += _retryDelay*1000;
	_pTimer->schedule(new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::reconnect), ts);
}


void WebTunnelAgent::reconnect(Poco::Util::TimerTask&)
{
	try
	{
		disconnect();
		connect();
	}
	catch (Poco::Exception& exc)
	{
		_logger.fatal(exc.displayText());
	}
}


void WebTunnelAgent::init(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig)
{
	_deviceName = pConfig->getString("webtunnel.deviceName", "");
	_reflectorURI = pConfig->getString("webtunnel.reflectorURI");
	_username = pConfig->getString("webtunnel.username", "");
	_password = pConfig->getString("webtunnel.password", "");
	std::string host = pConfig->getString("webtunnel.host", "localhost");
	if (!Poco::Net::IPAddress::tryParse(host, _host))
	{
		_host = Poco::Net::DNS::resolveOne(host);
	}
	std::string ports = pConfig->getString("webtunnel.ports", "");
	Poco::StringTokenizer tok(ports, ";,", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	for (Poco::StringTokenizer::Iterator it = tok.begin(); it != tok.end(); ++it)
	{
		int port = Poco::NumberParser::parse(*it);
		if (port > 0 && port < 65536)
		{
			_ports.insert(static_cast<Poco::UInt16>(port));
		}
		else
		{
			_logger.warning("Ignoring out-of-range port number specified in configuration for device %s: %d", _deviceName, port);
		}
	}

	if (_ports.empty())
	{
		throw Poco::InvalidArgumentException("No ports to forward");
	}

	_localTimeout = Poco::Timespan(pConfig->getInt("webtunnel.localTimeout", 7200), 0);
	_connectTimeout = Poco::Timespan(pConfig->getInt("webtunnel.connectTimeout", 10), 0);
	_remoteTimeout = Poco::Timespan(pConfig->getInt("webtunnel.remoteTimeout", 300), 0);
	_httpPort = static_cast<Poco::UInt16>(pConfig->getInt("webtunnel.httpPort", 0));
	_vncPort = static_cast<Poco::UInt16>(pConfig->getInt("webtunnel.vncPort", 0));
	_userAgent = pConfig->getString("webtunnel.userAgent", "");
	_httpTimeout = Poco::Timespan(pConfig->getInt("http.timeout", 30), 0);
	_useProxy = pConfig->getBool("http.proxy.enable", false);
	_proxyHost = pConfig->getString("http.proxy.host", "");
	_proxyPort = static_cast<Poco::UInt16>(pConfig->getInt("http.proxy.port", 80));
	_proxyUsername = pConfig->getString("http.proxy.username", "");
	_proxyPassword = pConfig->getString("http.proxy.password", "");

	if (_httpPort != 0 && _ports.find(_httpPort) == _ports.end())
	{
		_logger.warning("HTTP port (%hu) not in list of forwarded ports for device %s.", _httpPort, _deviceName);
	}

	if (_userAgent.empty())
	{
		_userAgent = WEBTUNNEL_AGENT;
		_userAgent += "/";
		_userAgent += Utility::versionString();
		_userAgent += " (";
		_userAgent += Poco::Environment::osName();
		_userAgent += "/";
		_userAgent += Poco::Environment::osVersion();
		_userAgent += "; ";
		_userAgent += Poco::Environment::osArchitecture();
		_userAgent += ") POCO/";
		_userAgent += Poco::format("%d.%d.%d",
			static_cast<int>(Poco::Environment::libraryVersion() >> 24),
			static_cast<int>((Poco::Environment::libraryVersion() >> 16) & 0xFF),
			static_cast<int>((Poco::Environment::libraryVersion() >> 8) & 0xFF));
	}

	_pTimer->schedule(new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::reconnect), Poco::Timestamp());
}


} } // namespace MyDevices::Gateway
