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


namespace MyDevices {
namespace Gateway {


StatusJSONController::StatusJSONController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway", request);
	if (!pSession || !pSession->has("username"))
	{
		return;
	}
	_username = pSession->getValue<std::string>("username");
	_devices = pDeviceManager->enumerateDevices();
}


StatusJSONController::~StatusJSONController()
{
}


std::string StatusJSONController::deviceStatus(const std::string& id) const
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
