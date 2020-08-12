//
// IndexPageController.cpp
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "IndexPageController.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/NumberFormatter.h"
#include "Poco/NumberParser.h"
#include "Poco/StringTokenizer.h"
#include "Poco/String.h"
#include <set>


namespace MyDevices {
namespace Gateway {




IndexPageController::IndexPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
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
	processForm();
	_devices = pDeviceManager->enumerateDevices();
}


IndexPageController::~IndexPageController()
{
}


void IndexPageController::processForm()
{
	std::string action = _form.get("action", "");
	std::string target = _form.get("target", "");
	std::string csrfToken = _form.get("csrfToken", "");
	if (csrfToken == _csrfToken)
	{
		try
		{
			if (action == "add")
			{
				_request.response().redirect("/create");
			}
			else if (action == "remove")
			{
				_pDeviceManager->removeDevice(target);
				_pDeviceManager->reconfigureAgents(2000);
				_request.response().redirect(_request.getURI());
			}
		}
		catch (Poco::Exception& exc)
		{
			_message = exc.displayText();
		}
	}
}


std::string IndexPageController::formatPorts(Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig) const
{
	unsigned httpPort = pDeviceConfig->getUInt("webtunnel.httpPort", 0);
	unsigned sshPort = pDeviceConfig->getUInt("webtunnel.sshPort", 0);
	unsigned vncPort = pDeviceConfig->getUInt("webtunnel.vncPort", 0);
	unsigned rdpPort = pDeviceConfig->getUInt("webtunnel.rdpPort", 0);
	bool httpsEnable = pDeviceConfig->getBool("webtunnel.https.enable", false);
	std::string portsStr = pDeviceConfig->getString("webtunnel.ports", "");
	Poco::StringTokenizer portsTok(portsStr, ",;", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
	std::set<unsigned> ports;
	for (Poco::StringTokenizer::Iterator it = portsTok.begin(); it != portsTok.end(); ++it)
	{
		unsigned port;
		if (Poco::NumberParser::tryParseUnsigned(*it, port))
		{
			ports.insert(port);
		}
	}
	std::string result;
	for (std::set<unsigned>::const_iterator it = ports.begin(); it != ports.end(); ++it)
	{
		if (it != ports.begin()) result += ", ";
		result += Poco::NumberFormatter::format(*it);
		if (*it == httpPort)
			result += httpsEnable ? "/HTTPS" : "/HTTP";
		else if (*it == sshPort)
			result += "/SSH";
		else if (*it == vncPort)
			result += "/VNC";
		else if (*it == rdpPort)
			result += "/RDP";
	}
	return result;
}



std::string IndexPageController::deviceStatus(const std::string& id) const
{
	WebTunnelAgent::Status status = WebTunnelAgent::STATUS_DISCONNECTED;
	WebTunnelAgent::Ptr pAgent = _pDeviceManager->agentForDevice(id);
	if (pAgent)
	{
		status = pAgent->status();
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


} } // namespace MyDevices::Gateway
