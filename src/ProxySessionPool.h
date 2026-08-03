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


class ProxySession: public Poco::RefCountedObject
{
public:
	using Ptr = Poco::AutoPtr<ProxySession>;

	ProxySession(DeviceManager& deviceManager, const std::string& deviceId);

#if defined(WEBTUNNEL_ENABLE_TLS)
	ProxySession(DeviceManager& deviceManager, Poco::Net::Context::Ptr pContext, const std::string& deviceId);
#endif

	~ProxySession() = default;

	Poco::SharedPtr<Poco::Net::HTTPClientSession> session();

	const std::string& deviceId() const
	{
		return _deviceId;
	}

	void markUsed()
	{
		_lastUsed.update();
	}

protected:
	Poco::SharedPtr<Poco::Net::HTTPClientSession> createSession(const std::string& host, Poco::UInt16 port, bool secure);
	void init();

private:
	DeviceManager& _deviceManager;
#if defined(WEBTUNNEL_ENABLE_TLS)
	Poco::Net::Context::Ptr _pContext;
#endif
	std::string _deviceId;
	Poco::Timespan _requestTimeout;
	Poco::Timespan _keepAliveTimeout;
	Poco::SharedPtr<Poco::Net::HTTPClientSession> _pSession;
	Poco::Timestamp _lastUsed;
};


class ProxySessionFactory
	/// A PoolableObjectFactory implementation for HTTPClientSession.
{
public:
	ProxySessionFactory(DeviceManager& deviceManager, const std::string& deviceId):
		_pDeviceManager(&deviceManager),
		_deviceId(deviceId)
	{
	}

#if defined(WEBTUNNEL_ENABLE_TLS)
	ProxySessionFactory(DeviceManager& deviceManager, Poco::Net::Context::Ptr pContext, const std::string& deviceId):
		_pDeviceManager(&deviceManager),
		_pContext(pContext),
		_deviceId(deviceId)
	{
	}
#endif

	ProxySessionFactory(const ProxySessionFactory& other):
		_pDeviceManager(other._pDeviceManager)
#if defined(WEBTUNNEL_ENABLE_TLS)
		,
		_pContext(other._pContext)
#endif
		,
		_deviceId(other._deviceId)
	{
	}

	ProxySessionFactory& operator = (const ProxySessionFactory& other)
	{
		if (this != &other)
		{
			_pDeviceManager = other._pDeviceManager;
#if defined(WEBTUNNEL_ENABLE_TLS)
			_pContext = other._pContext;
#endif
		}
		_deviceId = other._deviceId;
		return *this;
	}

	ProxySession::Ptr createObject()
	{
#if defined(WEBTUNNEL_ENABLE_TLS)
		return Poco::makeAuto<ProxySession>(*_pDeviceManager, _pContext, _deviceId);
#else
		return Poco::makeAuto<ProxySession>(*_pDeviceManager, _deviceId);
#endif
	}

	bool validateObject(ProxySession::Ptr pProxySession)
	{
		return true;
	}

	void activateObject(ProxySession::Ptr pProxySession)
	{
	}

	void deactivateObject(ProxySession::Ptr pProxySession)
	{
	}

	void destroyObject(ProxySession::Ptr pProxySession)
	{
	}

private:
	DeviceManager* _pDeviceManager;
#if defined(WEBTUNNEL_ENABLE_TLS)
	Poco::Net::Context::Ptr _pContext;
#endif
	std::string _deviceId;
};


class ProxySessionPool
	/// A pool of HTTPClientSession objects for use by the reverse proxy server.
{
public:
	using ObjectPool = Poco::ObjectPool<ProxySession, ProxySession::Ptr, ProxySessionFactory>;
	using ObjectPoolPtr = Poco::SharedPtr<ObjectPool>;

	ProxySessionPool(DeviceManager& deviceManager);

	ProxySession::Ptr borrowSession(const std::string& deviceId);

	void returnSession(ProxySession::Ptr pSession);

private:
	DeviceManager& _deviceManager;
#if defined(WEBTUNNEL_ENABLE_TLS)
	Poco::Net::Context::Ptr _pContext;
#endif
	std::map<std::string, ObjectPoolPtr> _pools;
	mutable Poco::FastMutex _mutex;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_ProxySessionPool_INCLUDED
