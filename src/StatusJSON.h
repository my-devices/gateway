//
// StatusJSON.h
//
// This file has been generated from StatusJSON.cpsp on 2020-08-12 06:42:46.
//


#ifndef StatusJSON_INCLUDED
#define StatusJSON_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class StatusJSON: public Poco::Net::HTTPRequestHandler
{
public:
	StatusJSON(DeviceManager::Ptr);

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

protected:
	DeviceManager::Ptr context() const
	{
		return _context;
	}

private:
	DeviceManager::Ptr _context;
};


} } // namespace MyDevices::Gateway


#endif // StatusJSON_INCLUDED
