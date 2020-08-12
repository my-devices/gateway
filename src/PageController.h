//
// PageController.h
//
// Copyright (c) 2017-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_PageController_INCLUDED
#define MyGateway_PageController_INCLUDED


#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
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

	void message(const std::string& text, const std::string& messageClass = MSG_CLASS_ERROR);

	const std::string& message() const
	{
		return _message;
	}

	const std::string& messageClass() const
	{
		return _messageClass;
	}

	bool mustRedirect() const
	{
		return _request.response().getStatus() == Poco::Net::HTTPResponse::HTTP_FOUND;
	}

	const std::string& username() const
	{
		return _username;
	}

	const std::string& csrfToken() const
	{
		return _csrfToken;
	}

	const Poco::Net::HTTPServerRequest& request() const
	{
		return _request;
	}

	const Poco::Net::HTMLForm& form() const
	{
		return _form;
	}

	std::string defaultDomain() const;

	static const std::string MSG_CLASS_ERROR;
	static const std::string MSG_CLASS_WARNING;
	static const std::string MSG_CLASS_INFORMATION;

protected:
	void username(const std::string& name)
	{
		_username = name;
	}

	void csrfToken(const std::string& token)
	{
		_csrfToken = token;
	}

private:
	DeviceManager::Ptr _pDeviceManager;
	const Poco::Net::HTTPServerRequest& _request;
	const Poco::Net::HTMLForm& _form;
	std::string _message;
	std::string _messageClass;
	std::string _username;
	std::string _csrfToken;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_PageController_INCLUDED
