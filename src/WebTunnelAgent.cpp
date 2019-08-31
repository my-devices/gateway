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
#include "Poco/Net/NetException.h"
#include "Poco/Net/DNS.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberParser.h"
#include "Poco/NumberFormatter.h"
#include "Poco/Environment.h"
#include "Poco/Delegate.h"
#include "Poco/Buffer.h"
#include "Poco/String.h"


namespace MyDevices {
namespace Gateway {


const std::string WebTunnelAgent::SEC_WEBSOCKET_PROTOCOL("Sec-WebSocket-Protocol");
const std::string WebTunnelAgent::WEBTUNNEL_PROTOCOL("com.appinf.webtunnel.server/1.0");
const std::string WebTunnelAgent::WEBTUNNEL_AGENT("macchina.io Remote Manager Gateway");


WebTunnelAgent::WebTunnelAgent(const std::string& deviceId, Poco::SharedPtr<Poco::Util::Timer> pTimer, Poco::SharedPtr<Poco::WebTunnel::SocketDispatcher> pDispatcher, Poco::AutoPtr<Poco::Util::AbstractConfiguration> pConfig):
	_id(deviceId),
	_pConfig(pConfig),
	_httpPort(0),
	_sshPort(0),
	_vncPort(0),
	_rdpPort(0),
	_useProxy(false),
	_proxyPort(0),
	_retryDelay(MIN_RETRY_DELAY),
	_pTimer(pTimer),
	_pDispatcher(pDispatcher),
	_status(STATUS_DISCONNECTED),
	_logger(Poco::Logger::get("WebTunnelAgent"))
{
	init();
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
	_logger.debug("Stopping agent %s...", _id);
	_stopped.set();
	disconnect();
}


void WebTunnelAgent::addProperties(Poco::Net::HTTPRequest& request, const std::map<std::string, std::string>& props)
{
	request.add("X-PTTH-Set-Property", Poco::format("device;targetHost=%s", _host.toString()));
	request.add("X-PTTH-Set-Property", Poco::format("device;targetPorts=%s", formatPorts()));
	if (!_httpPath.empty())
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;httpPath=%s", quoteString(_httpPath)));
	}
	if (_httpPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;httpPort=%hu", _httpPort));
	}
	if (_sshPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;sshPort=%hu", _sshPort));
	}
	if (_vncPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;vncPort=%hu", _vncPort));
	}
	if (_rdpPort != 0)
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;rdpPort=%hu", _rdpPort));
	}
	if (!_deviceName.empty())
	{
		request.add("X-PTTH-Set-Property", Poco::format("device;name=%s", quoteString(_deviceName)));
	}

	if (!props.empty())
	{
		for (std::map<std::string, std::string>::const_iterator it = props.begin(); it != props.end(); ++it)
		{
			request.add("X-PTTH-Set-Property", Poco::format("device;%s=%s", it->first, quoteString(it->second)));
		}
	}
	request.set("User-Agent", _userAgent);
}


std::string WebTunnelAgent::formatPorts()
{
	std::string result;
	for (std::set<Poco::UInt16>::const_iterator it = _ports.begin(); it != _ports.end(); ++it)
	{
		if (!result.empty()) result += ", ";
		Poco::NumberFormatter::append(result, *it);
	}
	return result;
}


void WebTunnelAgent::startPropertiesUpdateTask()
{
	_logger.debug("Starting PropertiesUpdateTask...");
	_pPropertiesUpdateTask = new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::updateProperties);
	_pTimer->scheduleAtFixedRate(_pPropertiesUpdateTask, _propertiesUpdateInterval.totalMilliseconds(), _propertiesUpdateInterval.totalMilliseconds());
}


void WebTunnelAgent::stopPropertiesUpdateTask()
{
	if (_pPropertiesUpdateTask)
	{
		_logger.debug("Stopping PropertiesUpdateTask...");
		_pPropertiesUpdateTask->cancel();
		_pPropertiesUpdateTask.reset();
	}
}


