//
// PlusIconX2.cpp
//
// This file has been generated from PlusIconX2.cpsp on 2022-04-10 09:31:12.
//


#include "PlusIconX2.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/Users/guenter/ws/git/my-devices/gateway/src/PlusIconX2.cpsp"


// res/PlusIconX2.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x28, 0x08, 0x03, 0x00, 0x00, 0x00, 0xBB, 0x20, 0x48, 0x5F, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x01, 0x68, 0x50, 0x4C, 0x54, 0x45, 0x00, 0x8A, 0xC5, 0x04, 0x8C, 0xC5, 0x00, 
	0x8A, 0xC4, 0x00, 0x8B, 0xC5, 0xFF, 0xFF, 0xFF, 0x00, 0x8B, 0xC6, 0x00, 0x8B, 0xC4, 0x00, 0x89, 0xC5, 
	0x00, 0x86, 0xC3, 0x04, 0x8D, 0xC5, 0xFC, 0xFA, 0xF7, 0xFF, 0xFE, 0xFF, 0xF6, 0xFE, 0xFF, 0x00, 0x85, 
	0xC3, 0x00, 0x85, 0xC2, 0x6D, 0xD2, 0xF4, 0x00, 0x8A, 0xC3, 0x00, 0x85, 0xC1, 0xDC, 0xEC, 0xF5, 0xBF, 
	0xD8, 0xE9, 0x90, 0x94, 0xC2, 0x00, 0x87, 0xC3, 0xC0, 0xD9, 0xEA, 0x07, 0x8D, 0xC5, 0x6E, 0xD2, 0xF5, 
	0x91, 0x95, 0xC3, 0xFC, 0xFA, 0xF8, 0x00, 0x86, 0xC4, 0xDD, 0xED, 0xF6, 0x6E, 0xD3, 0xF5, 0xDC, 0xEC, 
	0xF6, 0x00, 0x82, 0xC1, 0xF5, 0xFD, 0xFF, 0x90, 0x95, 0xC3, 0xF6, 0xFD, 0xFF, 0x00, 0x89, 0xC4, 0x00, 
	0x8A, 0xC6, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xF8, 0x00, 0x88, 0xC3, 0x00, 0x84, 0xC2, 
	0x00, 0x82, 0xC2, 0x97, 0x95, 0xC3, 0x90, 0x94, 0xC3, 0x89, 0x88, 0xC1, 0x97, 0x95, 0xC2, 0x59, 0x8D, 
	0xC4, 0xE8, 0xF5, 0xF9, 0x03, 0x96, 0xD3, 0x00, 0x88, 0xC5, 0x64, 0xBF, 0xE6, 0xE9, 0xF1, 0xF0, 0x5C, 
	0xB3, 0xD5, 0xEF, 0xF9, 0xFE, 0xD9, 0xE9, 0xF6, 0xC1, 0xD9, 0xEA, 0xA1, 0x96, 0xC2, 0xB8, 0xD5, 0xEA, 
	0xC0, 0xD9, 0xE9, 0x6E, 0xD2, 0xF4, 0x8F, 0xBE, 0xDF, 0x93, 0xAE, 0xD0, 0x5A, 0xB5, 0xDA, 0x1D, 0x9E, 
	0xD7, 0x0D, 0x84, 0xC3, 0xBF, 0xD9, 0xEB, 0xCE, 0xF0, 0xFB, 0x18, 0x80, 0xC2, 0x2E, 0x8C, 0xC4, 0xFE, 
	0xFE, 0xFF, 0x28, 0xA5, 0xD6, 0xFE, 0xFE, 0xFE, 0xCE, 0xDD, 0xE5, 0x03, 0x96, 0xD2, 0x00, 0x81, 0xBF, 
	0xDD, 0xEC, 0xF6, 0x8F, 0x8C, 0xC0, 0x96, 0x95, 0xC2, 0xAE, 0xB8, 0xD3, 0xB0, 0xB7, 0xD2, 0x0D, 0x88, 
	0xC4, 0xEE, 0xED, 0xF6, 0x86, 0xDB, 0xFB, 0x7C, 0xA6, 0xCC, 0x90, 0x95, 0xC2, 0x00, 0x80, 0xC0, 0x6D, 
	0xD1, 0xF9, 0xBF, 0xD8, 0xEA, 0x03, 0x90, 0xCC, 0x11, 0x83, 0xC2, 0xF1, 0xDE, 0xE8, 0x75, 0xD3, 0xF7, 
	0x91, 0x95, 0xC2, 0x97, 0xBE, 0xDB, 0xCE, 0xDE, 0xEA, 0x18, 0x81, 0xC2, 0x00, 0x8B, 0xCA, 0x0D, 0x89, 
	0xC3, 0x5E, 0xB5, 0xDA, 0xFB, 0xFF, 0xFF, 0x84, 0xDA, 0xFB, 0x61, 0xCE, 0xF5, 0xDD, 0xED, 0xF9, 0xFF, 
	0xFF, 0xF7, 0x99, 0xC1, 0xDF, 0x06, 0x89, 0xC5, 0x48, 0xBC, 0xE7, 0xBA, 0xD3, 0xE7, 0xF7, 0xFE, 0xFF, 
	0xFF, 0xFF, 0xFD, 0x5F, 0xCD, 0xF3, 0xFC, 0xFA, 0xF5, 0x00, 0x88, 0xC4, 0x9A, 0x92, 0xC2, 0x79, 0xDA, 
	0xF9, 0xDF, 0xEC, 0xF5, 0xFF, 0xFE, 0xFD, 0x0B, 0x88, 0xC3, 0x00, 0x87, 0xC2, 0xEF, 0x2B, 0x0F, 0x1D, 
	0x00, 0x00, 0x02, 0x2C, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0x6C, 0x55, 0x05, 0x7B, 0xDB, 0x30, 0x10, 
	0x3D, 0xFB, 0x24, 0xCB, 0xEE, 0x66, 0xC7, 0x49, 0xDA, 0xA4, 0x4D, 0xB3, 0xC2, 0xCA, 0x63, 0xE6, 0xAD, 
	0x63, 0x66, 0x66, 0x66, 0xE6, 0xFD, 0xFD, 0x49, 0xB2, 0xE8, 0x5C, 0xDF, 0x67, 0xC7, 0x67, 0xE9, 0xE5, 
	0xDD, 0xE9, 0xC8, 0xD0, 0x8F, 0x9C, 0x64, 0xFA, 0x32, 0x9A, 0x51, 0xAC, 0xD6, 0x87, 0x28, 0x8E, 0xE3, 
	0xC4, 0xDC, 0x95, 0x24, 0xEE, 0x59, 0xBA, 0xB5, 0x38, 0x82, 0x28, 0x01, 0x40, 0x00, 0x0E, 0x4A, 0xAA, 
	0x5F, 0x2B, 0xE8, 0x55, 0x05, 0x8C, 0xED, 0x3B, 0xA7, 0x30, 0x22, 0x9A, 0x91, 0xD3, 0xBF, 0x63, 0x13, 
	0xB9, 0x66, 0x24, 0x76, 0xE4, 0xBE, 0x10, 0xC2, 0xEA, 0x68, 0x57, 0x03, 0xA0, 0xC5, 0x62, 0xFE, 0xF7, 
	0xC6, 0xCB, 0x8F, 0xD4, 0x30, 0x07, 0x0A, 0xD4, 0x7C, 0x73, 0xC7, 0x8F, 0x7E, 0x78, 0xBA, 0x5D, 0xE9, 
	0x68, 0xCD, 0xA3, 0x33, 0xCD, 0x0D, 0x99, 0x3A, 0xD0, 0xCA, 0x3D, 0xC6, 0xBE, 0x1E, 0x14, 0xB5, 0xB3, 
	0x27, 0x99, 0x67, 0x44, 0xED, 0x10, 0x6F, 0x3F, 0xFE, 0xC2, 0x06, 0xB3, 0xE4, 0x38, 0x68, 0x80, 0x15, 
	0x40, 0x3B, 0x2E, 0xEF, 0x76, 0x6B, 0x3D, 0x1B, 0x99, 0x50, 0xFB, 0xF3, 0x0A, 0x51, 0x99, 0xC2, 0x2A, 
	0x8E, 0x08, 0xD6, 0x1D, 0xA9, 0x16, 0xAD, 0x8D, 0x6C, 0x64, 0x56, 0x78, 0xAB, 0xDC, 0x01, 0x69, 0x2E, 
	0xDA, 0x1B, 0x24, 0xE3, 0xA8, 0x30, 0xE1, 0xB4, 0xF1, 0x51, 0xC0, 0x12, 0x48, 0x80, 0x2D, 0x90, 0xE6, 
	0xB1, 0x8C, 0x20, 0x8B, 0x31, 0x8C, 0x0E, 0xB4, 0xC7, 0x3D, 0x90, 0xBB, 0x2A, 0xA8, 0x9B, 0xB6, 0xC0, 
	0x3B, 0x82, 0x94, 0x84, 0x07, 0xA2, 0xF7, 0xA6, 0x38, 0x22, 0x81, 0xDB, 0x04, 0x2D, 0x1E, 0x30, 0x65, 
	0x26, 0x65, 0x39, 0x9D, 0xCC, 0x73, 0x79, 0xE5, 0x77, 0xBF, 0xCD, 0xB0, 0xC1, 0x95, 0x34, 0xAF, 0x64, 
	0x72, 0x97, 0x01, 0x66, 0xD2, 0x47, 0xF9, 0x9C, 0x7B, 0xF1, 0x69, 0xC7, 0xEF, 0xCE, 0xB0, 0x33, 0xD5, 
	0xE9, 0xEC, 0xDF, 0xB7, 0xC0, 0x16, 0x6F, 0x0E, 0x87, 0x97, 0xE5, 0xCB, 0xD4, 0xBB, 0x3D, 0xC7, 0x1E, 
	0x12, 0xC6, 0xB1, 0x9D, 0x6F, 0x58, 0xA3, 0xBC, 0xBF, 0xFE, 0x3C, 0xF0, 0x11, 0xE1, 0xDF, 0xC5, 0x5B, 
	0x6C, 0x5D, 0x25, 0xE7, 0x17, 0xE4, 0xFE, 0xE2, 0x59, 0xF3, 0xB6, 0x74, 0xED, 0x34, 0x39, 0xCC, 0xF2, 
	0x83, 0xDD, 0xCF, 0xBA, 0xBD, 0x5E, 0xB7, 0xDB, 0x3B, 0xF0, 0xF9, 0xD4, 0x6B, 0xF6, 0xE7, 0xD1, 0x21, 
	0xA9, 0x76, 0x0F, 0xDF, 0x3F, 0x79, 0xE1, 0xF6, 0x89, 0x5A, 0xE1, 0x8E, 0xA5, 0x69, 0xAA, 0xEE, 0xF4, 
	0xD2, 0xDB, 0x19, 0xF6, 0x7D, 0x6B, 0xAA, 0x5F, 0xE5, 0x82, 0x58, 0x53, 0xE1, 0x56, 0x8A, 0x71, 0x99, 
	0xEB, 0xCD, 0x32, 0x85, 0x2E, 0x3C, 0x18, 0x00, 0x83, 0x06, 0x29, 0x54, 0xF5, 0x8C, 0x42, 0x90, 0x69, 
	0x4E, 0xE2, 0xE8, 0x72, 0xA8, 0x73, 0x3D, 0x21, 0x1A, 0xBA, 0x90, 0x9A, 0xE6, 0x9A, 0xF1, 0x89, 0xCD, 
	0xB5, 0xED, 0xC9, 0x26, 0x1F, 0x5B, 0x9E, 0x11, 0x09, 0x63, 0x09, 0xBE, 0x6A, 0x01, 0x8D, 0x8F, 0x22, 
	0x00, 0x71, 0xB9, 0x11, 0xD4, 0xA3, 0x06, 0x72, 0x63, 0x7A, 0x8B, 0x70, 0x6D, 0xE0, 0x81, 0xF4, 0x30, 
	0x1A, 0x38, 0xB8, 0x2A, 0x1A, 0x66, 0x4F, 0xE2, 0xC2, 0xA3, 0x37, 0x56, 0x7E, 0x31, 0xB6, 0xF4, 0x93, 
	0xD4, 0x72, 0x05, 0xCC, 0x6A, 0x87, 0xF9, 0x71, 0x6E, 0xF5, 0xD5, 0xDE, 0x33, 0x4D, 0x43, 0x2A, 0x46, 
	0xDA, 0x5D, 0xC5, 0xF4, 0xF4, 0xA6, 0x35, 0xD3, 0xCF, 0xFB, 0x88, 0x7E, 0xEA, 0x61, 0xD0, 0xAA, 0xF3, 
	0xBE, 0x0B, 0xB3, 0xB2, 0x6E, 0x06, 0x43, 0x15, 0x83, 0x5C, 0x73, 0x0C, 0x3B, 0x18, 0xE9, 0xB0, 0xC4, 
	0x7A, 0xCF, 0x84, 0x74, 0x1C, 0x78, 0x9D, 0x3A, 0x89, 0xF4, 0xB0, 0x97, 0x12, 0xCC, 0xF5, 0xA6, 0xB1, 
	0x2F, 0x19, 0x83, 0xCF, 0x47, 0xF0, 0x19, 0xA9, 0x1E, 0x99, 0x5F, 0xEB, 0xFF, 0x17, 0x60, 0x00, 0x86, 
	0xA2, 0x2A, 0xCE, 0x69, 0xB9, 0xEC, 0x10, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 
	0x60, 0x82, 
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


using namespace std::string_literals;


namespace MyDevices {
namespace Gateway {


void PlusIconX2::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png"s);

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 98 "/Users/guenter/ws/git/my-devices/gateway/src/PlusIconX2.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
