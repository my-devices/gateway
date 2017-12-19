//
// DevicePageController.h
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_DevicePageController_INCLUDED
#define MyGateway_DevicePageController_INCLUDED


#include "PageController.h"


namespace MyDevices {
namespace Gateway {


class DevicePageController: public PageController
{
public:
	DevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	virtual ~DevicePageController();
		/// Destroys the PageController.

	const std::string& deviceId() const
	{
		return _deviceId;
	}

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> deviceConfig() const
	{
		return _pDeviceConfig;
	}

private:
	std::string _deviceId;
	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pDeviceConfig;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_DevicePageController_INCLUDED
