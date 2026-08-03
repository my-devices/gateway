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


//
// ProxySession
//
ProxySession::ProxySession(DeviceManager& deviceManager, const std::string& deviceId):
	_deviceManager(deviceManager),
	_deviceId(deviceId)
{
	init();
}


#if defined(WEBTUNNEL_ENABLE_TLS)
ProxySession::ProxySession(DeviceManager& deviceManager, Poco::Net::Context::Ptr pContext, const std::string& deviceId):
	_deviceManager(deviceManager),
	_pContext(pContext),
	_deviceId(deviceId)
{
	init();
}
#endif


Poco::SharedPtr<Poco::Net::HTTPClientSession> ProxySession::session()
{
	auto pDeviceProps = _deviceManager.deviceConfiguration(_deviceId);
	const std::string host = pDeviceProps->getString("webtunnel.host"s);
	const Poco::UInt16 port = pDeviceProps->getUInt16("webtunnel.httpPort"s, 0);
	const bool secure = pDeviceProps->getBool("webtunnel.https.enable"s, false);

	if (_pSession)
	{
		if (_pSession->getHost() == host && _pSession->getPort() == port && _pSession->secure() == secure)
		{
			if (_lastUsed.elapsed() < _keepAliveTimeout.totalMicroseconds())
			{
				_lastUsed.update();
				return _pSession;
			}
		}
	}
	_pSession = createSession(host, port, secure);
	_lastUsed.update();
	return _pSession;
}


Poco::SharedPtr<Poco::Net::HTTPClientSession> ProxySession::createSession(const std::string& host, Poco::UInt16 port, bool secure)
{
	Poco::SharedPtr<Poco::Net::HTTPClientSession> pSession;

#if defined(WEBTUNNEL_ENABLE_TLS)
	if (secure)
	{
		pSession = new Poco::Net::HTTPSClientSession(host, port, _pContext);
	}
	else
#endif
	{
		pSession = new Poco::Net::HTTPClientSession(host, port);
	}
	pSession->setKeepAlive(true);
	pSession->setKeepAliveTimeout(_keepAliveTimeout);
	pSession->setTimeout(_requestTimeout);
	return pSession;
}


void ProxySession::init()
{
	auto pConfig = _deviceManager.config();
	_requestTimeout = Poco::Timespan(pConfig->getUInt32("gateway.httpProxy.requestTimeout"s, 60), 0);
	_keepAliveTimeout = Poco::Timespan(pConfig->getUInt32("gateway.httpProxy.keepAliveTimeout"s, 60), 0);
}


//
// ProxySessionPool
//
ProxySessionPool::ProxySessionPool(DeviceManager& deviceManager):
	_deviceManager(deviceManager)
#if defined(WEBTUNNEL_ENABLE_TLS)
	,
	_pContext(deviceManager.context())
#endif
{
}


ProxySession::Ptr ProxySessionPool::borrowSession(const std::string& deviceId)
{
	ObjectPoolPtr pPool;

	{
		Poco::FastMutex::ScopedLock lock(_mutex);

		auto it = _pools.find(deviceId);
		if (it == _pools.end())
		{
			std::size_t maxConcurrentSessions = _deviceManager.config()->getUInt32("gateway.httpProxy.maxConcurrentSessions"s, 4);

#if defined(WEBTUNNEL_ENABLE_TLS)
			ProxySessionFactory factory(_deviceManager, _pContext, deviceId);
#else
			ProxySessionFactory factory(_deviceManager, deviceId);
#endif
			pPool = Poco::makeShared<ObjectPool>(factory, 1U, maxConcurrentSessions);
			_pools[deviceId] = pPool;
		}
		else
		{
			pPool = it->second;
		}
	}

	long borrowTimeout = _deviceManager.config()->getInt("gateway.httpProxy.borrowSessionTimeout"s, 30000);
	return pPool->borrowObject(borrowTimeout);
}


void ProxySessionPool::returnSession(ProxySession::Ptr pSession)
{
	ObjectPoolPtr pPool;

	if (pSession)
	{
		pSession->markUsed();

		Poco::FastMutex::ScopedLock lock(_mutex);

		auto it = _pools.find(pSession->deviceId());
		if (it != _pools.end())
		{
			pPool = it->second;
		}
	}

	if (pPool)
	{
		pPool->returnObject(pSession);
	}
}


} } // namespace MyDevices::Gateway
