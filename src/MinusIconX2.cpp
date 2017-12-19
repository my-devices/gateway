//
// MinusIconX2.cpp
//
// This file has been generated from MinusIconX2.cpsp.
//


#include "MinusIconX2.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/ws/my-devices.net/gateway/src/MinusIconX2.cpsp"


// res/MinusIconX2.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x28, 0x08, 0x03, 0x00, 0x00, 0x00, 0xBB, 0x20, 0x48, 0x5F, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x00, 0xBA, 0x50, 0x4C, 0x54, 0x45, 0xDF, 0x53, 0x29, 0xE0, 0x54, 0x2A, 0xDF, 
	0x54, 0x29, 0xDF, 0x54, 0x2A, 0xDF, 0x55, 0x2C, 0xE0, 0x56, 0x2D, 0xDF, 0x56, 0x2C, 0xE0, 0x53, 0x29, 
	0xE0, 0x53, 0x2A, 0xFF, 0xFF, 0xFF, 0xDF, 0x56, 0x2D, 0xDF, 0x53, 0x2A, 0xFD, 0xF5, 0xF2, 0xE0, 0x54, 
	0x29, 0xDF, 0x51, 0x26, 0xF4, 0xBD, 0xAE, 0xF4, 0xBD, 0xAD, 0xE6, 0x75, 0x54, 0xE6, 0x75, 0x55, 0xDE, 
	0x50, 0x25, 0xDF, 0x52, 0x27, 0xFD, 0xF4, 0xF2, 0xE0, 0x52, 0x28, 0xDE, 0x51, 0x26, 0xE0, 0x52, 0x27, 
	0xDE, 0x51, 0x25, 0xE6, 0x74, 0x54, 0xDF, 0x51, 0x27, 0xDE, 0x4E, 0x22, 0xF9, 0xDC, 0xD5, 0xF5, 0xC1, 
	0xB2, 0xF1, 0xAD, 0x9A, 0xDF, 0x52, 0x26, 0xE5, 0x74, 0x54, 0xE0, 0x59, 0x30, 0xFB, 0xE5, 0xE1, 0xDF, 
	0x52, 0x28, 0xDD, 0x4C, 0x1E, 0xE7, 0x7A, 0x5A, 0xE6, 0x78, 0x57, 0xE6, 0x77, 0x56, 0xE5, 0x70, 0x4E, 
	0xE5, 0x6F, 0x4E, 0xDF, 0x59, 0x2F, 0xE4, 0x6B, 0x48, 0xF5, 0xBD, 0xAE, 0xDD, 0x4C, 0x20, 0xE4, 0x6C, 
	0x49, 0xE1, 0x5C, 0x34, 0xDF, 0x55, 0x2D, 0xE6, 0x76, 0x56, 0xDD, 0x4B, 0x1E, 0xE0, 0x51, 0x26, 0xDF, 
	0x50, 0x25, 0xE1, 0x5C, 0x33, 0xE7, 0x7A, 0x5B, 0xDF, 0x58, 0x2F, 0xDF, 0x53, 0x28, 0xE7, 0x78, 0x58, 
	0xDE, 0x50, 0x26, 0xE0, 0x55, 0x2D, 0xDD, 0x4B, 0x20, 0x77, 0x5B, 0x2E, 0x07, 0x00, 0x00, 0x03, 0x09, 
	0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0x64, 0x55, 0xD7, 0x62, 0xDB, 0x40, 0x0C, 0x23, 0x79, 0xA7, 0x51, 
	0xC9, 0x92, 0x67, 0xEC, 0xCC, 0x26, 0x4D, 0xD2, 0xBD, 0xF7, 0xFE, 0xFF, 0xDF, 0x2A, 0x00, 0x3A, 0x4F, 
	0xD5, 0xC9, 0x3A, 0xF9, 0x06, 0x09, 0x82, 0xE0, 0xC9, 0x6E, 0x6B, 0xD3, 0x34, 0x6D, 0xDB, 0xD4, 0x5A, 
	0xD5, 0x35, 0xB8, 0xD9, 0x86, 0xDA, 0x0E, 0x1F, 0x6B, 0x6D, 0x39, 0x30, 0x34, 0xF5, 0xD6, 0xAA, 0x9B, 
	0x85, 0x15, 0x43, 0xE7, 0x1E, 0x78, 0x96, 0x88, 0x52, 0xF8, 0xB0, 0x82, 0xD1, 0xAE, 0xB8, 0x97, 0x30, 
	0xAF, 0xD6, 0x60, 0x24, 0xB0, 0x02, 0xFF, 0x0C, 0xAF, 0xBC, 0x0A, 0x37, 0x61, 0x1B, 0x6F, 0xE3, 0x2A, 
	0xB4, 0xD6, 0xAA, 0x26, 0xF9, 0xDE, 0xD3, 0xAE, 0x7B, 0x9A, 0x86, 0x35, 0x75, 0x9C, 0xC1, 0xDA, 0x68, 
	0xAC, 0xF1, 0x90, 0x19, 0x78, 0x01, 0x04, 0x9A, 0xC7, 0x93, 0x56, 0x9D, 0x83, 0x21, 0xF3, 0x18, 0x6A, 
	0xAC, 0xD2, 0x4E, 0xC8, 0x43, 0x47, 0x8B, 0xC0, 0x81, 0xC9, 0x60, 0x27, 0xEF, 0x00, 0x45, 0x9F, 0xC0, 
	0x48, 0x70, 0x98, 0x33, 0xC0, 0x36, 0x19, 0xC7, 0x04, 0x3D, 0x66, 0x14, 0xA6, 0x58, 0x8D, 0x18, 0xB5, 
	0x2A, 0x68, 0x9E, 0xE8, 0x8F, 0xD8, 0x33, 0xA8, 0xF0, 0x49, 0x3C, 0x60, 0x10, 0x16, 0xD3, 0xB4, 0x66, 
	0x71, 0x77, 0x25, 0x7A, 0x74, 0xBD, 0x76, 0x8D, 0x1C, 0xE8, 0x7C, 0xEA, 0xDC, 0x1B, 0x6B, 0x47, 0xB0, 
	0xE6, 0x13, 0x62, 0x63, 0x34, 0x98, 0xEE, 0x8F, 0xD0, 0x2C, 0xC6, 0xD1, 0x26, 0xBC, 0x76, 0x74, 0x52, 
	0xD1, 0xD2, 0x1C, 0xEC, 0x3B, 0x83, 0x61, 0x20, 0x4E, 0x20, 0xC2, 0x43, 0x77, 0x63, 0x8F, 0x15, 0x8D, 
	0xFD, 0x29, 0xDE, 0x77, 0x98, 0x86, 0xA9, 0x42, 0xDC, 0x58, 0x46, 0xFB, 0x0C, 0x49, 0x64, 0x71, 0xAC, 
	0xB7, 0x0E, 0xAE, 0xC9, 0x28, 0x2C, 0x38, 0xF9, 0xC4, 0x93, 0x64, 0x31, 0x58, 0xE4, 0x10, 0x68, 0x89, 
	0x85, 0xBE, 0x10, 0x75, 0x2B, 0xEA, 0xF2, 0xA1, 0x24, 0x88, 0x13, 0xAC, 0x12, 0x0A, 0xA6, 0x46, 0x3A, 
	0x40, 0x66, 0x08, 0x5C, 0x6A, 0xE0, 0xCD, 0xC4, 0x31, 0x0E, 0x13, 0x13, 0xF4, 0x11, 0xCC, 0x51, 0xA1, 
	0x45, 0x65, 0xC8, 0x1E, 0xF2, 0x20, 0x76, 0x23, 0xC7, 0xAC, 0x74, 0x9D, 0x84, 0x01, 0x03, 0x15, 0x0B, 
	0x8B, 0x06, 0x7B, 0x67, 0xD8, 0xF8, 0x01, 0x6E, 0x3C, 0xEC, 0x90, 0x03, 0x62, 0x62, 0x66, 0xD4, 0x47, 
	0x72, 0x14, 0x76, 0xCC, 0x27, 0xB6, 0xA0, 0xEB, 0x6C, 0x4C, 0x1D, 0x30, 0x33, 0xC3, 0x51, 0x83, 0xDD, 
	0x74, 0x3F, 0x9F, 0xDE, 0xDC, 0xCC, 0xF3, 0x6E, 0x3F, 0xEF, 0x4F, 0x77, 0xBB, 0x8B, 0xFD, 0xEE, 0xE2, 
	0x74, 0x0F, 0xE2, 0x24, 0x52, 0xA7, 0x1E, 0x49, 0x98, 0xDB, 0xE5, 0x9B, 0xEB, 0xC7, 0xAB, 0xE5, 0x72, 
	0xB9, 0xCA, 0xC7, 0xDB, 0xE5, 0x6A, 0xB9, 0x7A, 0x7C, 0xFD, 0xFE, 0x52, 0xA1, 0x05, 0x08, 0x1F, 0xA4, 
	0x51, 0x8B, 0xCF, 0xDF, 0xEF, 0x1E, 0xFD, 0x77, 0xDD, 0x3D, 0x7B, 0x2A, 0x2B, 0xA1, 0x14, 0x4A, 0xC6, 
	0xF6, 0xEE, 0xD7, 0xD5, 0x62, 0xB1, 0x38, 0xC9, 0x76, 0xB2, 0xC8, 0xEB, 0xEA, 0xF9, 0x5F, 0x6A, 0x0E, 
	0x92, 0x13, 0x3D, 0xDC, 0x14, 0xF7, 0x1F, 0x5E, 0xBD, 0xD8, 0xAC, 0x9F, 0xAC, 0xCF, 0x37, 0xF8, 0x9D, 
	0x6F, 0x36, 0xEB, 0xF5, 0x7A, 0xF3, 0xE9, 0xE5, 0xB7, 0x5D, 0x12, 0x85, 0x65, 0x43, 0xD2, 0x58, 0xFC, 
	0xE7, 0xE1, 0xF7, 0xD9, 0xD9, 0xD7, 0xED, 0xD9, 0x3C, 0x6F, 0xB7, 0xF3, 0xF6, 0xF0, 0x65, 0x9E, 0x0F, 
	0xDB, 0x43, 0xF2, 0x18, 0x96, 0xEA, 0x51, 0x95, 0x4C, 0x4C, 0x71, 0x78, 0x26, 0xE4, 0x48, 0x1E, 0xCB, 
	0x43, 0xE2, 0x2A, 0xD1, 0x22, 0x85, 0x59, 0x43, 0x96, 0x9A, 0x70, 0x3B, 0xA6, 0x89, 0xA6, 0x46, 0x11, 
	0xA2, 0x12, 0x6F, 0xE8, 0x5A, 0x39, 0x1A, 0xAD, 0x8C, 0x41, 0x31, 0xA8, 0xFE, 0x54, 0xA2, 0xF0, 0xC2, 
	0xC2, 0xA1, 0x19, 0x58, 0xAC, 0x9E, 0x0A, 0xA1, 0x1F, 0x16, 0x14, 0xFD, 0x63, 0xA6, 0x50, 0x2A, 0x94, 
	0xA2, 0x53, 0xBB, 0x1E, 0x83, 0x44, 0xA1, 0xB8, 0xB1, 0x9F, 0x88, 0xBA, 0xD4, 0x51, 0x49, 0x14, 0xA1, 
	0x9A, 0x03, 0x8C, 0x01, 0xB9, 0x0E, 0x09, 0xAF, 0x93, 0xD4, 0x62, 0xF4, 0xBE, 0x27, 0x14, 0x4A, 0xC4, 
	0x7B, 0x07, 0x20, 0x49, 0x8F, 0x55, 0x08, 0x23, 0x58, 0xD0, 0xEB, 0x44, 0x90, 0x33, 0x1D, 0x42, 0x94, 
	0x1C, 0x6A, 0x9D, 0xD2, 0xEB, 0x08, 0x45, 0x0B, 0xC9, 0xA2, 0x13, 0xD9, 0x04, 0x1B, 0x98, 0xEB, 0x99, 
	0xD4, 0xF2, 0x70, 0xC0, 0x99, 0x4D, 0xE2, 0xB1, 0x4D, 0xAD, 0x87, 0x2A, 0x99, 0x8D, 0xC5, 0x62, 0x59, 
	0x34, 0x82, 0x29, 0xD7, 0xA5, 0xCD, 0x52, 0xC0, 0x6F, 0xB4, 0x04, 0xE9, 0x6A, 0xD2, 0xA6, 0x82, 0xA6, 
	0x7A, 0x0B, 0x6B, 0xA6, 0x55, 0xA5, 0x94, 0x18, 0xCB, 0x54, 0xA4, 0x5D, 0xCF, 0x63, 0x10, 0xF1, 0xE2, 
	0x15, 0xEC, 0x30, 0xF0, 0x00, 0xE1, 0x95, 0xF6, 0x44, 0x5F, 0xC2, 0x0A, 0x31, 0x79, 0xAC, 0xB5, 0xD4, 
	0x01, 0x85, 0x08, 0x85, 0x2B, 0x54, 0xCA, 0xBE, 0xE4, 0x06, 0x46, 0x96, 0x05, 0x98, 0x45, 0x96, 0x27, 
	0x2B, 0x5C, 0x8B, 0x17, 0x8A, 0xB2, 0x4F, 0x35, 0xE4, 0xB9, 0xEA, 0x79, 0x9C, 0x68, 0x33, 0xCF, 0x35, 
	0xE4, 0x9A, 0x85, 0x2E, 0x61, 0x30, 0xA5, 0x2C, 0x43, 0x9D, 0x7D, 0x85, 0x44, 0x7B, 0x37, 0xB2, 0x34, 
	0x43, 0x55, 0xF8, 0x7A, 0xC0, 0x57, 0x03, 0xDF, 0x07, 0x7E, 0x26, 0xF4, 0xF5, 0x18, 0xEA, 0x80, 0x0F, 
	0xC9, 0x90, 0x5F, 0x14, 0x5E, 0x03, 0xE7, 0x7E, 0xFC, 0x13, 0x60, 0x00, 0xC2, 0xE4, 0x18, 0x6B, 0xD5, 
	0x86, 0x19, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};


static bool checkModified(Poco::Net::HTTPServerRequest& request)
{
	Poco::DateTime modified(2017, 10, 23, 11, 15, 41);
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


void MinusIconX2::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 100 "/ws/my-devices.net/gateway/src/MinusIconX2.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
