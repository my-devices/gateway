//
// AjaxCore.cpp
//
// This file has been generated from AjaxCore.cpsp on 2025-02-19 13:29:50.
//


#include "AjaxCore.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/Users/guenter/ws/git/my-devices/gateway/src/AjaxCore.cpsp"


// res/AjaxCore.js
static const unsigned char data[] = {
	0x2F, 0x2F, 0x0A, 0x2F, 0x2F, 0x20, 0x41, 0x6A, 0x61, 0x78, 0x43, 0x6F, 0x72, 0x65, 0x2E, 0x6A, 0x73, 
	0x0A, 0x2F, 0x2F, 0x0A, 0x2F, 0x2F, 0x20, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 
	0x28, 0x63, 0x29, 0x20, 0x32, 0x30, 0x30, 0x39, 0x2D, 0x32, 0x30, 0x32, 0x30, 0x2C, 0x20, 0x41, 0x70, 
	0x70, 0x6C, 0x69, 0x65, 0x64, 0x20, 0x49, 0x6E, 0x66, 0x6F, 0x72, 0x6D, 0x61, 0x74, 0x69, 0x63, 0x73, 
	0x20, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x20, 0x45, 0x6E, 0x67, 0x69, 0x6E, 0x65, 0x65, 
	0x72, 0x69, 0x6E, 0x67, 0x20, 0x47, 0x6D, 0x62, 0x48, 0x2E, 0x0A, 0x2F, 0x2F, 0x20, 0x41, 0x6C, 0x6C, 
	0x20, 0x72, 0x69, 0x67, 0x68, 0x74, 0x73, 0x20, 0x72, 0x65, 0x73, 0x65, 0x72, 0x76, 0x65, 0x64, 0x2E, 
	0x0A, 0x2F, 0x2F, 0x0A, 0x2F, 0x2F, 0x20, 0x53, 0x50, 0x44, 0x58, 0x2D, 0x4C, 0x69, 0x63, 0x65, 0x6E, 
	0x73, 0x65, 0x2D, 0x49, 0x64, 0x65, 0x6E, 0x74, 0x69, 0x66, 0x69, 0x65, 0x72, 0x3A, 0x09, 0x42, 0x53, 
	0x4C, 0x2D, 0x31, 0x2E, 0x30, 0x0A, 0x2F, 0x2F, 0x0A, 0x0A, 0x0A, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 
	0x6F, 0x6E, 0x20, 0x24, 0x28, 0x69, 0x64, 0x29, 0x0A, 0x7B, 0x0A, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 
	0x6E, 0x20, 0x64, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 0x65, 
	0x6D, 0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 0x69, 0x64, 0x29, 0x3B, 0x0A, 0x7D, 0x0A, 0x0A, 
	0x0A, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x24, 0x65, 0x76, 0x28, 0x65, 0x76, 0x65, 
	0x6E, 0x74, 0x29, 0x0A, 0x7B, 0x0A, 0x09, 0x69, 0x66, 0x20, 0x28, 0x65, 0x76, 0x65, 0x6E, 0x74, 0x29, 
	0x0A, 0x09, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x65, 0x76, 0x65, 0x6E, 0x74, 0x3B, 0x0A, 
	0x09, 0x65, 0x6C, 0x73, 0x65, 0x0A, 0x09, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x77, 0x69, 
	0x6E, 0x64, 0x6F, 0x77, 0x2E, 0x65, 0x76, 0x65, 0x6E, 0x74, 0x3B, 0x0A, 0x7D, 0x0A, 0x0A, 0x0A, 0x66, 
	0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x24, 0x65, 0x76, 0x74, 0x28, 0x65, 0x76, 0x65, 0x6E, 
	0x74, 0x29, 0x0A, 0x7B, 0x0A, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x65, 0x76, 0x65, 0x6E, 
	0x74, 0x2E, 0x74, 0x61, 0x72, 0x67, 0x65, 0x74, 0x20, 0x3F, 0x20, 0x65, 0x76, 0x65, 0x6E, 0x74, 0x2E, 
	0x74, 0x61, 0x72, 0x67, 0x65, 0x74, 0x20, 0x3A, 0x20, 0x65, 0x76, 0x65, 0x6E, 0x74, 0x2E, 0x73, 0x72, 
	0x63, 0x45, 0x6C, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x3B, 0x0A, 0x7D, 0x0A, 0x0A, 0x0A, 0x76, 0x61, 0x72, 
	0x20, 0x41, 0x6A, 0x61, 0x78, 0x43, 0x6F, 0x72, 0x65, 0x20, 0x3D, 0x0A, 0x7B, 0x0A, 0x09, 0x63, 0x72, 
	0x65, 0x61, 0x74, 0x65, 0x50, 0x6C, 0x61, 0x69, 0x6E, 0x58, 0x4D, 0x4C, 0x48, 0x54, 0x54, 0x50, 0x52, 
	0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x3A, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 
	0x29, 0x0A, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x74, 0x72, 0x79, 0x0A, 0x09, 0x09, 0x09, 0x7B, 
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x6E, 0x65, 0x77, 0x20, 0x41, 
	0x63, 0x74, 0x69, 0x76, 0x65, 0x58, 0x4F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x28, 0x22, 0x4D, 0x73, 0x78, 
	0x6D, 0x6C, 0x32, 0x2E, 0x58, 0x4D, 0x4C, 0x48, 0x54, 0x54, 0x50, 0x22, 0x29, 0x3B, 0x0A, 0x09, 0x09, 
	0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x63, 0x61, 0x74, 0x63, 0x68, 0x20, 0x28, 0x65, 0x78, 0x63, 0x29, 
	0x0A, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x74, 0x72, 0x79, 
	0x0A, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 
	0x6E, 0x65, 0x77, 0x20, 0x41, 0x63, 0x74, 0x69, 0x76, 0x65, 0x58, 0x4F, 0x62, 0x6A, 0x65, 0x63, 0x74, 
	0x28, 0x22, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x2E, 0x58, 0x4D, 0x4C, 0x48, 0x54, 
	0x54, 0x50, 0x22, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x63, 0x61, 0x74, 
	0x63, 0x68, 0x20, 0x28, 0x65, 0x78, 0x63, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 
	0x7D, 0x0A, 0x09, 0x09, 0x09, 0x74, 0x72, 0x79, 0x0A, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x6E, 0x65, 0x77, 0x20, 0x58, 0x4D, 0x4C, 0x48, 0x74, 
	0x74, 0x70, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x28, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x7D, 
	0x0A, 0x09, 0x09, 0x09, 0x63, 0x61, 0x74, 0x63, 0x68, 0x20, 0x28, 0x65, 0x78, 0x63, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x72, 0x65, 0x74, 0x75, 0x72, 
	0x6E, 0x20, 0x6E, 0x75, 0x6C, 0x6C, 0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x2C, 0x0A, 0x0A, 0x09, 0x63, 0x72, 
	0x65, 0x61, 0x74, 0x65, 0x58, 0x4D, 0x4C, 0x48, 0x54, 0x54, 0x50, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 
	0x74, 0x3A, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x68, 0x61, 0x6E, 0x64, 0x6C, 
	0x65, 0x72, 0x29, 0x0A, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x76, 0x61, 0x72, 0x20, 0x72, 0x65, 
	0x71, 0x20, 0x3D, 0x20, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x50, 0x6C, 
	0x61, 0x69, 0x6E, 0x58, 0x4D, 0x4C, 0x48, 0x54, 0x54, 0x50, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 
	0x28, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x72, 0x65, 0x71, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 0x71, 0x2E, 0x6F, 0x6E, 0x72, 0x65, 0x61, 
	0x64, 0x79, 0x73, 0x74, 0x61, 0x74, 0x65, 0x63, 0x68, 0x61, 0x6E, 0x67, 0x65, 0x20, 0x3D, 0x20, 0x68, 
	0x61, 0x6E, 0x64, 0x6C, 0x65, 0x72, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x72, 
	0x65, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x72, 0x65, 0x71, 0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x2C, 0x0A, 0x0A, 
	0x09, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x45, 0x6C, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x3A, 0x20, 
	0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x29, 0x0A, 
	0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x66, 0x6F, 0x72, 0x20, 0x28, 0x76, 0x61, 0x72, 0x20, 0x6B, 
	0x65, 0x79, 0x20, 0x69, 0x6E, 0x20, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x29, 0x0A, 0x09, 0x09, 0x09, 
	0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x6B, 0x65, 0x79, 0x20, 0x3D, 0x3D, 0x20, 
	0x22, 0x72, 0x75, 0x6E, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x22, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 
	0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x76, 0x61, 0x6C, 0x28, 0x76, 0x61, 0x6C, 0x75, 0x65, 
	0x73, 0x5B, 0x6B, 0x65, 0x79, 0x5D, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 
	0x09, 0x09, 0x65, 0x6C, 0x73, 0x65, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x76, 0x61, 0x72, 0x20, 0x65, 0x6C, 0x65, 0x6D, 0x20, 0x3D, 0x20, 0x24, 0x28, 0x6B, 0x65, 0x79, 
	0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x65, 0x6C, 0x65, 0x6D, 0x29, 
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 
	0x28, 0x65, 0x6C, 0x65, 0x6D, 0x2E, 0x6E, 0x6F, 0x64, 0x65, 0x4E, 0x61, 0x6D, 0x65, 0x20, 0x3D, 0x3D, 
	0x20, 0x22, 0x49, 0x4D, 0x47, 0x22, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x65, 0x6C, 0x65, 0x6D, 0x2E, 0x63, 0x6C, 
	0x61, 0x73, 0x73, 0x4E, 0x61, 0x6D, 0x65, 0x20, 0x3D, 0x3D, 0x20, 0x22, 0x67, 0x61, 0x75, 0x67, 0x65, 
	0x22, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x6C, 0x65, 0x6D, 0x2E, 0x77, 
	0x69, 0x64, 0x74, 0x68, 0x20, 0x3D, 0x20, 0x32, 0x2A, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x5B, 0x6B, 
	0x65, 0x79, 0x5D, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x6C, 0x73, 0x65, 0x0A, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x6C, 0x65, 0x6D, 0x2E, 0x73, 0x72, 0x63, 0x20, 
	0x3D, 0x20, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x5B, 0x6B, 0x65, 0x79, 0x5D, 0x3B, 0x0A, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x6C, 0x73, 0x65, 0x0A, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x65, 0x6C, 
	0x65, 0x6D, 0x2E, 0x69, 0x6E, 0x6E, 0x65, 0x72, 0x48, 0x54, 0x4D, 0x4C, 0x20, 0x3D, 0x20, 0x22, 0x22, 
	0x20, 0x2B, 0x20, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x5B, 0x6B, 0x65, 0x79, 0x5D, 0x3B, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x7D, 0x2C, 0x0A, 0x0A, 0x09, 0x50, 0x65, 
	0x72, 0x69, 0x6F, 0x64, 0x69, 0x63, 0x55, 0x70, 0x64, 0x61, 0x74, 0x65, 0x72, 0x3A, 0x0A, 0x09, 0x7B, 
	0x0A, 0x09, 0x09, 0x70, 0x61, 0x74, 0x68, 0x3A, 0x20, 0x22, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x69, 0x6E, 
	0x74, 0x65, 0x72, 0x76, 0x61, 0x6C, 0x3A, 0x20, 0x30, 0x2C, 0x0A, 0x09, 0x09, 0x6D, 0x65, 0x74, 0x68, 
	0x6F, 0x64, 0x3A, 0x20, 0x22, 0x47, 0x45, 0x54, 0x22, 0x2C, 0x0A, 0x0A, 0x09, 0x09, 0x75, 0x70, 0x64, 
	0x61, 0x74, 0x65, 0x3A, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x76, 0x61, 0x72, 0x20, 0x72, 0x65, 0x71, 0x20, 0x3D, 
	0x20, 0x41, 0x6A, 0x61, 0x78, 0x43, 0x6F, 0x72, 0x65, 0x2E, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x58, 
	0x4D, 0x4C, 0x48, 0x54, 0x54, 0x50, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x28, 0x66, 0x75, 0x6E, 
	0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x72, 0x65, 0x71, 0x2E, 0x72, 0x65, 0x61, 0x64, 0x79, 
	0x53, 0x74, 0x61, 0x74, 0x65, 0x20, 0x3D, 0x3D, 0x20, 0x34, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x72, 0x65, 0x71, 
	0x2E, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x3D, 0x3D, 0x20, 0x32, 0x30, 0x30, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x76, 
	0x61, 0x72, 0x20, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x73, 0x20, 0x3D, 0x20, 0x65, 0x76, 0x61, 0x6C, 0x28, 
	0x22, 0x28, 0x22, 0x20, 0x2B, 0x20, 0x72, 0x65, 0x71, 0x2E, 0x72, 0x65, 0x73, 0x70, 0x6F, 0x6E, 0x73, 
	0x65, 0x54, 0x65, 0x78, 0x74, 0x20, 0x2B, 0x20, 0x22, 0x29, 0x22, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x41, 0x6A, 0x61, 0x78, 0x43, 0x6F, 0x72, 0x65, 0x2E, 0x75, 0x70, 0x64, 
	0x61, 0x74, 0x65, 0x45, 0x6C, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x28, 0x76, 0x61, 0x6C, 0x75, 0x65, 
	0x73, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x29, 0x3B, 
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 0x71, 0x2E, 0x6F, 0x70, 0x65, 0x6E, 0x28, 0x74, 0x68, 0x69, 
	0x73, 0x2E, 0x6D, 0x65, 0x74, 0x68, 0x6F, 0x64, 0x2C, 0x20, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x70, 0x61, 
	0x74, 0x68, 0x2C, 0x20, 0x74, 0x72, 0x75, 0x65, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 
	0x71, 0x2E, 0x73, 0x65, 0x6E, 0x64, 0x28, 0x6E, 0x75, 0x6C, 0x6C, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x69, 0x66, 0x20, 0x28, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 
	0x6C, 0x20, 0x3E, 0x20, 0x30, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x77, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x2E, 0x73, 0x65, 0x74, 0x54, 0x69, 0x6D, 0x65, 0x6F, 0x75, 
	0x74, 0x28, 0x22, 0x41, 0x6A, 0x61, 0x78, 0x43, 0x6F, 0x72, 0x65, 0x2E, 0x50, 0x65, 0x72, 0x69, 0x6F, 
	0x64, 0x69, 0x63, 0x55, 0x70, 0x64, 0x61, 0x74, 0x65, 0x72, 0x2E, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 
	0x28, 0x29, 0x22, 0x2C, 0x20, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 
	0x6C, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 0x7D, 0x2C, 0x0A, 0x0A, 
	0x09, 0x09, 0x73, 0x74, 0x61, 0x72, 0x74, 0x3A, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 
	0x28, 0x70, 0x61, 0x74, 0x68, 0x2C, 0x20, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6C, 0x29, 0x0A, 
	0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x70, 0x61, 0x74, 
	0x68, 0x20, 0x3D, 0x20, 0x70, 0x61, 0x74, 0x68, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x74, 0x68, 0x69, 
	0x73, 0x2E, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6C, 0x20, 0x3D, 0x20, 0x69, 0x6E, 0x74, 0x65, 
	0x72, 0x76, 0x61, 0x6C, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 0x74, 0x68, 0x69, 
	0x73, 0x2E, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6C, 0x20, 0x3E, 0x20, 0x30, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x74, 0x68, 0x69, 0x73, 0x2E, 0x75, 0x70, 
	0x64, 0x61, 0x74, 0x65, 0x28, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x09, 
	0x7D, 0x2C, 0x0A, 0x0A, 0x09, 0x09, 0x73, 0x74, 0x6F, 0x70, 0x3A, 0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 
	0x69, 0x6F, 0x6E, 0x28, 0x29, 0x0A, 0x09, 0x09, 0x09, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x74, 0x68, 
	0x69, 0x73, 0x2E, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6C, 0x20, 0x3D, 0x20, 0x30, 0x3B, 0x0A, 
	0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x7D, 0x0A, 0x7D, 0x3B, 0x0A, 
};


static bool checkModified(Poco::Net::HTTPServerRequest& request)
{
	Poco::DateTime modified(2020, 8, 8, 9, 29, 50);
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


void AjaxCore::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("application/javascript"s);

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 162 "/Users/guenter/ws/git/my-devices/gateway/src/AjaxCore.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
