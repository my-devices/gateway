//
// Utility.cpp
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Utility.h"
#include "Version.h"
#include "Poco/Net/HTTPBasicCredentials.h"
#include "Poco/Util/Application.h"
#include "Poco/PBKDF2Engine.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/Format.h"
#include "Poco/Mutex.h"
#include <set>
#ifdef POCO_OS_FAMILY_UNIX
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#if POCO_OS == POCO_OS_LINUX
#include <shadow.h>
#endif
#endif


namespace MyDevices {
namespace Gateway {


Poco::FastMutex Utility::_authMutex;


std::string Utility::htmlize(const std::string& str)
{
	std::string::const_iterator it(str.begin());
	std::string::const_iterator end(str.end());
	std::string html;
	for (; it != end; ++it)
	{
		switch (*it)
		{
		case '<': html += "&lt;"; break;
		case '>': html += "&gt;"; break;
		case '"': html += "&quot;"; break;
		case '&': html += "&amp;"; break;
		default:  html += *it; break;
		}
	}
	return html;
}


std::string Utility::escape(const std::string& str)
{
	std::string::const_iterator it(str.begin());
	std::string::const_iterator end(str.end());
	std::string escaped;
	for (; it != end; ++it)
	{
		switch (*it)
		{
		case '\'': escaped += "\\'"; break;
		case '\"': escaped += "\\\""; break;
		case '\\': escaped += "\\\\"; break;
		case '\n': escaped += "\\n"; break;
		case '\r': escaped += "\\r"; break;
		case '\t': escaped += "\\t"; break;
		default:  escaped += *it; break;
		}
	}
	return escaped;
}


bool Utility::authenticate(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	try
	{
		if (request.hasCredentials())
		{
			Poco::Net::HTTPBasicCredentials creds(request);
			Poco::Util::Application& app = Poco::Util::Application::instance();
			if (app.config().has("gateway.username"))
			{
				std::string username = app.config().getString("gateway.username");
				std::string password = app.config().getString("gateway.password", "");
				if (creds.getUsername() == username && Utility::hashPassword(creds.getPassword()) == password)
				{
					return true;
				}
			}
			else if (authenticate(creds.getUsername(), creds.getPassword()))
			{
				return true;
			}
		}
	}
	catch (Poco::Exception&)
	{
	}
	response.requireAuthentication("my-devices.net Gateway");
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");
	response.erase("Content-Encoding");
	response.send()
		<< "<html><head><title>Authentication Failed</title></head>"
		<< "<body><h1>Authentication Failed</h1>"
		<< "<p>The given username or password is invalid.</p></body></html>";
	return false;
}


bool Utility::authenticate(const std::string& username, const std::string& password)
{
	Poco::FastMutex::ScopedLock lock(_authMutex);

	std::string storedHash;
#ifdef POCO_OS_FAMILY_UNIX
#if POCO_OS == POCO_OS_LINUX
	struct spwd* pSpwd = getspnam(username.c_str());
	if (pSpwd)
	{
		storedHash = pSpwd->sp_pwdp;
	}
	else
#endif
	{
		setpwent();
		struct passwd* pPwd = getpwent();
		while (pPwd && username != pPwd->pw_name)
		{
			pPwd = getpwent();
		}
		if (pPwd)
		{
			storedHash = pPwd->pw_passwd;
			endpwent();
		}
		else
		{
			endpwent();
			return false;
		}
	}

	std::string salt;
	std::string::const_iterator it = storedHash.begin();
	std::string::const_iterator end = storedHash.end();
	if (it != end) salt += *it++;
	while (it != end && *it != '$') salt += *it++;
	if (it != end) salt += *it++;
	while (it != end && *it != '$') salt += *it++;
	if (it != end) salt += *it++;
	const char* credHash = crypt(password.c_str(), salt.c_str());

	bool authenticated = credHash && storedHash == credHash;
	return authenticated;
#else
	return false;
#endif
}


std::string Utility::hashPassword(const std::string& password)
{
	Poco::PBKDF2Engine<Poco::HMACEngine<Poco::SHA1Engine> > pbkdf2("my-devices.net", 8192, 32);
	pbkdf2.update(password);
	return Poco::DigestEngine::digestToHex(pbkdf2.digest());
}


std::string Utility::versionString()
{
	return Poco::format("%d.%d.%d",
		static_cast<int>(GATEWAY_VERSION_MAJOR),
		static_cast<int>(GATEWAY_VERSION_MINOR),
		static_cast<int>(GATEWAY_VERSION_PATCH));
}


} } // namespace MyDevices::Gateway