void WebTunnelAgent::connect()
{
	Poco::URI reflectorURI;
	if (!_redirectURI.empty())
		reflectorURI = _redirectURI;
	else
		reflectorURI = _reflectorURI;

	_logger.information("Connecting device %s to %s...", _deviceName, reflectorURI.toString());

	_pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
	_pHTTPClientSession->setTimeout(_httpTimeout);
	if (_useProxy && !_proxyHost.empty())
	{
		_pHTTPClientSession->setProxy(_proxyHost, _proxyPort);
		if (!_proxyUsername.empty())
		{
			_pHTTPClientSession->setProxyCredentials(_proxyUsername, _proxyPassword);
		}
	}

	std::string path(reflectorURI.getPathEtc());
	if (path.empty()) path = "/";
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, path, Poco::Net::HTTPRequest::HTTP_1_1);
	request.set(SEC_WEBSOCKET_PROTOCOL, WEBTUNNEL_PROTOCOL);

	if (!_username.empty())
	{
		Poco::Net::HTTPBasicCredentials creds(_username, _password);
		creds.authenticate(request);
	}

	std::map<std::string, std::string> props;
	collectProperties(props);
	addProperties(request, props);
	request.set("User-Agent", _userAgent);

	Poco::Net::HTTPResponse response;
	bool reconnect = true;
	if (!_stopped.tryWait(1))
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
				_retryDelay = MIN_RETRY_DELAY;
				_pForwarder = new Poco::WebTunnel::RemotePortForwarder(*_pDispatcher, pWebSocket, _host, _ports, _remoteTimeout);
				_pForwarder->setConnectTimeout(_connectTimeout);
				_pForwarder->setLocalTimeout(_localTimeout);
				_pForwarder->webSocketClosed += Poco::delegate(this, &WebTunnelAgent::onClose);
				_logger.information("WebTunnel connection established for device %s.", _deviceName);

				if (!props.empty() && _propertiesUpdateInterval > 0)
				{
					startPropertiesUpdateTask();
				}
				statusChanged(STATUS_CONNECTED);

				return;
			}
			else
			{
				statusChanged(STATUS_ERROR, Poco::format("The host at %s does not support the WebTunnel protocol.", reflectorURI.toString()));
				_logger.error(_lastError);

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
		catch (Poco::Net::WebSocketException& exc)
		{
			if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_FOUND)
			{
				_redirectURI = Poco::URI(_reflectorURI, response.get("Location"));
				_retryDelay = MIN_RETRY_DELAY;
				_logger.information("Redirected to %s.", _redirectURI.toString());
			}
			else
			{
				std::string msg = response.get("X-PTTH-Error", exc.displayText());
				statusChanged(STATUS_ERROR, Poco::format("Cannot connect to reflector at %s: %s", reflectorURI.toString(), msg));
				_logger.error(_lastError);
				if (_retryDelay < MAX_RETRY_DELAY)
				{
					_retryDelay *= 2;
				}
				_redirectURI.clear();
			}
		}
		catch (Poco::Exception& exc)
		{
			statusChanged(STATUS_ERROR, Poco::format("Cannot connect device to reflector at %s: %s", reflectorURI.toString(), exc.displayText()));
			_logger.error("Cannot connect device %s to reflector at %s: %s", _deviceName, reflectorURI.toString(), exc.displayText());
			if (_retryDelay < MAX_RETRY_DELAY)
			{
				_retryDelay *= 2;
			}
			_redirectURI.clear();
			reconnect = true;
		}
		if (reconnect && !_stopped.tryWait(1))
		{
			scheduleReconnect();
		}
	}
}


void WebTunnelAgent::disconnect()
{
	stopPropertiesUpdateTask();
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
	statusChanged(STATUS_DISCONNECTED);
}


void WebTunnelAgent::onClose(const int& reason)
{
	stopPropertiesUpdateTask();

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

	statusChanged(STATUS_DISCONNECTED);
	scheduleReconnect();
}


void WebTunnelAgent::reconnectTask(Poco::Util::TimerTask&)
{
	try
	{
		try
		{
			disconnect();
		}
		catch (Poco::Exception& exc)
		{
			_logger.warning("Exception during disconnect: " + exc.displayText());
		}
		catch (std::exception& exc)
		{
			_logger.error(std::string("Exception during disconnect: ") + exc.what());
		}
		catch (...)
		{
			_logger.error("Unknown exception during disconnect.");
		}
		connect();
	}
	catch (Poco::Exception& exc)
	{
		_logger.fatal(exc.displayText());
		_retryDelay = MAX_RETRY_DELAY;
		scheduleReconnect();
	}
	catch (...)
	{
		_logger.fatal("Unknown exception during connect()");
	}
}


void WebTunnelAgent::disconnectTask(Poco::Util::TimerTask&)
{
	try
	{
		disconnect();
	}
	catch (Poco::Exception& exc)
	{
		_logger.warning("Exception during disconnect: " + exc.displayText());
	}
}


void WebTunnelAgent::scheduleReconnect()
{
	if (!_stopped.tryWait(1))
	{
		Poco::Clock::ClockDiff retryDelay(static_cast<Poco::Clock::ClockDiff>(_retryDelay)*1000);
		retryDelay += _random.next(250*_retryDelay);
		Poco::Clock nextClock;
		nextClock += retryDelay;
		_logger.information(Poco::format("Will reconnect in %.2f seconds.", retryDelay/1000000.0));
		_pTimer->schedule(new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::reconnectTask), nextClock);
	}
}


