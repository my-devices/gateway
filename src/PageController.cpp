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


const std::string PageController::MSG_CLASS_ERROR("error");
const std::string PageController::MSG_CLASS_WARNING("warning");
const std::string PageController::MSG_CLASS_INFORMATION("information");


PageController::PageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	_pDeviceManager(pDeviceManager),
	_request(request),
	_form(form)
{
}


PageController::~PageController()
{
}


void PageController::message(const std::string& text, const std::string& messageClass)
{
	_message = text;
	_messageClass = messageClass;
}


std::string PageController::defaultDomain() const
{
	return _pDeviceManager->config()->getString("webtunnel.domain", "");
}


} } // namespace MyDevices::Gateway
