//
// ProxyRequestHandler.cpp
//
// Copyright (c) 2026, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "ProxyRequestHandler.h"
#include "Poco/StreamCopier.h"
#include "Poco/NullStream.h"
#include "Poco/String.h"
#include "ProxySessionPool.h"
#include <sstream>


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


class SessionHolder
{
public:
	SessionHolder(ProxySessionPool& pool, const std::string& deviceId):
		_pool(pool),
		_deviceId(deviceId),
		_pSession(pool.borrowSession(deviceId))
	{
	}

	~SessionHolder()
	{
		try
		{
			_pool.returnSession(_pSession);
		}
		catch (...)
		{
		}
	}

	Poco::Net::HTTPClientSession& session()
	{
		return *_pSession->session();
	}

private:
	ProxySessionPool& _pool;
	std::string _deviceId;
	ProxySession::Ptr _pSession;
};


ProxyRequestHandler::ProxyRequestHandler(DeviceManager::Ptr pDeviceManager, ProxySessionPool& sessionPool):
	_pDeviceManager(pDeviceManager),
	_sessionPool(sessionPool),
	_logger(Poco::Logger::get("ProxyRequestHandler"s))
{
}


void ProxyRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	if (_logger.trace())
	{
		std::ostringstream header;
		request.write(header);
		_logger.debug(header.str());
	}
	else if (_logger.debug())
	{
		_logger.debug("%s %s"s, request.getMethod(), request.getURI());
	}

	if (isWebSocketRequest(request) || isEventStreamRequest(request))
	{
		Poco::NullOutputStream null;
		Poco::StreamCopier::copyStream(request.stream(), null);
		sendErrorResponse(response, Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED, "The proxy server does not support WebSocket or Event Stream requests."s);
		return;
	}

	request.erase(Poco::Net::HTTPMessage::CONNECTION);

	std::string deviceId;
	try
	{
		deviceId = extractDeviceId(request.getHost());

		SessionHolder holder(_sessionPool, deviceId);
		auto& session = holder.session();

		int retries = 2;
		while (retries > 0)
		{
			if (_logger.debug())
			{
				_logger.debug("Sending request to target %s:%hu..."s, session.getHost(), session.getPort());
			}
			std::ostream* pRequestStream = nullptr;
			try
			{
				pRequestStream = &session.sendRequest(request);
				Poco::StreamCopier::copyStream(request.stream(), *pRequestStream);

				std::istream& responseStream = session.receiveResponse(response);
				Poco::StreamCopier::copyStream(responseStream, response.send());

				retries = 0;
			}
			catch (const Poco::Exception& exc)
			{
				if (!response.sent())
				{
					_logger.debug("Error: %s - retrying..."s, exc.displayText());
					session.reset();
					retries--;
				}
				else throw;
			}
		}
	}
	catch (Poco::TimeoutException& exc)
	{
		_logger.error("Timeout forwarding request (%s %s) to target %s."s, request.getMethod(), request.getURI(), deviceId);
		if (!response.sent())
		{
			sendErrorResponse(response, Poco::Net::HTTPResponse::HTTP_GATEWAY_TIMEOUT, "The web server on the device is taking too long to handle the request."s);
		}
	}
	catch (Poco::Exception& exc)
	{
		_logger.error("Error forwarding request (%s %s) to target %s: %s"s, request.getMethod(), request.getURI(), deviceId, exc.displayText());
		if (!response.sent())
		{
			sendErrorResponse(response, Poco::Net::HTTPResponse::HTTP_BAD_GATEWAY, "The web server on the device is not responding properly."s);
		}
	}
}


std::string ProxyRequestHandler::extractDeviceId(const std::string& host)
{
	auto p = host.find('.');
	if (p > 0 && p != std::string::npos)
	{
		return std::string(host, 0, p);
	}
	else throw Poco::InvalidArgumentException("Cannot extract device ID from Host header"s, host);
}


void ProxyRequestHandler::sendErrorResponse(Poco::Net::HTTPServerResponse& response, Poco::Net::HTTPResponse::HTTPStatus status, const std::string& message)
{
	response.setStatusAndReason(status);
	response.setChunkedTransferEncoding(true);
	response.send()
		<< "<html>"
		<< "<head><title>Error " << static_cast<int>(status) << "</title></head>"
		<< "<body>"
		<< "<h2>Error " << static_cast<int>(status) << " " << Poco::Net::HTTPResponse::getReasonForStatus(status) << "</h2>"
		<< "<p>" << Poco::Net::htmlize(message) << "</p>"
		<< "</body>"
		<< "</html>";
}


bool ProxyRequestHandler::isWebSocketRequest(const Poco::Net::HTTPServerRequest& request)
{
	return Poco::icompare(request.get("Connection"s, ""s), "upgrade"s) == 0 && Poco::icompare(request.get("Upgrade"s, ""s), "websocket"s) == 0;
}


bool ProxyRequestHandler::isEventStreamRequest(const Poco::Net::HTTPServerRequest& request)
{
	return request.get("Accept"s, ""s) == "text/event-stream" || (request.getKeepAlive() && request.has("Last-Event-ID"s));
}


} } // namespace MyDevices::Gateway
