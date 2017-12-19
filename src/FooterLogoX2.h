//
// FooterLogoX2.h
//
// This file has been generated from FooterLogoX2.cpsp.
//


#ifndef FooterLogoX2_INCLUDED
#define FooterLogoX2_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class FooterLogoX2: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // FooterLogoX2_INCLUDED
