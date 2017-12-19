//
// IndexPageController.h
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_IndexPageController_INCLUDED
#define MyGateway_IndexPageController_INCLUDED


#include "PageController.h"


namespace MyDevices {
namespace Gateway {


class IndexPageController: public PageController
{
public:
	IndexPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	virtual ~IndexPageController();
		/// Destroys the PageController.

	const std::vector<std::string>& devices() const
	{
		return _devices;
	}

protected:
	void processForm();

private:
	std::vector<std::string> _devices;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_IndexPageController_INCLUDED
