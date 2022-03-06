//
// StatusJSONController.cpp
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "StatusJSONController.h"
#include "Poco/Net/HTTPServerResponse.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


StatusJSONController::StatusJSONController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway"s, request);
	if (!pSession || !pSession->has("username"s))
	{
		return;
	}
	_devices = pDeviceManager->enumerateDevices();
}


StatusJSONController::~StatusJSONController()
{
}


std::string StatusJSONController::deviceStatus(const std::string& id) const
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
		return "disconnected"s;

	case WebTunnelAgent::STATUS_CONNECTED:
		return "connected"s;

	case WebTunnelAgent::STATUS_ERROR:
		return "error"s;

	default:
		return "unknown"s;
	}
}


} } // namespace MyDevices::Gateway
