//
// Stylesheet.h
//
// This file has been generated from Stylesheet.cpsp.
//


#ifndef Stylesheet_INCLUDED
#define Stylesheet_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class Stylesheet: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // Stylesheet_INCLUDED
