//
// WebSessionManager.h
//
// Copyright (c) 2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_WebSessionManager_INCLUDED
#define MyGateway_WebSessionManager_INCLUDED


#include "WebSession.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPCookie.h"
#include "Poco/UniqueExpireCache.h"
#include "Poco/Mutex.h"


namespace MyDevices {
namespace Gateway {


class WebSessionManager
	/// A WebSessionManager manages HTTP sessions using cookies.
	///
	/// Note that the application name (appName) specified in get() and create()
	/// can contain a domain name, separated by '@'. If a domain name is given,
	/// it is used to set the domain for the session cookie. Similarly, a path
	/// can be given, beginning with a slash.
	///
	/// For example, if the appName is sample@.appinf.com, then the browser
	/// will send the session cookie to all hosts with names in the appinf.com
	/// domain. If a domain is not given, the session cookie will only be available
	/// to the host that has originally set it.
{
public:
	enum CookiePersistence
	{
		COOKIE_TRANSIENT  = 1, /// Session cookies are transient (go away when browser is closed).
		COOKIE_PERSISTENT = 2  /// Session cookies are persistent (kept in browser until they expire).
	};

	WebSessionManager();
		/// Creates the SessionManager.

	~WebSessionManager();
		/// Destroys the SessionManager.

	void setDefaultDomain(const std::string& domain);
		/// Sets the default domain for the session cookie.

	const std::string& getDefaultDomain() const;
		/// Returns the default domain for the session cookie.

	void setDefaultPath(const std::string& path);
		/// Sets the default path for the session cookie.

	const std::string& getDefaultPath() const;
		/// Returns the default path for the session cookie.

	void setCookiePersistence(CookiePersistence persistence);
		/// Sets the cookie persistence, which controls whether
		/// session and CSRF cookies are transient (go away when the
		/// browser is closed) or persistent (default).

	CookiePersistence getCookiePersistence() const;
		/// Returns the cookie persistence for the session
		/// and CSRF cookies.

	void setCookieSecure(bool secure);
		/// Sets the secure attribute of the session cookie.
		///
		/// If set to true, the browser will only send the
		/// cookie over HTTPS connections.

	bool isCookieSecure() const;
		/// Returns true if the session cookie has the secure
		/// attribute set, otherwise false.

	void setVerifyAddress(bool verify);
		/// Enable or disable verification of client address
		/// against the address stored in the session.

	bool isAddressVerified() const;
		/// Returns true if the client IP address is verified
		/// against the address stored in the session.

	void setCSRFCookie(const std::string& name);
		/// Sets the name of the CSRF/XSRF cookie.
		///
		/// If set, the CSRF token of the session will be stored in
		/// the cookie with the given name. This cookie is accessible
		/// from JavaScript and can be used to authenticate scripted
		/// HTTP requests (together with the session cookie).

	const std::string& getCSRFCookie() const;
		/// Returns the name of the CSRF cookie, if set, otherwise
		/// an empty string.

	WebSession::Ptr findById(const std::string& sessionId);
		/// Returns the session with the given ID, or null if it does not exist.

	WebSession::Ptr find(const std::string& appName, const Poco::Net::HTTPServerRequest& request);
		/// Return a WebSession object for the application specified by appName and
		/// the given HTTP request if one exists, or a null pointer otherwise.

	WebSession::Ptr get(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds);
		/// Return a WebSession object for the application specified by appName and
		/// the given HTTP request. If no session is associated with the given request,
		/// a new session is created with the given expiration time.

	WebSession::Ptr create(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds);
		/// Creates a new WebSession object with the given expiration time for the application
		/// given by appName and the given HTTP request, and associates the WebSession with
		/// the browser's user session.

	void remove(WebSession::Ptr ptr);
		/// Removes a session from the manager, if it exists. Does nothing if the
		/// session is not known to the session manager.

protected:
	WebSession::Ptr findImpl(const std::string& appName, const Poco::Net::HTTPServerRequest& request);
	WebSession::Ptr findByIdImpl(const std::string& sessionId);
	WebSession::Ptr createImpl(const std::string& appName, const Poco::Net::HTTPServerRequest& request, int expireSeconds);
	void removeImpl(WebSession::Ptr pSession);
	std::string getId(const std::string& appName, const Poco::Net::HTTPServerRequest& request);
	void addSessionCookie(const std::string& appName, const Poco::Net::HTTPServerRequest& request, WebSession::Ptr ptrSes);
	void addCSRFCookie(const std::string& appName, const Poco::Net::HTTPServerRequest& request, WebSession::Ptr ptrSes);
	std::string createToken(const Poco::Net::HTTPServerRequest& request);
	std::string cookieName(const std::string& appName);
	std::string cookieDomain(const std::string& appName);
	std::string cookiePath(const std::string& appName);

private:
	static const std::string COOKIE_NAME;

	mutable Poco::FastMutex _mutex;
	Poco::UInt32 _serial;
	Poco::UniqueExpireCache<std::string, WebSession> _cache;
	std::string _defaultDomain;
	std::string _defaultPath;
	std::string _csrfCookie;
	CookiePersistence _cookiePersistence;
	bool _cookieSecure;
	bool _verifyAddress;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_WebSessionManager_INCLUDED
