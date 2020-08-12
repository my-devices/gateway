//
// HeaderLogo.h
//
// This file has been generated from HeaderLogo.cpsp on 2020-08-12 06:42:46.
//


#ifndef HeaderLogo_INCLUDED
#define HeaderLogo_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class HeaderLogo: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // HeaderLogo_INCLUDED
