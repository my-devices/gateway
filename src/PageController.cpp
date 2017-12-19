//
// PageController.cpp
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "PageController.h"


namespace MyDevices {
namespace Gateway {


PageController::PageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	_pDeviceManager(pDeviceManager),
	_request(request),
	_form(form)
{
}


PageController::~PageController()
{
}


} } // namespace MyDevices::Gateway
