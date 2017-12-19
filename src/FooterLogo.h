//
// FooterLogo.h
//
// This file has been generated from FooterLogo.cpsp.
//


#ifndef FooterLogo_INCLUDED
#define FooterLogo_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class FooterLogo: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // FooterLogo_INCLUDED
