//
// LoginPage.cpp
//
// This file has been generated from LoginPage.cpsp on 2022-04-10 09:31:12.
//


#include "LoginPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"
#include "LoginPageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


LoginPage::LoginPage(DeviceManager::Ptr context):
	_context(context)
{
}


void LoginPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8"s);
	bool _compressResponse(request.hasToken("Accept-Encoding"s, "gzip"s));
	if (_compressResponse) response.set("Content-Encoding"s, "gzip"s);

	Poco::Net::HTMLForm form(request, request.stream());
#line 4 "/Users/guenter/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
#line 12 "/Users/guenter/ws/git/my-devices/gateway/src/LoginPage.cpsp"

LoginPageController ctrl(context(), request, form);
if (ctrl.mustRedirect()) return;

pageTemplate.set("title", "Gateway");
	std::ostream& _responseStream = response.send();
	Poco::DeflatingOutputStream _gzipStream(_responseStream, Poco::DeflatingStreamBuf::STREAM_GZIP, 1);
	std::ostream& responseStream = _compressResponse ? _gzipStream : _responseStream;
	responseStream << "<!DOCTYPE HTML>\n";
	responseStream << "\n";
	// begin include html/template.inc
	responseStream << "\n";
	// end include html/template.inc
	responseStream << "\n";
	// begin include html/header.inc
	responseStream << "<html lang=\"en\">\n";
	responseStream << "  <head>\n";
	responseStream << "    <meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">\n";
	responseStream << "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
	responseStream << "    <title>";
#line 5 "/Users/guenter/ws/git/my-devices/gateway/html/header.inc"
	responseStream << ( U::htmlize(pageTemplate["title"]) );
	responseStream << "</title>\n";
	responseStream << "    <link rel=\"stylesheet\" href=\"/css/styles.css\" type=\"text/css\"/>\n";
	responseStream << "    <link rel=\"icon\" href=\"/images/favicon.ico\">\n";
	responseStream << "  </head>\n";
	responseStream << "  <body lang=\"en\">\n";
	responseStream << "    <header>\n";
	responseStream << "      <div class=\"headercontainer\">\n";
	responseStream << "        <div class=\"header\">\n";
	responseStream << "\t\t  <h1>REMOTE ";
#line 13 "/Users/guenter/ws/git/my-devices/gateway/html/header.inc"
	responseStream << ( U::htmlize(pageTemplate["title"]) );
	responseStream << "</h1>\n";
	responseStream << "        </div>\n";
	responseStream << "      </div>\n";
	responseStream << "    </header>\n";
	responseStream << "    <div class=\"contentcontainer\">\n";
	responseStream << "      <div class=\"content\">\n";
	// end include html/header.inc
	responseStream << "\n";
#line 21 "/Users/guenter/ws/git/my-devices/gateway/src/LoginPage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 23 "/Users/guenter/ws/git/my-devices/gateway/src/LoginPage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 25 "/Users/guenter/ws/git/my-devices/gateway/src/LoginPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "<div class=\"loginBox\">\n";
	responseStream << "  <form method=\"post\" action=\"/\" accept-charset=\"utf-8\">\n";
	responseStream << "    <table>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <th colspan=\"2\" id=\"notice\">\n";
	responseStream << "          Please log in with your macchina.io REMOTE credentials.\n";
	responseStream << "        </th>\n";
	responseStream << "      </tr>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <th id=\"usernameLabelCell\">Username:</th>\n";
	responseStream << "        <td id=\"usernameInputCell\"><input id=\"usernameInput\" type=\"text\" name=\"username\" autofocus></td>\n";
	responseStream << "      </tr>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <th id=\"passwordLabelCell\">Password:</th>\n";
	responseStream << "        <td id=\"passwordInputCell\"><input id=\"passwordInput\" type=\"password\" name=\"password\"></td>\n";
	responseStream << "      </tr>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <td>&nbsp;</td>\n";
	responseStream << "        <td id=\"loginButtonCell\">\n";
	responseStream << "          <input type=\"hidden\" name=\"action\" value=\"login\">\n";
	responseStream << "          <input id=\"loginButton\" type=\"submit\" name=\"accept\" value=\"Login\">\n";
	responseStream << "        </td>\n";
	responseStream << "      </tr>\n";
	responseStream << "    </table>\n";
	responseStream << "    <input type=\"hidden\" name=\"operation\" value=\"login\">\n";
	responseStream << "  </form>\n";
	responseStream << "</div>\n";
	responseStream << "\n";
	// begin include html/footer.inc
	responseStream << "      </div>\n";
	responseStream << "    </div>\n";
	responseStream << "    <footer>\n";
	responseStream << "      <div class=\"footercontainer\">\n";
	responseStream << "        <div class=\"footer\">\n";
	responseStream << "          ";
#line 6 "/Users/guenter/ws/git/my-devices/gateway/html/footer.inc"
	responseStream << ( pageTemplate["softwareVersion"] );
	responseStream << " | &copy; 2015-2022 by <a href=\"https://macchina.io\">Applied Informatics GmbH</a>\n";
	responseStream << "        </div>\n";
	responseStream << "      </div>\n";
	responseStream << "    </footer>\n";
	responseStream << "    <script>\n";
	responseStream << "      ";
#line 11 "/Users/guenter/ws/git/my-devices/gateway/html/footer.inc"
	responseStream << ( pageTemplate.get("onload"s, ""s) );
	responseStream << "\n";
	responseStream << "    </script>\n";
	responseStream << "  </body>\n";
	responseStream << "</html>\n";
	// end include html/footer.inc
	responseStream << "\n";
	if (_compressResponse) _gzipStream.close();
}


} } // namespace MyDevices::Gateway
