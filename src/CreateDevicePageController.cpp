//
// CreateDevicePageController.cpp
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "CreateDevicePageController.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/NumberParser.h"
#include "Poco/NumberFormatter.h"
#include "Poco/UUIDGenerator.h"
#include "Poco/StringTokenizer.h"
#include "Poco/String.h"
#include "Poco/Ascii.h"
#include "Poco/Path.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


namespace
{
	bool isValidId(const std::string& id)
	{
		std::string::const_iterator it = id.begin();
		std::string::const_iterator end = id.end();
		if (it == end) return false;
		if (!Poco::Ascii::hasSomeProperties(*it, Poco::Ascii::ACP_LOWER | Poco::Ascii::ACP_DIGIT)) return false;
		++it;
		while (it != end)
		{
			if (!Poco::Ascii::hasSomeProperties(*it, Poco::Ascii::ACP_LOWER | Poco::Ascii::ACP_DIGIT) && *it != '-') return false;
			++it;
		}
		return true;
	}
}


CreateDevicePageController::CreateDevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form)
{
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway"s, request);
	if (!pSession || !pSession->has("username"s))
	{
		request.response().redirect("/"s);
		return;
	}
	username(pSession->getValue<std::string>("username"s));
	csrfToken(pSession->csrfToken());
	try
	{
		if (form.has("action"s))
		{
			processForm();
		}
		else
		{
			Poco::UUIDGenerator uuidGen;
			_deviceId = uuidGen.createRandom().toString();
			_name = "Unnamed Device";
			_domain = pSession->getValue<std::string>("domain"s, defaultDomain());
		}
	}
	catch (Poco::Exception& exc)
	{
		message(exc.displayText());
	}
}


CreateDevicePageController::~CreateDevicePageController()
{
}


void CreateDevicePageController::processForm()
{
	const std::string action = form().get("action"s, ""s);
	const std::string token = form().get("csrfToken"s, ""s);

	if (token == csrfToken())
	{
		if (action == "create")
		{
			_deviceId = form().get("deviceId"s);
			_name = form().get("deviceName"s);
			_domain = form().get("domain"s);

			if (!isValidId(_deviceId))
			{
				message("Invalid device ID: "s + _deviceId);
				return;
			}

			if (!isValidId(_domain))
			{
				message("Invalid domain ID: "s + _domain);
				return;
			}

			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = deviceManager()->createDevice(_deviceId, _domain, _name);

			request().response().redirect("/device/"s + _deviceId);
		}
		else if (action == "cancel")
		{
			request().response().redirect("/devices"s);
		}
	}
}


} } // namespace MyDevices::Gateway
