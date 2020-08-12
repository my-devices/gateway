//
// LoginPageController.h
//
// Copyright (c) 2017-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_LoginPageController_INCLUDED
#define MyGateway_LoginPageController_INCLUDED


#include "PageController.h"
#include "Poco/Logger.h"


namespace MyDevices {
namespace Gateway {


class LoginPageController: public PageController
{
public:
	LoginPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	~LoginPageController();
		/// Destroys the PageController.

protected:
	void processForm();
	bool verifyDomainAccess(const Poco::URI& reflectorURI, const std::string& token, const std::string& domain);

private:
	Poco::Logger& _logger;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_LoginPageController_INCLUDED
