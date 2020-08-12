//
// WebSession.cpp
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "WebSession.h"
#include "Poco/Timespan.h"
#include "Poco/Exception.h"


namespace MyDevices {
namespace Gateway {


const std::string WebSession::CSRF_TOKEN("#csrfToken");


WebSession::WebSession(const std::string& id, const std::string& csrfToken, Poco::Int64 version, int timeoutSeconds, const Poco::Net::IPAddress& clientAddress):
	_id(id),
	_version(version),
	_timeout(timeoutSeconds, 0),
	_clientAddress(clientAddress)
{
	accessImpl();
	_attrs[CSRF_TOKEN] = csrfToken;
}


WebSession::WebSession(const std::string& id, Poco::Int64 version, int timeoutSeconds, const Poco::Net::IPAddress& clientAddress, Poco::Timestamp created, const Attributes& attrs):
	_id(id),
	_version(version),
	_timeout(timeoutSeconds, 0),
	_created(created),
	_clientAddress(clientAddress),
	_attrs(attrs)
{
	accessImpl();
}


WebSession::~WebSession()
{
}


bool WebSession::has(const std::string& key) const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Attributes::const_iterator it = _attrs.find(key);
	return it != _attrs.end();
}


const Poco::Any& WebSession::get(const std::string& key) const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	Attributes::const_iterator it = _attrs.find(key);
	if (it != _attrs.end())
		return it->second;
	else
		throw Poco::NotFoundException(key);
}


void WebSession::set(const std::string& key, const Poco::Any& value)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	_attrs[key] = value;
}


void WebSession::erase(const std::string& key)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	_attrs.erase(key);
}


void WebSession::clear()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	std::string token = csrfToken();
	clearImpl();
	_attrs[CSRF_TOKEN] = token;
}


void WebSession::clearImpl()
{
	_attrs.clear();
}


void WebSession::access()
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	accessImpl();
}


void WebSession::accessImpl()
{
	_expiration.update();
	_expiration += _timeout.totalMicroseconds();
}


} } // namespace MyDevices::Gateway
