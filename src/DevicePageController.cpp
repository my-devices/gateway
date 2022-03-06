//
// DevicePageController.cpp
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DevicePageController.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/NumberParser.h"
#include "Poco/NumberFormatter.h"
#include "Poco/StringTokenizer.h"
#include "Poco/String.h"
#include "Poco/Path.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


namespace
{
	Poco::UInt16 validatePort(const std::string& portStr)
	{
		const std::string portTrim = Poco::trim(portStr);
		if (portTrim.empty()) return 0;
		try
		{
			unsigned port = Poco::NumberParser::parseUnsigned(portTrim);
			if (port > 0 && port < 65536)
				return static_cast<Poco::UInt16>(port);
		}
		catch (Poco::Exception&)
		{
		}
		throw Poco::InvalidArgumentException("Invalid port"s, portTrim);
	}

	void validateHost(const std::string& host)
	{
		try
		{
			Poco::Net::SocketAddress sa(host, 80);
			return;
		}
		catch (...)
		{
		}
		throw Poco::InvalidArgumentException("Invalid host"s, host);
	}
}


DevicePageController::DevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway"s, request);
	if (!pSession || !pSession->has("username"s))
	{
		request.response().redirect("/"s);
		return;
	}
	username(pSession->getValue<std::string>("username"s));
	csrfToken(pSession->csrfToken());
	try
	{
		Poco::Path p(request.getURI());
		_deviceId = p.getFileName();
		_pDeviceConfig = deviceManager()->deviceConfiguration(_deviceId);
		_pAgent = deviceManager()->agentForDevice(_deviceId);
		message(deviceError());
		loadDevice();
		processForm();
	}
	catch (Poco::Exception& exc)
	{
		message(exc.displayText());
	}
}


DevicePageController::~DevicePageController()
{
}


void DevicePageController::loadDevice()
{
	_name = deviceConfig()->getString("webtunnel.deviceName"s, ""s);
	_domain = deviceConfig()->getString("webtunnel.domain"s, ""s);
	_password = deviceConfig()->getString("webtunnel.password"s, ""s);
	_host = deviceConfig()->getString("webtunnel.host"s, ""s);
	_httpPort = deviceConfig()->getString("webtunnel.httpPort"s, ""s);
	_httpsEnable = deviceConfig()->getBool("webtunnel.https.enable"s, false);
	_sshPort = deviceConfig()->getString("webtunnel.sshPort"s, ""s);
	_vncPort = deviceConfig()->getString("webtunnel.vncPort"s, ""s);
	_rdpPort = deviceConfig()->getString("webtunnel.rdpPort"s, ""s);
	_extraPorts = loadExtraPorts();
}


