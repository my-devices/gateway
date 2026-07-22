//
// ProxyRequestHandler.h
//
// Copyright (c) 2026, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_ProxyRequestHandler_INCLUDED
#define MyGateway_ProxyRequestHandler_INCLUDED


#include "Poco/Net/HTTPRequestHandler.h"


namespace MyDevices {
namespace Gateway {


class ProxyRequestHandler: public Poco::Net::HTTPRequestHandler
{
public:
	ProxyRequestHandler();

private:
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_ProxyRequestHandler_INCLUDED
