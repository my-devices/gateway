//
// FooterLogoX2.cpp
//
// This file has been generated from FooterLogoX2.cpsp on 2018-09-21 07:59:28.
//


#include "FooterLogoX2.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"


#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/ws/git/my-devices/gateway/src/FooterLogoX2.cpsp"


// res/FooterLogoX2.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x50, 0x08, 0x03, 0x00, 0x00, 0x00, 0x78, 0x64, 0x8A, 0x76, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x01, 0xCB, 0x50, 0x4C, 0x54, 0x45, 0xBD, 0xBD, 0xBD, 0x44, 0x40, 0x41, 0xEF, 
	0xEF, 0xEF, 0xF0, 0xF0, 0xF0, 0xBC, 0xBC, 0xBC, 0xB9, 0xB9, 0xB9, 0xBB, 0xBB, 0xBB, 0xEE, 0xEE, 0xEE, 
	0xBA, 0xBA, 0xBA, 0xB7, 0xB7, 0xB7, 0xB5, 0xB5, 0xB5, 0xF1, 0xF1, 0xF1, 0xB8, 0xB8, 0xB8, 0xC0, 0xC0, 
	0xC0, 0xED, 0xED, 0xED, 0xF2, 0xF2, 0xF2, 0xC1, 0xC1, 0xC1, 0xCC, 0xCC, 0xCC, 0xE7, 0xE7, 0xE7, 0xD9, 
	0xD9, 0xD9, 0xDE, 0xDE, 0xDE, 0xEA, 0xEA, 0xEA, 0xD6, 0xD6, 0xD6, 0xE4, 0xE4, 0xE4, 0xCD, 0xCD, 0xCD, 
	0xBE, 0xBE, 0xBE, 0xBF, 0xBF, 0xBF, 0xE6, 0xE6, 0xE6, 0xC7, 0xC7, 0xC7, 0xE8, 0xE8, 0xE8, 0xE3, 0xE3, 
	0xE3, 0xE9, 0xE9, 0xE9, 0xEB, 0xEB, 0xEB, 0xD3, 0xD3, 0xD3, 0xEC, 0xEC, 0xEC, 0xC4, 0xC4, 0xC4, 0xD9, 
	0xD8, 0xD8, 0xC8, 0xC8, 0xC8, 0xC9, 0xC9, 0xC9, 0xD0, 0xCF, 0xCF, 0xE2, 0xE2, 0xE2, 0xCA, 0xCA, 0xCA, 
	0xCE, 0xCE, 0xCE, 0xD8, 0xD8, 0xD8, 0xD4, 0xD4, 0xD4, 0xC5, 0xC5, 0xC5, 0xDC, 0xDC, 0xDC, 0xC2, 0xC2, 
	0xC2, 0xE0, 0xE0, 0xE0, 0x4A, 0x47, 0x48, 0xCC, 0xCB, 0xCC, 0x46, 0x43, 0x44, 0x47, 0x43, 0x44, 0xD5, 
	0xD5, 0xD5, 0xD2, 0xD2, 0xD2, 0xDA, 0xDA, 0xDA, 0xC9, 0xC8, 0xC8, 0x43, 0x3F, 0x40, 0xDA, 0xD9, 0xD9, 
	0xB4, 0xB4, 0xB4, 0x45, 0x42, 0x43, 0xDB, 0xDB, 0xDB, 0x73, 0x71, 0x71, 0x49, 0x46, 0x47, 0xD2, 0xD1, 
	0xD1, 0x66, 0x64, 0x64, 0xDB, 0xDA, 0xDA, 0xE1, 0xE1, 0xE1, 0x97, 0x96, 0x96, 0xD0, 0xD0, 0xD0, 0xF4, 
	0xF4, 0xF4, 0x92, 0x91, 0x91, 0x4D, 0x4A, 0x4B, 0xC3, 0xC3, 0xC3, 0xDD, 0xDD, 0xDD, 0xD7, 0xD7, 0xD7, 
	0x59, 0x56, 0x57, 0xD7, 0xD6, 0xD7, 0x66, 0x64, 0x65, 0x48, 0x44, 0x45, 0x75, 0x73, 0x73, 0x78, 0x77, 
	0x77, 0x7A, 0x78, 0x79, 0x72, 0x70, 0x70, 0x99, 0x97, 0x98, 0x51, 0x4E, 0x4E, 0x67, 0x64, 0x65, 0x79, 
	0x77, 0x78, 0x5D, 0x5B, 0x5B, 0x68, 0x66, 0x66, 0x90, 0x8E, 0x8E, 0x7E, 0x7B, 0x7C, 0xCE, 0xCD, 0xCD, 
	0x48, 0x45, 0x46, 0x53, 0x50, 0x50, 0xDA, 0xD9, 0xDA, 0x6E, 0x6C, 0x6D, 0xD9, 0xD8, 0xD9, 0x99, 0x98, 
	0x98, 0x55, 0x52, 0x52, 0x47, 0x44, 0x44, 0xC6, 0xC6, 0xC6, 0xD6, 0xD5, 0xD6, 0x4D, 0x4A, 0x4A, 0x4F, 
	0x4C, 0x4D, 0x5E, 0x5C, 0x5D, 0xB2, 0xB2, 0xB2, 0x97, 0x95, 0x96, 0x8A, 0x89, 0x89, 0xBF, 0xBE, 0xBE, 
	0x8E, 0x8C, 0x8D, 0xB2, 0xB0, 0xB0, 0xAE, 0xAD, 0xAD, 0xAE, 0xAC, 0xAC, 0x6B, 0x69, 0x69, 0x82, 0x80, 
	0x81, 0x50, 0x4D, 0x4D, 0x59, 0x56, 0x56, 0x86, 0x84, 0x85, 0x7D, 0x7C, 0x7C, 0x90, 0x8E, 0x8F, 0x88, 
	0x86, 0x87, 0x95, 0x94, 0x94, 0x82, 0x80, 0x80, 0x5C, 0x5A, 0x5B, 0xBD, 0xBB, 0xBB, 0xC1, 0xC0, 0xC0, 
	0x56, 0x53, 0x54, 0xD7, 0xD6, 0xD6, 0x7C, 0x7A, 0x7B, 0x83, 0x82, 0x82, 0xA0, 0x9E, 0x9F, 0x46, 0x42, 
	0x43, 0x53, 0x51, 0x51, 0xB1, 0xB0, 0xB0, 0xE5, 0xE5, 0xE5, 0x78, 0x76, 0x76, 0x76, 0x73, 0x74, 0x43, 
	0x40, 0x41, 0xD8, 0xD7, 0xD8, 0x93, 0x91, 0x92, 0xD1, 0xD0, 0xD1, 0xD5, 0xD4, 0xD4, 0xCB, 0xCB, 0xCB, 
	0x5D, 0x5A, 0x5B, 0x4E, 0x4B, 0x4C, 0xA5, 0xA4, 0xA4, 0xF3, 0xF3, 0xF3, 0x8F, 0x8D, 0x8D, 0xAF, 0xAE, 
	0xAE, 0x5B, 0x58, 0x58, 0x52, 0x50, 0x50, 0xEE, 0xEE, 0xEE, 0xC5, 0x34, 0xFC, 0xC1, 0x00, 0x00, 0x00, 
	0x99, 0x74, 0x52, 0x4E, 0x53, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF3, 0x5E, 0x70, 0x1B, 0x00, 0x00, 0x03, 0xD9, 0x49, 0x44, 0x41, 0x54, 
	0x78, 0xDA, 0xEC, 0xD9, 0x05, 0x7B, 0xDB, 0x56, 0x14, 0x06, 0x60, 0xF9, 0x32, 0x88, 0xCC, 0xCC, 0x76, 
	0x62, 0x87, 0x93, 0x86, 0x96, 0x94, 0x19, 0xC6, 0xCC, 0xCC, 0xCC, 0xCC, 0x5B, 0x87, 0xED, 0xD6, 0x0E, 
	0xFD, 0x73, 0x27, 0x2F, 0xDE, 0x5A, 0x67, 0x89, 0x2D, 0xDB, 0x57, 0x69, 0xBC, 0xE7, 0x9E, 0x5F, 0xF0, 
	0xBD, 0xD2, 0xA7, 0xE3, 0x2B, 0xD9, 0x68, 0x8D, 0xF9, 0x18, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 
	0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xF0, 0x3F, 0x00, 0x50, 0x28, 
	0x21, 0x38, 0x7D, 0x1A, 0x56, 0x8A, 0xD9, 0x46, 0x2C, 0x5A, 0x0E, 0xD7, 0x5D, 0xAB, 0x3D, 0x6E, 0x3D, 
	0x35, 0x93, 0x4A, 0xC4, 0xA2, 0x85, 0x82, 0x2D, 0x21, 0x74, 0x24, 0xD8, 0x7F, 0x00, 0x48, 0xA1, 0x5D, 
	0x3C, 0xB4, 0x9A, 0xCA, 0x59, 0x88, 0x71, 0x21, 0x36, 0x85, 0xE0, 0xDC, 0xC4, 0x04, 0x19, 0x5B, 0x83, 
	0x08, 0x46, 0x0C, 0x13, 0xCC, 0x84, 0x60, 0xC8, 0x6D, 0x96, 0xA3, 0xDF, 0x02, 0xE8, 0x80, 0x7D, 0x02, 
	0x00, 0x12, 0x44, 0x56, 0x72, 0x19, 0xD3, 0xCB, 0x46, 0x08, 0x41, 0xFF, 0x64, 0xDE, 0x75, 0x10, 0x62, 
	0xCC, 0x43, 0x72, 0xA3, 0xB9, 0xDA, 0x88, 0x03, 0x05, 0x77, 0xC3, 0x18, 0x29, 0xBC, 0x7D, 0x3E, 0x8C, 
	0x04, 0x67, 0xA4, 0x6F, 0xEE, 0xFF, 0x42, 0x08, 0x33, 0x4D, 0x6C, 0x85, 0xCF, 0x7B, 0xB5, 0xA2, 0x37, 
	0x04, 0x00, 0x65, 0x7E, 0x8A, 0x71, 0x3C, 0x44, 0xF6, 0x2E, 0x06, 0x16, 0x38, 0x77, 0xA1, 0x08, 0xC1, 
	0x1E, 0x03, 0xA0, 0x2C, 0x34, 0x4D, 0xAF, 0xD0, 0x86, 0x8A, 0x21, 0x98, 0xE3, 0xD9, 0x39, 0x7B, 0xC8, 
	0x1B, 0x31, 0x04, 0x80, 0xFE, 0x5A, 0x9A, 0x32, 0x39, 0x33, 0x54, 0x8E, 0x77, 0x27, 0xC8, 0x54, 0x56, 
	0xC2, 0x3D, 0x00, 0x40, 0x78, 0x01, 0x09, 0xB5, 0xE9, 0x3B, 0x75, 0xF2, 0x0A, 0x99, 0x2B, 0x40, 0x19, 
	0x2C, 0x00, 0x96, 0x52, 0x1C, 0xA3, 0x00, 0xE2, 0x1B, 0x19, 0xF7, 0x5C, 0xB5, 0x3A, 0x9F, 0x4E, 0x87, 
	0xF3, 0x83, 0xDD, 0x87, 0x41, 0x00, 0xC0, 0x69, 0xCC, 0x07, 0x71, 0xF1, 0xD3, 0x56, 0x75, 0xF6, 0xCC, 
	0xBB, 0x77, 0xBC, 0x79, 0xE5, 0xE2, 0xD5, 0xC5, 0x23, 0xCB, 0xCB, 0x07, 0x9E, 0x7B, 0x6F, 0xFD, 0x68, 
	0x00, 0x00, 0xEA, 0x24, 0x2D, 0x1E, 0xC0, 0xC5, 0x77, 0x67, 0xCF, 0x7C, 0x71, 0xFF, 0x23, 0x37, 0x85, 
	0xBA, 0xE6, 0xB6, 0x6F, 0x6A, 0xAA, 0x01, 0x32, 0x92, 0x16, 0x44, 0x7D, 0x71, 0xAA, 0x97, 0xBE, 0xBB, 
	0x67, 0x5B, 0xF8, 0xAD, 0x79, 0xFA, 0xB5, 0x84, 0x4A, 0x00, 0x8C, 0xBB, 0x42, 0xFD, 0xD5, 0xB7, 0x4E, 
	0xBE, 0xFC, 0xC2, 0x8E, 0xE9, 0xFF, 0x9E, 0xC5, 0x57, 0x6A, 0xAA, 0x00, 0x00, 0x4C, 0x04, 0x70, 0xF5, 
	0xDD, 0x93, 0x6F, 0x3D, 0x1F, 0xEA, 0x39, 0xC7, 0x3E, 0x57, 0x03, 0x70, 0x12, 0x01, 0x3C, 0xBA, 0xF3, 
	0x2F, 0xDD, 0x79, 0x24, 0xD4, 0x77, 0x3E, 0xA9, 0x8D, 0x0E, 0x80, 0x59, 0x62, 0x2A, 0xDF, 0x3B, 0xE7, 
	0x3E, 0xBC, 0xFD, 0x40, 0xC8, 0xCF, 0x7C, 0x34, 0x3D, 0x22, 0x00, 0xC8, 0x09, 0xE5, 0xE5, 0x47, 0xE6, 
	0x97, 0x0F, 0x84, 0xFC, 0xCE, 0xCD, 0xB5, 0x91, 0x00, 0x32, 0xC9, 0x55, 0xB7, 0x87, 0x08, 0x72, 0xE2, 
	0xAB, 0x90, 0xFF, 0x39, 0x38, 0x49, 0x87, 0x07, 0xC0, 0x94, 0x50, 0x7D, 0xF1, 0xCD, 0x67, 0x22, 0x0E, 
	0x78, 0x62, 0xE6, 0xC9, 0x65, 0xDF, 0x82, 0x1F, 0x26, 0x87, 0x05, 0xC0, 0x88, 0x89, 0xD5, 0xA6, 0xE7, 
	0xD6, 0x1C, 0xED, 0x1C, 0x76, 0xD6, 0x3E, 0xBD, 0xEB, 0xA0, 0x5F, 0xC2, 0x52, 0x6D, 0x18, 0x00, 0x70, 
	0x4E, 0x29, 0x6C, 0xBF, 0xF7, 0x4E, 0x69, 0x5A, 0x73, 0xF1, 0xAE, 0x83, 0xFF, 0xF1, 0xC9, 0x0F, 0xFE, 
	0xF4, 0x27, 0xE8, 0xD1, 0xA2, 0x5D, 0x01, 0xA0, 0x94, 0x56, 0xB5, 0x7C, 0x10, 0x31, 0x39, 0x09, 0xAF, 
	0xD9, 0x3B, 0xBC, 0x40, 0x6E, 0x3C, 0x5B, 0x7F, 0xE8, 0x33, 0x1F, 0x82, 0xA3, 0x74, 0x40, 0x00, 0x75, 
	0x62, 0x9B, 0x44, 0x49, 0x76, 0x8C, 0x99, 0x31, 0x11, 0x2B, 0xF6, 0x38, 0x62, 0x82, 0xE9, 0xC9, 0x07, 
	0x1F, 0xFF, 0xF8, 0xEB, 0xDE, 0x82, 0x5B, 0x28, 0x1D, 0x04, 0x40, 0x65, 0x53, 0x8C, 0x5E, 0x1A, 0x93, 
	0x63, 0x23, 0x97, 0x58, 0xC8, 0x43, 0x3F, 0x2F, 0x5B, 0x8F, 0xFD, 0xB4, 0xF4, 0xFB, 0xAD, 0xEF, 0x2C, 
	0xEE, 0x06, 0x38, 0xBB, 0x36, 0xC8, 0x1D, 0x00, 0x36, 0xC3, 0xA3, 0xF5, 0x1D, 0x63, 0x62, 0x85, 0x0F, 
	0x65, 0xE3, 0x52, 0x0E, 0xF4, 0xA2, 0x48, 0xE5, 0x8F, 0xE5, 0xD7, 0xDF, 0x3F, 0x7C, 0xEF, 0xD9, 0x1D, 
	0x8E, 0x15, 0x1B, 0xBE, 0x01, 0x14, 0xC6, 0x86, 0x7C, 0x7A, 0xBD, 0xC2, 0x70, 0xCE, 0x98, 0x15, 0x4E, 
	0xC4, 0x22, 0x95, 0x11, 0xBE, 0x99, 0x50, 0x10, 0xBD, 0xBC, 0xF4, 0xCB, 0xF7, 0x6F, 0x3F, 0x75, 0xFD, 
	0x9E, 0xFA, 0x2D, 0xEA, 0x13, 0x40, 0x9D, 0x29, 0x31, 0x70, 0xF0, 0x76, 0xD5, 0x19, 0xC9, 0x4C, 0x24, 
	0x1A, 0x91, 0x3C, 0x80, 0x50, 0xD1, 0x57, 0x2B, 0x70, 0x3C, 0xB1, 0xFE, 0xEA, 0xE1, 0x3F, 0x3A, 0x02, 
	0x1E, 0xF5, 0x05, 0x00, 0x20, 0x83, 0xFD, 0x07, 0x67, 0xA6, 0xE0, 0x5E, 0x5B, 0x72, 0xE1, 0xE8, 0x42, 
	0x21, 0x0F, 0xA5, 0xB2, 0xE8, 0xDD, 0x0F, 0xF9, 0xC3, 0x6F, 0xDC, 0xD7, 0x3E, 0x39, 0x85, 0x81, 0x0F, 
	0x00, 0x88, 0xF0, 0xBE, 0xDB, 0x07, 0xB5, 0x97, 0x3A, 0xC7, 0x8C, 0x58, 0xF5, 0x53, 0x73, 0xD9, 0x62, 
	0xC9, 0x06, 0x10, 0xD0, 0x56, 0xA0, 0x43, 0x37, 0xD6, 0xEF, 0x7E, 0x34, 0x04, 0xFB, 0x02, 0xA8, 0x9C, 
	0xEE, 0x51, 0xFF, 0xF6, 0x4E, 0xE4, 0x02, 0x93, 0xB4, 0x9B, 0x5A, 0x89, 0x65, 0xB3, 0x25, 0x60, 0xD3, 
	0xA0, 0x83, 0x77, 0xAF, 0x96, 0x06, 0xEC, 0x03, 0x00, 0xB2, 0xC9, 0x77, 0xF9, 0x15, 0x35, 0x19, 0x41, 
	0x56, 0x7D, 0x35, 0x9A, 0x2C, 0xC5, 0x6D, 0x0A, 0x21, 0xDC, 0xC3, 0xE0, 0xD7, 0xD7, 0xBB, 0x37, 0x00, 
	0x00, 0x84, 0xB7, 0x55, 0xBC, 0xBD, 0x55, 0x90, 0xFB, 0x73, 0x39, 0x96, 0x2C, 0xE4, 0x6D, 0xAF, 0x2A, 
	0xAD, 0x1B, 0x12, 0xDC, 0xE7, 0x61, 0x0E, 0x5E, 0xAB, 0x7F, 0x7B, 0x1F, 0x0A, 0xD3, 0x98, 0x4F, 0x45, 
	0x93, 0xF1, 0x38, 0x0D, 0xE4, 0xD1, 0x54, 0x0E, 0x00, 0x72, 0x45, 0x6C, 0x7D, 0xE4, 0x33, 0x39, 0xF3, 
	0xF6, 0x61, 0xB2, 0x62, 0xEF, 0xEF, 0xE4, 0xDB, 0x00, 0xC0, 0xA9, 0x72, 0xE4, 0x15, 0x06, 0xCD, 0xCE, 
	0x2C, 0xC4, 0x29, 0x05, 0x80, 0xB6, 0xC6, 0x63, 0x3A, 0x00, 0x58, 0xDC, 0x7C, 0x11, 0x67, 0xCA, 0xC9, 
	0x0A, 0x90, 0xA0, 0x35, 0x56, 0x63, 0x6C, 0x6D, 0xCF, 0xB2, 0x98, 0x89, 0x50, 0x38, 0x66, 0xD9, 0xFF, 
	0x05, 0x40, 0x79, 0xA2, 0x32, 0x96, 0xE1, 0xAF, 0x01, 0xC6, 0x35, 0x7D, 0x07, 0x30, 0xC6, 0xF1, 0xF5, 
	0x1F, 0xDD, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 
	0x1A, 0xA0, 0x01, 0x1A, 0xA0, 0x01, 0x63, 0x3B, 0x7F, 0x09, 0x30, 0x00, 0xFE, 0x2F, 0x87, 0xDE, 0xF9, 
	0xB0, 0xAD, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
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


void FooterLogoX2::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png");

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 138 "/ws/git/my-devices/gateway/src/FooterLogoX2.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
