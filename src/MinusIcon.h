//
// MinusIcon.h
//
// This file has been generated from MinusIcon.cpsp on 2019-09-11 06:54:11.
//


#ifndef MinusIcon_INCLUDED
#define MinusIcon_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class MinusIcon: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // MinusIcon_INCLUDED
