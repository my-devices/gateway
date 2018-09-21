//
// FooterLogo.cpp
//
// This file has been generated from FooterLogo.cpsp on 2018-09-21 07:59:28.
//


#include "FooterLogo.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/ws/git/my-devices/gateway/src/FooterLogo.cpsp"


// res/FooterLogo.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x28, 0x08, 0x03, 0x00, 0x00, 0x00, 0x36, 0x4D, 0x0F, 0x0B, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x00, 0x60, 0x50, 0x4C, 0x54, 0x45, 0xA3, 0xA5, 0xA7, 0xC7, 0xC8, 0xC9, 0x85, 
	0x84, 0x85, 0xB6, 0xB8, 0xB9, 0x72, 0x6F, 0x70, 0x44, 0x40, 0x41, 0xEB, 0xEB, 0xEB, 0xE4, 0xE4, 0xE5, 
	0xDA, 0xDA, 0xDB, 0xD3, 0xD4, 0xD4, 0xA8, 0xAA, 0xAC, 0x40, 0x3C, 0x3D, 0x5A, 0x57, 0x58, 0xA6, 0xA8, 
	0xAA, 0x4D, 0x4A, 0x4A, 0xA4, 0xA6, 0xA8, 0xAC, 0xAE, 0xB0, 0x3E, 0x3A, 0x3B, 0xC0, 0xC1, 0xC2, 0xB0, 
	0xB2, 0xB3, 0x43, 0x3E, 0x3F, 0xDF, 0xDF, 0xE0, 0x50, 0x4D, 0x4E, 0x97, 0x96, 0x97, 0xCC, 0xCC, 0xCD, 
	0xD0, 0xD0, 0xD0, 0x5F, 0x5D, 0x5E, 0xA2, 0xA4, 0xA6, 0x63, 0x61, 0x62, 0xA3, 0xA1, 0xA1, 0xA5, 0xA4, 
	0xA4, 0xEE, 0xEE, 0xEE, 0x98, 0x32, 0x76, 0xF7, 0x00, 0x00, 0x00, 0x20, 0x74, 0x52, 0x4E, 0x53, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x5C, 0x5C, 0x1B, 
	0xED, 0x00, 0x00, 0x01, 0x42, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xEC, 0xD5, 0x6B, 0x76, 0x83, 0x20, 
	0x10, 0x05, 0x60, 0xC6, 0x21, 0xC3, 0x88, 0x12, 0x15, 0x42, 0xC4, 0x3C, 0xDA, 0xFD, 0xEF, 0xB2, 0xD8, 
	0x73, 0xDA, 0x98, 0xC6, 0x07, 0x4D, 0x93, 0xD3, 0xFC, 0xF0, 0x2E, 0xE0, 0x7E, 0x38, 0xEA, 0x20, 0xDE, 
	0x9F, 0x1C, 0xB1, 0x02, 0x2B, 0xB0, 0x02, 0x2F, 0x01, 0x10, 0x29, 0xCF, 0x79, 0x17, 0x00, 0x6C, 0x0C, 
	0x40, 0x97, 0xB3, 0x57, 0xF4, 0x20, 0x80, 0x38, 0x58, 0x74, 0xB5, 0x36, 0x62, 0x98, 0x4A, 0xD7, 0x88, 
	0x90, 0x7B, 0xFA, 0x1B, 0x40, 0x0C, 0xA8, 0xC5, 0x44, 0xAA, 0xAA, 0x77, 0xA2, 0xA2, 0xEE, 0x05, 0x3C, 
	0xD4, 0x22, 0x25, 0x06, 0xC3, 0xEC, 0x93, 0x8C, 0x03, 0x94, 0xA3, 0x48, 0x4B, 0x65, 0xB4, 0xD6, 0x0E, 
	0x98, 0x7E, 0x03, 0x50, 0xA8, 0x13, 0xEB, 0x8D, 0x3E, 0xB6, 0x99, 0x3C, 0x94, 0x65, 0x79, 0x6A, 0x7D, 
	0x32, 0xD0, 0xA5, 0xD6, 0xEB, 0xAA, 0x95, 0xFB, 0xA2, 0x69, 0x8A, 0x98, 0xDD, 0x66, 0xDB, 0xAA, 0x24, 
	0x80, 0xF1, 0x98, 0x36, 0x1B, 0x6D, 0xB2, 0xC3, 0xAE, 0x29, 0x36, 0x97, 0x94, 0xB8, 0x0C, 0x90, 0x4D, 
	0x9D, 0xFD, 0x31, 0x2B, 0xFB, 0x73, 0x5F, 0xA7, 0x5D, 0x02, 0x38, 0x79, 0x3A, 0x60, 0xE5, 0x66, 0x24, 
	0x19, 0xCD, 0x01, 0xA9, 0xC7, 0x37, 0xD8, 0xF5, 0x3D, 0xFC, 0x26, 0xF7, 0x3F, 0x81, 0xE2, 0x46, 0x18, 
	0x00, 0xDE, 0xA5, 0x8C, 0xC6, 0xD9, 0xC1, 0xBF, 0xA5, 0xE0, 0x2C, 0x4F, 0xDB, 0xA1, 0xB0, 0xCB, 0x26, 
	0x81, 0xDC, 0x2C, 0x1D, 0xBC, 0x46, 0xE0, 0x91, 0x25, 0xE4, 0x03, 0x9E, 0x33, 0x59, 0x6E, 0xC7, 0xDF, 
	0x83, 0xF8, 0x1E, 0x4F, 0x35, 0x33, 0x71, 0x17, 0x77, 0x02, 0xCF, 0x2F, 0x38, 0xF2, 0x9D, 0x8D, 0x4E, 
	0x64, 0xDC, 0x18, 0xA0, 0x70, 0xA2, 0xD8, 0xC6, 0x66, 0x4F, 0xE9, 0xDB, 0x59, 0x41, 0x2B, 0xC3, 0x2D, 
	0xE0, 0xEB, 0xEB, 0x59, 0xC4, 0xE2, 0xB0, 0x74, 0xE4, 0x99, 0x25, 0x79, 0x03, 0x7C, 0x8D, 0x5F, 0x7F, 
	0x16, 0xFB, 0x3B, 0x8B, 0x27, 0x57, 0x45, 0xFF, 0x75, 0x6A, 0x67, 0x81, 0x1F, 0x5A, 0x7C, 0x01, 0x14, 
	0x62, 0x60, 0x7A, 0xDE, 0x95, 0x49, 0xAC, 0xFE, 0xFB, 0x4E, 0x5E, 0x81, 0x15, 0x58, 0x81, 0x97, 0x07, 
	0x3E, 0x04, 0x18, 0x00, 0xC8, 0x0C, 0x7B, 0x0F, 0x66, 0xF0, 0x54, 0x27, 0x00, 0x00, 0x00, 0x00, 0x49, 
	0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
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


void FooterLogo::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 71 "/ws/git/my-devices/gateway/src/FooterLogo.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
