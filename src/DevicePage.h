//
// DevicePage.h
//
// This file has been generated from DevicePage.cpsp on 2019-09-03 15:44:15.
//


#ifndef DevicePage_INCLUDED
#define DevicePage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class DevicePage: public Poco::Net::HTTPRequestHandler
{
public:
	DevicePage(DeviceManager::Ptr);

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


#endif // DevicePage_INCLUDED
