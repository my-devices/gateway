//
// Stylesheet.h
//
// This file has been generated from Stylesheet.cpsp on 2018-09-21 07:59:30.
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