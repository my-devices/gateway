//
// PageController.h
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_PageController_INCLUDED
#define MyGateway_PageController_INCLUDED


#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTMLForm.h"
#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class PageController
	/// The base class for all PageController classes in the gateway server
	/// web user interface. Can also be used as a minimal page controller instance
	/// for simple pages.
{
public:
	PageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	virtual ~PageController();
		/// Destroys the PageController.

	DeviceManager::Ptr deviceManager() const
	{
		return _pDeviceManager;
	}

	const std::string& message() const
	{
		return _message;
	}

	const std::string& messageStyle() const
	{
		return _messageStyle;
	}

protected:
	DeviceManager::Ptr _pDeviceManager;
	const Poco::Net::HTTPServerRequest& _request;
	const Poco::Net::HTMLForm& _form;
	std::string _message;
	std::string _messageStyle;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_PageController_INCLUDED
