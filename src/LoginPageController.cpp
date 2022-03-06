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
#include "Poco/Dynamic/Var.h"
#include "Poco/NullStream.h"
#include "Poco/StreamCopier.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


LoginPageController::LoginPageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form):
	PageController(pDeviceManager, request, form),
	_logger(Poco::Logger::get("LoginPageController"s))
{
	const std::string action = form.get("action"s, ""s);
	WebSession::Ptr pSession = pDeviceManager->webSessionManager().find("rmgateway"s, request);
	if (action == "logout")
	{
		if (pSession) pDeviceManager->webSessionManager().remove(pSession);
		return;
	}
	else if (pSession && pSession->has("username"s))
	{
		_logger.debug("Valid session found, redirecting."s);
		request.response().redirect("/devices"s);
		return;
	}
	else if (action == "login"s)
	{
		_logger.debug("Processing login form..."s);
		processForm();
	}
}


LoginPageController::~LoginPageController()
{
}


void LoginPageController::processForm()
{
	const std::string username = form().get("username"s, ""s);
	const std::string password = form().get("password"s, ""s);
	try
	{
		Poco::URI reflectorURI = Poco::URI(deviceManager()->config()->getString("webtunnel.reflectorURI"s));
		Poco::SharedPtr<Poco::Net::HTTPClientSession> pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
		Poco::Net::HTTPRequest apiRequest(Poco::Net::HTTPRequest::HTTP_GET, "/my-devices/api/token"s, Poco::Net::HTTPMessage::HTTP_1_1);
		Poco::Net::HTMLForm params;
		params.set("username"s, username);
		params.set("password"s, password);
		params.set("application"s, "RemoteManagerGateway"s);
		params.prepareSubmit(apiRequest);
		_logger.debug("Validating credentials with macchina.io REMOTE server at %s."s, reflectorURI.toString());
		std::ostream& requestStream = pHTTPClientSession->sendRequest(apiRequest);
		params.write(requestStream);
		Poco::Net::HTTPResponse apiResponse;
		std::istream& responseStream = pHTTPClientSession->receiveResponse(apiResponse);
		if (apiResponse.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
		{
			_logger.information("Login successful for user %s."s, username);
			Poco::Util::JSONConfiguration json(responseStream);
			std::string token = json.getString("token");

			std::string domain = deviceManager()->config()->getString("webtunnel.domain"s, "00000000-0000-0000-0000-000000000000"s);
			if (domain == "00000000-0000-0000-0000-000000000000" || verifyDomainAccess(reflectorURI, token, domain))
			{
				int sessionTimeout = deviceManager()->config()->getInt("gateway.sessionTimeout"s, 3600);
				WebSession::Ptr pWebSession = deviceManager()->webSessionManager().create("rmgateway"s, request(), sessionTimeout);
				pWebSession->set("username", username);
				pWebSession->set("token", token);

				if (domain == "00000000-0000-0000-0000-000000000000")
				{
					const std::string defaultDomain = requestDefaultDomain(reflectorURI, username, token);
					if (!defaultDomain.empty())
					{
						pWebSession->set("domain"s, defaultDomain);
					}
				}

				request().response().redirect("/devices"s);
			}
			else
			{
				_logger.warning("User %s does not have access to gateway domain %s."s, username, domain);
				message(Poco::format("User account %s does not have access to the gateway's domain %s."s, username, domain));
			}
		}
		else
		{
			_logger.warning("Login failed for user %s."s, username);
			message("The given username is not known, the password is wrong or the account has been disabled."s);
		}
		Poco::NullOutputStream nullStream;
		Poco::StreamCopier::copyStream(responseStream, nullStream);
	}
	catch (Poco::Exception& exc)
	{
		message(exc.displayText());
	}
}


bool LoginPageController::verifyDomainAccess(const Poco::URI& reflectorURI, const std::string& token, const std::string& domain)
{
	Poco::SharedPtr<Poco::Net::HTTPClientSession> pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
	std::string encodedDomain;
	Poco::URI::encode(domain, "?#"s, encodedDomain);
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, Poco::format("/my-devices/api/domains/%s"s, encodedDomain), Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::Net::OAuth20Credentials creds(token);
	creds.authenticate(request);
	_logger.debug("Validating domain access with macchina.io REMOTE server at %s."s, reflectorURI.toString());
	pHTTPClientSession->sendRequest(request);
	Poco::Net::HTTPResponse response;
	std::istream& responseStream = pHTTPClientSession->receiveResponse(response);
	Poco::NullOutputStream nullStream;
	Poco::StreamCopier::copyStream(responseStream, nullStream);
	return response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK;
}


std::string LoginPageController::requestDefaultDomain(const Poco::URI& reflectorURI, const std::string& username, const std::string& token)
{
	std::string domain;
	Poco::SharedPtr<Poco::Net::HTTPClientSession> pHTTPClientSession = Poco::Net::HTTPSessionFactory::defaultFactory().createClientSession(reflectorURI);
	std::string encodedUsername;
	Poco::URI::encode(username, "?#"s, encodedUsername);
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, Poco::format("/my-devices/api/users/%s/attributes/domain"s, encodedUsername), Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::Net::OAuth20Credentials creds(token);
	creds.authenticate(request);
	_logger.debug("Requesting default domain for user %s on server at %s."s, username, reflectorURI.toString());
	pHTTPClientSession->sendRequest(request);
	Poco::Net::HTTPResponse response;
	std::istream& responseStream = pHTTPClientSession->receiveResponse(response);
	if (response.getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
	{
		std::string json;
		Poco::StreamCopier::copyToString(responseStream, json);
		Poco::Dynamic::Var var = Poco::Dynamic::Var::parse(json);
		domain = var.convert<std::string>();
		_logger.debug("Default domain for user %s is %s."s, username, domain);
	}
	else
	{
		Poco::NullOutputStream nullStream;
		Poco::StreamCopier::copyStream(responseStream, nullStream);
	}
	return domain;
}


} } // namespace MyDevices::Gateway
