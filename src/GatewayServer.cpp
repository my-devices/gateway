//
// GatewayServer.cpp
//
// Copyright (c) 2015-2024, Applied Informatics Software Engineering GmbH.
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
#include "Poco/DirectoryWatcher.h"
#include "Poco/URI.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/NumberParser.h"
#include "Poco/SharedPtr.h"
#include "Poco/Delegate.h"
#include "WebTunnelAgent.h"
#include "DeviceManager.h"
#include "Utility.h"
#include "LoginPage.h"
#include "IndexPage.h"
#include "StatusJSON.h"
#include "DevicePage.h"
#include "CreateDevicePage.h"
#include "Stylesheet.h"
#include "FavIcon.h"
#include "HeaderLogo.h"
#include "HeaderLogoX2.h"
#include "PlusIcon.h"
#include "PlusIconX2.h"
#include "MinusIcon.h"
#include "MinusIconX2.h"
#include "AjaxCore.h"
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
using Poco::DirectoryWatcher;
using Poco::delegate;


using namespace std::string_literals;


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
		_pDeviceManager(pDeviceManager),
		_logger(Poco::Logger::get("GatewayRequestHandlerFactory"s))
	{
	}

	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{

		const std::string& uri = request.getURI();
		_logger.debug("%s %s %s"s, request.getMethod(), uri, request.getVersion());

		if (uri == "/")
			return new LoginPage(_pDeviceManager);
		else if (uri == "/devices")
			return new IndexPage(_pDeviceManager);
		else if (uri == "/create")
			return new CreateDevicePage(_pDeviceManager);
		else if (uri == "/status.json")
			return new StatusJSON(_pDeviceManager);
		else if (uri.compare(0, 8, "/device/") == 0)
			return new DevicePage(_pDeviceManager);
		else if (uri == "/images/favicon.ico")
			return new FavIcon;
		else if (uri == "/css/styles.css")
			return new Stylesheet;
		else if (uri == "/images/headerlogo.png")
			return new HeaderLogo;
		else if (uri == "/images/headerlogo-x2.png")
			return new HeaderLogoX2;
		else if (uri == "/images/plusicon.png")
			return new PlusIcon;
		else if (uri == "/images/plusicon-x2.png")
			return new PlusIconX2;
		else if (uri == "/images/minusicon.png")
			return new MinusIcon;
		else if (uri == "/images/minusicon-x2.png")
			return new MinusIconX2;
		else if (uri == "/js/ajaxcore.js")
			return new AjaxCore;
		else
			return 0;
	}

private:
	DeviceManager::Ptr _pDeviceManager;
	Poco::Logger& _logger;
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
			Option("help"s, "h"s, "Display help information on command line arguments."s)
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleHelp)));

		options.addOption(
			Option("config-file"s, "c"s, "Load configuration data from a file."s)
				.required(false)
				.repeatable(true)
				.argument("file"s)
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleConfig)));

		options.addOption(
			Option("define"s, "D"s, "Define or override a configuration property."s)
				.required(false)
				.repeatable(true)
				.argument("name=value"s)
				.callback(OptionCallback<GatewayServer>(this, &GatewayServer::handleDefine)));
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

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS"s);
		helpFormatter.setHeader("\n"
			"macchina.io REMOTE Gateway Server.\n\n"
			"Copyright (c) 2015-2024 by Applied Informatics Software Engineering GmbH.\n"
			"All rights reserved.\n\n"
			"This application is used to connect device web servers in the local\n"
			"network to the macchina.io REMOTE server in order to make them\n"
			"accessible remotely.\n\n"
			"The following command-line options are supported:"s);
		helpFormatter.setFooter(
			"For more information, please visit the macchina.io REMOTE "
			"website at <https://macchina.io/remote>."s
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

#if defined(WEBTUNNEL_ENABLE_TLS)

	Poco::Net::Context::Ptr createContext(const std::string& prefix)
	{
		std::string cipherList = config().getString(prefix + ".ciphers", "HIGH:!DSS:!aNULL@STRENGTH"s);
		bool extendedVerification = config().getBool(prefix + ".extendedCertificateVerification"s, false);
		std::string caLocation = config().getString(prefix + ".caLocation", ""s);
		std::string privateKey = config().getString(prefix + ".privateKey", ""s);
		std::string certificate = config().getString(prefix + ".certificate", ""s);
		std::string tlsMinVersion = config().getString(prefix + ".minVersion", ""s);

		Poco::Net::Context::VerificationMode vMode = Poco::Net::Context::VERIFY_RELAXED;
		std::string vModeStr = config().getString(prefix + ".verification", ""s);
		if (vModeStr == "none")
			vMode = Poco::Net::Context::VERIFY_NONE;
		else if (vModeStr == "relaxed")
			vMode = Poco::Net::Context::VERIFY_RELAXED;
		else if (vModeStr == "strict")
			vMode = Poco::Net::Context::VERIFY_STRICT;

		Poco::Net::Context::Protocols minProto = Poco::Net::Context::PROTO_TLSV1_2;
		if (tlsMinVersion == "tlsv1")
			minProto = Poco::Net::Context::PROTO_TLSV1;
		else if (tlsMinVersion == "tlsv1_1")
			minProto = Poco::Net::Context::PROTO_TLSV1_1;
		else if (tlsMinVersion == "tlsv1_2")
			minProto = Poco::Net::Context::PROTO_TLSV1_2;
		else if (tlsMinVersion == "tlsv1_3")
			minProto = Poco::Net::Context::PROTO_TLSV1_3;

#if defined(POCO_NETSSL_WIN)
		int options = Poco::Net::Context::OPT_DEFAULTS;
		if (!certificate.empty()) options |= Poco::Net::Context::OPT_LOAD_CERT_FROM_FILE;
		Poco::Net::Context::Ptr pContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, certificate, vMode, options);
#else
		Poco::Net::Context::Ptr pContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, privateKey, certificate, caLocation, vMode, 5, true, cipherList);
