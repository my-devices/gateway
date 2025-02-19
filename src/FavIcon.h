//
// FavIcon.h
//
// This file has been generated from FavIcon.cpsp on 2025-02-19 13:29:52.
//


#ifndef FavIcon_INCLUDED
#define FavIcon_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class FavIcon: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // FavIcon_INCLUDED
