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
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway", request);
	if (!pSession || !pSession->has("username"))
	{
		request.response().redirect("/");
		return;
	}
	_username = pSession->getValue<std::string>("username");
	_csrfToken = pSession->csrfToken();
	try
	{
		if (_form.has("action"))
		{
			processForm();
		}
		else
		{
			Poco::UUIDGenerator uuidGen;
			_deviceId = uuidGen.createRandom().toString();
			_name = "Unnamed Device";
			_domain = defaultDomain();
		}
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


CreateDevicePageController::~CreateDevicePageController()
{
}


void CreateDevicePageController::processForm()
{
	std::string action = _form.get("action", "");
	std::string csrfToken = _form.get("csrfToken", "");

	if (csrfToken == _csrfToken)
	{
		if (action == "create")
		{
			_deviceId = _form.get("deviceId");
			_name = _form.get("deviceName");
			_domain = _form.get("domain");

			if (!isValidId(_deviceId))
			{
				_message = "Invalid device ID: " + _deviceId;
				return;
			}

			if (!isValidId(_domain))
			{
				_message = "Invalid domain ID: " + _domain;
				return;
			}

			Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = _pDeviceManager->createDevice(_deviceId, _domain, _name);

			_request.response().redirect("/device/" + _deviceId);
		}
		else if (action == "cancel")
		{
			_request.response().redirect("/devices");
		}
	}
}


} } // namespace MyDevices::Gateway
