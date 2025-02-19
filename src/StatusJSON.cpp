//
// StatusJSON.cpp
//
// This file has been generated from StatusJSON.cpsp on 2025-02-19 13:29:52.
//


#include "StatusJSON.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DeflatingStream.h"
#include "Utility.h"
#include "StatusJSONController.h"


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


StatusJSON::StatusJSON(DeviceManager::Ptr context):
	_context(context)
{
}


void StatusJSON::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html;charset=utf-8"s);
	bool _compressResponse(request.hasToken("Accept-Encoding"s, "gzip"s));
	if (_compressResponse) response.set("Content-Encoding"s, "gzip"s);

	Poco::Net::HTMLForm form(request, request.stream());
#line 11 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"

StatusJSONController ctrl(context(), request, form);
	std::ostream& _responseStream = response.send();
	Poco::DeflatingOutputStream _gzipStream(_responseStream, Poco::DeflatingStreamBuf::STREAM_GZIP, 1);
	std::ostream& responseStream = _compressResponse ? _gzipStream : _responseStream;
	responseStream << "\n";
	responseStream << "{\n";
#line 15 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"
 for (std::vector<std::string>::const_iterator it = ctrl.devices().begin(); it != ctrl.devices().end(); ++it) { 	responseStream << "\n";
#line 16 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"
	responseStream << ( it != ctrl.devices().begin() ? "," : "" );
	responseStream << "\n";
	responseStream << "  \"";
#line 17 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"
	responseStream << ( Utility::escape(*it) );
	responseStream << "\": \"";
#line 17 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"
	responseStream << ( ctrl.deviceStatus(*it) );
	responseStream << "\"\n";
#line 18 "/Users/guenter/ws/git/my-devices/gateway/src/StatusJSON.cpsp"
 } 	responseStream << "\n";
	responseStream << "}\n";
	if (_compressResponse) _gzipStream.close();
}


} } // namespace MyDevices::Gateway