#endif // POCO_NETSSL_WIN

		pContext->requireMinimumProtocol(minProto);
		pContext->enableExtendedCertificateVerification(extendedVerification);
		return pContext;
	}

#endif // WEBTUNNEL_ENABLE_TLS

	void onItemChanged(const DirectoryWatcher::DirectoryEvent& ev)
	{
		logger().notice("Device configuration changed: %s"s, ev.item.path());
		_pDeviceManager->reconfigureAgents(500);
	}

	int main(const std::vector<std::string>& args)
	{
		if (_dontRun) return Application::EXIT_OK;

		logger().information(
			"\n"
			"\n"
			"      oooooooooooooooooo\n"
			"    oooooooooooooooooooooo\n"
			"    oooooooooooooooooooooo\n"
			"    oooooooooooooooooooooo\n"
			"    oooooooooooooooooooooo\n"
			"    ooooooooo            o\n"
			"    ooooooooo   oo   oo  \n"
			"    ooooooooo   oo   oo \n"
			"    ooooooooo   oo   oo \n"
			"    ooooooooo   oo   oo \n"
			"      ooooooo   oo   oo \n"
			"\n"
			"    macchina.io REMOTE Gateway %s\n"
			"\n"
			"    Copyright (c) 2015-2024 by Applied Informatics Software Engineering GmbH.\n"
			"    All rights reserved.\n"s,
			U::versionString()
		);

#if defined(WEBTUNNEL_ENABLE_TLS)
		Poco::Net::Context::Ptr pContext = createContext("tls"s);
		bool acceptUnknownCert = config().getBool("tls.acceptUnknownCertificate"s, true);
		Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> pCertificateHandler;
		if (acceptUnknownCert)
			pCertificateHandler = new Poco::Net::AcceptCertificateHandler(false);
		else
			pCertificateHandler = new Poco::Net::RejectCertificateHandler(false);
		Poco::Net::SSLManager::instance().initializeClient(0, pCertificateHandler, pContext);
#endif

#if defined(WEBTUNNEL_ENABLE_TLS)
		_pDeviceManager = new DeviceManager(config(), _pTimer, createContext("webtunnel.https"s));
#else
		_pDeviceManager = new DeviceManager(config(), _pTimer);
#endif

		bool watchRepository = config().getBool("gateway.watchRepository"s, false);
		if (watchRepository)
		{
			_pDirectoryWatcher = new DirectoryWatcher(_pDeviceManager->deviceRepositoryPath());
			_pDirectoryWatcher->itemAdded    += delegate(this, &GatewayServer::onItemChanged);
			_pDirectoryWatcher->itemRemoved  += delegate(this, &GatewayServer::onItemChanged);
			_pDirectoryWatcher->itemModified += delegate(this, &GatewayServer::onItemChanged);
		}

		Poco::UInt16 port = static_cast<Poco::UInt16>(config().getInt("gateway.http.port"s, 8080));
		if (port != 0)
		{
			ServerSocket svs(port);
			_pHTTPServer = new HTTPServer(new GatewayRequestHandlerFactory(_pDeviceManager), svs, new HTTPServerParams);
			_pHTTPServer->start();
			logger().information("Web server started on port %hu."s, port);
		}

		waitForTerminationRequest();

		if (_pHTTPServer)
		{
			_pHTTPServer->stopAll(true);
			_pHTTPServer.reset();
		}

		if (_pDirectoryWatcher)
		{
			_pDirectoryWatcher->itemAdded    -= delegate(this, &GatewayServer::onItemChanged);
			_pDirectoryWatcher->itemRemoved  -= delegate(this, &GatewayServer::onItemChanged);
			_pDirectoryWatcher->itemModified -= delegate(this, &GatewayServer::onItemChanged);
			_pDirectoryWatcher.reset();
		}

		_pDeviceManager->stopAgents();
		_pDeviceManager.reset();

		return Application::EXIT_OK;
	}

private:
	bool _dontRun;
	SSLInitializer _sslInitializer;
	Poco::SharedPtr<Poco::Util::Timer> _pTimer;
	Poco::SharedPtr<HTTPServer> _pHTTPServer;
	Poco::SharedPtr<DirectoryWatcher> _pDirectoryWatcher;
	DeviceManager::Ptr _pDeviceManager;
};


} } // namespace MyDevices::Gateway


POCO_SERVER_MAIN(MyDevices::Gateway::GatewayServer)
