//
// DevicePage.cpp
//
// This file has been generated from DevicePage.cpsp on 2019-09-10 18:07:16.
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
#line 4 "/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
#line 8 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"

DevicePageController ctrl(context(), request, form);
if (response.sent()) return;

if (ctrl.deviceConfig())
{
	pageTemplate.set("title", "Gateway > " + ctrl.deviceConfig()->getString("webtunnel.deviceName"));
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
#line 5 "/ws/git/my-devices/gateway/html/header.inc"
	responseStream << ( U::htmlize(pageTemplate["title"]) );
	responseStream << "</title>\n";
	responseStream << "    <link rel=\"stylesheet\" href=\"/css/styles.css\" type=\"text/css\"/>\n";
	responseStream << "    <link rel=\"icon\" href=\"/images/favicon.ico\">\n";
	responseStream << "  </head>\n";
	responseStream << "  <body lang=\"en\">\n";
	responseStream << "    <header>\n";
	responseStream << "      <div class=\"headercontainer\">\n";
	responseStream << "        <div class=\"header\">\n";
	responseStream << "\t\t  <h1>Remote Manager ";
#line 13 "/ws/git/my-devices/gateway/html/header.inc"
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
#line 32 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 34 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 36 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << "\n";
#line 38 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (ctrl.deviceConfig()) { 	responseStream << "\n";
	responseStream << "  <div class=\"groupbox\">\n";
	responseStream << "    <h2>Device Properties</h2>\n";
	responseStream << "\n";
	responseStream << "    <form name=\"actionForm\" method=\"post\" action=\"/\">\n";
	responseStream << "      <input type=\"hidden\" name=\"action\" value=\"update\">\n";
	responseStream << "      <input type=\"hidden\" name=\"target\" value=\"";
#line 44 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.deviceConfig()->getString("webtunnel.deviceId") );
	responseStream << "\">\n";
	responseStream << "      <table class=\"list\">\n";
	responseStream << "        <tbody>\n";
	responseStream << "          <tr class=\"intermediateHeader\">\n";
	responseStream << "            <th colspan=\"2\">\n";
	responseStream << "              Basic Properties\n";
	responseStream << "            </th>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Name</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"deviceName\"\n";
	responseStream << "                     value=\"";
#line 57 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.deviceName")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">ID</td>\n";
	responseStream << "            <td>";
#line 65 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.deviceId")) );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Domain</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"domain\"\n";
	responseStream << "                     value=\"";
#line 72 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.domain", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\"\n";
	responseStream << "                     >\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>Device Password</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"password\"\n";
	responseStream << "                     name=\"password\"\n";
	responseStream << "                     value=\"";
#line 84 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.password", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"32\"\n";
	responseStream << "                     maxLength=\"32\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (optional)\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td>Status</td>\n";
	responseStream << "            <td>";
#line 93 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.deviceStatus() );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"intermediateHeader\">\n";
	responseStream << "            <th colspan=\"2\">\n";
	responseStream << "              Device Address and Ports\n";
	responseStream << "            </th>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Device IP Address or Domain Name</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"host\"\n";
	responseStream << "                     value=\"";
#line 105 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.host", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">Forwarded TCP Ports</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"ports\"\n";
	responseStream << "                     value=\"";
#line 116 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.ports", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"40\"\n";
	responseStream << "                     maxLength=\"40\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (comma-separated)\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Device HTTP Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"httpPort\"\n";
	responseStream << "                     value=\"";
#line 128 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.httpPort", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"5\"\n";
	responseStream << "                     maxLength=\"5\"\n";
	responseStream << "                     min=\"0\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"httpsRequired\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 137 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.deviceConfig()->getBool("webtunnel.httpsRequired", false) ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              <label for=\"httpsRequired\">Requires HTTPS</label>\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>Device SSH Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"sshPort\"\n";
	responseStream << "                     value=\"";
#line 147 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.sshPort", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"5\"\n";
	responseStream << "                     maxLength=\"5\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (optional)\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td>Device VNC Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"vncPort\"\n";
	responseStream << "                     value=\"";
#line 161 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.vncPort", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"5\"\n";
	responseStream << "                     maxLength=\"5\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (optional)\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>Device RDP Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"rdpPort\"\n";
	responseStream << "                     value=\"";
#line 175 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceConfig()->getString("webtunnel.rdpPort", "")) );
	responseStream << "\"\n";
	responseStream << "                     size=\"5\"\n";
	responseStream << "                     maxLength=\"5\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (optional)\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr>\n";
	responseStream << "            <td colspan=\"2\" style=\"text-align: right\">\n";
	responseStream << "              <a href=\"#\" onclick=\"cancelUpdateDevice()\">Cancel</a>\n";
	responseStream << "              &nbsp;\n";
	responseStream << "              <input type=\"submit\" value=\"Save\" class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "        </tbody>\n";
	responseStream << "      </table>\n";
	responseStream << "    </div>\n";
	responseStream << "  </form>\n";
#line 195 "/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << " ";
	responseStream << "\n";
	// begin include html/footer.inc
	responseStream << "      </div>\n";
	responseStream << "    </div>\n";
	responseStream << "    <footer>\n";
	responseStream << "      <div class=\"footercontainer\">\n";
	responseStream << "        <div class=\"footer\">\n";
	responseStream << "          ";
#line 6 "/ws/git/my-devices/gateway/html/footer.inc"
	responseStream << ( pageTemplate["softwareVersion"] );
	responseStream << " | &copy; 2015-2019 by <a href=\"https://macchina.io\">Applied Informatics GmbH</a>.\n";
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
