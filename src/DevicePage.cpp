//
// DevicePage.cpp
//
// This file has been generated from DevicePage.cpsp on 2018-03-08 20:22:33.
//


#include "DevicePage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"


#include "DevicePageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


namespace MyDevices {
namespace Gateway {


DevicePage::DevicePage(DeviceManager::Ptr context):
	_context(context)
{
}


void DevicePage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8");
	bool _compressResponse(request.hasToken("Accept-Encoding", "gzip"));
	if (_compressResponse) response.set("Content-Encoding", "gzip");

	if (!(U::authenticate(request, response))) return;

	Poco::Net::HTMLForm form(request, request.stream());
#line 4 "/Users/guenter/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
#line 8 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"

	DevicePageController pageController(context(), request, form);
	
	if (pageController.deviceConfig())
	{
		pageTemplate.set("title", "Gateway > " + pageController.deviceConfig()->getString("webtunnel.deviceName"));
	}
	else
	{
		pageTemplate.set("title", "Gateway > Unknown Device");
	}
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
	responseStream << "<html>\n";
	responseStream << "  <head>\n";
	responseStream << "    <meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">\n";
	responseStream << "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge,chrome=1\">\n";
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
	responseStream << "        <div class=\"header\">  \n";
	responseStream << "\t\t  <h1>";
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
	responseStream << "<script language=\"JavaScript\">\n";
	responseStream << "function cancelUpdateDevice(id)\n";
	responseStream << "{\n";
	responseStream << "  document.actionForm.action.value = \"cancel\";\n";
	responseStream << "  document.actionForm.submit();\n";
	responseStream << "}\n";
	responseStream << "</script>\n";
	responseStream << "\n";
#line 31 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (!pageController.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 33 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 35 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << "\n";
#line 37 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (pageController.deviceConfig()) { 	responseStream << "\n";
	responseStream << "  <div class=\"groupbox\">\n";
	responseStream << "    <h2>Device Settings</h2>\n";
	responseStream << "  \n";
	responseStream << "    <form name=\"actionForm\" method=\"post\" action=\"/\">\n";
	responseStream << "      <input type=\"hidden\" name=\"action\" value=\"update\">\n";
	responseStream << "      <input type=\"hidden\" name=\"target\" value=\"";
#line 43 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( pageController.deviceConfig()->getString("webtunnel.deviceId") );
	responseStream << "\">\n";
	responseStream << "      <table class=\"list\">\n";
	responseStream << "        <tbody>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">ID</td>\n";
	responseStream << "            <td>";
#line 48 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.deviceId")) );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">Name</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input name=\"deviceName\" \n";
	responseStream << "                     value=\"";
#line 54 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.deviceName")) );
	responseStream << "\" \n";
	responseStream << "                     size=\"64\" \n";
	responseStream << "                     maxLength=\"64\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Device IP Address or Domain Name</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input name=\"host\" \n";
	responseStream << "                     value=\"";
#line 63 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.host")) );
	responseStream << "\" \n";
	responseStream << "                     size=\"64\" \n";
	responseStream << "                     maxLength=\"64\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">Forwarded TCP Ports</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input name=\"ports\" \n";
	responseStream << "                     value=\"";
#line 72 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.ports")) );
	responseStream << "\" \n";
	responseStream << "                     size=\"40\" \n";
	responseStream << "                     maxLength=\"40\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Device HTTP Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input name=\"httpPort\" \n";
	responseStream << "                     value=\"";
#line 81 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.httpPort")) );
	responseStream << "\" \n";
	responseStream << "                     size=\"5\" \n";
	responseStream << "                     maxLength=\"5\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>Device Password</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"password\" \n";
	responseStream << "                     name=\"password\" \n";
	responseStream << "                     value=\"";
#line 91 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(pageController.deviceConfig()->getString("webtunnel.password")) );
	responseStream << "\" \n";
	responseStream << "                     size=\"32\" \n";
	responseStream << "                     maxLength=\"32\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td colspan=\"2\" style=\"text-align: right\">\n";
	responseStream << "              <a href=\"#\" onclick=\"cancelUpdateDevice()\">Cancel</a>\n";
	responseStream << "              &nbsp;\n";
	responseStream << "              <input type=\"submit\" value=\"Save\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "        </tbody>\n";
	responseStream << "      </table>\n";
	responseStream << "    </div>\n";
	responseStream << "  </form>\n";
#line 107 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << " ";
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
	responseStream << " | &copy; 2015-2018 by <a href=\"https://www.appinf.com\">Applied Informatics</a>.\n";
	responseStream << "        </div>\n";
	responseStream << "      </div>\n";
	responseStream << "    </footer>\n";
	responseStream << "  </body>\n";
	responseStream << "</html>\n";
	// end include html/footer.inc
	responseStream << "\n";
	if (_compressResponse) _gzipStream.close();
}


} } // namespace MyDevices::Gateway
