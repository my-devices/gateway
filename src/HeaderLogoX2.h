//
// HeaderLogoX2.h
//
// This file has been generated from HeaderLogoX2.cpsp on 2021-11-27 19:58:16.
//


#ifndef HeaderLogoX2_INCLUDED
#define HeaderLogoX2_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class HeaderLogoX2: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // HeaderLogoX2_INCLUDED
