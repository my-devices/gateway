//
// ProxySessionPool.h
//
// Copyright (c) 2026, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "ProxySessionPool.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


ProxySessionPool::ProxySessionPool(DeviceManager& deviceManager):
	_deviceManager(deviceManager)
{
}


Poco::SharedPtr<Poco::Net::HTTPClientSession> ProxySessionPool::borrowSession(const std::string& deviceId)
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	auto it = _pools.find(deviceId);
	if (it == _pools.end())
	{
		auto pDeviceProps = _deviceManager.deviceConfiguration(deviceId);
		Poco::UInt16 httpPort = pDeviceProps->getUInt16("webtunnel.httpPort"s, 0);
		bool httpsRequired = pDeviceProps->getBool("webtunnel.https.enable"s, false);

		ObjectPoolPtr pPool = std::make_unique<ObjectPool>()
	}
}


void ProxySessionPool::returnSession(const std::string& deviceId, Poco::SharedPtr<Poco::Net::HTTPClientSession> pSession)
{

}


} } // namespace MyDevices::Gateway
