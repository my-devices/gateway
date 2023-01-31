//
// AjaxCore.h
//
// This file has been generated from AjaxCore.cpsp on 2023-01-31 11:25:53.
//


#ifndef AjaxCore_INCLUDED
#define AjaxCore_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class AjaxCore: public Poco::Net::HTTPRequestHandler
{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


} } // namespace MyDevices::Gateway


#endif // AjaxCore_INCLUDED
