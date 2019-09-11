//
// IndexPage.cpp
//
// This file has been generated from IndexPage.cpsp on 2019-09-11 06:54:14.
//


#include "IndexPage.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"


#include "IndexPageController.h"
#include "Poco/Net/NameValueCollection.h"
#include "Utility.h"


namespace MyDevices {
namespace Gateway {


IndexPage::IndexPage(DeviceManager::Ptr context):
	_context(context)
{
}


void IndexPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
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
#line 8 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"

IndexPageController ctrl(context(), request, form);
if (response.sent()) return;

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
	responseStream << "function addDevice()\n";
	responseStream << "{\n";
	responseStream << "  document.actionForm.action.value = \"add\";\n";
	responseStream << "  document.actionForm.submit();\n";
	responseStream << "}\n";
	responseStream << "\n";
	responseStream << "function removeDevice(id, name)\n";
	responseStream << "{\n";
	responseStream << "  if (confirm('Delete device \"' + name + '\" (' + id + ')?\\n\\nThis action cannot be undone.'))\n";
	responseStream << "  {\n";
	responseStream << "    document.actionForm.target.value = id;\n";
	responseStream << "    document.actionForm.action.value = \"remove\";\n";
	responseStream << "    document.actionForm.submit();\n";
	responseStream << "  }\n";
	responseStream << "}\n";
	responseStream << "</script>\n";
	responseStream << "\n";
#line 35 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 if (!ctrl.message().empty()) { 	responseStream << "\n";
	responseStream << "  <div class=\"error\">\n";
	responseStream << "    ";
#line 37 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(ctrl.message()) );
	responseStream << "\n";
	responseStream << "  </div>\n";
#line 39 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 } 	responseStream << "\n";
	responseStream << "<form name=\"actionForm\" method=\"post\">\n";
	responseStream << "  <input type=\"hidden\" name=\"action\" value=\"\">\n";
	responseStream << "  <input type=\"hidden\" name=\"target\" value=\"\">\n";
	responseStream << "</form>\n";
	responseStream << "\n";
	responseStream << "<div class=\"groupbox\">\n";
	responseStream << "  <h2>Devices</h2>\n";
	responseStream << "\n";
	responseStream << "  <table class=\"list\">\n";
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
#line 61 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"

      bool even = false;
      	responseStream << "\n";
	responseStream << "      ";
#line 64 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 for (std::vector<std::string>::const_iterator it = ctrl.devices().begin(); it != ctrl.devices().end(); ++it) { 	responseStream << "\n";
	responseStream << "        ";
#line 65 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"

        Poco::AutoPtr<Poco::Util::AbstractConfiguration> pDeviceConfig = ctrl.deviceManager()->deviceConfiguration(*it);
        	responseStream << "\n";
	responseStream << "        <tr class=\"";
#line 68 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( even ? "even" : "odd" );
	responseStream << "\">\n";
	responseStream << "          <td>\n";
	responseStream << "            <a href=\"/device/";
#line 70 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( *it );
	responseStream << "\">\n";
	responseStream << "              ";
#line 71 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.deviceName", "")) );
	responseStream << "\n";
	responseStream << "            </a>\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 75 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.deviceId", "")) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 78 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.host", "")) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 81 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(pDeviceConfig->getString("webtunnel.ports", "")) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td>\n";
	responseStream << "            ";
#line 84 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( ctrl.deviceStatus(*it) );
	responseStream << "\n";
	responseStream << "          </td>\n";
	responseStream << "          <td class=\"deviceListButton\">\n";
	responseStream << "            <a href=\"#\" onclick=\"removeDevice('";
#line 87 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::escape(*it) );
	responseStream << "', '";
#line 87 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
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
#line 95 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"

        even = !even;
        	responseStream << "\n";
	responseStream << "      ";
#line 98 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
 } 	responseStream << " ";
	responseStream << "\n";
	responseStream << "      <tr class=\"";
#line 99 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( even ? "even" : "odd" );
	responseStream << "\">\n";
	responseStream << "        <td colspan=\"6\">\n";
	responseStream << "          <a href=\"#\" onclick=\"addDevice()\">\n";
	responseStream << "            <img class=\"button\"\n";
	responseStream << "                 src=\"/images/plusicon.png\"\n";
	responseStream << "                 srcset=\"/images/plusicon-x2.png 2x\"\n";
	responseStream << "                 title=\"Add Device\">\n";
	responseStream << "          </a>\n";
	responseStream << "        </td>\n";
	responseStream << "      </tr>\n";
	responseStream << "    </tbody>\n";
	responseStream << "  </table>\n";
	responseStream << "</div>\n";
	responseStream << "\n";
	responseStream << "<div class=\"groupbox\">\n";
	responseStream << "  <h2>System Settings</h2>\n";
	responseStream << "\n";
	responseStream << "  <table class=\"list\">\n";
	responseStream << "    <tbody>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <td>Reflector Server</td>\n";
	responseStream << "        <td>\n";
	responseStream << "          <a href=\"";
#line 121 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( ctrl.deviceManager()->config()->getString("webtunnel.reflectorURI", "") );
	responseStream << "\">\n";
	responseStream << "            ";
#line 122 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceManager()->config()->getString("webtunnel.reflectorURI", "")) );
	responseStream << "\n";
	responseStream << "          </a>\n";
	responseStream << "        </td>\n";
	responseStream << "      </tr>\n";
	responseStream << "      <tr>\n";
	responseStream << "        <td>Default Domain</td>\n";
	responseStream << "        <td>\n";
	responseStream << "          ";
#line 129 "/ws/git/my-devices/gateway/src/IndexPage.cpsp"
	responseStream << ( U::htmlize(ctrl.deviceManager()->config()->getString("webtunnel.domain", "")) );
	responseStream << "\n";
	responseStream << "        </td>\n";
	responseStream << "      </tr>\n";
	responseStream << "    </tbody>\n";
	responseStream << "  </table>\n";
	responseStream << "</div>\n";
	responseStream << "\n";
	responseStream << "<script>\n";
	responseStream << "\tsetTimeout(function() {\n";
	responseStream << "\t\tlocation.reload()\n";
	responseStream << "\t}, 10000);\n";
	responseStream << "</script>\n";
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
