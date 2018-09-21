//
// GatewayServer.cpp
//
// Copyright (c) 2015-2017, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/WebTunnel/RemotePortForwarder.h"
#include "Poco/Net/HTTPSessionFactory.h"
#include "Poco/Net/HTTPSessionInstantiator.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/ServerSocket.h"
#if defined(WEBTUNNEL_ENABLE_TLS)
#include "Poco/Net/HTTPSSessionInstantiator.h"
#include "Poco/Net/Context.h"
#include "Poco/Net/PrivateKeyPassphraseHandler.h"
#include "Poco/Net/AcceptCertificateHandler.h"
#include "Poco/Net/RejectCertificateHandler.h"
#include "Poco/Net/SSLManager.h"
#endif
#include "Poco/Util/Timer.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/LayeredConfiguration.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/URI.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/NumberParser.h"
#include "Poco/SharedPtr.h"
#include "WebTunnelAgent.h"
#include "DeviceManager.h"
#include "Utility.h"
#include "IndexPage.h"
#include "DevicePage.h"
#include "Stylesheet.h"
#include "FavIcon.h"
#include "Gradient.h"
#include "HeaderLogo.h"
#include "HeaderLogoX2.h"
#include "FooterLogo.h"
#include "FooterLogoX2.h"
#include "PlusIcon.h"
#include "PlusIconX2.h"
#include "MinusIcon.h"
#include "MinusIconX2.h"
#include <iostream>


using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;


namespace MyDevices {
namespace Gateway {


class SSLInitializer
{
public:
	SSLInitializer()
	{
#if defined(WEBTUNNEL_ENABLE_TLS)
		Poco::Net::initializeSSL();
#endif
	}

	~SSLInitializer()
	{
#if defined(WEBTUNNEL_ENABLE_TLS)
		Poco::Net::uninitializeSSL();
#endif
	}
};


class GatewayRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
	GatewayRequestHandlerFactory(DeviceManager::Ptr pDeviceManager):
		_pDeviceManager(pDeviceManager)
	{
	}

	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{
		const std::string& uri = request.getURI();
		if (uri == "/")
			return new IndexPage(_pDeviceManager);
		else if (uri.compare(0, 8, "/device/") == 0)
			return new DevicePage(_pDeviceManager);
		else if (uri == "/images/favicon.ico")
			return new FavIcon;
		else if (uri == "/css/styles.css")
			return new Stylesheet;
		else if (uri == "/images/gradient.png")
			return new Gradient;
		else if (uri == "/images/headerlogo.png")
			return new HeaderLogo;
		else if (uri == "/images/headerlogo-x2.png")
			return new HeaderLogoX2;
		else if (uri == "/images/footerlogo.png")
			return new FooterLogo;
		else if (uri == "/images/footerlogo-x2.png")
			return new FooterLogoX2;
		else if (uri == "/images/plusicon.png")
			return new PlusIcon;
		else if (uri == "/images/plusicon-x2.png")
			return new PlusIconX2;
		else if (uri == "/images/minusicon.png")
			return new MinusIcon;
		else if (uri == "/images/minusicon-x2.png")
			return new MinusIconX2;
		else
			return 0;
	}

private:
	DeviceManager::Ptr _pDeviceManager;
};


class GatewayServer: public Poco::Util::ServerApplication
{
public:
	GatewayServer(): _dontRun(false)
	{
	}

	~GatewayServer()
	{
	}

protected:
	void initialize(Application& self)
	{
		loadConfiguration();
		ServerApplication::initialize(self);

		Poco::Net::HTTPSessionInstantiator::registerInstantiator();
#if defined(WEBTUNNEL_ENABLE_TLS)
		Poco::Net::HTTPSSessionInstantiator::registerInstantiator();
#endif

		_pTimer = new Poco::Util::Timer;
	}