void WebTunnelAgent::init()
{
	_deviceName = _pConfig->getString("webtunnel.deviceName", "");
	_reflectorURI = _pConfig->getString("webtunnel.reflectorURI");
	_username = _pConfig->getString("webtunnel.username", "");
	_password = _pConfig->getString("webtunnel.password", "");
	std::string host = _pConfig->getString("webtunnel.host", "localhost");
	if (!Poco::Net::IPAddress::tryParse(host, _host))
	{
		_host = Poco::Net::DNS::resolveOne(host);
	}
	std::string ports = _pConfig->getString("webtunnel.ports", "");
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

	_localTimeout = Poco::Timespan(_pConfig->getInt("webtunnel.localTimeout", 7200), 0);
	_connectTimeout = Poco::Timespan(_pConfig->getInt("webtunnel.connectTimeout", 10), 0);
	_remoteTimeout = Poco::Timespan(_pConfig->getInt("webtunnel.remoteTimeout", 300), 0);
	_propertiesUpdateInterval = Poco::Timespan(_pConfig->getInt("webtunnel.propertiesUpdateInterval", 0), 0);
	_httpPath = _pConfig->getString("webtunnel.httpPath", "");
	_httpPort = static_cast<Poco::UInt16>(_pConfig->getInt("webtunnel.httpPort", 0));
	_vncPort = static_cast<Poco::UInt16>(_pConfig->getInt("webtunnel.vncPort", 0));
	_userAgent = _pConfig->getString("webtunnel.userAgent", "");
	_httpTimeout = Poco::Timespan(_pConfig->getInt("http.timeout", 30), 0);
	_useProxy = _pConfig->getBool("http.proxy.enable", false);
	_proxyHost = _pConfig->getString("http.proxy.host", "");
	_proxyPort = static_cast<Poco::UInt16>(_pConfig->getInt("http.proxy.port", 80));
	_proxyUsername = _pConfig->getString("http.proxy.username", "");
	_proxyPassword = _pConfig->getString("http.proxy.password", "");

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

	_pTimer->schedule(new Poco::Util::TimerTaskAdapter<WebTunnelAgent>(*this, &WebTunnelAgent::reconnectTask), Poco::Clock());
}


void WebTunnelAgent::updateProperties(Poco::Util::TimerTask&)
{
	_logger.debug("Updating device properties...");
	try
	{
		std::map<std::string, std::string> props;
		collectProperties(props);
		_pForwarder->updateProperties(props);
	}
	catch (Poco::Exception& exc)
	{
		_logger.error("Failed to update device properties: %s", exc.displayText());
	}
	_logger.debug("Done updating device properties.");
}


void WebTunnelAgent::collectProperties(std::map<std::string, std::string>& props)
{
	std::vector<std::string> keys;
	_pConfig->keys("webtunnel.properties", keys);
	for (std::vector<std::string>::const_iterator it = keys.begin(); it != keys.end(); ++it)
	{
		std::string fullName("webtunnel.properties.");
		fullName += *it;
		std::string value = _pConfig->getString(fullName);
		if (!value.empty() && value[0] == '`' && value[value.length() - 1] == '`')
		{
			std::string command(value, 1, value.length() - 2);
			try
			{
				value = runCommand(command);
				props[*it] = value;
			}
			catch (Poco::Exception& exc)
			{
				_logger.warning("Command for property '%s' failed: %s", *it, exc.displayText());
			}
		}
		else
		{
			props[*it] = value;
		}
	}
}


std::string WebTunnelAgent::runCommand(const std::string& command)
{
	std::string output;
#ifdef _WIN32
	std::string shell("cmd.exe");
	std::string shellArg("/C");
#else
	std::string shell("/bin/sh");
	std::string shellArg("-c");
#endif
	Poco::Pipe outPipe;
	Poco::Process::Args shellArgs;
	shellArgs.push_back(shellArg);
	shellArgs.push_back(command);
	Poco::ProcessHandle ph(Poco::Process::launch(shell, shellArgs, 0, &outPipe, &outPipe));
	Poco::PipeInputStream istr(outPipe);
	Poco::StreamCopier::copyToString(istr, output);
	ph.wait();
	Poco::trimInPlace(output);
	return output;
}


WebTunnelAgent::Status WebTunnelAgent::status() const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	return _status;
}


std::string WebTunnelAgent::lastError() const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	return _lastError;
}


void WebTunnelAgent::statusChanged(Status status)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	_status = status;
	_lastError.clear();
}


void WebTunnelAgent::statusChanged(Status status, const std::string& error)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	_status = status;
	_lastError = error;
}


std::string WebTunnelAgent::quoteString(const std::string& str)
{
	std::string quoted("\"");
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it < ' ')
		{
			quoted += ' ';
		}
		else
		{
			if (*it == '\"')
				quoted += '\\';
			quoted += *it;
		}
	}
	quoted += '"';
	return quoted;
}


} } // namespace MyDevices::Gateway
