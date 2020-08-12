//
// LoginPageController.cpp
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "LoginPageController.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPSessionFactory.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/OAuth20Credentials.h"
#include "Poco/Util/JSONConfiguration.h"
#include "Poco/NullStream.h"
#include "Poco/StreamCopier.h"


namespace MyDevices {
namespace Gateway {


LoginPageController::LoginPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form),
	_logger(Poco::Logger::get("LoginPageController"))
{
	std::string action = form.get("action", "");
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway", request);
	if (action == "logout")
	{
		if (pSession) pDeviceManager->webSessionManager().remove(pSession);
		return;
	}
	else if (pSession && pSession->has("username"))
	{
		_logger.debug("Valid session found, redirecting.");
		request.response().redirect("/devices");
		return;
	}
	else if (action == "login")
	{
		_logger.debug("Processing login form...");
		processForm();
	}
}


LoginPageController::~LoginPageController()
{
}


void LoginPageController::processForm()
{
	std::string username = _form.get("username", "");
	std::string password = _form.get("password", "");
	try
	{
		Poco::URI reflectorURI = Poco::URI(_pDeviceManager->config()->getString("webtunnel.reflectorURI"));
		Poco::SharedPtr<Poco::Net::HTTPClientSession> pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
		Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/my-devices/api/token", Poco::Net::HTTPMessage::HTTP_1_1);
		Poco::Net::HTMLForm params;
		params.set("username", username);
		params.set("password", password);
		params.set("application", "RemoteManagerGateway");
		params.prepareSubmit(request);
		_logger.debug("Validating credentials with Remote Manager server at %s.", reflectorURI.toString());
		std::ostream& requestStream = pHTTPClientSession->sendRequest(request);
		params.write(requestStream);
		Poco::Net::HTTPResponse response;
		std::istream& responseStream = pHTTPClientSession->receiveResponse(response);
		if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
		{
			_logger.information("Login successful for user %s.", username);
			Poco::Util::JSONConfiguration json(responseStream);
			std::string token = json.getString("token");

			std::string domain = _pDeviceManager->config()->getString("webtunnel.domain");
			if (verifyDomainAccess(reflectorURI, token, domain))
			{
				int sessionTimeout = _pDeviceManager->config()->getInt("gateway.sessionTimeout", 3600);
				WebSession::Ptr pWebSession = _pDeviceManager->webSessionManager().create("rmgateway", _request, sessionTimeout);
				pWebSession->set("username", username);
				pWebSession->set("token", token);
				_request.response().redirect("/devices");
			}
			else
			{
				_logger.warning("User %s does not have access to gateway domain %s.", username, domain);
				_message = Poco::format("User account %s does not have access to the gateway's domain %s.", username, domain);
			}
		}
		else
		{
			_logger.warning("Login failed for user %s.", username);
			_message = "The given username is not known, the password is wrong or the account has been disabled.";
		}
		Poco::NullOutputStream nullStream;
		Poco::StreamCopier::copyStream(responseStream, nullStream);
	}
	catch (Poco::Exception& exc)
	{
		_message = exc.displayText();
	}
}


bool LoginPageController::verifyDomainAccess(const Poco::URI& reflectorURI, const std::string& token, const std::string& domain)
{
	Poco::SharedPtr<Poco::Net::HTTPClientSession> pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
	std::string encodedDomain;
	Poco::URI::encode(domain, "?#", encodedDomain);
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, Poco::format("/my-devices/api/domains/%s", encodedDomain), Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::Net::OAuth20Credentials creds(token);
	creds.authenticate(request);
	_logger.debug("Validating domain access with Remote Manager server at %s.", reflectorURI.toString());
	std::ostream& requestStream = pHTTPClientSession->sendRequest(request);
	Poco::Net::HTTPResponse response;
	std::istream& responseStream = pHTTPClientSession->receiveResponse(response);
	Poco::NullOutputStream nullStream;
	Poco::StreamCopier::copyStream(responseStream, nullStream);
	return response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK;
}


} } // namespace MyDevices::Gateway
