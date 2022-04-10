//
// LoginPage.h
//
// This file has been generated from LoginPage.cpsp on 2022-04-10 09:31:12.
//


#ifndef LoginPage_INCLUDED
#define LoginPage_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


#include "DeviceManager.h"


namespace MyDevices {
namespace Gateway {


class LoginPage: public Poco::Net::HTTPRequestHandler
{
public:
	LoginPage(DeviceManager::Ptr);

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


#endif // LoginPage_INCLUDED
