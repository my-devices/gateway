//
// TOTPPage.h
//
// This file has been generated from TOTPPage.cpsp on 2025-11-04 19:08:46.
//


#ifndef TOTPPage_INCLUDED
#define TOTPPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class TOTPPage: public Poco::Net::HTTPRequestHandler
{
public:
	TOTPPage(DeviceManager::Ptr);

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


#endif // TOTPPage_INCLUDED
