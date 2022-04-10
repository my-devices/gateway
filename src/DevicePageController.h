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
		if (_password.empty())
			return "";
		else
			return PASSWORD_PLACEHOLDER;
	}

	const std::string host() const
	{
		return _host;
	}

	bool httpPortEnabled() const
	{
		return _httpPortEnabled;
	}

	bool sshPortEnabled() const
	{
		return _sshPortEnabled;
	}

	bool vncPortEnabled() const
	{
		return _vncPortEnabled;
	}

	bool rdpPortEnabled() const
	{
		return _rdpPortEnabled;
	}

	bool appPortEnabled() const
	{
		return _appPortEnabled;
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

	const std::string appPort() const
	{
		return _appPort;
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

	void savePort(const std::string& proto, Poco::UInt16 port);

	Poco::UInt16 loadPort(const std::string& proto) const;

protected:
	void loadDevice();
	void processForm();
	std::string loadExtraPorts() const;

	static const std::string PASSWORD_PLACEHOLDER;

private:
	std::string _deviceId;
	std::string _name;
	std::string _domain;
	std::string _password;
	std::string _host;
	bool _httpPortEnabled = true;
	bool _sshPortEnabled = true;
	bool _vncPortEnabled = true;
	bool _rdpPortEnabled = true;
	bool _appPortEnabled = true;
	std::string _httpPort;
	bool _httpsEnable;
	std::string _sshPort;
	std::string _vncPort;
	std::string _rdpPort;
	std::string _appPort;
	std::string _extraPorts;
	Poco::AutoPtr<Poco::Util::AbstractConfiguration> _pDeviceConfig;
	WebTunnelAgent::Ptr _pAgent;
};


} } // namespace MyDevices::Gateway


#endif // MyGateway_DevicePageController_INCLUDED