	void uninitialize()
	{
		ServerApplication::uninitialize();

		Poco::Net::HTTPSessionInstantiator::unregisterInstantiator();
#if defined(WEBTUNNEL_ENABLE_TLS)
		Poco::Net::HTTPSSessionInstantiator::unregisterInstantiator();
#endif

		_pTimer = 0;
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "Display help information on command line arguments.")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleHelp)));

		options.addOption(
			Option("config-file", "c", "Load configuration data from a file.")
				.required(false)
				.repeatable(true)
				.argument("file")
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleConfig)));

		options.addOption(
			Option("define", "D", "Define or override a configuration property.")
				.required(false)
				.repeatable(true)
				.argument("name=value")
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleDefine)));

		options.addOption(
			Option("hash-password", "H", "Compute password hash for configuration file.")
				.required(false)
				.repeatable(true)
				.argument("password")
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleHash)));
	}

	void handleHelp(const std::string& name, const std::string& value)
	{
		_dontRun = true;
		displayHelp();
		stopOptionsProcessing();
	}

	void handleConfig(const std::string& name, const std::string& value)
	{
		loadConfiguration(value);
	}

	void handleDefine(const std::string& name, const std::string& value)
	{
		defineProperty(value);
	}

	void handleHash(const std::string& name, const std::string& value)
	{
		_dontRun = true;
		std::cout << Utility::hashPassword(value) << std::endl;
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("\n"
			"macchina.io Remote Manager Gateway Server.\n\n"
			"Copyright (c) 2015-2018 by Applied Informatics Software Engineering GmbH.\n"
			"All rights reserved.\n\n"
			"This application is used to connect device web servers in the local\n"
			"network to the macchina.io Remote Manager server in order to make them\n"
			"accessible remotely.\n\n"
			"The following command-line options are supported:");
		helpFormatter.setFooter(
			"For more information, please visit the macchina.io "
			"website at <https://macchina.io>."
		);
		helpFormatter.setIndent(8);
		helpFormatter.format(std::cout);
	}

	void defineProperty(const std::string& def)
	{
		std::string name;
		std::string value;
		std::string::size_type pos = def.find('=');
		if (pos != std::string::npos)
		{
			name.assign(def, 0, pos);
			value.assign(def, pos + 1, def.length() - pos);
		}
		else name = def;
		config().setString(name, value);
	}

	int main(const std::vector<std::string>& args)
	{
		if (_dontRun) return Application::EXIT_OK;

#if defined(WEBTUNNEL_ENABLE_TLS)
		bool acceptUnknownCert = config().getBool("tls.acceptUnknownCertificate", true);
		std::string cipherList = config().getString("tls.ciphers", "HIGH:!DSS:!aNULL@STRENGTH");
		bool extendedVerification = config().getBool("tls.extendedCertificateVerification", false);
		std::string caLocation = config().getString("tls.caLocation", "");

		Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> pCertificateHandler;
		if (acceptUnknownCert)
			pCertificateHandler = new Poco::Net::AcceptCertificateHandler(false);
		else
			pCertificateHandler = new Poco::Net::RejectCertificateHandler(false);
		Poco::Net::Context::Ptr pContext = new Poco::Net::Context(Poco::Net::Context::TLSV1_CLIENT_USE, "", "", caLocation, Poco::Net::Context::VERIFY_RELAXED, 5, true, cipherList);
		pContext->enableExtendedCertificateVerification(extendedVerification);
		Poco::Net::SSLManager::instance().initializeClient(0, pCertificateHandler, pContext);
#endif

		DeviceManager::Ptr pDeviceManager = new DeviceManager(config(), _pTimer);

		Poco::UInt16 port = static_cast<Poco::UInt16>(config().getInt("gateway.http.port", 8080));

		ServerSocket svs(port);
		HTTPServer srv(new GatewayRequestHandlerFactory(pDeviceManager), svs, new HTTPServerParams);
		srv.start();
		waitForTerminationRequest();
		srv.stop();

		pDeviceManager->stopAgents();
		_pTimer->cancel(true);

		return Application::EXIT_OK;
	}

private:
	bool _dontRun;
	SSLInitializer _sslInitializer;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
};


} } // namespace MyDevices::Gateway


POCO_SERVER_MAIN(MyDevices::Gateway::GatewayServer)