//
// MinusIcon.cpp
//
// This file has been generated from MinusIcon.cpsp on 2019-09-10 18:07:13.
//


#include "MinusIcon.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/ws/git/my-devices/gateway/src/MinusIcon.cpsp"


// res/MinusIcon.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x08, 0x03, 0x00, 0x00, 0x00, 0xBA, 0x57, 0xED, 0x3F, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x00, 0x30, 0x50, 0x4C, 0x54, 0x45, 0xDE, 0x56, 0x16, 0xFB, 0xE9, 0xE5, 0xDD, 
	0x54, 0x14, 0xEF, 0xB1, 0x95, 0xDF, 0x5D, 0x21, 0xDC, 0x4C, 0x08, 0xDE, 0x55, 0x16, 0xE0, 0x64, 0x2C, 
	0xDF, 0x5B, 0x1D, 0xDD, 0x55, 0x15, 0xDE, 0x55, 0x15, 0xDD, 0x51, 0x0F, 0xDD, 0x52, 0x11, 0xDD, 0x55, 
	0x16, 0xDD, 0x56, 0x16, 0xE8, 0x8A, 0x5F, 0xD3, 0x85, 0xB1, 0x94, 0x00, 0x00, 0x00, 0xB2, 0x49, 0x44, 
	0x41, 0x54, 0x78, 0xDA, 0x6C, 0x51, 0xDB, 0x16, 0x83, 0x20, 0x0C, 0xCB, 0x94, 0x55, 0x22, 0xD2, 0xFD, 
	0xFF, 0xDF, 0x2E, 0xA9, 0x97, 0x97, 0x2D, 0x1E, 0xA1, 0xB4, 0xE9, 0x85, 0x80, 0xAD, 0xFD, 0x60, 0x43, 
	0x0F, 0x80, 0x09, 0x0A, 0x20, 0x04, 0xB2, 0xA3, 0x05, 0x0A, 0x8E, 0x71, 0xB7, 0x11, 0x0D, 0xED, 0x3C, 
	0xB2, 0x7E, 0xD9, 0xDA, 0xE4, 0x64, 0x38, 0xCF, 0x9C, 0xF4, 0xA2, 0x52, 0x76, 0xBA, 0x20, 0x32, 0x95, 
	0xB0, 0x73, 0x4E, 0x71, 0x9C, 0xAE, 0x60, 0x9C, 0xA9, 0x85, 0x1D, 0x55, 0x93, 0x91, 0xD5, 0x55, 0x91, 
	0x60, 0x66, 0xD5, 0x44, 0x8C, 0xF7, 0x03, 0xFB, 0xCD, 0xCC, 0xF1, 0x59, 0x1F, 0xC4, 0x82, 0x6A, 0x14, 
	0xEF, 0xF5, 0xF5, 0xA0, 0x9F, 0x4E, 0x70, 0x69, 0xDB, 0x8D, 0x36, 0x34, 0x48, 0x39, 0x71, 0x0C, 0x7F, 
	0xC6, 0xA1, 0x29, 0x5C, 0xD3, 0xE3, 0xD0, 0x8B, 0x6E, 0x83, 0xA9, 0x6D, 0x9E, 0x73, 0x5E, 0x37, 0x2F, 
	0x41, 0x24, 0x40, 0x8D, 0x54, 0xDA, 0x20, 0xA7, 0x53, 0xA7, 0xAC, 0x9B, 0x69, 0x02, 0xAD, 0x86, 0xAE, 
	0x6A, 0x66, 0x69, 0xA9, 0x73, 0x96, 0x52, 0x62, 0xA8, 0x51, 0xBF, 0xD2, 0x4B, 0x4A, 0x87, 0x2D, 0xF2, 
	0xBF, 0xE7, 0xF8, 0x0A, 0x30, 0x00, 0x72, 0xB7, 0x08, 0x07, 0xE7, 0x95, 0x54, 0xBE, 0x00, 0x00, 0x00, 
	0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
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


void MinusIcon::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 57 "/ws/git/my-devices/gateway/src/MinusIcon.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
