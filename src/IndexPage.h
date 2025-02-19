//
// IndexPage.h
//
// This file has been generated from IndexPage.cpsp on 2025-02-19 13:29:53.
//


#ifndef IndexPage_INCLUDED
#define IndexPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class IndexPage: public Poco::Net::HTTPRequestHandler
{
public:
	IndexPage(DeviceManager::Ptr);

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


#endif // IndexPage_INCLUDED
