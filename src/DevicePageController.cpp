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


namespace MyDevices {
namespace Gateway {


namespace
{
	Poco::UInt16 validatePort(const std::string& portStr)
	{
		std::string portTrim = Poco::trim(portStr);
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
		throw Poco::InvalidArgumentException("Invalid port", portTrim);
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
		throw Poco::InvalidArgumentException("Invalid host", host);
	}
}


DevicePageController::DevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway", request);
	if (!pSession || !pSession->has("username"))
	{
		request.response().redirect("/");
		return;
	}
	_username = pSession->getValue<std::string>("username");
	_csrfToken = pSession->csrfToken();
	try
	{
		Poco::Path p(request.getURI());
		_deviceId = p.getFileName();
		_pDeviceConfig = _pDeviceManager->deviceConfiguration(_deviceId);
		_pAgent = _pDeviceManager->agentForDevice(_deviceId);
		_message = deviceError();
		loadDevice();
		processForm();
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


DevicePageController::~DevicePageController()
{
}


void DevicePageController::loadDevice()
{
	_name = deviceConfig()->getString("webtunnel.deviceName", "");
	_domain = deviceConfig()->getString("webtunnel.domain", "");
	_password = deviceConfig()->getString("webtunnel.password", "");
	_host = deviceConfig()->getString("webtunnel.host", "");
	_httpPort = deviceConfig()->getString("webtunnel.httpPort", "");
	_httpsEnable = deviceConfig()->getBool("webtunnel.https.enable", false);
	_sshPort = deviceConfig()->getString("webtunnel.sshPort", "");
	_vncPort = deviceConfig()->getString("webtunnel.vncPort", "");
	_rdpPort = deviceConfig()->getString("webtunnel.rdpPort", "");
	_extraPorts = loadExtraPorts();
}


std::string DevicePageController::loadExtraPorts() const
{
	unsigned httpPort = deviceConfig()->getUInt("webtunnel.httpPort", 0);
	unsigned sshPort = deviceConfig()->getUInt("webtunnel.sshPort", 0);
	unsigned vncPort = deviceConfig()->getUInt("webtunnel.vncPort", 0);
	unsigned rdpPort = deviceConfig()->getUInt("webtunnel.rdpPort", 0);
	std::string portsStr = deviceConfig()->getString("webtunnel.ports", "");
	Poco::StringTokenizer portsTok(portsStr, ",;", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
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
	std::string action = _form.get("action", "");
	std::string csrfToken = _form.get("csrfToken", "");

	if (csrfToken == _csrfToken)
	{
		if (action == "update")
		{
			_name = _form.get("deviceName");
			_domain = _form.get("domain");
			_password = _form.get("password");
			_host = _form.get("host");
			_httpPort = _form.get("httpPort");
			_httpsEnable = _form.get("httpsRequired", "") == "true";
			_sshPort = _form.get("sshPort");
			_vncPort = _form.get("vncPort");
			_rdpPort = _form.get("rdpPort");
			_extraPorts = _form.get("ports");

			bool ok = true;
			try
			{
				deviceConfig()->setString("webtunnel.deviceName", _name);

				if (!_domain.empty())
					deviceConfig()->setString("webtunnel.domain", _domain);
				else
					deviceConfig()->remove("webtunnel.domain");


				validateHost(_host);
				deviceConfig()->setString("webtunnel.host", _host);

				std::set<Poco::UInt16> ports;
				Poco::UInt16 httpPort = validatePort(_httpPort);
				if (httpPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.httpPort", httpPort);
					ports.insert(httpPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.httpPort");
				}

				if (_httpsEnable)
				{
					deviceConfig()->setBool("webtunnel.https.enable", true);
				}
				else
				{
					deviceConfig()->remove("webtunnel.https.enable");
				}

				Poco::UInt16 sshPort = validatePort(_sshPort);
				if (sshPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.sshPort", sshPort);
					ports.insert(sshPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.sshPort");
				}

				Poco::UInt16 vncPort = validatePort(_vncPort);
				if (vncPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.vncPort", vncPort);
					ports.insert(vncPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.vncPort");
				}

				Poco::UInt16 rdpPort = validatePort(_rdpPort);
				if (rdpPort > 0)
				{
					deviceConfig()->setUInt("webtunnel.rdpPort", rdpPort);
					ports.insert(rdpPort);
				}
				else
				{
					deviceConfig()->remove("webtunnel.rdpPort");
				}

				deviceConfig()->setString("webtunnel.password", _password);

				Poco::StringTokenizer portsTok(_extraPorts, ",;", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
				for (Poco::StringTokenizer::Iterator it = portsTok.begin(); it != portsTok.end(); ++it)
				{
					ports.insert(validatePort(*it));
				}

				if (!ports.empty())
				{
					std::string portsStr;
					for (std::set<Poco::UInt16>::const_iterator it = ports.begin(); it != ports.end(); ++it)
					{
						if (it != ports.begin()) portsStr += ", ";
						portsStr += Poco::NumberFormatter::format(static_cast<unsigned>(*it));
					}
					deviceConfig()->setString("webtunnel.ports", portsStr);
				}
				else
				{
					_message = "At least one port must be enabled.";
					ok = false;
				}
			}
			catch (Poco::Exception& exc)
			{
				_message = exc.displayText();
				ok = false;
			}

			if (ok)
			{
				_pDeviceManager->updateDevice(deviceConfig());
				_pDeviceManager->reconfigureAgents(2000);
				_request.response().redirect("/devices");
			}
		}
		else if (action == "cancel")
		{
			if (!deviceConfig()->getBool("webtunnel.enable", true))
			{
				_pDeviceManager->removeDevice(_deviceId);
			}
			_request.response().redirect("/devices");
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
		return "disconnected";

	case WebTunnelAgent::STATUS_CONNECTED:
		return "connected";

	case WebTunnelAgent::STATUS_ERROR:
		return "error";

	default:
		return "unknown";
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
