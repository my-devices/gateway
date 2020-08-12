//
// StatusJSONController.h
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_StatusJSONController_INCLUDED
#define MyGateway_StatusJSONController_INCLUDED


#include "PageController.h"


namespace MyDevices {
namespace Gateway {


class StatusJSONController: public PageController
{
public:
	StatusJSONController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	virtual ~StatusJSONController();
		/// Destroys the PageController.

	const std::vector<std::string>& devices() const
	{
		return _devices;
	}

	std::string deviceStatus(const std::string& id) const;

private:
	std::vector<std::string> _devices;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_StatusJSONController_INCLUDED
