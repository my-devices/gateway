//
// Gradient.h
//
// This file has been generated from Gradient.cpsp on 2019-09-11 06:54:12.
//


#ifndef Gradient_INCLUDED
#define Gradient_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class Gradient: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // Gradient_INCLUDED
