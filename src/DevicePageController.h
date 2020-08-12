//
// DevicePageController.h
//
// Copyright (c) 2017-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef MyGateway_DevicePageController_INCLUDED
#define MyGateway_DevicePageController_INCLUDED


#include "PageController.h"
#include "WebTunnelAgent.h"


namespace MyDevices {
namespace Gateway {


class DevicePageController: public PageController
{
public:
	DevicePageController(DeviceManager::Ptr pDeviceManager, const Poco::Net::HTTPServerRequest& request, const Poco::Net::HTMLForm& form);
		/// Creates the PageController.

	virtual ~DevicePageController();
		/// Destroys the PageController.

	const std::string& deviceId() const
	{
		return _deviceId;
	}

	const std::string& name() const
	{
		return _name;
	}

	const std::string domain() const
	{
		return _domain;
	}

	const std::string password() const
	{
		return _password;
	}

	const std::string host() const
	{
		return _host;
	}

	const std::string httpPort() const
	{
		return _httpPort;
	}

	bool httpsEnable() const
	{
		return _httpsEnable;
	}

	const std::string sshPort() const
	{
		return _sshPort;
	}

	const std::string vncPort() const
	{
		return _vncPort;
	}

	const std::string rdpPort() const
	{
		return _rdpPort;
	}

	const std::string extraPorts() const
	{
		return _extraPorts;
	}

	Poco::AutoPtr<Poco::Util::AbstractConfiguration> deviceConfig() const
	{
		return _pDeviceConfig;
	}

	std::string deviceStatus() const;

	std::string deviceError() const;

protected:
	void loadDevice();
	void processForm();
	std::string loadExtraPorts() const;

private:
	std::string _deviceId;
	std::string _name;
	std::string _domain;
	std::string _password;
	std::string _host;
	std::string _httpPort;
	bool _httpsEnable;
	std::string _sshPort;
	std::string _vncPort;
	std::string _rdpPort;
	std::string _extraPorts;
	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pDeviceConfig;
	WebTunnelAgent::Ptr _pAgent;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_DevicePageController_INCLUDED
