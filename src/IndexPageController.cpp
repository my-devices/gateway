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
	username(pSession->getValue<std::string>("username"));
	csrfToken(pSession->csrfToken());
	processForm();
	_devices = pDeviceManager->enumerateDevices();
}


IndexPageController::~IndexPageController()
{
}


void IndexPageController::processForm()
{
	std::string action = form().get("action", "");
	std::string target = form().get("target", "");
	std::string token = form().get("csrfToken", "");
	if (token == csrfToken())
	{
		try
		{
			if (action == "add")
			{
				request().response().redirect("/create");
			}
			else if (action == "remove")
			{
				deviceManager()->removeDevice(target);
				deviceManager()->reconfigureAgents(2000);
				request().response().redirect(request().getURI());
			}
		}
		catch (Poco::Exception& exc)
		{
			message(exc.displayText());
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
	WebTunnelAgent::Ptr pAgent = deviceManager()->agentForDevice(id);
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
