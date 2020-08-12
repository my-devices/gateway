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
#include "Poco/Format.h"


namespace MyDevices {
namespace Gateway {


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


std::string Utility::versionString()
{
	return Poco::format("%d.%d.%d",
		static_cast<int>(GATEWAY_VERSION_MAJOR),
		static_cast<int>(GATEWAY_VERSION_MINOR),
		static_cast<int>(GATEWAY_VERSION_PATCH));
}


} } // namespace MyDevices::Gateway
