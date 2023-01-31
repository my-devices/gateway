//
// DevicePage.cpp
//
// This file has been generated from DevicePage.cpsp on 2023-01-31 11:25:56.
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
#line 46 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
#line 57 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 59 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 61 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 } 	responseStream << "\n";
#line 63 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
 if (ctrl.deviceConfig()) { 	responseStream << "\n";
	responseStream << "  <div class=\"groupbox\">\n";
	responseStream << "    <h2>Device Properties</h2>\n";
	responseStream << "\n";
	responseStream << "    <form name=\"actionForm\" method=\"post\" accept-charset=\"utf-8\" autocomplete=\"off\">\n";
	responseStream << "      <input type=\"hidden\" name=\"action\" value=\"update\">\n";
	responseStream << "      <input type=\"hidden\" name=\"csrfToken\" value=\"";
#line 69 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.csrfToken() );
	responseStream << "\">\n";
	responseStream << "      <input type=\"hidden\" name=\"target\" value=\"";
#line 70 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <label for=\"deviceNameInput\">Name</label></td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     id=\"deviceNameInput\"\n";
	responseStream << "                     name=\"deviceName\"\n";
	responseStream << "                     value=\"";
#line 85 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.name()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\"\n";
	responseStream << "                     autofocus>\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">ID</td>\n";
	responseStream << "            <td>";
#line 94 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceId()) );
	responseStream << "</td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <label for=\"deviceDomainInput\">Domain</label>\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     id=\"deviceDomainInput\"\n";
	responseStream << "                     name=\"deviceDomain\"\n";
	responseStream << "                     value=\"";
#line 104 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.domain()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td>\n";
	responseStream << "              <label for=\"devicePasswordInput\">Device Password</label>\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"password\"\n";
	responseStream << "                     id=\"devicePasswordInput\"\n";
	responseStream << "                     name=\"devicePassword\"\n";
	responseStream << "                     value=\"";
#line 118 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
#line 127 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
#line 139 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.host()) );
	responseStream << "\"\n";
	responseStream << "                     size=\"64\"\n";
	responseStream << "                     maxLength=\"64\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"httpPortEnabled\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 150 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.httpPortEnabled() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              HTTP Server Port\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"httpPort\"\n";
	responseStream << "                     value=\"";
#line 157 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.httpPort()) );
	responseStream << "\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     placeholder=\"80\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     id=\"httpsRequired\"\n";
	responseStream << "                     name=\"httpsRequired\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 166 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.httpsEnable() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              <label for=\"httpsRequired\">requires HTTPS</label>\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"sshPortEnabled\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 176 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.sshPortEnabled() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              SSH Server Port\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"sshPort\"\n";
	responseStream << "                     value=\"";
#line 183 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.sshPort()) );
	responseStream << "\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     placeholder=\"22\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"vncPortEnabled\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 195 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.vncPortEnabled() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              VNC Server Port\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"vncPort\"\n";
	responseStream << "                     value=\"";
#line 202 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.vncPort()) );
	responseStream << "\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     placeholder=\"5900\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"rdpPortEnabled\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 214 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.rdpPortEnabled() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              RDP Server Port\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"rdpPort\"\n";
	responseStream << "                     value=\"";
#line 221 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.rdpPort()) );
	responseStream << "\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     placeholder=\"3389\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"odd\">\n";
	responseStream << "            <td class=\"basicProperty\">\n";
	responseStream << "              <input type=\"checkbox\"\n";
	responseStream << "                     name=\"appPortEnabled\"\n";
	responseStream << "                     value=\"true\"\n";
	responseStream << "                     ";
#line 233 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( ctrl.appPortEnabled() ? "checked" : "" );
	responseStream << "\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "              Application Server Port\n";
	responseStream << "            </td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"number\"\n";
	responseStream << "                     name=\"appPort\"\n";
	responseStream << "                     value=\"";
#line 240 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
	responseStream << ( U::htmlize(ctrl.appPort()) );
	responseStream << "\"\n";
	responseStream << "                     min=\"1\"\n";
	responseStream << "                     max=\"65535\"\n";
	responseStream << "                     class=\"form-control\">\n";
	responseStream << "            </td>\n";
	responseStream << "          </tr>\n";
	responseStream << "          <tr class=\"even\">\n";
	responseStream << "            <td>Additional Forwarded TCP Ports</td>\n";
	responseStream << "            <td>\n";
	responseStream << "              <input type=\"text\"\n";
	responseStream << "                     name=\"ports\"\n";
	responseStream << "                     value=\"";
#line 251 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
#line 269 "/Users/guenter/ws/git/my-devices/gateway/src/DevicePage.cpsp"
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
	responseStream << " | &copy; 2015-2023 by <a href=\"https://macchina.io\">Applied Informatics GmbH</a>\n";
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
