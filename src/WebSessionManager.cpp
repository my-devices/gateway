//
// WebSessionManager.cp
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "WebSessionManager.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/NameValueCollection.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberParser.h"
#include "Poco/NumberFormatter.h"
#include "Poco/RandomStream.h"
#include "Poco/SHA1Engine.h"


using Poco::Net::NameValueCollection;
using Poco::FastMutex;
using Poco::NumberFormatter;


namespace MyDevices {
namespace Gateway {


const std::string WebSessionManager::COOKIE_NAME("websession");


WebSessionManager::WebSessionManager():
	_serial(0),
	_cookiePersistence(COOKIE_PERSISTENT),
	_cookieSecure(false),
	_verifyAddress(true)
{
}


WebSessionManager::~WebSessionManager()
{
}


void WebSessionManager::setDefaultDomain(const std::string& domain)
{
	_defaultDomain = domain;
}


const std::string& WebSessionManager::getDefaultDomain() const
{
	return _defaultDomain;
}


void WebSessionManager::setDefaultPath(const std::string& path)
{
	_defaultPath = path;
}


const std::string& WebSessionManager::getDefaultPath() const
{
	return _defaultPath;
}


void WebSessionManager::setCookiePersistence(WebSessionManager::CookiePersistence persistence)
{
	_cookiePersistence = persistence;
}


WebSessionManager::CookiePersistence WebSessionManager::getCookiePersistence() const
{
	return _cookiePersistence;
}


void WebSessionManager::setCookieSecure(bool secure)
{
	_cookieSecure = secure;
}


bool WebSessionManager::isCookieSecure() const
{
	return _cookieSecure;
}


void WebSessionManager::setVerifyAddress(bool verify)
{
	_verifyAddress = verify;
}


bool WebSessionManager::isAddressVerified() const
{
	return _verifyAddress;
}


void WebSessionManager::setCSRFCookie(const std::string& name)
{
	_csrfCookie = name;
}


const std::string& WebSessionManager::getCSRFCookie() const
{
	return _csrfCookie;
}


WebSession::Ptr WebSessionManager::findById(const std::string& sessionId)
{
	FastMutex::ScopedLock lock(_mutex);

	return findByIdImpl(sessionId);
}


WebSession::Ptr WebSessionManager::find(const std::string& appName, const Poco::Net::HTTPServerRequest& request)
{
	FastMutex::ScopedLock lock(_mutex);

	return findImpl(appName, request);
}


WebSession::Ptr WebSessionManager::get(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds)
{
	FastMutex::ScopedLock lock(_mutex);

	WebSession::Ptr pSession = findImpl(appName, request);
	if (!pSession)
	{
		pSession = createImpl(appName, request, expireSeconds);
	}
	return pSession;
}


WebSession::Ptr WebSessionManager::create(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds)
{
	FastMutex::ScopedLock lock(_mutex);

	return createImpl(appName, request, expireSeconds);
}


void WebSessionManager::remove(WebSession::Ptr pSession)
{
	FastMutex::ScopedLock lock(_mutex);

	removeImpl(pSession);
}


WebSession::Ptr WebSessionManager::findImpl(const std::string& appName, const Poco::Net::HTTPServerRequest& request)
{
	WebSession::Ptr pSession;
	std::string sessionId(getId(appName, request));
	if (!sessionId.empty())
	{
		pSession = findByIdImpl(sessionId);
	}
	if (pSession)
	{
		if (!_verifyAddress || pSession->clientAddress() == request.clientAddress().host())
		{
			pSession->access();
			_cache.add(pSession->id(), pSession);
			addSessionCookie(appName, request, pSession);
			addCSRFCookie(appName, request, pSession);
		}
		else
		{
			// possible attack: same session ID from different host - invalidate session
			removeImpl(pSession);
			return 0;
		}
	}
	return pSession;
}


WebSession::Ptr WebSessionManager::findByIdImpl(const std::string& sessionId)
{
	return _cache.get(sessionId);
}


WebSession::Ptr WebSessionManager::createImpl(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds)
{
	WebSession::Ptr pSession(new WebSession(createToken(request), createToken(request), 1, expireSeconds, request.clientAddress().host()));
	_cache.add(pSession->id(), pSession);
	addSessionCookie(appName, request, pSession);
	addCSRFCookie(appName, request, pSession);
	return pSession;
}


void WebSessionManager::removeImpl(WebSession::Ptr pSession)
{
	_cache.remove(pSession->id());
}


std::string WebSessionManager::getId(const std::string& appName, const Poco::Net::HTTPServerRequest& request)
{
	std::string id;
	std::string name(cookieName(appName));
	NameValueCollection cookies;
	request.getCookies(cookies);
	NameValueCollection::ConstIterator it = cookies.find(name);
	if (it != cookies.end())
	{
		id = it->second;
	}
	return id;
}


void WebSessionManager::addSessionCookie(const std::string& appName, const Poco::Net::HTTPServerRequest& request, WebSession::Ptr pSession)
{
	Poco::Net::HTTPCookie cookie(cookieName(appName), pSession->id());
	if (_cookiePersistence == COOKIE_PERSISTENT)
	{
		cookie.setMaxAge(pSession->timeout());
	}
	cookie.setPath(cookiePath(appName));
	cookie.setDomain(cookieDomain(appName));
	cookie.setHttpOnly();
	cookie.setSecure(_cookieSecure);
	request.response().addCookie(cookie);
}


void WebSessionManager::addCSRFCookie(const std::string& appName, const Poco::Net::HTTPServerRequest& request, WebSession::Ptr pSession)
{
	if (!_csrfCookie.empty())
	{
		Poco::Net::HTTPCookie csrfCookie(_csrfCookie, pSession->csrfToken());
		if (_cookiePersistence == COOKIE_PERSISTENT)
		{
			csrfCookie.setMaxAge(pSession->timeout());
		}
		csrfCookie.setPath(cookiePath(appName));
		csrfCookie.setSecure(_cookieSecure);
		request.response().addCookie(csrfCookie);
	}
}


std::string WebSessionManager::createToken(const Poco::Net::HTTPServerRequest& request)
{
	++_serial;

	Poco::SHA1Engine sha1;
	sha1.update(&_serial, sizeof(_serial));
	Poco::Timestamp::TimeVal tv = Poco::Timestamp().epochMicroseconds();
	sha1.update(&tv, sizeof(tv));
	Poco::RandomInputStream ris;
	for (int i = 0; i < 32; i++)
	{
		char c = ris.get();
		sha1.update(c);
	}
	sha1.update(request.clientAddress().toString());

	std::string result = Poco::DigestEngine::digestToHex(sha1.digest());
	return result;
}


std::string WebSessionManager::cookieName(const std::string& appName)
{
	std::string cookieName(COOKIE_NAME);
	if (!appName.empty())
	{
		std::string::size_type pos = appName.find('@');
		if (pos == std::string::npos) pos = appName.find('/');
		if (pos == std::string::npos) pos = appName.size();
		cookieName.append(".");
		cookieName.append(appName, 0, pos);
	}
	return cookieName;
}


std::string WebSessionManager::cookieDomain(const std::string& appName)
{
	std::string result;
	std::string::size_type pos = appName.find('@');
	if (pos != std::string::npos)
	{
		pos++;
		while (pos < appName.size() && appName[pos] != '/') result += appName[pos++];
	}
	return result.empty() ? _defaultDomain : result;
}


std::string WebSessionManager::cookiePath(const std::string& appName)
{
	std::string result("/");
	std::string::size_type pos = appName.find('/');
	if (pos != std::string::npos)
	{
		result.assign(appName, pos, appName.size() - pos);
	}
	return result.empty() ? _defaultPath : result;
}


} } // namespace MyDevices::Gateway
