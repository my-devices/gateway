//
// ProxySessionPool.h
//
// Copyright (c) 2026, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_ProxySessionPool_INCLUDED
#define MyGateway_ProxySessionPool_INCLUDED


#include "DeviceManager.h"
#if defined(WEBTUNNEL_ENABLE_TLS)
#include "Poco/Net/HTTPSClientSession.h"
#else
#include "Poco/Net/HTTPClientSession.h"
#endif
#include "Poco/ObjectPool.h"
#include "Poco/Mutex.h"


namespace MyDevices {
namespace Gateway {


class ProxySessionFactory
	/// A PoolableObjectFactory implementation for HTTPClientSession.
{
public:
	ProxySessionFactory(const Poco::Net::SocketAddress& addr):
		_addr(addr)
	{
	}

#if defined(WEBTUNNEL_ENABLE_TLS)
	ProxySessionFactory(const Poco::Net::SocketAddress& addr, Poco::Net::Context::Ptr pContext):
		_addr(addr),
		_pContext(pContext)
	{
	}
#endif

	ProxySessionFactory(const ProxySessionFactory& other):
		_addr(other._addr)
#if defined(WEBTUNNEL_ENABLE_TLS)
		,
		_pContext(other._pContext)
#endif
	{
	}

	ProxySessionFactory& operator = (const ProxySessionFactory& other)
	{
		if (this != &other)
		{
			_addr = other._addr;
#if defined(WEBTUNNEL_ENABLE_TLS)
			_pContext = other._pContext;
#endif
		}
		return *this;
	}

	Poco::SharedPtr<Poco::Net::HTTPClientSession> createObject()
	{
		Poco::SharedPtr<Poco::Net::HTTPClientSession> pClientSession;
#if defined(WEBTUNNEL_ENABLE_TLS)
		if (_pContext)
		{
			pClientSession = new Poco::Net::HTTPSClientSession(_addr.host().toString(), _addr.port(), _pContext);
		}
		else
#endif
		{
			pClientSession = new Poco::Net::HTTPClientSession(_addr);
		}
		return pClientSession;
	}

	bool validateObject(Poco::SharedPtr<Poco::Net::HTTPClientSession> pClientSession)
	{
		return pClientSession->connected();
	}

	void activateObject(Poco::SharedPtr<Poco::Net::HTTPClientSession> pClientSession)
	{
		pClientSession->setKeepAlive(true);
		pClientSession->setKeepAliveTimeout(Poco::Timespan(60, 0));
	}

	void deactivateObject(Poco::SharedPtr<Poco::Net::HTTPClientSession> pClientSession)
	{
	}

	void destroyObject(Poco::SharedPtr<Poco::Net::HTTPClientSession> pClientSession)
	{
	}

private:
	Poco::Net::SocketAddress _addr;
#if defined(WEBTUNNEL_ENABLE_TLS)
	Poco::Net::Context::Ptr _pContext;
#endif
};


class ProxySessionPool
	/// A pool of HTTPClientSession objects for use by the reverse proxy server.
{
public:
	using ObjectPool = Poco::ObjectPool<Poco::SharedPtr<Poco::Net::HTTPClientSession>, ProxySessionFactory>;
	using ObjectPoolPtr = std::unique_ptr<ObjectPool>;

	ProxySessionPool(DeviceManager& deviceManager);

	Poco::SharedPtr<Poco::Net::HTTPClientSession> borrowSession(const std::string& deviceId);

	void returnSession(const std::string& deviceId, Poco::SharedPtr<Poco::Net::HTTPClientSession> pSession);

private:
	DeviceManager& _deviceManager;
	std::map<std::string, ObjectPoolPtr> _pools;
	mutable Poco::FastMutex _mutex;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_ProxySessionPool_INCLUDED
