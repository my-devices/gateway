//
// HeaderLogoX2.cpp
//
// This file has been generated from HeaderLogoX2.cpsp on 2025-02-19 13:29:51.
//


#include "HeaderLogoX2.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/Users/guenter/ws/git/my-devices/gateway/src/HeaderLogoX2.cpsp"


// res/HeaderLogoX2.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0x28, 0x08, 0x06, 0x00, 0x00, 0x00, 0x57, 0x69, 0xD0, 0x0A, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x15, 0xBE, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xEC, 0x5D, 0x07, 0x9C, 0x55, 
	0xC5, 0xB9, 0xFF, 0x4E, 0xB9, 0x6D, 0xF7, 0x6E, 0xB9, 0x5B, 0xD8, 0xA5, 0x49, 0x93, 0xB2, 0x94, 0x85, 
	0x88, 0x02, 0x1A, 0x2C, 0x01, 0x7D, 0x8A, 0x0D, 0x34, 0x28, 0x62, 0x89, 0x31, 0x88, 0x18, 0x93, 0x58, 
	0x52, 0x48, 0x34, 0x2F, 0x4F, 0x4C, 0x9E, 0xC6, 0xA7, 0x91, 0x17, 0x9E, 0x89, 0x3D, 0x98, 0x97, 0x97, 
	0x04, 0x51, 0xB1, 0x20, 0xA2, 0xA0, 0x88, 0x10, 0x50, 0x5A, 0x00, 0xA5, 0x2B, 0xB0, 0x48, 0x59, 0xD8, 
	0xC6, 0xB6, 0xDB, 0xEF, 0xB9, 0xE7, 0xBC, 0xFF, 0x9C, 0x99, 0xBD, 0x77, 0xEF, 0xEE, 0x3D, 0x5B, 0x60, 
	0x91, 0x65, 0x73, 0xE7, 0xC7, 0xC7, 0x6D, 0x67, 0xE6, 0xCC, 0x7C, 0xF3, 0x9F, 0xFF, 0x7C, 0xDF, 0x37, 
	0x73, 0x66, 0x25, 0xC3, 0x30, 0x28, 0x95, 0x52, 0xA9, 0xAB, 0x24, 0xB5, 0xD1, 0xFB, 0x3C, 0xC8, 0x8F, 
	0x20, 0x53, 0x20, 0x3D, 0x20, 0x0A, 0xE4, 0xEB, 0x40, 0xBB, 0x04, 0xD1, 0x20, 0x47, 0x20, 0x0B, 0x20, 
	0x73, 0xC5, 0xE7, 0x53, 0x92, 0x26, 0x40, 0x56, 0x42, 0x16, 0x43, 0x0A, 0x20, 0x67, 0x41, 0x5E, 0x85, 
	0xDC, 0xD3, 0x44, 0x19, 0xC9, 0x93, 0x11, 0x53, 0xC9, 0x01, 0x54, 0xFB, 0x38, 0x44, 0xC7, 0xFB, 0x2F, 
	0x20, 0x37, 0x8B, 0x2B, 0x22, 0x90, 0x5A, 0xD1, 0x28, 0xAB, 0x12, 0xB2, 0x20, 0xB6, 0xA4, 0xBF, 0xB2, 
	0x9C, 0x61, 0x8B, 0xDC, 0x06, 0x79, 0x51, 0xC3, 0xD5, 0xE4, 0x31, 0xEF, 0xD9, 0xF4, 0x8A, 0x28, 0xE4, 
	0x1C, 0x48, 0xAF, 0x66, 0xF9, 0x96, 0x43, 0x2E, 0xB7, 0xA8, 0x4D, 0x0E, 0xE4, 0x4B, 0xF3, 0x35, 0x8A, 
	0x9A, 0x6B, 0xA8, 0x15, 0xD3, 0x81, 0xDC, 0xA8, 0x63, 0xE2, 0xB5, 0x0E, 0x42, 0xD6, 0x41, 0x2E, 0x86, 
	0x54, 0x98, 0x77, 0x9C, 0x08, 0xC8, 0x7C, 0x44, 0x76, 0xBA, 0x10, 0x9F, 0x56, 0x37, 0x02, 0x8B, 0xD4, 
	0xA2, 0x0E, 0xD9, 0x95, 0x63, 0x20, 0x4E, 0xC8, 0xBB, 0x90, 0xAB, 0x2D, 0xAF, 0xF4, 0xD1, 0x1C, 0x72, 
	0xD0, 0xC3, 0xA8, 0x93, 0x96, 0xD0, 0x3B, 0x51, 0x71, 0x0F, 0x5E, 0xCF, 0x1D, 0x42, 0xBE, 0x09, 0x29, 
	0x8E, 0x5D, 0x35, 0x12, 0xF2, 0x06, 0xA4, 0xFF, 0x69, 0x1C, 0x5C, 0xF9, 0x90, 0x51, 0x90, 0xF1, 0x90, 
	0x5B, 0x20, 0xF5, 0xA7, 0xE2, 0x26, 0xD1, 0x14, 0x89, 0x75, 0xE9, 0xC4, 0x40, 0x9E, 0x0B, 0x79, 0xED, 
	0x34, 0x83, 0xB9, 0x71, 0xBA, 0x06, 0xF2, 0xFC, 0xA9, 0x28, 0xB8, 0x06, 0xB2, 0x2B, 0xD5, 0xE7, 0x5D, 
	0xDE, 0xE4, 0xB8, 0x17, 0x32, 0xB0, 0x93, 0xD5, 0x6B, 0x3A, 0xE4, 0x65, 0xC8, 0x07, 0x27, 0x57, 0x4C, 
	0x89, 0x98, 0x52, 0x55, 0x93, 0x9B, 0xBF, 0xC4, 0x14, 0x59, 0x41, 0xDF, 0x48, 0xF5, 0x7A, 0x17, 0x07, 
	0xF4, 0x35, 0x9D, 0xB4, 0x6E, 0x53, 0x4E, 0x1E, 0xD0, 0x2F, 0x42, 0x7E, 0x1B, 0xFB, 0x54, 0x6F, 0x5A, 
	0xD0, 0x2B, 0x52, 0xBD, 0xDE, 0xC5, 0x4D, 0x8E, 0x5E, 0x9D, 0xB4, 0x6E, 0x27, 0x30, 0x6B, 0x30, 0xE7, 
	0xE1, 0x60, 0xA3, 0xCF, 0x7A, 0xAA, 0x87, 0xFF, 0x05, 0x01, 0xAD, 0x74, 0xD2, 0xBA, 0x9D, 0x40, 0xBD, 
	0x98, 0xCB, 0xF7, 0x55, 0x93, 0x00, 0x4A, 0x2A, 0xFD, 0xAB, 0x01, 0x3A, 0x95, 0x52, 0x29, 0x05, 0xE8, 
	0x54, 0x4A, 0xA5, 0x14, 0xA0, 0x53, 0x29, 0x95, 0x4E, 0x71, 0x52, 0x53, 0x2A, 0xE8, 0xF8, 0x64, 0xB4, 
	0xFE, 0xDB, 0x58, 0xE2, 0x0B, 0x86, 0x7A, 0xA2, 0xCF, 0x20, 0xFD, 0x13, 0x52, 0x69, 0x6D, 0xFB, 0xB7, 
	0xD9, 0x27, 0xC8, 0x10, 0xB7, 0xF2, 0xA6, 0x00, 0x9D, 0x4A, 0x27, 0x95, 0xD8, 0x92, 0xB6, 0x0B, 0x52, 
	0x65, 0x01, 0x41, 0xA0, 0x4C, 0x06, 0xDA, 0x5E, 0xC4, 0x75, 0x23, 0x92, 0xE0, 0xF0, 0x2A, 0xFC, 0xB7, 
	0xB4, 0xB5, 0x81, 0x22, 0x91, 0xD5, 0xE2, 0xB8, 0x19, 0xB1, 0x7A, 0x82, 0xF8, 0x0A, 0x3F, 0xBB, 0x9C, 
	0xAD, 0x7B, 0xFF, 0x1C, 0x72, 0x2C, 0x05, 0xE8, 0x54, 0x3A, 0xE1, 0xE4, 0x16, 0xAF, 0x55, 0x82, 0x82, 
	0xA5, 0xE6, 0xA0, 0x34, 0x4E, 0x84, 0x81, 0x1D, 0xC8, 0xE6, 0xB2, 0x28, 0x33, 0x8D, 0xC8, 0x99, 0xCD, 
	0xB7, 0x2F, 0x9C, 0xD7, 0xE8, 0xA7, 0xEF, 0x00, 0xE3, 0x7D, 0x89, 0x7A, 0x4E, 0x24, 0x0A, 0x6A, 0xF1, 
	0xC0, 0x11, 0xCB, 0xCD, 0x76, 0x16, 0xB0, 0x31, 0x95, 0x49, 0x5D, 0x29, 0xBC, 0x99, 0x02, 0xF4, 0x29, 
	0x04, 0xB5, 0x1D, 0x52, 0x46, 0xF1, 0xCD, 0x34, 0x27, 0x9B, 0x58, 0x79, 0x6C, 0x53, 0xD5, 0xEF, 0xC5, 
	0x2C, 0xD0, 0x90, 0x02, 0x90, 0x7F, 0x23, 0x3A, 0x7F, 0x59, 0x22, 0x98, 0x45, 0x1A, 0x7A, 0x11, 0xD1, 
	0xD9, 0xDF, 0x24, 0x5A, 0xB5, 0x2A, 0xEE, 0x32, 0x31, 0x00, 0xF7, 0x26, 0xBE, 0x18, 0xCB, 0x20, 0x10, 
	0x49, 0x01, 0xFA, 0x74, 0xDA, 0xA6, 0x67, 0x4A, 0x74, 0x99, 0x01, 0xB0, 0x9B, 0x98, 0xEF, 0x8D, 0x0E, 
	0xA9, 0xB7, 0x44, 0xB3, 0x69, 0x37, 0xED, 0xA1, 0x5C, 0x94, 0x99, 0x1F, 0xDB, 0xB1, 0xC7, 0x00, 0xDD, 
	0xB7, 0xC5, 0x1D, 0x8A, 0xC3, 0x30, 0xA6, 0xEA, 0xC4, 0x30, 0x60, 0xE0, 0xF5, 0x40, 0x1E, 0x85, 0xF4, 
	0x4B, 0x99, 0x1C, 0xA7, 0x1B, 0xD0, 0x67, 0xDA, 0x52, 0x89, 0x83, 0xF8, 0xEE, 0xAF, 0xCA, 0x0E, 0x6A, 
	0x6F, 0x77, 0x98, 0x0A, 0xEF, 0x82, 0xFF, 0x9B, 0xA2, 0x17, 0x88, 0xDD, 0x18, 0x26, 0xFA, 0xCC, 0xCE, 
	0x77, 0x4E, 0x36, 0x4A, 0xA1, 0x8D, 0x44, 0x8F, 0xAF, 0x67, 0xE6, 0x86, 0x86, 0x12, 0x25, 0x80, 0x5A, 
	0xE9, 0xC2, 0xC1, 0x2D, 0xF9, 0x4C, 0x02, 0xF3, 0x99, 0x6C, 0x7E, 0x64, 0x77, 0xA0, 0xA5, 0xDA, 0xB0, 
	0x17, 0x38, 0xD2, 0x48, 0x00, 0xE8, 0xA0, 0x9F, 0xE8, 0x46, 0x83, 0x3B, 0x95, 0x6C, 0x63, 0x75, 0x0D, 
	0xE6, 0x06, 0xD8, 0xD4, 0x65, 0x37, 0x10, 0xF9, 0x22, 0x1A, 0xBE, 0xFA, 0x25, 0x72, 0x96, 0x76, 0xF1, 
	0x48, 0xAD, 0x7A, 0x26, 0x00, 0x99, 0x39, 0x57, 0x39, 0x67, 0xB8, 0xA2, 0x19, 0xA0, 0x43, 0xC4, 0x36, 
	0xAD, 0xB7, 0x9E, 0xA2, 0x6D, 0x60, 0x1A, 0x45, 0x44, 0x54, 0xA2, 0x89, 0xEC, 0xF4, 0x05, 0x06, 0xCD, 
	0x35, 0x0A, 0x0F, 0x09, 0x42, 0x75, 0x65, 0x00, 0xB6, 0x1B, 0xAF, 0x3D, 0xE9, 0x69, 0x0C, 0xA7, 0xB9, 
	0xC8, 0xF1, 0xD3, 0x54, 0x94, 0xA3, 0x6D, 0x29, 0xAA, 0x1B, 0x46, 0x30, 0xAC, 0xD5, 0xD4, 0x06, 0xC2, 
	0x86, 0xDD, 0xA6, 0x1A, 0x19, 0x2E, 0x5B, 0xA6, 0x43, 0x91, 0x6D, 0x56, 0xD7, 0x47, 0xB4, 0x68, 0xC4, 
	0x1B, 0x8C, 0xD4, 0xF9, 0x23, 0xBA, 0x94, 0xE9, 0xB2, 0x4B, 0x2E, 0xBB, 0x92, 0xAD, 0xCA, 0x52, 0x33, 
	0x8B, 0x82, 0x3D, 0x0D, 0xF2, 0x1E, 0xE4, 0xFE, 0xE6, 0x0C, 0xE7, 0x16, 0x92, 0x2E, 0xFA, 0x1F, 0x04, 
	0x45, 0xD5, 0xE2, 0xF5, 0x64, 0x92, 0x4D, 0xE0, 0xCF, 0x2D, 0x70, 0xE3, 0x13, 0x8C, 0xE7, 0x4F, 0x34, 
	0x00, 0x2C, 0x8D, 0x1F, 0x66, 0xA8, 0x66, 0x89, 0x7A, 0x91, 0xC8, 0xCF, 0x0C, 0x58, 0x3F, 0x1B, 0x94, 
	0xC1, 0xF6, 0x01, 0xDA, 0x23, 0xC6, 0x32, 0xFB, 0xEA, 0xB8, 0x28, 0xC7, 0x72, 0x7A, 0xB5, 0xC5, 0x3D, 
	0xBE, 0x6A, 0xFE, 0x76, 0x78, 0x8C, 0xCF, 0xAB, 0x4C, 0x93, 0xA3, 0xA5, 0x89, 0xDA, 0x68, 0xFA, 0x45, 
	0x9E, 0x68, 0x47, 0x58, 0x58, 0x4C, 0xBE, 0x76, 0xEA, 0x91, 0x3D, 0x92, 0x92, 0x21, 0xF4, 0x60, 0x17, 
	0xE3, 0xB9, 0x46, 0xE8, 0xF2, 0xF4, 0x02, 0x7A, 0xE1, 0xBA, 0xFD, 0xAB, 0x76, 0x56, 0x07, 0xDF, 0x77, 
	0x2A, 0x92, 0x93, 0xA9, 0xA7, 0x36, 0xA8, 0x45, 0x46, 0x0D, 0x2C, 0x9C, 0x31, 0xAD, 0x28, 0xBF, 0x9F, 
	0x86, 0x54, 0x5A, 0x5E, 0xBB, 0x70, 0xC7, 0x91, 0x9A, 0xBF, 0xE7, 0x67, 0xA5, 0xAD, 0xDF, 0x7C, 0xA8, 
	0x56, 0xEF, 0x9E, 0x9F, 0xA9, 0x97, 0x6A, 0xD2, 0x20, 0x5D, 0x55, 0xEE, 0x99, 0x3A, 0x30, 0x77, 0x7A, 
	0xBE, 0x4B, 0x71, 0x34, 0x94, 0xE5, 0xF7, 0x05, 0xCA, 0x37, 0xEE, 0x2D, 0xFF, 0x4B, 0x99, 0x2F, 0xF2, 
	0x7A, 0x9E, 0xDB, 0xBE, 0xFB, 0xCB, 0xCA, 0x80, 0x5C, 0x74, 0x56, 0x9E, 0xBC, 0xA3, 0x2E, 0x7C, 0xDE, 
	0xC8, 0xEE, 0x99, 0xB3, 0xC6, 0x16, 0xA6, 0x4F, 0x51, 0x1A, 0x61, 0xE5, 0x19, 0x8A, 0x79, 0x3B, 0xAC, 
	0x0C, 0xF6, 0xB4, 0xCF, 0x15, 0x90, 0x73, 0x21, 0x67, 0x0B, 0x85, 0xD9, 0xE2, 0x33, 0xB0, 0x0D, 0x1D, 
	0x39, 0x62, 0x33, 0xDE, 0xBF, 0x09, 0x79, 0x1D, 0x9D, 0xE4, 0x6B, 0xA3, 0x12, 0xDC, 0xB8, 0xE5, 0x95, 
	0x78, 0x7B, 0x2D, 0x64, 0xB4, 0x69, 0xAA, 0xF2, 0x4E, 0x90, 0xC4, 0x8C, 0xCE, 0xC0, 0xC4, 0x9E, 0x0D, 
	0x98, 0x8F, 0xAF, 0x5E, 0xE3, 0x35, 0x92, 0x4D, 0x91, 0x78, 0x7E, 0xF6, 0xC8, 0xDA, 0xF5, 0xC4, 0x9F, 
	0x75, 0x1A, 0x21, 0x40, 0xD8, 0x30, 0x98, 0x23, 0x02, 0x60, 0x3B, 0xF1, 0xC5, 0x4B, 0x68, 0xC4, 0x22, 
	0x2B, 0xF3, 0x09, 0x68, 0x35, 0x36, 0xE0, 0xF5, 0x52, 0xF3, 0x9F, 0xB9, 0x4F, 0xFD, 0x02, 0x01, 0x08, 
	0x43, 0xC4, 0xD9, 0xD8, 0x76, 0xDA, 0x87, 0x48, 0x6C, 0x29, 0xD4, 0x29, 0xFE, 0xB8, 0x17, 0xA4, 0x07, 
	0xD0, 0xFF, 0x7B, 0x89, 0xD7, 0x5B, 0x8C, 0x7D, 0x85, 0x0D, 0x48, 0xB6, 0xB8, 0xF2, 0x43, 0x51, 0x07, 
	0x36, 0x48, 0xFF, 0x28, 0x06, 0x6C, 0x34, 0x3E, 0x00, 0xFD, 0x73, 0x35, 0x52, 0x50, 0xB6, 0x9A, 0x86, 
	0xCF, 0xB7, 0xA3, 0x8C, 0xEF, 0xE2, 0xB5, 0x88, 0x62, 0x65, 0x49, 0x68, 0xBF, 0xF2, 0x31, 0xB2, 0x3D, 
	0x85, 0x8F, 0x5B, 0x2C, 0x06, 0x33, 0xFB, 0x92, 0x3D, 0x71, 0x74, 0xA5, 0xA8, 0xF7, 0x60, 0x31, 0x28, 
	0x6C, 0x82, 0x18, 0xA2, 0xBC, 0x2E, 0xC5, 0xD0, 0xA3, 0x8D, 0x71, 0xD4, 0xFF, 0xA1, 0x59, 0xA5, 0xA7, 
	0x05, 0xD0, 0xF6, 0xB2, 0xEA, 0x8F, 0x2B, 0x8F, 0xD4, 0x3F, 0x5E, 0xEA, 0x70, 0xA0, 0xF5, 0x06, 0x95, 
	0xD9, 0xD3, 0xC9, 0x08, 0xC8, 0xDD, 0xA7, 0x45, 0x82, 0x33, 0xB7, 0x7C, 0x7E, 0xE0, 0x1A, 0x4D, 0x56, 
	0x96, 0xD7, 0x06, 0x34, 0x2A, 0xF4, 0xB8, 0xC9, 0xA9, 0xCA, 0x04, 0xA6, 0xA5, 0x60, 0x44, 0xDF, 0xF8, 
	0x61, 0x49, 0xED, 0x1D, 0x07, 0x7C, 0xF4, 0xE2, 0x3D, 0xC5, 0xB9, 0x6F, 0xF7, 0x49, 0x57, 0xF2, 0x76, 
	0xED, 0x2D, 0x5D, 0xEF, 0xAF, 0xAE, 0x99, 0x52, 0x52, 0x15, 0x39, 0xA6, 0x3B, 0xEC, 0x54, 0x98, 0xE5, 
	0x24, 0x9B, 0x2A, 0x11, 0x2E, 0xA7, 0x9A, 0xA0, 0xF6, 0xFE, 0xAA, 0x43, 0xBE, 0xF7, 0xBF, 0xF2, 0xEA, 
	0xCF, 0x4F, 0x1F, 0x98, 0x71, 0x17, 0x53, 0x10, 0xA3, 0x5A, 0xF6, 0x28, 0xCD, 0x1D, 0x7C, 0xA1, 0xE0, 
	0x05, 0x40, 0x68, 0x40, 0xCB, 0xFE, 0x97, 0x8C, 0x0E, 0xCB, 0x66, 0xF1, 0xA8, 0xC9, 0x90, 0x07, 0xA0, 
	0xB8, 0xDB, 0xF0, 0xBA, 0xCD, 0x2A, 0x83, 0xC6, 0x29, 0xF0, 0xE6, 0xE9, 0x44, 0x8F, 0x41, 0xE3, 0x7D, 
	0x5A, 0x61, 0x1A, 0xFC, 0xBE, 0x0E, 0x9D, 0xB1, 0xEC, 0xB5, 0x4D, 0xE8, 0x37, 0x1D, 0xB7, 0x40, 0x7D, 
	0x1C, 0xC3, 0x00, 0xB0, 0x21, 0x7C, 0x02, 0xC9, 0x6C, 0x25, 0xFF, 0x59, 0x44, 0x6B, 0x76, 0x10, 0x15, 
	0x2E, 0xE2, 0x63, 0xB1, 0x79, 0x2A, 0x21, 0x43, 0xF7, 0x91, 0xF4, 0xA8, 0x00, 0x6D, 0x32, 0xE6, 0xBF, 
	0x85, 0x68, 0xD0, 0x65, 0xE8, 0x11, 0xB6, 0x57, 0xFC, 0x53, 0x55, 0x30, 0x7E, 0x88, 0x77, 0x64, 0x06, 
	0x50, 0x3A, 0x59, 0x00, 0xBA, 0xC9, 0x38, 0xA1, 0x9F, 0xC0, 0x90, 0xA6, 0x41, 0x00, 0x96, 0xCB, 0x8C, 
	0xF0, 0x51, 0x61, 0xE2, 0x25, 0x8B, 0x3E, 0x0E, 0xD0, 0xC8, 0xAD, 0x19, 0xF4, 0x8D, 0x65, 0xD0, 0x43, 
	0xB2, 0x27, 0x20, 0x7A, 0xA2, 0x58, 0xDC, 0x7B, 0xD4, 0x8D, 0x18, 0x9F, 0x3F, 0x00, 0x10, 0x5F, 0x64, 
	0xF8, 0x2D, 0x14, 0xE3, 0xC6, 0xCD, 0x17, 0x74, 0xFE, 0x26, 0xF1, 0xC7, 0xE7, 0x5A, 0xB2, 0x96, 0x30, 
	0x60, 0xB2, 0x59, 0xE0, 0x87, 0x3D, 0x98, 0x08, 0xEB, 0xC7, 0x76, 0x37, 0xBB, 0xF9, 0xD7, 0x0E, 0xE8, 
	0x34, 0x45, 0xA6, 0x51, 0x86, 0x86, 0x8A, 0xAB, 0xB4, 0x02, 0x7A, 0xDD, 0x6D, 0xA4, 0x93, 0x54, 0x5A, 
	0x7F, 0x74, 0xFE, 0xA1, 0xFD, 0xB7, 0xD7, 0x05, 0xA3, 0xCB, 0x87, 0x0C, 0xEE, 0x4E, 0xBE, 0x68, 0x94, 
	0x0E, 0x96, 0xD7, 0xD2, 0x91, 0xFA, 0x10, 0x81, 0xA1, 0xC9, 0x69, 0x93, 0x49, 0x07, 0x52, 0x5F, 0xDA, 
	0x5A, 0xFE, 0xC9, 0x3F, 0xCB, 0x03, 0x0F, 0x3F, 0xDA, 0x5F, 0xF9, 0xFE, 0xCA, 0x35, 0x5F, 0x5E, 0x7D, 
	0xE1, 0xE8, 0xC2, 0x4A, 0x2D, 0xCD, 0x45, 0x91, 0x30, 0xDC, 0x94, 0x3A, 0x3F, 0xF9, 0xFC, 0x1A, 0x40, 
	0x2D, 0x93, 0x03, 0x52, 0x81, 0xEF, 0x66, 0xAF, 0x2D, 0x9B, 0xE5, 0xD5, 0xF4, 0xE2, 0x99, 0x45, 0x59, 
	0x69, 0x8C, 0x92, 0x3F, 0xE1, 0x3D, 0xC9, 0x3A, 0x73, 0x40, 0x3B, 0xDB, 0x06, 0x6F, 0xFF, 0x07, 0x60, 
	0x9D, 0x91, 0x50, 0x9E, 0xB1, 0x87, 0x11, 0xC4, 0x56, 0xF3, 0x91, 0xD8, 0x98, 0x0D, 0x2A, 0xA3, 0xC0, 
	0x67, 0x70, 0x8F, 0x59, 0x8E, 0x36, 0x17, 0x79, 0x78, 0x5D, 0x0D, 0xC6, 0xCD, 0x7D, 0x34, 0x96, 0x9E, 
	0x23, 0x2A, 0x40, 0xCF, 0x2C, 0x72, 0xF1, 0xA7, 0x33, 0xDB, 0x98, 0x4A, 0x3F, 0xE5, 0x81, 0xBC, 0xE4, 
	0xEE, 0x42, 0x0F, 0xD2, 0x9F, 0x18, 0x4E, 0xCA, 0xF0, 0x96, 0xCB, 0xC8, 0xEA, 0xC6, 0x41, 0x70, 0xDF, 
	0x58, 0x89, 0x96, 0x1F, 0x4A, 0xC7, 0xB8, 0x8D, 0xD0, 0x5D, 0x0C, 0x45, 0x86, 0x85, 0xEF, 0x6C, 0x7E, 
	0x37, 0x80, 0x47, 0x5B, 0x0C, 0x35, 0x89, 0x6F, 0x1A, 0xA5, 0xEB, 0x47, 0xA6, 0x53, 0xDA, 0x12, 0x0B, 
	0x30, 0x37, 0x26, 0x61, 0xB0, 0xAD, 0xED, 0x05, 0xA8, 0xAE, 0x0C, 0xEF, 0x17, 0x3F, 0x8B, 0x3B, 0xFF, 
	0x1A, 0xE3, 0x15, 0xFA, 0xD3, 0x41, 0xBF, 0xC5, 0x4A, 0xFB, 0x82, 0x0C, 0x60, 0xEF, 0x8B, 0x30, 0x8B, 
	0xBE, 0x33, 0x0D, 0x33, 0xC4, 0xAB, 0xCD, 0xB3, 0x86, 0x05, 0xE1, 0x9F, 0x02, 0x40, 0x17, 0x78, 0xEC, 
	0x64, 0x0B, 0x39, 0x68, 0x84, 0x5D, 0xA2, 0x35, 0x65, 0x1A, 0xF9, 0x2A, 0xAB, 0x68, 0x5B, 0x95, 0xF6, 
	0xD4, 0x9B, 0xE1, 0x50, 0x58, 0xE9, 0x55, 0x40, 0xD5, 0x5E, 0x05, 0x43, 0x58, 0xA2, 0x7A, 0xAF, 0x9F, 
	0x96, 0xEC, 0xAB, 0xA5, 0x4D, 0x95, 0x41, 0x2A, 0xEA, 0x9D, 0x43, 0x35, 0xA1, 0x28, 0x1D, 0xAF, 0xF1, 
	0xD3, 0x2A, 0x9F, 0xFF, 0x7F, 0x97, 0x96, 0x06, 0x16, 0x1E, 0x0E, 0x4B, 0x55, 0x7B, 0x2A, 0x55, 0x1A, 
	0xEA, 0x71, 0x91, 0x27, 0x5A, 0x47, 0x21, 0x5F, 0x90, 0x36, 0x6C, 0x3F, 0x8E, 0x7C, 0x1A, 0x79, 0x73, 
	0x33, 0x69, 0xFE, 0xFE, 0x10, 0x95, 0xD7, 0x84, 0xE9, 0xF1, 0x8D, 0x15, 0x4F, 0x4C, 0x1B, 0x98, 0x79, 
	0x7F, 0x26, 0xD8, 0x9B, 0x3D, 0x23, 0x7C, 0x08, 0xD4, 0x06, 0x0A, 0x3C, 0x92, 0x6E, 0x32, 0x45, 0x33, 
	0x73, 0xB3, 0xC1, 0x47, 0x4A, 0x92, 0x0A, 0x0B, 0x88, 0xAE, 0x9B, 0x0B, 0x0E, 0xBB, 0x8A, 0xF5, 0x6B, 
	0x3E, 0xC8, 0xEB, 0x62, 0xC1, 0x68, 0xF9, 0x44, 0xCF, 0xE1, 0xC7, 0x99, 0x6D, 0x57, 0x95, 0x0E, 0xD3, 
	0xA1, 0x7A, 0xDB, 0x6A, 0xF3, 0xC9, 0xE2, 0xC2, 0x2C, 0x4C, 0x03, 0xEF, 0x64, 0x27, 0x5D, 0xC8, 0xB0, 
	0xB4, 0x8C, 0x23, 0x06, 0xF9, 0xB7, 0x69, 0x26, 0x59, 0x27, 0x47, 0x4B, 0x3E, 0x29, 0xC5, 0x6D, 0x2C, 
	0x0C, 0x26, 0xD1, 0x80, 0x1F, 0x13, 0xED, 0x7E, 0xC0, 0x49, 0x4B, 0xF0, 0xF1, 0xAE, 0x36, 0xD9, 0xE5, 
	0x11, 0x4E, 0xE8, 0xF5, 0xCD, 0x1D, 0xCC, 0xCC, 0xE9, 0x6D, 0xDF, 0x7C, 0x6E, 0xDA, 0xE4, 0xFF, 0x4E, 
	0xF4, 0xD4, 0x12, 0x83, 0xD2, 0xF4, 0xD7, 0x40, 0xB4, 0x3E, 0x72, 0x96, 0xC2, 0x46, 0x59, 0x33, 0xA0, 
	0xF9, 0x23, 0xDC, 0xBA, 0x10, 0xD5, 0xDA, 0xDD, 0xB8, 0x0A, 0x66, 0x4C, 0x00, 0xE6, 0x0C, 0x95, 0x37, 
	0x9F, 0x41, 0x9D, 0xE6, 0xF4, 0xD6, 0xE1, 0x80, 0xF6, 0xB8, 0x61, 0x46, 0x64, 0x2B, 0xE4, 0xB6, 0x29, 
	0x74, 0x27, 0xDA, 0xF3, 0x89, 0x8F, 0xD5, 0x52, 0x0A, 0xEE, 0x75, 0xA5, 0x51, 0xFF, 0x3C, 0x0F, 0xC9, 
	0x46, 0xB4, 0xB7, 0xDB, 0xA1, 0x0E, 0x95, 0xA2, 0xF2, 0xB6, 0xB0, 0x6E, 0x94, 0x6E, 0x28, 0xAD, 0xA3, 
	0x5D, 0x55, 0x7E, 0x0A, 0x3A, 0x51, 0x61, 0x30, 0xB5, 0x2C, 0x1B, 0xBE, 0x12, 0x49, 0xF2, 0xBD, 0x89, 
	0x41, 0x37, 0xC6, 0x6F, 0xC8, 0xA3, 0xF3, 0xA5, 0xA1, 0x69, 0x76, 0xB5, 0xC0, 0x08, 0x68, 0xEB, 0xC3, 
	0x51, 0xDD, 0xBB, 0x6D, 0x6F, 0x39, 0x85, 0x8E, 0x7A, 0x49, 0x77, 0x78, 0x28, 0x37, 0x43, 0x65, 0x2C, 
	0xBF, 0x72, 0xF9, 0x41, 0xEF, 0x84, 0xA9, 0xFD, 0x33, 0x4C, 0x83, 0xF9, 0x00, 0x4C, 0x45, 0xCC, 0x9B, 
	0x9F, 0x02, 0xD0, 0x53, 0x89, 0x3F, 0x4B, 0xFF, 0x16, 0x64, 0x13, 0xF1, 0x85, 0x38, 0x76, 0xB2, 0x08, 
	0xA3, 0xDE, 0x59, 0x12, 0x37, 0x35, 0x9A, 0x76, 0x17, 0x6C, 0xBA, 0x05, 0x63, 0x60, 0x79, 0x6C, 0x50, 
	0x68, 0x0A, 0x0D, 0xA4, 0x4B, 0x98, 0x2D, 0x72, 0xC7, 0xD0, 0x16, 0xC1, 0xAC, 0xC1, 0xDE, 0x54, 0xB6, 
	0xA2, 0xF3, 0x4A, 0x85, 0x63, 0x04, 0xD6, 0xF4, 0x85, 0xAB, 0x29, 0xB4, 0x7F, 0x23, 0x88, 0x1F, 0x06, 
	0xFA, 0x93, 0xD6, 0x60, 0x66, 0x84, 0x18, 0xC5, 0x18, 0x54, 0xB7, 0x09, 0x67, 0x8A, 0x85, 0xA1, 0x61, 
	0x99, 0x78, 0xC3, 0x06, 0xE9, 0x07, 0x74, 0xD3, 0x7C, 0x6D, 0x35, 0x31, 0xD0, 0x95, 0x0A, 0x5B, 0xDE, 
	0xC2, 0x94, 0xB9, 0x13, 0xD3, 0xFF, 0xB9, 0xBF, 0xB6, 0x91, 0xA3, 0x5A, 0x31, 0x31, 0x23, 0xB7, 0x1A, 
	0x2D, 0x32, 0xB8, 0x95, 0xD5, 0x9A, 0x5F, 0x1A, 0xE0, 0x1C, 0x62, 0x4E, 0x25, 0x16, 0x95, 0xCD, 0x41, 
	0xDB, 0xAF, 0xF8, 0x56, 0x16, 0x95, 0xAF, 0xB8, 0x15, 0x16, 0xCD, 0x51, 0xC0, 0xCE, 0xE0, 0xFB, 0x46, 
	0x18, 0xA0, 0xBF, 0x14, 0xFD, 0xC3, 0xB8, 0x88, 0x1D, 0x4D, 0x11, 0x30, 0x78, 0x59, 0xD7, 0x49, 0xDC, 
	0x96, 0x6F, 0x82, 0x39, 0x09, 0xE6, 0xCA, 0x5A, 0x58, 0x7D, 0x1F, 0xCC, 0xA3, 0x18, 0x7C, 0xA3, 0x68, 
	0x91, 0x1B, 0x1C, 0x7D, 0x3F, 0x25, 0xAE, 0x89, 0x76, 0x10, 0xA0, 0x75, 0x9D, 0x45, 0x31, 0xA0, 0x09, 
	0x0C, 0xF3, 0xBE, 0x98, 0x74, 0xD2, 0x00, 0xA1, 0x4A, 0x4D, 0x46, 0x6F, 0xC9, 0x74, 0x9D, 0xC7, 0x71, 
	0xD7, 0xDD, 0xC3, 0x32, 0xE7, 0x75, 0x73, 0xA9, 0xCE, 0x6A, 0xAF, 0xBF, 0x7A, 0xEF, 0xF1, 0xC0, 0x0D, 
	0x65, 0x95, 0xBE, 0x15, 0x36, 0x05, 0x90, 0xC7, 0xD8, 0x5D, 0xA8, 0xD8, 0xA9, 0x14, 0x6A, 0xFC, 0x7B, 
	0xBD, 0x84, 0x6A, 0xCA, 0xF6, 0xC9, 0x03, 0x3D, 0x7F, 0x9A, 0x31, 0x2C, 0xF7, 0x16, 0x87, 0x22, 0x49, 
	0x87, 0x8F, 0x55, 0xEF, 0x5E, 0xBD, 0xA7, 0x66, 0x72, 0x85, 0x2F, 0xFA, 0x45, 0x46, 0x20, 0x48, 0x7D, 
	0x15, 0x3F, 0x95, 0xBB, 0x61, 0xD8, 0xC8, 0x7A, 0xCD, 0xF2, 0xC3, 0xC1, 0x0D, 0xD9, 0x8E, 0x0C, 0xDB, 
	0x01, 0x3B, 0x45, 0xBC, 0xF9, 0xE6, 0xF6, 0xB4, 0xE7, 0xBB, 0x93, 0xC1, 0x9C, 0xB2, 0xF7, 0x92, 0x70, 
	0xC6, 0x0E, 0xD8, 0x16, 0xEF, 0xC1, 0xE6, 0x5E, 0x34, 0x99, 0x3B, 0x67, 0x4D, 0xD2, 0xB5, 0xB0, 0x3B, 
	0x27, 0x6E, 0x58, 0x41, 0x05, 0xCC, 0x84, 0xC9, 0x78, 0x28, 0xB9, 0x8D, 0xDA, 0x60, 0x56, 0x3C, 0x4B, 
	0xB4, 0x7F, 0x0E, 0xD1, 0xB8, 0xF2, 0x46, 0xE6, 0x28, 0xB4, 0x6A, 0xEF, 0xB1, 0x9E, 0x66, 0x84, 0xB6, 
	0x90, 0xEB, 0x3C, 0x20, 0x6C, 0x86, 0x05, 0x0F, 0xA2, 0x0A, 0x7B, 0x1F, 0x04, 0x93, 0xC3, 0xC6, 0x1C, 
	0x17, 0x48, 0xA4, 0x22, 0x57, 0x0F, 0x8D, 0x6E, 0x0C, 0xEB, 0xE4, 0x92, 0x5B, 0x5E, 0x1C, 0xDA, 0xB5, 
	0x00, 0xF7, 0xFA, 0x39, 0x18, 0xF8, 0x08, 0x54, 0xDE, 0x0D, 0x1C, 0xF0, 0x24, 0xBA, 0xF9, 0xD6, 0x24, 
	0xEC, 0x06, 0x47, 0x74, 0xE0, 0x28, 0x99, 0x1F, 0x33, 0xD2, 0xDE, 0x30, 0xB6, 0x15, 0xEC, 0x97, 0xF2, 
	0x80, 0x92, 0xB4, 0x0F, 0x5D, 0x9D, 0xB3, 0x11, 0xF7, 0x1E, 0xC7, 0x1D, 0xC4, 0x24, 0x45, 0x38, 0x30, 
	0xD9, 0x1D, 0x5E, 0x71, 0x04, 0xD8, 0x5F, 0x09, 0xBC, 0xC2, 0x3E, 0x5F, 0x7E, 0x36, 0x19, 0xB7, 0xE3, 
	0xB7, 0x57, 0x9B, 0x0E, 0x1A, 0x5C, 0xBD, 0x1B, 0xA4, 0xB4, 0x1A, 0x73, 0xC9, 0x61, 0x20, 0xFA, 0x77, 
	0xCD, 0xCB, 0x1B, 0x3B, 0x09, 0x16, 0xFE, 0xBC, 0xF8, 0x44, 0xAB, 0x03, 0xCC, 0x32, 0xF0, 0xE2, 0x6A, 
	0xF7, 0x42, 0x5A, 0xBB, 0xC2, 0x76, 0x0E, 0x68, 0xEF, 0xC3, 0x3A, 0x89, 0xFC, 0xBA, 0x42, 0x92, 0xAC, 
	0x53, 0x3F, 0x4F, 0xDA, 0xA5, 0xF7, 0x15, 0x67, 0x3F, 0x5F, 0xE0, 0xE4, 0x15, 0xC9, 0xC9, 0x4C, 0xF7, 
	0xCC, 0xBC, 0xA0, 0xDF, 0xFF, 0x2C, 0x58, 0xB2, 0x6D, 0x2C, 0xE0, 0xEC, 0x75, 0xC8, 0x06, 0xF5, 0x4C, 
	0xB3, 0x53, 0x9D, 0x6E, 0xA3, 0x70, 0x44, 0xA7, 0x6B, 0x07, 0x78, 0x66, 0xDF, 0x3B, 0x32, 0x3F, 0xD6, 
	0x39, 0x67, 0x75, 0xCF, 0x19, 0x72, 0xEB, 0x05, 0xBD, 0x9F, 0x5C, 0xB9, 0xAE, 0x64, 0x72, 0xA6, 0x5D, 
	0xA1, 0x3C, 0x29, 0x42, 0x7F, 0x66, 0xB1, 0x0A, 0xDD, 0x49, 0x6F, 0x1C, 0xDB, 0xF2, 0xD5, 0x5F, 0xF3, 
	0x16, 0xCA, 0x85, 0xC0, 0xD4, 0xBB, 0x79, 0x3F, 0xA2, 0x22, 0x69, 0xD4, 0x87, 0x4D, 0x18, 0xC7, 0x21, 
	0x71, 0xF6, 0x63, 0x0C, 0xEA, 0x80, 0xC1, 0x1C, 0xAE, 0x30, 0xC9, 0x3C, 0x59, 0x3A, 0x7A, 0xAE, 0x41, 
	0x4F, 0xD3, 0x7F, 0x99, 0x87, 0x96, 0xF4, 0xBA, 0x26, 0xDB, 0xCA, 0x2B, 0xA3, 0x4D, 0x8F, 0x10, 0x6D, 
	0x9F, 0x63, 0x2E, 0x24, 0x27, 0x9A, 0xA3, 0x81, 0x30, 0x29, 0xFB, 0x86, 0x41, 0xE1, 0x0B, 0x89, 0xBE, 
	0xA7, 0x26, 0xA5, 0x43, 0x0D, 0x35, 0x5F, 0x06, 0x7B, 0xB0, 0x6E, 0x49, 0x12, 0x73, 0x1F, 0xE0, 0x36, 
	0xF6, 0xD5, 0x21, 0x5B, 0xCB, 0x8B, 0x2B, 0x75, 0x6B, 0x88, 0x3E, 0xBB, 0x8D, 0x2F, 0x55, 0x9B, 0xA6, 
	0xD1, 0xB1, 0x5A, 0xD8, 0x13, 0x39, 0x70, 0x04, 0xEC, 0xCD, 0x76, 0xE7, 0xB1, 0xAE, 0x5E, 0x3D, 0x52, 
	0xA6, 0x45, 0x2B, 0x55, 0x7A, 0x04, 0xD4, 0x7B, 0xB2, 0x0F, 0xEE, 0x1F, 0xDB, 0x0E, 0x62, 0xBE, 0x09, 
	0x2A, 0xAD, 0x67, 0xED, 0xD7, 0x48, 0xAE, 0x04, 0xBD, 0xCE, 0x02, 0x32, 0x8B, 0x9D, 0xFC, 0x0C, 0x9B, 
	0x26, 0x29, 0x13, 0x06, 0xEE, 0x6E, 0x10, 0xCD, 0x76, 0x3A, 0x97, 0xEE, 0x41, 0x6D, 0xCE, 0x81, 0x9F, 
	0x42, 0x7B, 0x1A, 0x4F, 0x8D, 0xD0, 0x60, 0x8E, 0xC4, 0x43, 0x8F, 0x4E, 0xE6, 0x85, 0x9E, 0x4F, 0x54, 
	0x91, 0x7C, 0x2E, 0x31, 0x30, 0x61, 0xCE, 0x83, 0x6F, 0xE9, 0xF7, 0x36, 0xC4, 0x6C, 0xFC, 0xE6, 0x26, 
	0xC1, 0x53, 0x1C, 0x87, 0x8E, 0xA2, 0x86, 0xEB, 0xFD, 0xCC, 0x2F, 0x50, 0xC8, 0x88, 0xC0, 0x95, 0x28, 
	0xCA, 0xFB, 0x7E, 0x03, 0x98, 0x1B, 0x52, 0x6E, 0x37, 0xCF, 0xD0, 0xA1, 0x7D, 0x32, 0xCF, 0xD3, 0xC2, 
	0x91, 0x95, 0x21, 0x43, 0xA2, 0xD0, 0x71, 0x3B, 0x18, 0x5D, 0x05, 0xEB, 0x46, 0x6D, 0xB7, 0x0F, 0xCF, 
	0x9B, 0xDE, 0xB4, 0xCC, 0xC1, 0xFD, 0xF2, 0x26, 0x2C, 0xDB, 0x71, 0xF8, 0xAC, 0x32, 0x5D, 0x3A, 0x58, 
	0x11, 0xD1, 0xE8, 0xB8, 0x17, 0xB3, 0xB4, 0x06, 0x15, 0xE6, 0x7D, 0x55, 0x47, 0x43, 0x97, 0x1B, 0x25, 
	0x50, 0xED, 0xB7, 0xE9, 0x26, 0xF3, 0x74, 0xA3, 0xE1, 0x68, 0x28, 0xAA, 0x30, 0x9E, 0x85, 0x95, 0x24, 
	0xEE, 0x29, 0x17, 0x8A, 0x28, 0x82, 0x82, 0x39, 0x4D, 0xEA, 0x66, 0xB9, 0xA0, 0x58, 0x90, 0x63, 0xD0, 
	0x55, 0xA0, 0x8D, 0x1C, 0x86, 0xFE, 0x1B, 0x92, 0x5F, 0x53, 0x02, 0xF2, 0x7E, 0x68, 0x0E, 0x8F, 0x32, 
	0x4D, 0x84, 0x5C, 0x12, 0x8B, 0x84, 0xD4, 0x9B, 0xF1, 0x26, 0x53, 0x55, 0x6E, 0xFC, 0x7A, 0x55, 0xF2, 
	0xFC, 0x2B, 0x9E, 0x26, 0x9A, 0x23, 0xC0, 0xCC, 0x2C, 0xA3, 0x31, 0x09, 0xBF, 0xFA, 0xC0, 0xF6, 0xDE, 
	0x56, 0x0D, 0x83, 0xE8, 0x1F, 0xD1, 0xAC, 0x28, 0x63, 0xAA, 0x7D, 0x80, 0xFE, 0x73, 0xB8, 0x1A, 0x0C, 
	0x1D, 0x00, 0x7D, 0xBD, 0x71, 0x45, 0xD2, 0xED, 0xA6, 0x65, 0xC0, 0xFA, 0x3F, 0x70, 0x55, 0x4D, 0x07, 
	0xC4, 0x07, 0xB6, 0x3F, 0x43, 0xF4, 0x51, 0x3D, 0xE3, 0x88, 0x7D, 0x34, 0x8B, 0x5E, 0xC0, 0x94, 0x0F, 
	0x1D, 0x87, 0x81, 0xB2, 0xB7, 0x2E, 0x4F, 0x0A, 0x68, 0x29, 0x83, 0x31, 0x29, 0x53, 0xF8, 0xCD, 0xE0, 
	0x52, 0xA6, 0x94, 0xEF, 0xF0, 0xFE, 0x19, 0x24, 0xC2, 0x7E, 0x93, 0x24, 0xBE, 0x59, 0x84, 0xD9, 0x0C, 
	0x2A, 0x3A, 0x49, 0x1E, 0x6D, 0xD9, 0x3F, 0x4E, 0x94, 0x35, 0x21, 0x0D, 0xB7, 0xF3, 0xF2, 0x81, 0x6C, 
	0x83, 0x74, 0x3B, 0xA1, 0x35, 0xCD, 0x76, 0x01, 0x5A, 0xD3, 0x0D, 0xEA, 0x95, 0x9B, 0x4D, 0xA3, 0xB3, 
	0x5C, 0x14, 0xD6, 0xA2, 0x54, 0xE4, 0x71, 0x37, 0xB3, 0xB1, 0x54, 0x55, 0xA6, 0xF1, 0xC3, 0xB2, 0x25, 
	0xC5, 0xD0, 0xA8, 0x22, 0x2C, 0xD1, 0xA1, 0x95, 0x06, 0x55, 0x87, 0xD0, 0x0E, 0x5D, 0xCE, 0x48, 0x57, 
	0xE4, 0xC2, 0x66, 0xD7, 0x3B, 0x6C, 0xEE, 0x83, 0x35, 0x74, 0x76, 0x7D, 0x7D, 0xE4, 0xA0, 0x37, 0x5F, 
	0x22, 0x79, 0x1A, 0xBB, 0x14, 0x64, 0x27, 0x0D, 0xDE, 0x49, 0xC7, 0x17, 0xE8, 0x64, 0xCF, 0xA5, 0xA0, 
	0xBB, 0x88, 0x01, 0x8B, 0x51, 0xD0, 0x3C, 0x28, 0x69, 0x52, 0xFB, 0xA7, 0xD3, 0x02, 0x45, 0x82, 0xFD, 
	0x0C, 0x8D, 0xC1, 0x00, 0xB2, 0xA2, 0xB2, 0xCF, 0xDE, 0xE3, 0x84, 0xEF, 0x10, 0x91, 0xBE, 0xBD, 0x66, 
	0xA8, 0xDB, 0x27, 0xBC, 0x1A, 0x37, 0xE7, 0xEC, 0xDE, 0x6A, 0xB3, 0x90, 0x57, 0x2C, 0xFF, 0x3B, 0x44, 
	0x43, 0xC4, 0xD5, 0x2C, 0x9A, 0x3C, 0xC9, 0x0C, 0x21, 0x1B, 0xB1, 0xD5, 0x04, 0xC9, 0xAC, 0x5C, 0xCB, 
	0x4B, 0xF8, 0x9E, 0xEA, 0x18, 0x31, 0x40, 0xEE, 0x16, 0x03, 0x00, 0xF5, 0xDE, 0x9F, 0xFC, 0xFA, 0x7B, 
	0x6C, 0xFC, 0x10, 0xB3, 0x8E, 0x48, 0x13, 0xF7, 0xF3, 0xF0, 0xB7, 0x81, 0x7B, 0xEB, 0xA6, 0x9B, 0x29, 
	0xEE, 0x6D, 0x31, 0xEB, 0x0D, 0x81, 0x2A, 0x5E, 0xA0, 0xF7, 0x89, 0xEF, 0x59, 0xBD, 0x9A, 0xDB, 0xFA, 
	0xBF, 0x41, 0x1B, 0x67, 0x09, 0x25, 0xB6, 0xA3, 0x7F, 0xD8, 0xDC, 0x7F, 0x75, 0x0C, 0xBF, 0xFE, 0xB8, 
	0x9E, 0x18, 0x5B, 0x7E, 0x4B, 0x84, 0x3C, 0x56, 0x27, 0x7A, 0x04, 0x52, 0xC7, 0xAC, 0x14, 0xE6, 0xBB, 
	0x54, 0xEA, 0x61, 0xD8, 0xD9, 0x4A, 0x1F, 0xE8, 0xCA, 0x62, 0x0C, 0x31, 0x2B, 0x11, 0xEC, 0x6C, 0xBE, 
	0x9A, 0xC2, 0x17, 0x9F, 0x8C, 0xE6, 0x0B, 0x81, 0xF0, 0x19, 0x15, 0x9A, 0x90, 0x29, 0x11, 0x4C, 0x72, 
	0x3A, 0x84, 0x71, 0xBA, 0xCC, 0x25, 0x34, 0xC9, 0x0C, 0x77, 0x3D, 0x62, 0x90, 0x23, 0x9F, 0x2E, 0x02, 
	0xDD, 0x0D, 0xE1, 0x07, 0xA1, 0xE5, 0x9D, 0x60, 0x6F, 0x19, 0x8C, 0x65, 0x17, 0x03, 0x61, 0xD7, 0x01, 
	0x2B, 0xC9, 0xB5, 0x7D, 0xE1, 0x01, 0x1E, 0x81, 0x6B, 0x80, 0x5D, 0x08, 0x1D, 0x15, 0xA2, 0xC3, 0xE8, 
	0x1B, 0x9B, 0x60, 0x6A, 0x78, 0x68, 0xB9, 0x53, 0x93, 0x1E, 0x4B, 0x17, 0x85, 0xC2, 0xBF, 0x5B, 0x9A, 
	0xB8, 0x3D, 0xB3, 0x1A, 0xA5, 0xD8, 0xE0, 0xB5, 0xDA, 0x4D, 0x2F, 0xAB, 0x8D, 0x6C, 0xA3, 0x24, 0xC4, 
	0x12, 0xE2, 0xDD, 0xF6, 0x35, 0x9C, 0x60, 0x26, 0xC9, 0x0D, 0x77, 0x96, 0xC4, 0xF6, 0x25, 0x29, 0xDE, 
	0x18, 0xCB, 0x84, 0x69, 0x89, 0x31, 0x44, 0xCE, 0x85, 0x7C, 0x0F, 0xC9, 0xD8, 0x13, 0xED, 0x9F, 0xC6, 
	0xC1, 0xBA, 0xFA, 0xB8, 0x32, 0xAE, 0x94, 0xCD, 0x6E, 0x63, 0x30, 0xFD, 0x03, 0x2C, 0x96, 0x5D, 0xEB, 
	0xF8, 0x3A, 0xD5, 0x2F, 0xC8, 0xEA, 0xA0, 0xAF, 0x76, 0x03, 0x3A, 0x0A, 0x96, 0xD6, 0xE0, 0x14, 0x6A, 
	0xB0, 0x3F, 0x74, 0x0B, 0xBA, 0x61, 0x61, 0x87, 0x06, 0x69, 0x4B, 0x92, 0x1B, 0x61, 0x3F, 0xA6, 0x3E, 
	0x03, 0x6F, 0x14, 0x77, 0xB4, 0x97, 0x2D, 0x27, 0x03, 0x4A, 0x7B, 0xD9, 0x69, 0x0D, 0x66, 0x66, 0xB7, 
	0x7D, 0xCA, 0x28, 0x15, 0xCA, 0xE8, 0x87, 0x06, 0xCD, 0x48, 0x06, 0x1E, 0xE6, 0xA5, 0xEC, 0xE4, 0x4B, 
	0x81, 0x16, 0x2C, 0xB1, 0x3F, 0x8D, 0x3B, 0xE8, 0x76, 0xA1, 0xD2, 0xC1, 0xA0, 0xC5, 0x5E, 0xE6, 0x31, 
	0x80, 0x0E, 0xA1, 0xE8, 0x80, 0x65, 0x5E, 0x19, 0xB7, 0xDD, 0xEC, 0xE4, 0x5C, 0xAC, 0x88, 0xFC, 0xE3, 
	0x71, 0xB1, 0x9D, 0x31, 0x9C, 0x79, 0xEF, 0x33, 0x60, 0xA7, 0x60, 0xBB, 0xAB, 0xC7, 0x0E, 0x8C, 0x60, 
	0xF1, 0xB6, 0xE5, 0x98, 0x39, 0xFB, 0x5A, 0x83, 0xF9, 0xA8, 0x58, 0x4E, 0xD8, 0xA9, 0x71, 0xBC, 0xFD, 
	0x50, 0x25, 0xEB, 0xD8, 0xA5, 0x22, 0x66, 0x27, 0x51, 0xA1, 0x7A, 0xA1, 0x37, 0x98, 0x22, 0x6F, 0xD5, 
	0xB3, 0x43, 0x82, 0x42, 0xF4, 0x33, 0xE8, 0xB2, 0xBF, 0xE5, 0x14, 0xD0, 0x29, 0x36, 0x27, 0x19, 0x94, 
	0x64, 0x55, 0x00, 0xA3, 0x61, 0x9C, 0xE2, 0x06, 0x03, 0xC8, 0xB7, 0xA2, 0xF5, 0x43, 0x2D, 0x42, 0x5B, 
	0x6C, 0x7A, 0x5B, 0xD8, 0x30, 0x0C, 0xD0, 0xEA, 0x71, 0x99, 0x16, 0x80, 0x66, 0x27, 0x41, 0x3E, 0x08, 
	0x6C, 0xA5, 0xF1, 0x95, 0xB3, 0x82, 0x24, 0xD1, 0xAA, 0xE1, 0x9C, 0x64, 0x98, 0x4A, 0x8B, 0xCC, 0x99, 
	0xEE, 0xA7, 0x02, 0xC8, 0x0D, 0xB6, 0x2F, 0xEA, 0x57, 0x07, 0xAA, 0xD4, 0x9B, 0x2F, 0x20, 0x30, 0x76, 
	0x3B, 0x0C, 0x47, 0xFF, 0xE3, 0xCF, 0xF9, 0x80, 0x18, 0x1F, 0xBB, 0x45, 0xA6, 0x28, 0xF1, 0x38, 0x75, 
	0xBD, 0x83, 0x22, 0x19, 0x2A, 0xE1, 0xDB, 0x8C, 0x1A, 0xC3, 0x0F, 0xD7, 0x4C, 0x96, 0xFE, 0x13, 0xF2, 
	0x38, 0x89, 0x7D, 0x20, 0xF8, 0x2F, 0x03, 0xDA, 0xB9, 0xAD, 0x35, 0x40, 0xA7, 0xC7, 0x71, 0xB1, 0x1A, 
	0x72, 0x3E, 0x2C, 0x73, 0x70, 0xC2, 0xCF, 0x76, 0x84, 0x61, 0x84, 0x79, 0x61, 0xDC, 0x88, 0x27, 0x82, 
	0x3C, 0x5C, 0x54, 0xF0, 0x8C, 0x5C, 0x8E, 0xAB, 0xA3, 0x44, 0x9D, 0x7A, 0xFB, 0xA8, 0x61, 0xD8, 0x95, 
	0x74, 0xF6, 0x5C, 0x85, 0x85, 0xCD, 0xFC, 0x8F, 0x87, 0x89, 0x96, 0x2C, 0xC0, 0xD4, 0xAE, 0xAF, 0xC2, 
	0xA7, 0xDB, 0x21, 0xCF, 0x41, 0x1F, 0x6A, 0x0B, 0x83, 0x06, 0xC0, 0x0C, 0x47, 0x12, 0x8F, 0x56, 0x6A, 
	0x94, 0x06, 0x80, 0xBC, 0xCB, 0x3C, 0x3C, 0x74, 0xCA, 0xC2, 0xD9, 0x7D, 0xB9, 0x49, 0x24, 0x46, 0xBD, 
	0x8F, 0x8F, 0x20, 0x16, 0x4A, 0xAB, 0x4E, 0x9E, 0xBF, 0xDF, 0x2D, 0x7C, 0x0E, 0x60, 0x63, 0xEB, 0x46, 
	0x11, 0x7C, 0xE1, 0x29, 0xDD, 0x34, 0x57, 0x42, 0xE8, 0x2C, 0x2F, 0x75, 0xA5, 0xD3, 0xB8, 0xCB, 0xB9, 
	0x8D, 0x7D, 0xA9, 0x3D, 0x29, 0xBB, 0xEF, 0x84, 0x69, 0xFD, 0xFA, 0xAF, 0x60, 0x82, 0xFB, 0x98, 0x11, 
	0xCE, 0x02, 0xD0, 0xBF, 0xC4, 0x75, 0xC1, 0x56, 0x0E, 0x10, 0xD2, 0xC5, 0xC2, 0x57, 0x88, 0x9B, 0x79, 
	0x97, 0xC8, 0xA6, 0x89, 0xAE, 0xBF, 0xC3, 0xC6, 0x0D, 0x77, 0x3D, 0x9D, 0x79, 0x28, 0xE0, 0x25, 0x89, 
	0xFB, 0x15, 0xFB, 0x60, 0xF0, 0x94, 0x10, 0x5D, 0x86, 0x89, 0x42, 0x39, 0xB7, 0x93, 0x03, 0x9A, 0x0C, 
	0xB8, 0xD6, 0x6A, 0x81, 0xE5, 0x51, 0x65, 0x73, 0xB6, 0xF0, 0x63, 0xF9, 0x3E, 0x34, 0x29, 0x77, 0xBB, 
	0x69, 0xB5, 0x5A, 0x1F, 0x6B, 0x26, 0x09, 0xC7, 0x0E, 0x0D, 0x5E, 0x93, 0xFC, 0x8A, 0x9E, 0x7D, 0xC0, 
	0xD0, 0xBF, 0x25, 0x73, 0xE5, 0xAD, 0x28, 0x21, 0x5F, 0xA6, 0x19, 0x4E, 0xA9, 0x23, 0x27, 0x1D, 0xAA, 
	0x04, 0x20, 0xB7, 0x5A, 0x38, 0x55, 0x53, 0x30, 0xB3, 0x7E, 0x8F, 0x9F, 0xA7, 0xE7, 0x6E, 0x36, 0x98, 
	0x54, 0x3A, 0x06, 0x5A, 0x9A, 0xDF, 0xA5, 0x00, 0xCD, 0x56, 0xB3, 0xCE, 0xB1, 0x7C, 0xEC, 0xE5, 0x95, 
	0xAD, 0x3C, 0xA0, 0x34, 0xCF, 0x9C, 0xE1, 0x4A, 0x38, 0xFA, 0xF2, 0xD3, 0xA8, 0xE5, 0x95, 0x25, 0x43, 
	0xCC, 0x64, 0x62, 0x89, 0xD1, 0x21, 0x16, 0x97, 0x7A, 0x79, 0xC9, 0x6F, 0x9B, 0xC9, 0xA3, 0x3E, 0xAF, 
	0xA8, 0x7C, 0x1D, 0x80, 0x59, 0x73, 0xAB, 0xA3, 0x24, 0xA3, 0xF8, 0x2C, 0x4C, 0x89, 0xD9, 0x98, 0x5E, 
	0xEF, 0xEC, 0x2F, 0x53, 0x27, 0x7E, 0xD4, 0x5D, 0xB6, 0x7E, 0xC0, 0x19, 0x69, 0x7E, 0x31, 0x11, 0x06, 
	0x2E, 0x7D, 0xDB, 0x84, 0x35, 0xE6, 0x35, 0x0F, 0xD0, 0x34, 0xBB, 0x25, 0x40, 0x7F, 0x46, 0x66, 0x8E, 
	0xB7, 0xC3, 0x96, 0xB3, 0xBF, 0x0A, 0x13, 0x46, 0x5D, 0x94, 0x80, 0x68, 0xAE, 0x64, 0xB7, 0x42, 0xD5, 
	0xA3, 0x35, 0xFA, 0x15, 0x73, 0xB5, 0x5F, 0xB3, 0xAE, 0xB1, 0x1D, 0x68, 0x96, 0x1F, 0x4B, 0x62, 0xD2, 
	0x00, 0xE1, 0xF6, 0xD1, 0x6E, 0x9A, 0x6F, 0x43, 0x39, 0x5D, 0x06, 0xD3, 0x72, 0xBC, 0x8F, 0x92, 0xA4, 
	0x9F, 0x8C, 0xE0, 0x0B, 0x86, 0x0F, 0x9B, 0x9B, 0x58, 0xD9, 0x6A, 0xCA, 0x8F, 0x61, 0xF5, 0x39, 0x5A, 
	0x59, 0xFA, 0x53, 0x28, 0xE1, 0xA4, 0xFD, 0xD8, 0x4B, 0x19, 0x39, 0x7D, 0x45, 0xE4, 0x18, 0xDF, 0x9D, 
	0xC7, 0x54, 0x91, 0x9E, 0x9C, 0x13, 0xA5, 0x4F, 0x2E, 0x5E, 0x41, 0x34, 0x8D, 0x77, 0xA6, 0x0B, 0x56, 
	0xE5, 0xE4, 0x99, 0xAC, 0x4E, 0x9B, 0x3A, 0xAB, 0x93, 0x82, 0x8A, 0x45, 0xCA, 0xF8, 0x12, 0x70, 0x32, 
	0x46, 0xFD, 0x0D, 0xD1, 0xB0, 0x07, 0xA0, 0x52, 0xE6, 0x8C, 0xDC, 0x7C, 0x19, 0x46, 0x6B, 0x51, 0xD2, 
	0x78, 0x69, 0x3C, 0x31, 0xCF, 0xF1, 0x26, 0xA2, 0x2D, 0x9B, 0xF9, 0xA1, 0xFD, 0x16, 0xB0, 0x57, 0xD9, 
	0x4A, 0x23, 0x63, 0x61, 0xB6, 0x0D, 0x95, 0x6D, 0xD7, 0x5C, 0x29, 0x99, 0x8E, 0x67, 0xB7, 0x8F, 0x65, 
	0xBA, 0xBE, 0xE7, 0x7F, 0x50, 0xE0, 0xCF, 0x95, 0x7C, 0x9B, 0x76, 0xB2, 0x2E, 0x86, 0x3E, 0x95, 0x07, 
	0x85, 0xA3, 0xBA, 0x36, 0x31, 0xBF, 0x07, 0xF9, 0x1F, 0x29, 0x94, 0xC8, 0xD9, 0x65, 0xFE, 0x08, 0xC8, 
	0x01, 0x0E, 0x9E, 0xAF, 0x92, 0xFF, 0x9A, 0x05, 0x7A, 0x2E, 0x86, 0x3F, 0xEF, 0x66, 0xA1, 0xA3, 0x49, 
	0xE8, 0x9B, 0x77, 0x2E, 0xB3, 0x5C, 0x61, 0x4D, 0x0C, 0x75, 0xD8, 0xCC, 0x98, 0x52, 0xA2, 0x96, 0x76, 
	0x93, 0xAC, 0x19, 0x71, 0xC7, 0x13, 0x96, 0xE3, 0xB0, 0xB7, 0x43, 0xE0, 0x89, 0x51, 0xB0, 0x3D, 0xA3, 
	0xEC, 0x67, 0x1E, 0x23, 0x19, 0xC3, 0x00, 0xFD, 0x6C, 0x27, 0xC5, 0xB3, 0x14, 0x88, 0xFA, 0x18, 0x12, 
	0x16, 0x5B, 0xB0, 0x29, 0x2C, 0x81, 0x7E, 0xEC, 0xCF, 0x57, 0xB0, 0xBD, 0x1D, 0x7F, 0x23, 0xBE, 0x9B, 
	0xBD, 0x05, 0xCB, 0x2C, 0x0C, 0x0F, 0x32, 0x6C, 0x86, 0x99, 0x30, 0x48, 0x7E, 0xE1, 0xE3, 0xFB, 0x15, 
	0x2C, 0xA9, 0x96, 0xF8, 0xCE, 0x33, 0x16, 0x98, 0xBD, 0x84, 0xCC, 0xFD, 0xCE, 0x2E, 0x77, 0x21, 0x95, 
	0x0D, 0x7A, 0x82, 0x3E, 0x09, 0xC1, 0xD6, 0x79, 0x40, 0x6F, 0x39, 0x9C, 0xC5, 0x0C, 0xE8, 0x0B, 0x12, 
	0xF3, 0x3B, 0xDD, 0x32, 0x55, 0xF7, 0x53, 0x4D, 0x1B, 0xBD, 0x6B, 0xA4, 0x6E, 0x5C, 0x97, 0xEF, 0x07, 
	0x2D, 0x67, 0xBC, 0x7E, 0x30, 0x9D, 0x55, 0x66, 0xE2, 0x2D, 0xA5, 0x96, 0xFE, 0xF6, 0x04, 0x07, 0xA3, 
	0x11, 0x80, 0x4A, 0x75, 0x73, 0xF7, 0x4F, 0x40, 0x52, 0x4C, 0x2B, 0xBA, 0x51, 0x74, 0x0D, 0x08, 0xF7, 
	0x27, 0x98, 0xC8, 0x92, 0x51, 0x01, 0x02, 0x5A, 0x2A, 0x1C, 0x77, 0xA1, 0x76, 0x16, 0xFD, 0x25, 0xB6, 
	0xA4, 0xFC, 0x58, 0x27, 0xC4, 0x33, 0x6D, 0x8A, 0xD6, 0xD2, 0x5A, 0x43, 0xFB, 0x2B, 0x3E, 0x7D, 0xDE, 
	0xA6, 0x90, 0x22, 0x19, 0xA1, 0x88, 0xD9, 0xEE, 0xA6, 0x49, 0x83, 0x57, 0xED, 0x93, 0x72, 0x28, 0x80, 
	0xC6, 0x46, 0xD9, 0xC1, 0xD3, 0x07, 0xAF, 0x24, 0x9A, 0x1A, 0xA2, 0xF6, 0xA2, 0x6B, 0xD8, 0xE0, 0xDE, 
	0xF0, 0x45, 0xA6, 0x52, 0xD5, 0xD2, 0x7B, 0xF9, 0xE6, 0xA6, 0x76, 0x3E, 0xFF, 0x7F, 0xF6, 0x10, 0x99, 
	0x6C, 0x5D, 0x06, 0xD0, 0x8C, 0x43, 0x77, 0xC0, 0x92, 0xAB, 0x25, 0xFA, 0x4B, 0xDB, 0xAE, 0x37, 0xA2, 
	0x21, 0xBE, 0x24, 0xD0, 0xB4, 0xE7, 0x1C, 0x3E, 0x0A, 0xA8, 0x3E, 0x92, 0x26, 0xC9, 0x66, 0xEC, 0x54, 
	0x5D, 0xA0, 0xF2, 0xED, 0x20, 0xB1, 0x81, 0x72, 0x31, 0xE9, 0xEA, 0x9D, 0x71, 0xFF, 0x05, 0x4A, 0xDC, 
	0x30, 0xC5, 0x09, 0xAF, 0x09, 0xD3, 0xE8, 0x85, 0x36, 0xBE, 0xA2, 0xC5, 0x42, 0xAF, 0x9F, 0x36, 0x20, 
	0x1E, 0x0E, 0xA8, 0xF9, 0x07, 0x83, 0xAA, 0x92, 0x55, 0x24, 0x0D, 0xE5, 0x66, 0x61, 0x1A, 0xC8, 0x44, 
	0xFF, 0x39, 0x24, 0x99, 0x54, 0x49, 0xC5, 0x30, 0x52, 0x49, 0x91, 0xE4, 0xE4, 0xCE, 0x97, 0x11, 0x25, 
	0x17, 0x84, 0xBD, 0x4A, 0x31, 0xAB, 0x48, 0x49, 0x6A, 0x0E, 0xB3, 0xC5, 0x52, 0x97, 0x64, 0x50, 0x3A, 
	0xC4, 0xDC, 0xB3, 0x15, 0x0B, 0x62, 0xE3, 0x17, 0xCD, 0xAF, 0x16, 0x84, 0x2B, 0x7C, 0x68, 0xDA, 0x2D, 
	0x1A, 0x5F, 0xBA, 0x6B, 0x21, 0x85, 0xB4, 0x3A, 0xAA, 0x99, 0x55, 0x9A, 0x64, 0xF3, 0x12, 0x91, 0xBF, 
	0x10, 0x4E, 0x64, 0x26, 0xDB, 0x77, 0x33, 0xDB, 0xDC, 0x23, 0x50, 0x47, 0x60, 0xD9, 0x0D, 0x95, 0x7C, 
	0x0A, 0x6B, 0xC7, 0x06, 0xF3, 0x8C, 0x41, 0x7D, 0xD0, 0x8E, 0x99, 0xE4, 0x67, 0x9E, 0xE5, 0x7C, 0x7C, 
	0x71, 0x11, 0x64, 0x4B, 0xDB, 0xF3, 0xBB, 0x07, 0x19, 0xC8, 0x6F, 0xB4, 0x21, 0xE6, 0x6B, 0x24, 0x8A, 
	0xDC, 0x86, 0xD8, 0xB1, 0x95, 0xBF, 0x21, 0x35, 0x2A, 0x53, 0xA2, 0x0E, 0xBC, 0x37, 0x8B, 0x17, 0xCF, 
	0xE1, 0x05, 0xDE, 0x1F, 0x6C, 0xE1, 0xC4, 0xA7, 0x86, 0x59, 0x52, 0xA3, 0xAA, 0xFF, 0x2E, 0x21, 0x3D, 
	0x09, 0x79, 0xEA, 0xCE, 0xC5, 0xB4, 0xBA, 0xFB, 0x5A, 0x1E, 0x86, 0x85, 0x73, 0x6E, 0x9B, 0x86, 0xFE, 
	0x1C, 0x21, 0x82, 0x1D, 0xE6, 0x1D, 0xD2, 0x29, 0x9C, 0xFE, 0x32, 0x45, 0x3E, 0xD8, 0xC5, 0x4D, 0x39, 
	0x06, 0xD9, 0x47, 0xBA, 0xD1, 0xF8, 0x55, 0x4F, 0x11, 0x2D, 0x14, 0x31, 0xE9, 0xA3, 0x44, 0xCB, 0xFE, 
	0xD4, 0x38, 0xCA, 0xF5, 0x07, 0x11, 0xD3, 0x65, 0x46, 0xF7, 0x40, 0x11, 0xAD, 0x62, 0x6D, 0x72, 0xBD, 
	0x62, 0x14, 0xAC, 0xFD, 0x5C, 0xCF, 0x02, 0xF0, 0x64, 0xDA, 0xAC, 0x55, 0x53, 0xA5, 0x5E, 0x46, 0xBE, 
	0x88, 0x4E, 0xE5, 0xD1, 0x5E, 0xAF, 0xC0, 0x09, 0x5D, 0xDF, 0x98, 0xF5, 0x03, 0x92, 0x6C, 0xFB, 0x5D, 
	0x7A, 0xFE, 0x81, 0x00, 0xB2, 0x06, 0x42, 0x51, 0x70, 0x22, 0x06, 0x9C, 0xA1, 0x31, 0x90, 0xE2, 0xBF, 
	0x7C, 0xCC, 0xF8, 0xAE, 0x84, 0x15, 0xE0, 0x30, 0x49, 0x69, 0xAF, 0x47, 0xD2, 0x8E, 0xD5, 0x47, 0x34, 
	0xF2, 0xEA, 0x12, 0x9A, 0xA6, 0x37, 0x78, 0x05, 0x6C, 0x56, 0xD7, 0xE7, 0x4A, 0xE5, 0x74, 0x39, 0x75, 
	0xDF, 0x8E, 0x39, 0xFC, 0x7C, 0x00, 0x70, 0x76, 0x5F, 0xFE, 0xC4, 0x85, 0xB9, 0x21, 0x49, 0x34, 0x18, 
	0x23, 0xFE, 0x28, 0x40, 0xB5, 0x72, 0xDE, 0x5A, 0x2A, 0xDE, 0xAC, 0x91, 0x47, 0xED, 0xC3, 0x4F, 0x51, 
	0xF1, 0xC6, 0xFD, 0x0C, 0x57, 0x1D, 0xD1, 0x04, 0x89, 0x2D, 0x71, 0x5C, 0x80, 0xFE, 0x99, 0x8E, 0x01, 
	0xBA, 0x90, 0xFF, 0xC6, 0x18, 0xDA, 0xDC, 0x78, 0x81, 0x0A, 0x4D, 0x97, 0xF8, 0x06, 0x0C, 0x8F, 0x30, 
	0x39, 0x14, 0x1E, 0x39, 0x6A, 0x58, 0xBC, 0x32, 0xE0, 0xA4, 0x0F, 0x7F, 0x9B, 0x6D, 0xA9, 0x98, 0x81, 
	0x81, 0xBD, 0x83, 0x1B, 0x32, 0xEB, 0x90, 0x67, 0x1C, 0xDE, 0x5E, 0x2E, 0xF1, 0x72, 0x86, 0x51, 0xFC, 
	0x8C, 0x19, 0x12, 0xF9, 0x23, 0xF1, 0xFC, 0x23, 0x17, 0xDB, 0xF9, 0x10, 0x5F, 0x47, 0x3C, 0x1E, 0xDE, 
	0x78, 0x5E, 0x45, 0x7B, 0x02, 0x95, 0x0D, 0x0F, 0x9C, 0xA9, 0xF8, 0xE8, 0x20, 0xBB, 0x89, 0x3E, 0x1B, 
	0xAF, 0x27, 0x73, 0x01, 0x02, 0x89, 0x8E, 0x26, 0x1F, 0xE4, 0x82, 0x2E, 0x18, 0xF3, 0x7D, 0x44, 0x7C, 
	0x6F, 0x8B, 0x1E, 0x6F, 0xBB, 0x81, 0xFB, 0xF8, 0x42, 0x2A, 0xCA, 0x72, 0x91, 0x5D, 0x97, 0x3B, 0xE6, 
	0xDE, 0xCE, 0x06, 0xDF, 0x4B, 0x74, 0x66, 0x1D, 0x94, 0x34, 0x19, 0x88, 0x9A, 0x05, 0xC5, 0xDF, 0xAA, 
	0xF2, 0xB0, 0xBF, 0x8B, 0x62, 0x8F, 0x5D, 0x05, 0x4A, 0x88, 0x96, 0x3F, 0xBF, 0x97, 0xDC, 0x8B, 0x57, 
	0xD0, 0xC4, 0xF3, 0x86, 0x70, 0x50, 0x36, 0xBA, 0xBF, 0xEA, 0x98, 0x40, 0xFD, 0xFD, 0x7E, 0xFE, 0xE7, 
	0x15, 0x40, 0x12, 0xFA, 0x1E, 0x89, 0xEC, 0x25, 0x32, 0x8F, 0x64, 0x20, 0xAF, 0xA4, 0xA9, 0xA4, 0x07, 
	0xEB, 0x51, 0xD4, 0x2E, 0xF2, 0xDC, 0x50, 0x64, 0xFE, 0xA5, 0x34, 0x75, 0x2C, 0xEE, 0x3D, 0xD2, 0xC6, 
	0xFB, 0xF9, 0x5D, 0xBC, 0x3C, 0x44, 0xF4, 0xE8, 0xA1, 0xFF, 0x17, 0x60, 0x00, 0xDF, 0x73, 0xDF, 0x54, 
	0x96, 0xA5, 0xA5, 0xC5, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
};


static bool checkModified(Poco::Net::HTTPServerRequest& request)
{
	Poco::DateTime modified(2018, 9, 21, 7, 25, 46);
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


void HeaderLogoX2::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png"s);

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 370 "/Users/guenter/ws/git/my-devices/gateway/src/HeaderLogoX2.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
