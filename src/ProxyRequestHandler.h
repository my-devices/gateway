//
// ProxyRequestHandler.h
//
// Copyright (c) 2026, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_ProxyRequestHandler_INCLUDED
#define MyGateway_ProxyRequestHandler_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Logger.h"
#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class ProxySessionPool;


class ProxyRequestHandler: public Poco::Net::HTTPRequestHandler
{
public:
	ProxyRequestHandler(DeviceManager::Ptr pDeviceManager, ProxySessionPool& sessionPool);

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

protected:
	static std::string extractDeviceId(const std::string& host);
	void sendErrorResponse(Poco::Net::HTTPServerResponse& response, Poco::Net::HTTPResponse::HTTPStatus status, const std::string& message);
	static bool isWebSocketRequest(const Poco::Net::HTTPServerRequest& request);
	static bool isEventStreamRequest(const Poco::Net::HTTPServerRequest& request);

private:
	DeviceManager::Ptr _pDeviceManager;
	ProxySessionPool& _sessionPool;
	Poco::Logger& _logger;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_ProxyRequestHandler_INCLUDED
