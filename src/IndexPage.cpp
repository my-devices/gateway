//
// IndexPage.cpp
//
// This file has been generated from IndexPage.cpsp on 2025-02-19 13:29:53.
//


#include "IndexPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"
#include "IndexPageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


IndexPage::IndexPage(DeviceManager::Ptr context):
	_context(context)
{
}


void IndexPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8"s);
	bool _compressResponse(request.hasToken("Accept-Encoding"s, "gzip"s));
	if (_compressResponse) response.set("Content-Encoding"s, "gzip"s);

	Poco::Net::HTMLForm form(request, request.stream());
#line 4 "/Users/guenter/ws/git/my-devices/gateway/html/template.inc"

	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion"s, Utility::versionString());
#line 12 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"

IndexPageController ctrl(context(), request, form);
if (response.sent()) return;
if (ctrl.mustRedirect()) return;

pageTemplate.set("title"s, "Gateway"s);
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
	responseStream << "function addDevice()\n";
	responseStream << "{\n";
	responseStream << "  document.actionForm.action.value = \"add\";\n";
	responseStream << "  document.actionForm.submit();\n";
	responseStream << "}\n";
	responseStream << "\n";
	responseStream << "function removeDevice(id, name)\n";
	responseStream << "{\n";
	responseStream << "  if (confirm('Delete device \"' + name + '\" (' + id + ')?\\n\\nThis action cannot be undone.\\n\\nPlease note that the corresponding device on the macchina.io REMOTE server will not be deleted.'))\n";
	responseStream << "  {\n";
	responseStream << "    document.actionForm.target.value = id;\n";
	responseStream << "    document.actionForm.action.value = \"remove\";\n";
	responseStream << "    document.actionForm.submit();\n";
	responseStream << "  }\n";
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
#line 46 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
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
#line 57 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 59 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 61 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "<form name=\"actionForm\" method=\"post\">\n";
	responseStream << "  <input type=\"hidden\" name=\"action\" value=\"\">\n";
	responseStream << "  <input type=\"hidden\" name=\"target\" value=\"\">\n";
	responseStream << "  <input type=\"hidden\" name=\"csrfToken\" value=\"";
#line 66 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( ctrl.csrfToken() );
	responseStream << "\">\n";
	responseStream << "</form>\n";
	responseStream << "\n";
	responseStream << "<div class=\"groupbox\">\n";
	responseStream << "  <h2>Local Devices</h2>\n";
	responseStream << "\n";
	responseStream << "  <table class=\"list\" style=\"width: 100%\">\n";
	responseStream << "    <thead>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <th>Name</th>\n";
	responseStream << "        <th>ID</th>\n";
	responseStream << "        <th>Host</th>\n";
	responseStream << "        <th>Ports</th>\n";
	responseStream << "        <th>Status</th>\n";
	responseStream << "        <th></th>\n";
	responseStream << "      </tr>\n";
	responseStream << "    </thead>\n";
	responseStream << "    <tbody>\n";
	responseStream << "      ";
#line 84 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"

      bool even = false;
      	responseStream << "\n";
	responseStream << "      ";
#line 87 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 for (std::vector<std::string>::const_iterator it = ctrl.devices().begin(); it != ctrl.devices().end(); ++it) { 	responseStream << "\n";
	responseStream << "        ";
#line 88 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"

        Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = ctrl.deviceManager()->deviceConfiguration(*it);
        	responseStream << "\n";
	responseStream << "        <tr class=\"";
#line 91 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( even ? "even" : "odd" );
	responseStream << "\">\n";
	responseStream << "          <td>\n";
	responseStream << "            <a href=\"/device/";
#line 93 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( *it );
	responseStream << "\">\n";
	responseStream << "              <span class=\"deviceName\">";
#line 94 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.deviceName", "")) );
	responseStream << "</span>\n";
	responseStream << "            </a>\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 98 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.deviceId", "")) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 101 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.host", "")) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 104 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( ctrl.formatPorts(pDeviceConfig) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td id=\"";
#line 106 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( *it );
	responseStream << "\">\n";
	responseStream << "            ";
#line 107 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( ctrl.deviceStatus(*it) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td class=\"deviceListButton\">\n";
	responseStream << "            <a href=\"#\" onclick=\"removeDevice('";
#line 110 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::escape(*it) );
	responseStream << "', '";
#line 110 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::escape(pDeviceConfig->getString("webtunnel.deviceName", "")) );
	responseStream << "')\">\n";
	responseStream << "              <img class=\"button\"\n";
	responseStream << "                   src=\"/images/minusicon.png\"\n";
	responseStream << "                   srcset=\"/images/minusicon-x2.png 2x\"\n";
	responseStream << "                   title=\"Remove Device\">\n";
	responseStream << "            </a>\n";
	responseStream << "          </td>\n";
	responseStream << "        </tr>\n";
	responseStream << "        ";
#line 118 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"

        even = !even;
        	responseStream << "\n";
	responseStream << "      ";
#line 121 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 } 	responseStream << " ";
	responseStream << "\n";
	responseStream << "      <tr class=\"";
#line 122 "/Users/guenter/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( even ? "even" : "odd" );
	responseStream << "\">\n";
	responseStream << "        <td colspan=\"6\">\n";
	responseStream << "          <a href=\"#\" onclick=\"addDevice()\">\n";
	responseStream << "            <img class=\"button\"\n";
	responseStream << "                 src=\"/images/plusicon.png\"\n";
	responseStream << "                 srcset=\"/images/plusicon-x2.png 2x\"\n";
	responseStream << "                 title=\"Create Device\">\n";
	responseStream << "          </a>\n";
	responseStream << "        </td>\n";
	responseStream << "      </tr>\n";
	responseStream << "    </tbody>\n";
	responseStream << "  </table>\n";
	responseStream << "</div>\n";
	responseStream << "\n";
	responseStream << "<script src=\"/js/ajaxcore.js\"></script>\n";
	responseStream << "<script>\n";
	responseStream << "\tAjaxCore.PeriodicUpdater.start('/status.json', 2500);\n";
	responseStream << "</script>\n";
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
	responseStream << " | &copy; 2015-2025 by <a href=\"https://macchina.io\">Applied Informatics GmbH</a>\n";
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
