//
// DevicePageController.cpp
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DevicePageController.h"
#include "Poco/Path.h"


namespace MyDevices {
namespace Gateway {


DevicePageController::DevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	try
	{
		Poco::Path p(request.getURI());
		_deviceId = p.getFileName();
		_pDeviceConfig = _pDeviceManager->deviceConfiguration(_deviceId);
		_pAgent = _pDeviceManager->agentForDevice(_deviceId);
		_message = deviceError();
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


DevicePageController::~DevicePageController()
{
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