std::string DevicePageController::loadExtraPorts() const
{
	const unsigned httpPort = deviceConfig()->getUInt("webtunnel.httpPort"s, 0);
	const unsigned sshPort = deviceConfig()->getUInt("webtunnel.sshPort"s, 0);
	const unsigned vncPort = deviceConfig()->getUInt("webtunnel.vncPort"s, 0);
	const unsigned rdpPort = deviceConfig()->getUInt("webtunnel.rdpPort"s, 0);
	const std::string portsStr = deviceConfig()->getString("webtunnel.ports"s, ""s);
	Poco::StringTokenizer portsTok(portsStr, ",;"s, Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	std::set<unsigned> ports;
	for (Poco::StringTokenizer::Iterator it = portsTok.begin(); it != portsTok.end(); ++it)
	{
		unsigned port;
		if (Poco::NumberParser::tryParseUnsigned(*it, port))
		{
			if (port != httpPort && port != sshPort && port != vncPort && port != rdpPort)
			{
				ports.insert(port);
			}
		}
	}
	std::string result;
	for (std::set<unsigned>::const_iterator it = ports.begin(); it != ports.end(); ++it)
	{
		if (it != ports.begin()) result += ", ";
		result += Poco::NumberFormatter::format(*it);
	}
	return result;
}


void DevicePageController::processForm()
{
	const std::string action = form().get("action"s, ""s);
	const std::string token = form().get("csrfToken"s, ""s);

	if (token == csrfToken())
	{
		if (action == "update"s)
		{
			_name = form().get("deviceName"s);
			_domain = form().get("domain"s);
			_password = form().get("password"s);
			_host = form().get("host"s);
			_httpPort = form().get("httpPort"s);
			_httpsEnable = form().get("httpsRequired"s, ""s) == "true";
			_sshPort = form().get("sshPort"s);
			_vncPort = form().get("vncPort"s);
			_rdpPort = form().get("rdpPort"s);
			_extraPorts = form().get("ports"s);

			bool ok = true;
			try
			{
				deviceConfig()->setString("webtunnel.deviceName"s, _name);

				if (!_domain.empty())
					deviceConfig()->setString("webtunnel.domain"s, _domain);
				else
					deviceConfig()->remove("webtunnel.domain"s);


				validateHost(_host);
				deviceConfig()->setString("webtunnel.host"s, _host);

				std::set<Poco::UInt16> ports;
				Poco::UInt16 httpPort = validatePort(_httpPort);
				if (httpPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.httpPort"s, httpPort);
					ports.insert(httpPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.httpPort"s);
				}

				if (_httpsEnable)
				{
					deviceConfig()->setBool("webtunnel.https.enable"s, true);
				}
				else
				{
					deviceConfig()->remove("webtunnel.https.enable"s);
				}

				Poco::UInt16 sshPort = validatePort(_sshPort);
				if (sshPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.sshPort"s, sshPort);
					ports.insert(sshPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.sshPort"s);
				}

				Poco::UInt16 vncPort = validatePort(_vncPort);
				if (vncPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.vncPort"s, vncPort);
					ports.insert(vncPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.vncPort"s);
				}

				Poco::UInt16 rdpPort = validatePort(_rdpPort);
				if (rdpPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.rdpPort"s, rdpPort);
					ports.insert(rdpPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.rdpPort"s);
				}

				deviceConfig()->setString("webtunnel.password"s, _password);

				Poco::StringTokenizer portsTok(_extraPorts, ",;"s, Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
				for (Poco::StringTokenizer::Iterator it = portsTok.begin(); it != portsTok.end(); ++it)
				{
					ports.insert(validatePort(*it));
				}

				if (!ports.empty())
				{
					std::string portsStr;
					for (std::set<Poco::UInt16>::const_iterator it = ports.begin(); it != ports.end(); ++it)
					{
						if (it != ports.begin()) portsStr += ", "s;
						portsStr += Poco::NumberFormatter::format(static_cast<unsigned>(*it));
					}
					deviceConfig()->setString("webtunnel.ports"s, portsStr);
				}
				else
				{
					message("At least one port must be enabled."s);
					ok = false;
				}
			}
			catch (Poco::Exception& exc)
			{
				message(exc.displayText());
				ok = false;
			}

			if (ok)
			{
				deviceManager()->updateDevice(deviceConfig());
				deviceManager()->reconfigureAgents(2000);
				request().response().redirect("/devices"s);
			}
		}
		else if (action == "cancel")
		{
			if (!deviceConfig()->getBool("webtunnel.enable", true))
			{
				deviceManager()->removeDevice(_deviceId);
			}
			request().response().redirect("/devices"s);
		}
	}
}


std::string DevicePageController::deviceStatus() const
{
	WebTunnelAgent::Status status = WebTunnelAgent::STATUS_DISCONNECTED;
	if (_pAgent)
	{
		status = _pAgent->status();
	}
	switch (status)
	{
	case WebTunnelAgent::STATUS_DISCONNECTED:
		return "disconnected"s;

	case WebTunnelAgent::STATUS_CONNECTED:
		return "connected"s;

	case WebTunnelAgent::STATUS_ERROR:
		return "error"s;

	default:
		return "unknown"s;
	}
}


std::string DevicePageController::deviceError() const
{
	if (_pAgent)
		return _pAgent->lastError();
	else
		return std::string();
}


} } // namespace MyDevices::Gateway
