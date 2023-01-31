//
// MinusIconX2.h
//
// This file has been generated from MinusIconX2.cpsp on 2023-01-31 11:25:53.
//


#ifndef MinusIconX2_INCLUDED
#define MinusIconX2_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class MinusIconX2: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // MinusIconX2_INCLUDED
