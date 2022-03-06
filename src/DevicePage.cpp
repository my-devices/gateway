//
// DevicePage.cpp
//
// This file has been generated from DevicePage.cpsp on 2022-03-06 10:00:36.
//


#include "DevicePage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"
#include "DevicePageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


DevicePage::DevicePage(DeviceManager::Ptr context):
	_context(context)
{
}


void DevicePage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8"s);
	bool _compressResponse(request.hasToken("Accept-Encoding"s, "gzip"s));
	if (_compressResponse) response.set("Content-Encoding"s, "gzip"s);

	Poco::Net::HTMLForm form(request, request.stream());
#line 4 "/Users/guenter/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
#line 13 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"

DevicePageController ctrl(context(), request, form);
if (response.sent()) return;
if (ctrl.mustRedirect()) return;

if (ctrl.deviceConfig())
{
	pageTemplate.set("title", "Gateway > " + ctrl.name());
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
	responseStream << "<script language=\"JavaScript\">\n";
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
#line 44 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
#line 55 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 57 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 59 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << "\n";
#line 61 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (ctrl.deviceConfig()) { 	responseStream << "\n";
	responseStream << "  <div class=\"groupbox\">\n";
	responseStream << "    <h2>Device Properties</h2>\n";
	responseStream << "\n";
	responseStream << "    <form name=\"actionForm\" method=\"post\" autocomplete=\"off\">\n";
	responseStream << "      <input type=\"hidden\" name=\"action\" value=\"update\">\n";
	responseStream << "      <input type=\"hidden\" name=\"csrfToken\" value=\"";
#line 67 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.csrfToken() );
	responseStream << "\">\n";
	responseStream << "      <input type=\"hidden\" name=\"target\" value=\"";
#line 68 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.deviceId() );
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
#line 81 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.name()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">ID</td>\n";
	responseStream << "            <td>";
#line 89 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceId()) );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Domain</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"domain\"\n";
	responseStream << "                     value=\"";
#line 96 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.domain()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>Device Password</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"password\"\n";
	responseStream << "                     name=\"password\"\n";
	responseStream << "                     value=\"";
#line 107 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.password()) );
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
#line 116 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.deviceStatus() );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"intermediateHeader\">\n";
	responseStream << "            <th colspan=\"2\">\n";
	responseStream << "              Device Address and Forwarded Ports\n";
	responseStream << "            </th>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">Device IP Address or Domain Name</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"host\"\n";
	responseStream << "                     value=\"";
#line 128 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.host()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">HTTP Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"httpPort\"\n";
	responseStream << "                     value=\"";
#line 139 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.httpPort()) );
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
#line 148 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.httpsEnable() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              <label for=\"httpsRequired\">Requires HTTPS</label>\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">SSH Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"sshPort\"\n";
	responseStream << "                     value=\"";
#line 158 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.sshPort()) );
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
	responseStream << "            <td class=\"basicProperty\">VNC Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"vncPort\"\n";
	responseStream << "                     value=\"";
#line 172 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.vncPort()) );
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
	responseStream << "            <td class=\"basicProperty\">RDP Server Port</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"rdpPort\"\n";
	responseStream << "                     value=\"";
#line 186 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.rdpPort()) );
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
	responseStream << "            <td>Additional Forwarded TCP Ports</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"ports\"\n";
	responseStream << "                     value=\"";
#line 200 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.extraPorts() );
	responseStream << "\"\n";
	responseStream << "                     size=\"40\"\n";
	responseStream << "                     maxLength=\"40\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              (comma-separated)\n";
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
	responseStream << "    </form>\n";
	responseStream << "  </div>\n";
#line 218 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
	responseStream << " | &copy; 2015-2022 by <a href=\"https://macchina.io\">Applied Informatics GmbH</a>\n";
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
