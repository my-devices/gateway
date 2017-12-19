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
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


DevicePageController::~DevicePageController()
{
}


} } // namespace MyDevices::Gateway
