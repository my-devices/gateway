//
// Utility.h
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_Utility_INCLUDED
#define MyGateway_Utility_INCLUDED


#include "Poco/Poco.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Mutex.h"


namespace MyDevices {
namespace Gateway {


class Utility
	/// This class contains various utility functions used by server pages.
{
public:
	static std::string htmlize(const std::string& str);
		/// Creates a copy of str with reserved HTML characters propery escaped.

	static std::string escape(const std::string& str);
		/// Creates a copy of str with reserved JavaScript characters propery escaped.

	static bool authenticate(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
		/// Returns true if the given HTTP request is authenticated with a valid
		/// username and password, using HTTP Basic authentication.

	static bool authenticate(const std::string& username, const std::string& password);
		/// Returns true if the given username and password are valid, otherwise
		/// false.
		///
		/// Username and password are validated using the system's user database
		/// (/etc/passwd, etc.).

	static std::string hashPassword(const std::string& password);
		/// Creates a hash for the password.

	static std::string versionString();
		/// Returns the software version number as string.

private:
	static Poco::FastMutex _authMutex;
};


// Shortcut, since it's needed so often.
typedef Utility U;


} } // namespace MyDevices::Gateway


#endif // MyGateway_Utility_INCLUDED
