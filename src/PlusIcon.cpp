//
// PlusIcon.cpp
//
// This file has been generated from PlusIcon.cpsp on 2020-08-12 06:42:46.
//


#include "PlusIcon.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/Users/guenter/ws/git/my-devices/gateway/src/PlusIcon.cpsp"


// res/PlusIcon.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x08, 0x03, 0x00, 0x00, 0x00, 0xBA, 0x57, 0xED, 0x3F, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x00, 0x30, 0x50, 0x4C, 0x54, 0x45, 0xED, 0xF7, 0xFC, 0x0C, 0x88, 0xCB, 0xB2, 
	0xD9, 0xEE, 0x09, 0x87, 0xCA, 0x04, 0x85, 0xC9, 0x14, 0x8C, 0xCC, 0x24, 0x94, 0xD0, 0x18, 0x8D, 0xCC, 
	0x5C, 0xB2, 0xDE, 0x9F, 0xD0, 0xEB, 0xD1, 0xEA, 0xF6, 0x08, 0x86, 0xCA, 0x00, 0x7B, 0xC5, 0x00, 0x80, 
	0xC8, 0x0F, 0x8B, 0xCC, 0x43, 0xA5, 0xD7, 0x1C, 0xC2, 0xC5, 0xEE, 0x00, 0x00, 0x00, 0x73, 0x49, 0x44, 
	0x41, 0x54, 0x78, 0xDA, 0x94, 0xD1, 0xC1, 0x0E, 0xC3, 0x20, 0x0C, 0x03, 0x50, 0x83, 0x03, 0x19, 0x4D, 
	0x81, 0xFF, 0xFF, 0xDB, 0x06, 0xAD, 0xE5, 0x50, 0xAA, 0x6A, 0xF3, 0x21, 0x89, 0xDE, 0x09, 0x19, 0x64, 
	0x5D, 0x92, 0x91, 0xC2, 0x92, 0x04, 0xBD, 0x4E, 0x91, 0xEB, 0xD2, 0x89, 0xD6, 0x3F, 0x89, 0x77, 0xAC, 
	0x11, 0x59, 0x16, 0x2C, 0xBF, 0x20, 0x69, 0x36, 0xB0, 0x92, 0x9C, 0xD8, 0x3C, 0xE2, 0x48, 0xDF, 0x27, 
	0x9A, 0xC6, 0xCD, 0x03, 0x8C, 0xB9, 0x75, 0xF9, 0x62, 0x2A, 0xD1, 0x03, 0x8C, 0x19, 0x4F, 0x0C, 0xAC, 
	0x9E, 0xBD, 0x40, 0xC7, 0x96, 0xFF, 0x9F, 0xF4, 0x8A, 0x76, 0xC7, 0x96, 0x7B, 0x5B, 0x0A, 0x09, 0x14, 
	0xCE, 0xEA, 0x1E, 0x4B, 0x7E, 0xFA, 0x8E, 0x43, 0x80, 0x01, 0x00, 0x15, 0x4C, 0x06, 0x35, 0xE1, 0xF0, 
	0x01, 0x5E, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};


static bool checkModified(Poco::Net::HTTPServerRequest& request)
{
	Poco::DateTime modified(2018, 3, 9, 11, 48, 5);
	request.response().setChunkedTransferEncoding(false);
	request.response().set("Last-Modified", Poco::DateTimeFormatter::format(modified, Poco::DateTimeFormat::HTTP_FORMAT));
	if (request.has("If-Modified-Since"))
	{
		Poco::DateTime modifiedSince;
		int tzd;
		Poco::DateTimeParser::parse(request.get("If-Modified-Since"), modifiedSince, tzd);
		if (modified <= modifiedSince)
		{
			request.response().setContentLength(0);
			request.response().setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_MODIFIED);
			request.response().send();
			return false;
		}
	}
	request.response().setContentLength(static_cast<int>(sizeof(data)));
	return true;
}


namespace MyDevices {
namespace Gateway {


void PlusIcon::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 53 "/Users/guenter/ws/git/my-devices/gateway/src/PlusIcon.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
