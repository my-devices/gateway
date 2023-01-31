//
// PlusIconX2.h
//
// This file has been generated from PlusIconX2.cpsp on 2023-01-31 11:25:54.
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
