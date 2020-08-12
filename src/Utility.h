//
// Utility.h
//
// Copyright (c) 2015-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_Utility_INCLUDED
#define MyGateway_Utility_INCLUDED


#include "Poco/Poco.h"


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

	static std::string versionString();
		/// Returns the software version number as string.
};


// Shortcut, since it's needed so often.
typedef Utility U;


} } // namespace MyDevices::Gateway


#endif // MyGateway_Utility_INCLUDED
