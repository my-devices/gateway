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
		}
		else if (action == "remove")
		{
			_pDeviceManager->removeDevice(target);
			_pDeviceManager->reconfigureAgents(2000);
			_request.response().redirect(_request.getURI());
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
				pDeviceConfig->setString("webtunnel.httpPort", httpPort);
			else
				pDeviceConfig->remove("webtunnel.httpPort");

			std::string httpsRequired = _form.get("httpsRequired");
			if (httpsRequired == "true")
				pDeviceConfig->setBool("webtunnel.https.enable", true);
			else
				pDeviceConfig->remove("webtunnel.https.enable");

			std::string sshPort = _form.get("sshPort");
			if (!sshPort.empty())
				pDeviceConfig->setString("webtunnel.sshPort", sshPort);
			else
				pDeviceConfig->remove("webtunnel.sshPort");

			std::string vncPort = _form.get("vncPort");
			if (!vncPort.empty())
				pDeviceConfig->setString("webtunnel.vncPort", vncPort);
			else
				pDeviceConfig->remove("webtunnel.vncPort");

			std::string rdpPort = _form.get("rdpPort");
			if (!rdpPort.empty())
				pDeviceConfig->setString("webtunnel.rdpPort", rdpPort);
			else
				pDeviceConfig->remove("webtunnel.rdpPort");

			pDeviceConfig->setString("webtunnel.password", _form.get("password"));
			_pDeviceManager->updateDevice(pDeviceConfig);
			_pDeviceManager->reconfigureAgents(2000);
			_request.response().redirect(_request.getURI());
		}
		else if (action == "cancel")
		{
			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = _pDeviceManager->deviceConfiguration(target);
			if (!pDeviceConfig->getBool("webtunnel.enable", true))
			{
				_pDeviceManager->removeDevice(target);
			}
			_request.response().redirect(_request.getURI());
		}
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


std::string IndexPageController::deviceStatus(const std::string& id) const
{
	WebTunnelAgent::Status status = WebTunnelAgent::STATUS_DISCONNECTED;
	WebTunnelAgent::Ptr pAgent = _pDeviceManager->agentForDevice(id);
	if (pAgent)
	{
		status = pAgent->status();
	}
	switch (status)
	{
	case WebTunnelAgent::STATUS_DISCONNECTED:
		return "disconnected";

	case WebTunnelAgent::STATUS_CONNECTED:
		return "connected";

	case WebTunnelAgent::STATUS_ERROR:
		return "error";

	default:
		return "unknown";
	}
}


} } // namespace MyDevices::Gateway
