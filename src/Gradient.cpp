//
// Gradient.cpp
//
// This file has been generated from Gradient.cpsp on 2018-09-21 07:59:29.
//


#include "Gradient.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/ws/git/my-devices/gateway/src/Gradient.cpsp"


// res/Gradient.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x04, 0x00, 0x08, 0x03, 0x00, 0x00, 0x00, 0xDF, 0xB4, 0x29, 0xDB, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x00, 0x6C, 0x50, 0x4C, 0x54, 0x45, 0xED, 0xED, 0xED, 0xEC, 0xEC, 0xEC, 0xCC, 
	0xCC, 0xCC, 0xCE, 0xCE, 0xCE, 0xCB, 0xCB, 0xCB, 0xCD, 0xCD, 0xCD, 0xEA, 0xEA, 0xEA, 0xE8, 0xE8, 0xE8, 
	0xEB, 0xEB, 0xEB, 0xD0, 0xD0, 0xD0, 0xE9, 0xE9, 0xE9, 0xD4, 0xD4, 0xD4, 0xD1, 0xD1, 0xD1, 0xE4, 0xE4, 
	0xE4, 0xE5, 0xE5, 0xE5, 0xCF, 0xCF, 0xCF, 0xDF, 0xDF, 0xDF, 0xD2, 0xD2, 0xD2, 0xD7, 0xD7, 0xD7, 0xD3, 
	0xD3, 0xD3, 0xE2, 0xE2, 0xE2, 0xDC, 0xDC, 0xDC, 0xE6, 0xE6, 0xE6, 0xDB, 0xDB, 0xDB, 0xDD, 0xDD, 0xDD, 
	0xE0, 0xE0, 0xE0, 0xE7, 0xE7, 0xE7, 0xD5, 0xD5, 0xD5, 0xE1, 0xE1, 0xE1, 0xD6, 0xD6, 0xD6, 0xD9, 0xD9, 
	0xD9, 0xDA, 0xDA, 0xDA, 0xE3, 0xE3, 0xE3, 0xD8, 0xD8, 0xD8, 0xDE, 0xDE, 0xDE, 0xEE, 0xEE, 0xEE, 0x68, 
	0xAF, 0x3B, 0xAF, 0x00, 0x00, 0x01, 0x65, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xEC, 0xCF, 0xC7, 0x7A, 
	0xC3, 0x30, 0x0C, 0x03, 0xE0, 0x74, 0xA6, 0xBB, 0xE9, 0xDE, 0x4D, 0xC7, 0xFB, 0xBF, 0x63, 0xAF, 0x0D, 
	0x78, 0x80, 0x4D, 0x93, 0x92, 0x2C, 0x03, 0xC7, 0xFF, 0x13, 0x41, 0x6A, 0xF5, 0x0B, 0x59, 0x19, 0x30, 
	0xE1, 0x2F, 0x2A, 0x25, 0xE5, 0xB0, 0x66, 0x7F, 0xAB, 0xC4, 0x67, 0x0F, 0x92, 0x53, 0x1A, 0xB1, 0xC5, 
	0x51, 0xCA, 0x47, 0x04, 0x82, 0x51, 0x70, 0x02, 0xB1, 0xC0, 0x47, 0x1C, 0x5B, 0x52, 0xEE, 0x10, 0x4C, 
	0x86, 0x63, 0x48, 0x4E, 0xA9, 0x03, 0x1C, 0xA5, 0x29, 0x77, 0x08, 0x26, 0xC3, 0x19, 0x24, 0x64, 0xA4, 
	0x4C, 0xA9, 0x03, 0x52, 0x4A, 0x97, 0x05, 0x6B, 0x48, 0x48, 0x87, 0x40, 0xF0, 0x0F, 0x5E, 0x21, 0x03, 
	0x5E, 0x08, 0x76, 0xE1, 0x11, 0x62, 0xC1, 0xD1, 0x51, 0xE6, 0x30, 0xC1, 0x64, 0xB8, 0x82, 0x58, 0x70, 
	0x8C, 0xA4, 0x74, 0x08, 0xC6, 0xC2, 0x25, 0xC4, 0x42, 0x44, 0x87, 0xA0, 0x00, 0x7C, 0x41, 0x0A, 0xBD, 
	0x10, 0x10, 0xB8, 0x87, 0x58, 0x70, 0x8C, 0x08, 0x0A, 0xC0, 0x3B, 0x24, 0x07, 0x2A, 0xAD, 0x6D, 0x05, 
	0x5E, 0x20, 0x16, 0x1C, 0x23, 0xBC, 0x23, 0xA2, 0xB4, 0x27, 0xD8, 0x40, 0x72, 0x4A, 0x05, 0x35, 0xE0, 
	0x07, 0x12, 0xD2, 0xB1, 0x2C, 0x78, 0x86, 0x84, 0x74, 0xF0, 0x52, 0x3E, 0x22, 0x20, 0xF0, 0x00, 0xF1, 
	0x8C, 0x08, 0x08, 0x3C, 0x41, 0x72, 0x5E, 0x38, 0xEE, 0xE0, 0x90, 0x52, 0xDA, 0x35, 0x6C, 0x21, 0x16, 
	0xCA, 0x8C, 0x74, 0x0D, 0x9F, 0x90, 0x90, 0x0E, 0x5E, 0xCA, 0x47, 0x04, 0x04, 0xBE, 0x21, 0xB5, 0xA0, 
	0xD9, 0xC3, 0xCA, 0xC0, 0x2D, 0x44, 0xD0, 0x06, 0x7C, 0x40, 0x2C, 0x38, 0x3A, 0x1C, 0x5B, 0x04, 0x63, 
	0xE1, 0x0D, 0x22, 0xA8, 0x02, 0xE7, 0x90, 0x01, 0x2F, 0x04, 0x4D, 0xC0, 0x1D, 0xC4, 0xF3, 0x82, 0x8F, 
	0x38, 0xB6, 0xF4, 0x04, 0x37, 0x90, 0x39, 0x5F, 0x6A, 0x5E, 0x08, 0x08, 0x5C, 0x40, 0x72, 0x4A, 0x23, 
	0xB6, 0xF0, 0xD2, 0x85, 0xC3, 0x29, 0x24, 0xA7, 0x94, 0x6F, 0x71, 0xDC, 0xC1, 0xB7, 0x44, 0x40, 0xA5, 
	0xB5, 0x0B, 0x87, 0x6B, 0xC8, 0x80, 0x17, 0x82, 0x5D, 0x38, 0x80, 0xCC, 0x68, 0x8B, 0x29, 0xE5, 0x10, 
	0xD1, 0x21, 0xE8, 0x17, 0x8E, 0x20, 0x1E, 0x98, 0x4F, 0xA9, 0xA0, 0x09, 0xD8, 0x87, 0x84, 0x00, 0xDF, 
	0x52, 0xE6, 0x0E, 0xC1, 0x5C, 0xE1, 0x10, 0x92, 0xF3, 0xC2, 0x71, 0x07, 0x07, 0x47, 0x47, 0xCA, 0x1D, 
	0x82, 0x5E, 0xE0, 0x4F, 0x80, 0x01, 0x00, 0xAB, 0xFE, 0xB8, 0x8E, 0x11, 0xEA, 0x25, 0xBC, 0x00, 0x00, 
	0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
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


void Gradient::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 71 "/ws/git/my-devices/gateway/src/Gradient.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
