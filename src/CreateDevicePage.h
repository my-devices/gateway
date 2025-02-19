//
// CreateDevicePage.h
//
// This file has been generated from CreateDevicePage.cpsp on 2025-02-19 13:33:15.
//


#ifndef CreateDevicePage_INCLUDED
#define CreateDevicePage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class CreateDevicePage: public Poco::Net::HTTPRequestHandler
{
public:
	CreateDevicePage(DeviceManager::Ptr);

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


#endif // CreateDevicePage_INCLUDED
