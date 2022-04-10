//
// PlusIconX2.h
//
// This file has been generated from PlusIconX2.cpsp on 2022-04-10 09:31:12.
//


#ifndef PlusIconX2_INCLUDED
#define PlusIconX2_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class PlusIconX2: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // PlusIconX2_INCLUDED
