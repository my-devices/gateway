//
// MinusIcon.h
//
// This file has been generated from MinusIcon.cpsp on 2023-01-31 11:25:54.
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
