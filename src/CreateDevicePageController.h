//
// CreateDevicePageController.h
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_CreateDevicePageController_INCLUDED
#define MyGateway_CreateDevicePageController_INCLUDED


#include "PageController.h"
#include "WebTunnelAgent.h"


namespace MyDevices {
namespace Gateway {


class CreateDevicePageController: public PageController
{
public:
	CreateDevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the CreateDevicePageController.

	virtual ~CreateDevicePageController();
		/// Destroys the CreateDevicePageController.

	const std::string& deviceId() const
	{
		return _deviceId;
	}

	const std::string& name() const
	{
		return _name;
	}

	const std::string domain() const
	{
		return _domain;
	}

protected:
	void processForm();

private:
	std::string _deviceId;
	std::string _name;
	std::string _domain;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_CreateDevicePageController_INCLUDED
