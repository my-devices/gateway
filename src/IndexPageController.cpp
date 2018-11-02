//
// IndexPageController.cpp
//
// Copyright (c) 2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "IndexPageController.h"
#include "Poco/Net/HTTPServerResponse.h"


namespace MyDevices {
namespace Gateway {


IndexPageController::IndexPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	processForm();
	_devices = pDeviceManager->enumerateDevices();
}


IndexPageController::~IndexPageController()
{
}


void IndexPageController::processForm()
{
	std::string action = _form.get("action", "");
	std::string target = _form.get("target", "");
	try
	{
		if (action == "add")
		{
			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = _pDeviceManager->createDevice();
			_request.response().redirect("/device/" + pDeviceConfig->getString("webtunnel.deviceId"));
			return;
		}
		else if (action == "remove")
		{
			_pDeviceManager->removeDevice(target);
			_pDeviceManager->restartAgents(2000);
		}
		else if (action == "update")
		{
			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = _pDeviceManager->deviceConfiguration(target);
			pDeviceConfig->setString("webtunnel.deviceName", _form.get("deviceName"));
			std::string domain = _form.get("domain");
			if (!domain.empty())
				pDeviceConfig->setString("webtunnel.domain", domain);
			else
				pDeviceConfig->remove("webtunnel.domain");
			pDeviceConfig->setString("webtunnel.host", _form.get("host"));
			pDeviceConfig->setString("webtunnel.ports", _form.get("ports"));
			std::string httpPort = _form.get("httpPort");
			if (!httpPort.empty())
				pDeviceConfig->setString("webtunnel.httpPort", _form.get("httpPort"));
			else
				pDeviceConfig->remove("webtunnel.httpPort");
			std::string vncPort = _form.get("vncPort");
			if (!vncPort.empty())
				pDeviceConfig->setString("webtunnel.vncPort", _form.get("vncPort"));
			else
				pDeviceConfig->remove("webtunnel.vncPort");
			pDeviceConfig->setString("webtunnel.password", _form.get("password"));
			_pDeviceManager->updateDevice(pDeviceConfig);
			_pDeviceManager->restartAgents(2000);
		}
		else if (action == "cancel")
		{
			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = _pDeviceManager->deviceConfiguration(target);
			if (!pDeviceConfig->getBool("webtunnel.enable", true))
			{
				_pDeviceManager->removeDevice(target);
			}
		}
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


} } // namespace MyDevices::Gateway
