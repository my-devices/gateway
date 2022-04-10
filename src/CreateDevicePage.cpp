//
// CreateDevicePage.cpp
//
// This file has been generated from CreateDevicePage.cpsp on 2022-04-10 09:31:11.
//


#include "CreateDevicePage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"
#include "CreateDevicePageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


CreateDevicePage::CreateDevicePage(DeviceManager::Ptr context):
	_context(context)
{
}


void CreateDevicePage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8"s);
	bool _compressResponse(request.hasToken("Accept-Encoding"s, "gzip"s));
	if (_compressResponse) response.set("Content-Encoding"s, "gzip"s);

	Poco::Net::HTMLForm form(request, request.stream());
#line 4 "/Users/guenter/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
#line 13 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"

CreateDevicePageController ctrl(context(), request, form);
if (response.sent()) return;
if (ctrl.mustRedirect()) return;

pageTemplate.set("title", "Gateway > Create Device");
pageTemplate.set("onload"s, "document.getElementById('deviceNameInput').focus();"s);
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
	responseStream << "<script>\n";
	responseStream << "function cancelUpdateDevice(id)\n";
	responseStream << "{\n";
	responseStream << "  document.actionForm.action.value = \"cancel\";\n";
	responseStream << "  document.actionForm.submit();\n";
	responseStream << "}\n";
	responseStream << "</script>\n";
	responseStream << "\n";
	responseStream << "<nav>\n";
	responseStream << "  <div class=\"usernav\">\n";
	responseStream << "    <div class=\"navigation\">\n";
	responseStream << "    </div>\n";
	responseStream << "    <div class=\"username\">\n";
	responseStream << "      &nbsp;\n";
	responseStream << "      ";
#line 38 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( ctrl.username() );
	responseStream << "\n";
	responseStream << "      &nbsp;\n";
	responseStream << "      <a id=\"logoutLink\" href=\"#\" onclick=\"document.logout.submit()\">Sign out</a>\n";
	responseStream << "   </div>\n";
	responseStream << "   <form method=\"post\" name=\"logout\" action=\"/\">\n";
	responseStream << "     <input type=\"hidden\" name=\"action\" value=\"logout\">\n";
	responseStream << "   </form>\n";
	responseStream << "   <div style=\"clear: both;\"></div>\n";
	responseStream << " </div>\n";
	responseStream << "</nav>\n";
	responseStream << "\n";
#line 49 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 51 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 53 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
 } 	responseStream << "\n";
	responseStream << "<div class=\"groupbox\">\n";
	responseStream << "  <h2>New Device Properties</h2>\n";
	responseStream << "\n";
	responseStream << "  <form name=\"actionForm\" method=\"post\" accept-charset=\"utf-8\" autocomplete=\"off\">\n";
	responseStream << "    <input type=\"hidden\" name=\"action\" value=\"create\">\n";
	responseStream << "    <input type=\"hidden\" name=\"csrfToken\" value=\"";
#line 60 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( ctrl.csrfToken() );
	responseStream << "\">\n";
	responseStream << "    <table class=\"list\">\n";
	responseStream << "      <tbody>\n";
	responseStream << "        <tr class=\"even\">\n";
	responseStream << "          <td class=\"basicProperty\">Name</td>\n";
	responseStream << "          <td>\n";
	responseStream << "            <input type=\"text\"\n";
	responseStream << "                   id=\"deviceNameInput\"\n";
	responseStream << "                   name=\"deviceName\"\n";
	responseStream << "                   value=\"";
#line 69 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.name()) );
	responseStream << "\"\n";
	responseStream << "                   size=\"64\"\n";
	responseStream << "                   maxLength=\"64\"\n";
	responseStream << "                   class=\"form-control\"\n";
	responseStream << "                   autofocus>\n";
	responseStream << "          </td>\n";
	responseStream << "        </tr>\n";
	responseStream << "        <tr class=\"odd\">\n";
	responseStream << "          <td class=\"basicProperty\">ID</td>\n";
	responseStream << "          <td>\n";
	responseStream << "            <input type=\"text\"\n";
	responseStream << "                   name=\"deviceId\"\n";
	responseStream << "                   value=\"";
#line 81 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceId()) );
	responseStream << "\"\n";
	responseStream << "                   size=\"64\"\n";
	responseStream << "                   maxLength=\"64\"\n";
	responseStream << "                   class=\"form-control\">\n";
	responseStream << "          </td>\n";
	responseStream << "        </tr>\n";
	responseStream << "        <tr class=\"even\">\n";
	responseStream << "          <td class=\"basicProperty\">Domain</td>\n";
	responseStream << "          <td>\n";
	responseStream << "            <input type=\"text\"\n";
	responseStream << "                   name=\"deviceDomain\"\n";
	responseStream << "                   value=\"";
#line 92 "/Users/guenter/ws/git/my-devices/gateway/src/CreateDevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.domain()) );
	responseStream << "\"\n";
	responseStream << "                   size=\"64\"\n";
	responseStream << "                   maxLength=\"64\"\n";
	responseStream << "                   class=\"form-control\">\n";
	responseStream << "          </td>\n";
	responseStream << "        </tr>\n";
	responseStream << "        <tr>\n";
	responseStream << "          <td colspan=\"2\" style=\"text-align: right\">\n";
	responseStream << "            <a href=\"#\" onclick=\"cancelUpdateDevice()\">Cancel</a>\n";
	responseStream << "            &nbsp;\n";
	responseStream << "            <input type=\"submit\" value=\"Next\" class=\"form-control\">\n";
	responseStream << "          </td>\n";
	responseStream << "        </tr>\n";
	responseStream << "      </tbody>\n";
	responseStream << "    </table>\n";
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
