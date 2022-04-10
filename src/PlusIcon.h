//
// PlusIcon.h
//
// This file has been generated from PlusIcon.cpsp on 2022-04-10 09:31:12.
//


#ifndef PlusIcon_INCLUDED
#define PlusIcon_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class PlusIcon: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // PlusIcon_INCLUDED
