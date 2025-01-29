//
// HeaderLogo.cpp
//
// This file has been generated from HeaderLogo.cpsp on 2025-01-29 07:16:40.
//


#include "HeaderLogo.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#line 9 "/Users/guenter/ws/git/my-devices/gateway/src/HeaderLogo.cpsp"


// res/HeaderLogo.png
static const unsigned char data[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 
	0x00, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x14, 0x08, 0x06, 0x00, 0x00, 0x00, 0x0D, 0xFA, 0x2A, 0x1E, 0x00, 
	0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x41, 
	0x64, 0x6F, 0x62, 0x65, 0x20, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xC9, 
	0x65, 0x3C, 0x00, 0x00, 0x09, 0xDC, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xE4, 0x59, 0x69, 0x70, 0x14, 
	0xC7, 0x15, 0xFE, 0x66, 0x66, 0x67, 0x57, 0x7B, 0xE8, 0xBE, 0x05, 0xBA, 0x38, 0x2D, 0x4B, 0x1C, 0xC6, 
	0x9C, 0x06, 0xC2, 0x6D, 0x81, 0x0F, 0x20, 0xCE, 0x0F, 0xE1, 0x0A, 0x31, 0x09, 0x18, 0x13, 0x3B, 0x50, 
	0x04, 0x53, 0x39, 0x70, 0x0A, 0xC7, 0x06, 0x7C, 0x55, 0x8C, 0x9D, 0xD8, 0xA4, 0x2C, 0xFC, 0x83, 0x38, 
	0x8E, 0x93, 0xAA, 0x38, 0x8E, 0x43, 0x25, 0x2E, 0xE1, 0x70, 0x85, 0x10, 0x13, 0xC0, 0x41, 0x60, 0x08, 
	0x97, 0x10, 0x02, 0x81, 0xB9, 0x24, 0x24, 0xA1, 0x63, 0xB5, 0x5A, 0xED, 0xEE, 0xCC, 0xE4, 0x9B, 0x43, 
	0x3B, 0x2B, 0x0C, 0x18, 0x1B, 0x9C, 0x0A, 0xA1, 0xAB, 0x9E, 0x66, 0xB6, 0xBB, 0xA7, 0x8F, 0xAF, 0xDF, 
	0xFB, 0xDE, 0x7B, 0x2D, 0x41, 0xD3, 0x34, 0x07, 0x80, 0x1F, 0x51, 0xE6, 0x50, 0x52, 0xF1, 0xC5, 0x8B, 
	0x4A, 0xD9, 0x41, 0x59, 0x4A, 0xA9, 0xB9, 0x9E, 0x0F, 0x42, 0x94, 0x91, 0x94, 0xE5, 0x94, 0x1E, 0x94, 
	0x3E, 0x94, 0x94, 0x6E, 0x3D, 0x34, 0x43, 0xAA, 0x20, 0xE2, 0x53, 0xBE, 0x4D, 0xA2, 0x04, 0x28, 0x1D, 
	0x14, 0xC1, 0x6A, 0x8D, 0xA3, 0xF8, 0xA2, 0xFD, 0x83, 0x94, 0xB6, 0x68, 0x6B, 0x00, 0x0E, 0x6C, 0x47, 
	0x12, 0x22, 0xFC, 0xAD, 0xB0, 0x26, 0x97, 0x32, 0x24, 0xDA, 0x57, 0xDF, 0xE6, 0xDB, 0xD6, 0xBB, 0x3E, 
	0xEB, 0x51, 0xF6, 0x4B, 0x37, 0xBE, 0x94, 0xA2, 0x7D, 0x6A, 0x8D, 0xD1, 0xCB, 0x39, 0xCE, 0x4A, 0x8E, 
	0x53, 0x63, 0xCD, 0x67, 0x97, 0x08, 0xA5, 0x91, 0x52, 0x67, 0x8D, 0xAC, 0x18, 0xB5, 0x61, 0x4C, 0xE4, 
	0x8A, 0xB7, 0x18, 0xE3, 0x68, 0x56, 0x4F, 0x81, 0xBB, 0x00, 0xD6, 0x42, 0x07, 0x79, 0x05, 0x65, 0x19, 
	0x6E, 0xAC, 0xCC, 0xA0, 0xF4, 0xA7, 0x8C, 0xA2, 0x34, 0x5F, 0xBD, 0x5B, 0xD8, 0x00, 0xA4, 0x91, 0x4B, 
	0xA9, 0x43, 0x62, 0xCC, 0xC6, 0xFE, 0xFF, 0x8B, 0x48, 0xF9, 0xF6, 0x4D, 0x1A, 0xEB, 0x0E, 0xCA, 0x84, 
	0xAB, 0x2B, 0xBD, 0x2E, 0x1F, 0x51, 0xFA, 0xE2, 0x22, 0xA6, 0xA2, 0x85, 0x5A, 0x21, 0xDE, 0x46, 0x40, 
	0xEB, 0x1A, 0xED, 0xBE, 0x89, 0xE3, 0xA5, 0x5C, 0xB9, 0xBA, 0x3D, 0x86, 0x34, 0x9A, 0x68, 0x4E, 0x8D, 
	0x86, 0xA9, 0xE2, 0x36, 0x03, 0x5A, 0xBD, 0x89, 0xE3, 0xA9, 0x9F, 0x6F, 0x40, 0x5D, 0xD3, 0x7E, 0xF1, 
	0x22, 0x58, 0x72, 0xE5, 0xA2, 0x75, 0xE3, 0xF7, 0xFF, 0x45, 0xA0, 0x6F, 0x19, 0x8E, 0x0B, 0xC5, 0x38, 
	0x43, 0x2E, 0x7C, 0x04, 0x1F, 0xD3, 0xCC, 0x56, 0xE9, 0x00, 0x0D, 0xF3, 0x7D, 0xBB, 0x55, 0x82, 0x93, 
	0xEF, 0x0E, 0xCB, 0x4D, 0x89, 0xE6, 0xE7, 0xD3, 0xCC, 0xC6, 0xC8, 0x06, 0xFB, 0x24, 0x3A, 0xFF, 0x6B, 
	0x87, 0x72, 0x4B, 0x00, 0xAD, 0x59, 0xFC, 0x16, 0xB4, 0x3C, 0xAD, 0xFE, 0xDB, 0x09, 0x7C, 0x8D, 0x8F, 
	0x9F, 0x9A, 0x3D, 0xE4, 0x3F, 0x52, 0xDE, 0xEF, 0xEA, 0x2F, 0x53, 0x4E, 0x1A, 0x24, 0x65, 0x9A, 0x18, 
	0x1D, 0xC7, 0x93, 0x7C, 0xFC, 0xCC, 0x6C, 0xBD, 0x93, 0xEF, 0x89, 0xAF, 0x9A, 0xA3, 0x8C, 0xB0, 0x62, 
	0x17, 0xED, 0x9A, 0xB6, 0x72, 0x5B, 0x69, 0xB4, 0x5E, 0x92, 0x2D, 0x48, 0x2E, 0xD9, 0xEA, 0xD8, 0x55, 
	0x02, 0xB1, 0xFD, 0x64, 0xC2, 0x1B, 0xA1, 0x1F, 0xF8, 0x98, 0x61, 0x9B, 0x5E, 0x86, 0x11, 0x5D, 0xBB, 
	0x75, 0x5C, 0x31, 0x70, 0x84, 0x4F, 0x2F, 0x4C, 0xFC, 0x3D, 0x96, 0xDE, 0x4B, 0xB7, 0x1E, 0xD0, 0x6A, 
	0x0C, 0x1B, 0xDF, 0xEC, 0x92, 0x62, 0x51, 0x88, 0xF6, 0x39, 0x2B, 0x58, 0x80, 0x56, 0x4A, 0x7A, 0x97, 
	0x0B, 0x5E, 0xC9, 0xFE, 0x2E, 0x01, 0x6D, 0x44, 0xB4, 0x68, 0xC5, 0x06, 0xC6, 0xD1, 0x77, 0x73, 0x85, 
	0x19, 0x46, 0xAB, 0x72, 0x03, 0x76, 0x76, 0x03, 0x40, 0xB7, 0x87, 0x22, 0xE1, 0xC6, 0x40, 0xB8, 0x4D, 
	0xD2, 0x34, 0x64, 0x26, 0xBA, 0x53, 0x1C, 0x44, 0xAC, 0xB1, 0x35, 0xB8, 0xB7, 0x2D, 0xA4, 0x34, 0x7B, 
	0x3D, 0xAE, 0xBE, 0xE9, 0x1E, 0x39, 0xD7, 0x58, 0x7C, 0x58, 0x09, 0x37, 0xFA, 0x83, 0x95, 0x21, 0x55, 
	0xE8, 0x48, 0xF2, 0xB9, 0x8A, 0x13, 0x5D, 0x52, 0x86, 0x3E, 0xF5, 0x46, 0xCA, 0x78, 0x8A, 0x0B, 0x28, 
	0xE4, 0xA3, 0xC0, 0xB4, 0x4D, 0xD1, 0x0F, 0x43, 0x8D, 0x94, 0x0B, 0xA6, 0x53, 0x0B, 0x45, 0x97, 0xAA, 
	0x9A, 0xCF, 0x34, 0x3E, 0x8A, 0x28, 0x89, 0x14, 0xF6, 0x15, 0xAA, 0x29, 0x67, 0x05, 0x1B, 0x86, 0x1C, 
	0x4A, 0x3F, 0xCB, 0xCE, 0xFD, 0x04, 0xFB, 0xA8, 0x3F, 0x66, 0xA7, 0xEC, 0x13, 0xEE, 0x34, 0xE9, 0x65, 
	0x08, 0xBF, 0xC9, 0xE6, 0x2B, 0xF3, 0x1C, 0xE1, 0x80, 0x6A, 0xD1, 0x0D, 0x37, 0xD9, 0xC8, 0xFA, 0x1F, 
	0x52, 0xD7, 0xF9, 0x4D, 0x5C, 0xDB, 0xAB, 0x04, 0xB9, 0x1C, 0xE8, 0x95, 0x61, 0x34, 0x69, 0x2D, 0xAC, 
	0xAC, 0x63, 0x7B, 0x1E, 0xBB, 0x16, 0x9B, 0xE7, 0x22, 0x54, 0xEA, 0x2C, 0x15, 0xEE, 0x6E, 0x2A, 0x3D, 
	0x29, 0xBD, 0xCC, 0x35, 0x0A, 0x1C, 0x56, 0x66, 0x26, 0xA2, 0x9E, 0xEE, 0x7E, 0x50, 0xA1, 0xEB, 0x07, 
	0xFA, 0x54, 0x6D, 0xC3, 0xAE, 0xD7, 0xB7, 0x55, 0xCF, 0xAC, 0x76, 0x27, 0x88, 0x0B, 0x87, 0xE5, 0xAC, 
	0xEB, 0x1D, 0xF1, 0x97, 0x9F, 0x6A, 0x57, 0x2B, 0x42, 0x92, 0x03, 0x7B, 0x83, 0x62, 0x72, 0x41, 0x6A, 
	0xFC, 0xEA, 0x99, 0x69, 0xC2, 0x3D, 0xFB, 0x8E, 0x9F, 0x9F, 0x55, 0x17, 0x16, 0x3E, 0xF1, 0x26, 0x78, 
	0x51, 0xAB, 0x39, 0x73, 0x46, 0xE7, 0x24, 0xAC, 0x1F, 0x98, 0x19, 0xE7, 0xD8, 0x03, 0x64, 0x4C, 0x01, 
	0xDE, 0xE3, 0x50, 0xC3, 0x4D, 0xBC, 0x61, 0x99, 0x29, 0x1A, 0xB8, 0xC6, 0x5F, 0x30, 0xDC, 0x5E, 0xD5, 
	0xC9, 0x58, 0xDA, 0x4F, 0xB8, 0x09, 0x44, 0x3C, 0xD1, 0x5B, 0x11, 0x0F, 0x3C, 0xCC, 0xF6, 0x4C, 0x7B, 
	0x15, 0x67, 0x36, 0x56, 0xE3, 0x48, 0x69, 0x2B, 0x26, 0x67, 0x0E, 0x86, 0xF0, 0xA2, 0x68, 0x26, 0x44, 
	0xC9, 0x36, 0x35, 0xD4, 0xBF, 0xEB, 0x80, 0x63, 0x6B, 0x57, 0x34, 0xD9, 0x0C, 0x2D, 0x2D, 0x08, 0xE1, 
	0x37, 0x24, 0x81, 0xD9, 0x96, 0xEB, 0x64, 0xEA, 0x96, 0xF6, 0x32, 0xB0, 0x7F, 0x59, 0x13, 0xCF, 0x3A, 
	0x1E, 0x89, 0x4F, 0x91, 0xD3, 0x17, 0x5B, 0xF9, 0xDD, 0xAA, 0xC7, 0x81, 0xE7, 0xF8, 0xE5, 0xDF, 0xF9, 
	0x9E, 0xAE, 0xE1, 0xE2, 0x87, 0x1A, 0x5C, 0xDB, 0x24, 0xA4, 0x3C, 0x63, 0x1D, 0xB4, 0x7E, 0xAE, 0xA4, 
	0xF8, 0xF6, 0xB9, 0xBD, 0x20, 0x6C, 0x23, 0xBF, 0x27, 0x4B, 0x66, 0x2A, 0x39, 0xDE, 0x4E, 0x46, 0x75, 
	0x9A, 0x49, 0x6D, 0xA5, 0x17, 0xF8, 0x15, 0xCF, 0xE6, 0x07, 0x3C, 0xAC, 0xB0, 0x59, 0xDF, 0xE7, 0xFA, 
	0x81, 0x4E, 0x75, 0x09, 0xA1, 0xE9, 0xC9, 0x5A, 0xD3, 0x92, 0xD6, 0x30, 0x96, 0x6F, 0xAA, 0x99, 0x3D, 
	0x39, 0x3F, 0xB9, 0xB5, 0xC4, 0xAB, 0x60, 0xF3, 0x99, 0x46, 0x34, 0xB9, 0x7D, 0x97, 0x56, 0xEF, 0xA9, 
	0xFF, 0xDE, 0x6E, 0x4F, 0xD0, 0x9B, 0x94, 0x97, 0xD6, 0xD0, 0x4F, 0x08, 0xE1, 0xE4, 0xB9, 0x76, 0x7C, 
	0x24, 0xFA, 0xCE, 0xAD, 0x39, 0xD8, 0xBA, 0xE8, 0xC0, 0xAC, 0x3E, 0x85, 0xF7, 0xCB, 0x08, 0x30, 0x55, 
	0x1E, 0xED, 0x35, 0xF3, 0xD4, 0xFD, 0x16, 0x8B, 0x94, 0xC0, 0xD0, 0xDA, 0x51, 0x2B, 0x81, 0x8A, 0x93, 
	0x61, 0x04, 0x7E, 0x3B, 0x05, 0x92, 0x67, 0x30, 0xB0, 0x9E, 0x1B, 0x9E, 0x78, 0x99, 0x4A, 0x38, 0x23, 
	0x38, 0x73, 0x78, 0x23, 0x32, 0x7C, 0x0F, 0x41, 0xD8, 0x44, 0xF4, 0x07, 0xC4, 0xB4, 0xEB, 0x8A, 0xEB, 
	0x52, 0x71, 0xEE, 0xB8, 0x8A, 0x1E, 0x1D, 0x36, 0x9D, 0x08, 0xD3, 0xBB, 0xBB, 0x32, 0x91, 0xFB, 0x4A, 
	0xF8, 0xB1, 0x88, 0xB5, 0xDB, 0x9D, 0x78, 0x70, 0x83, 0x8A, 0x69, 0xCE, 0x98, 0x2C, 0xDA, 0x39, 0xC9, 
	0xD4, 0x7E, 0x1D, 0x2D, 0xD2, 0x49, 0xD6, 0x7D, 0x8C, 0x50, 0x66, 0x74, 0x47, 0x41, 0xA6, 0x35, 0x3A, 
	0xD6, 0x95, 0x62, 0xEB, 0x40, 0x37, 0xA6, 0x05, 0xFC, 0x90, 0x87, 0x26, 0x9B, 0x20, 0x1F, 0xB2, 0xD2, 
	0x5B, 0x9D, 0xF3, 0x13, 0x98, 0x7C, 0xF1, 0xF0, 0x36, 0x33, 0x0F, 0x3F, 0xFD, 0x82, 0x49, 0x58, 0x19, 
	0x16, 0x65, 0x7E, 0xD6, 0xB9, 0x7E, 0x86, 0x4A, 0x5D, 0x2E, 0x51, 0xB8, 0x33, 0xDD, 0x81, 0x41, 0x8E, 
	0x30, 0x0E, 0x86, 0xA4, 0xF6, 0x91, 0xC5, 0x39, 0x6F, 0x96, 0x0E, 0xCA, 0xDD, 0x9D, 0x83, 0xC8, 0x00, 
	0xDF, 0xD9, 0x0B, 0x88, 0x53, 0x3B, 0x3B, 0xFE, 0x10, 0x94, 0x3A, 0xC7, 0x15, 0x65, 0xFF, 0x69, 0xEA, 
	0xE0, 0xBC, 0x7F, 0xF8, 0x9B, 0xFC, 0x05, 0xC2, 0xB9, 0x06, 0x04, 0x02, 0xCA, 0xFE, 0x17, 0x0F, 0xD5, 
	0x1C, 0xAC, 0x0E, 0xD4, 0xF9, 0x89, 0xC6, 0x4C, 0x0E, 0x95, 0x4F, 0x19, 0xCC, 0x29, 0x07, 0x1E, 0x03, 
	0x96, 0xD8, 0x8C, 0x26, 0xCD, 0x0B, 0x53, 0xB9, 0x17, 0x00, 0x8F, 0xE7, 0x47, 0x41, 0x56, 0x99, 0xD1, 
	0x9C, 0x58, 0x48, 0x43, 0xD7, 0x41, 0xBD, 0xFB, 0x34, 0xFA, 0xBD, 0x3C, 0x00, 0x25, 0xCF, 0x66, 0x47, 
	0x41, 0xEE, 0xA8, 0x07, 0x6A, 0xBE, 0x65, 0x1D, 0xD8, 0x50, 0x05, 0x3D, 0xDF, 0x50, 0x90, 0xEC, 0xB5, 
	0xE3, 0xEB, 0x30, 0x0F, 0xE8, 0xD4, 0x52, 0x6E, 0x50, 0xC7, 0x70, 0xA7, 0xBD, 0x9B, 0x67, 0xCA, 0x64, 
	0xF4, 0xBE, 0x3C, 0xBE, 0xD7, 0x82, 0x26, 0x14, 0x41, 0xEB, 0x6B, 0x06, 0x29, 0x91, 0x7D, 0xAC, 0x99, 
	0x42, 0x27, 0xBB, 0x38, 0x1C, 0xB5, 0x7F, 0x5F, 0xA1, 0x03, 0xC1, 0x51, 0xE9, 0x38, 0xD2, 0x19, 0x34, 
	0xB3, 0xE7, 0xDE, 0xD6, 0xFC, 0x77, 0x1D, 0x07, 0xBE, 0x19, 0x8A, 0x8E, 0xE9, 0x99, 0x03, 0x54, 0x39, 
	0x75, 0x66, 0xEC, 0xBC, 0x86, 0x67, 0x12, 0xAF, 0xC4, 0xF1, 0x2D, 0x61, 0x01, 0x55, 0x8A, 0x07, 0x23, 
	0x0A, 0xD3, 0xEE, 0x2F, 0xEB, 0x1D, 0x3F, 0xBF, 0x67, 0x5A, 0xFC, 0xF0, 0xC7, 0x86, 0xF7, 0x58, 0x78, 
	0x5F, 0xB6, 0x0C, 0x8F, 0xC7, 0x83, 0xD2, 0x3B, 0x7A, 0xCC, 0x7E, 0x20, 0x3F, 0x61, 0x66, 0x6E, 0x66, 
	0xE2, 0x98, 0x89, 0x83, 0xB2, 0xE6, 0xA5, 0xCB, 0x21, 0x34, 0x8A, 0x1D, 0xA1, 0x55, 0xE2, 0xEA, 0xFA, 
	0xE7, 0x1C, 0x6B, 0x74, 0xD6, 0xFA, 0x8B, 0x15, 0x3B, 0xBD, 0xC9, 0x73, 0xDD, 0x4A, 0xA2, 0x7E, 0xD4, 
	0x9E, 0xC0, 0x99, 0x3D, 0x0C, 0x2E, 0xE7, 0xD7, 0x81, 0x32, 0xBB, 0xEE, 0xED, 0xE7, 0x80, 0xF2, 0x5F, 
	0xF2, 0xE5, 0x18, 0xA7, 0xDF, 0x9B, 0x8C, 0x94, 0x86, 0xB1, 0x90, 0x1E, 0xB6, 0xDB, 0x5F, 0x5B, 0x02, 
	0xFC, 0xEE, 0x1D, 0x2E, 0x8E, 0x7B, 0x44, 0x65, 0x0B, 0x52, 0xCF, 0xA8, 0x70, 0x38, 0x63, 0x2E, 0x79, 
	0x36, 0xB3, 0xED, 0x95, 0xBD, 0x9C, 0x8B, 0x7C, 0xF0, 0xAC, 0x5D, 0x7F, 0x32, 0x5F, 0xC2, 0x07, 0xD7, 
	0xCA, 0x7F, 0xAC, 0x1D, 0xEF, 0x58, 0xEA, 0x47, 0xD5, 0x66, 0x72, 0xD1, 0x6B, 0x8D, 0xC0, 0x6E, 0xBB, 
	0x4B, 0x47, 0x7E, 0x33, 0xFE, 0x49, 0xB7, 0x8A, 0xBF, 0xC2, 0xF4, 0x39, 0xAF, 0x53, 0x36, 0x51, 0x41, 
	0x96, 0xC9, 0xD1, 0xEF, 0x5D, 0x34, 0xBA, 0x60, 0xBC, 0x82, 0x0E, 0x9E, 0x5C, 0x9A, 0x55, 0x29, 0x5C, 
	0x5F, 0xD4, 0xA1, 0xDB, 0x7C, 0xBF, 0xCC, 0x14, 0x14, 0x64, 0x24, 0x66, 0x74, 0xD5, 0xF5, 0xCF, 0xF5, 
	0xB9, 0xE2, 0x1D, 0xA9, 0x98, 0x4F, 0x6F, 0x27, 0x3B, 0xE4, 0x9C, 0xAE, 0xFA, 0x04, 0xD9, 0x99, 0x97, 
	0x40, 0x63, 0xC7, 0x8C, 0x4B, 0x2A, 0x5C, 0x65, 0xF5, 0x61, 0x69, 0x48, 0x0E, 0x4F, 0xEF, 0x5D, 0x36, 
	0x8D, 0x8E, 0x42, 0xDB, 0x6D, 0xF4, 0x2C, 0xE5, 0x24, 0xB2, 0x92, 0xE8, 0x59, 0x72, 0xE3, 0xA3, 0x75, 
	0x85, 0xDC, 0x48, 0x3C, 0x6A, 0xB9, 0xA5, 0xDD, 0xB4, 0x70, 0xD6, 0xE7, 0x4F, 0x25, 0xD5, 0x98, 0xCB, 
	0x55, 0xE8, 0x8F, 0xEE, 0xDA, 0xA6, 0xA7, 0xF1, 0x1A, 0x5A, 0x68, 0x0B, 0x49, 0xEC, 0x25, 0xF0, 0x6F, 
	0xAC, 0xDB, 0x77, 0xD7, 0xEB, 0x7E, 0x37, 0xDD, 0x24, 0xF2, 0x8B, 0x76, 0xFD, 0x08, 0xC1, 0x3C, 0xEF, 
	0x6B, 0x86, 0x08, 0xD4, 0xCC, 0xB1, 0x75, 0x92, 0xE5, 0x09, 0xC9, 0xF3, 0xE7, 0xED, 0x8B, 0x83, 0x39, 
	0xCA, 0x4B, 0xA4, 0x1C, 0x06, 0xE0, 0xBF, 0xE7, 0xCF, 0xE9, 0xB1, 0x71, 0x7A, 0x0C, 0x07, 0x50, 0xE6, 
	0x8B, 0xED, 0xE6, 0x40, 0xBD, 0x04, 0x28, 0x54, 0x98, 0xB5, 0xF3, 0x38, 0xDA, 0x39, 0x86, 0x92, 0xD1, 
	0xA9, 0xC5, 0xAB, 0x1D, 0x75, 0x9C, 0xC4, 0xCC, 0x4A, 0xB4, 0x5D, 0xAA, 0xAA, 0x42, 0x0D, 0xF3, 0x1B, 
	0x51, 0x10, 0xF4, 0x4F, 0xA3, 0xF5, 0x89, 0xEC, 0x93, 0xC7, 0xB9, 0x54, 0x87, 0x86, 0x14, 0xC9, 0x8B, 
	0x37, 0xA4, 0xF8, 0x97, 0x52, 0x6D, 0x90, 0x3F, 0xE4, 0x11, 0x4C, 0x26, 0x89, 0xDD, 0x1B, 0x89, 0x71, 
	0xC9, 0x04, 0x5E, 0x15, 0xBA, 0x99, 0xF3, 0x89, 0x24, 0xFD, 0x86, 0xD5, 0x4D, 0xDA, 0x4C, 0x32, 0x97, 
	0xAE, 0xD8, 0xE0, 0xE8, 0xA6, 0x7D, 0x98, 0xD8, 0x9F, 0xE5, 0xBA, 0x44, 0x23, 0xEA, 0xBD, 0x82, 0x76, 
	0x48, 0x5D, 0x00, 0x38, 0xBF, 0x54, 0x64, 0x29, 0x4A, 0xFA, 0xD8, 0x4E, 0x3B, 0x8B, 0x34, 0x0A, 0xB5, 
	0x3B, 0x40, 0x8A, 0x5B, 0x58, 0x64, 0x83, 0xFC, 0x31, 0x17, 0xFD, 0x20, 0x4F, 0x75, 0x58, 0xC8, 0x70, 
	0xEE, 0x76, 0xF1, 0x9A, 0x4E, 0xA8, 0x93, 0x2E, 0x9E, 0x8E, 0xB4, 0xB5, 0x23, 0xC8, 0xE0, 0x47, 0x30, 
	0x42, 0x78, 0x57, 0x5F, 0x9D, 0xD6, 0xC5, 0xAB, 0x81, 0xCD, 0xE8, 0xCE, 0x90, 0xEB, 0x89, 0x99, 0x23, 
	0x3A, 0xF2, 0xAA, 0xC6, 0xE3, 0x74, 0xFA, 0x98, 0xAE, 0x8D, 0xB5, 0xAE, 0x44, 0x09, 0xD6, 0xF2, 0xEF, 
	0xD6, 0xA2, 0x76, 0xCB, 0x1A, 0x12, 0x68, 0x4C, 0x46, 0x20, 0x65, 0x31, 0x50, 0xE0, 0xA6, 0x4E, 0xD8, 
	0xA3, 0x0C, 0x25, 0x35, 0x94, 0x3A, 0x33, 0x91, 0x8A, 0x52, 0x83, 0x73, 0xEA, 0x4F, 0xA9, 0x50, 0x2C, 
	0xCD, 0x12, 0x89, 0xDF, 0x3D, 0xCC, 0x2C, 0xA6, 0x1A, 0xFE, 0xC7, 0x6B, 0x5C, 0x9A, 0x57, 0xEA, 0xB7, 
	0xCE, 0x5F, 0xF9, 0xBD, 0x14, 0x1D, 0x75, 0x1C, 0x23, 0xA8, 0x7B, 0xED, 0x9A, 0xE7, 0x97, 0x36, 0xA0, 
	0xF2, 0x83, 0x57, 0x48, 0xC8, 0x9D, 0x97, 0x29, 0xB6, 0x6A, 0x86, 0x99, 0xD4, 0x13, 0x61, 0xDA, 0x27, 
	0x78, 0x32, 0xBB, 0x1D, 0xFD, 0xDE, 0xE3, 0x1A, 0xDF, 0x0A, 0xA3, 0xE0, 0x6F, 0x0C, 0x02, 0x9E, 0xD0, 
	0x95, 0x43, 0x37, 0xB5, 0xA4, 0x1B, 0x5D, 0x94, 0x60, 0x84, 0x0C, 0x9A, 0xC2, 0x50, 0x20, 0x64, 0x5E, 
	0x07, 0xCA, 0x04, 0x76, 0xEE, 0xA2, 0x3E, 0xE8, 0xB1, 0x85, 0x5E, 0xEA, 0x29, 0x47, 0x4C, 0xEA, 0x45, 
	0xD7, 0x1D, 0x39, 0x08, 0xAC, 0x9B, 0x0B, 0x8C, 0x31, 0x6B, 0x06, 0x3C, 0x60, 0xFD, 0xF3, 0x40, 0xE7, 
	0x42, 0x6F, 0x00, 0xC7, 0x76, 0x56, 0xA2, 0xB8, 0x7C, 0x1C, 0x92, 0x5F, 0x30, 0xDB, 0x87, 0x3F, 0x66, 
	0xDC, 0xAF, 0x9A, 0xF7, 0xAC, 0x09, 0x6E, 0x34, 0xEC, 0x0C, 0xA3, 0xCD, 0x6F, 0x66, 0x75, 0x5F, 0x5D, 
	0xD1, 0x1D, 0x1E, 0xF7, 0xD3, 0x69, 0x5F, 0xFA, 0x3F, 0x32, 0x3F, 0x03, 0x89, 0xBE, 0x65, 0xC0, 0x82, 
	0xF8, 0x68, 0x28, 0x68, 0x76, 0x15, 0x09, 0xB5, 0x4A, 0xCB, 0xD0, 0x8D, 0xFC, 0x18, 0x94, 0x09, 0x45, 
	0x08, 0x7D, 0x23, 0x88, 0xCA, 0xF4, 0x4B, 0x18, 0xFB, 0x44, 0x0E, 0x26, 0x2D, 0x17, 0xAD, 0x8B, 0x7F, 
	0xCD, 0x26, 0x6D, 0xCD, 0xE3, 0xE5, 0xD9, 0xC8, 0x54, 0x74, 0x09, 0x52, 0xF4, 0xD4, 0x44, 0x4D, 0x73, 
	0xFB, 0xB4, 0xAE, 0x9C, 0x4F, 0x74, 0xD9, 0x7C, 0xA5, 0xB9, 0x5D, 0xFC, 0x5C, 0x24, 0xD4, 0x27, 0x95, 
	0x40, 0xC7, 0x41, 0x2D, 0xF2, 0x8E, 0x3D, 0x7F, 0x21, 0x31, 0x96, 0x2B, 0x78, 0x8A, 0x63, 0x6C, 0xE3, 
	0x08, 0x27, 0x97, 0xE0, 0x68, 0xDC, 0x06, 0xB4, 0xFC, 0xFA, 0xCF, 0xC0, 0x5B, 0x31, 0x8B, 0x1D, 0x4A, 
	0xF9, 0x09, 0xE5, 0xFB, 0xE9, 0x48, 0x7F, 0xF4, 0x08, 0xAA, 0x57, 0xD3, 0xB1, 0x55, 0xC4, 0xB4, 0x4F, 
	0xB0, 0xFE, 0x29, 0xB3, 0x58, 0x40, 0x51, 0x19, 0xE7, 0x8B, 0x65, 0x90, 0xB8, 0x98, 0x7B, 0xBB, 0x58, 
	0x0B, 0x75, 0x5F, 0xC1, 0x4D, 0x38, 0xAD, 0xB5, 0x78, 0x62, 0x68, 0x47, 0x8C, 0x21, 0xF2, 0xB8, 0xD8, 
	0xDC, 0xAF, 0xB6, 0xDB, 0x1A, 0x7B, 0x3E, 0x42, 0x5F, 0xB2, 0x21, 0xD1, 0x88, 0xAA, 0x34, 0x8B, 0xFA, 
	0x22, 0x71, 0x17, 0xD1, 0x3E, 0x92, 0x40, 0x3F, 0x2D, 0x21, 0xA4, 0x6B, 0xB4, 0x54, 0x00, 0x2D, 0x20, 
	0x19, 0x99, 0x97, 0x5C, 0x72, 0xC1, 0x70, 0xA2, 0xF5, 0x4D, 0xFA, 0x62, 0x75, 0x60, 0x48, 0xDC, 0x46, 
	0x48, 0xE6, 0xAB, 0xD1, 0xDC, 0x55, 0xEB, 0xD5, 0x2C, 0x1C, 0x55, 0x9A, 0x20, 0x29, 0xA1, 0xA3, 0x54, 
	0x30, 0x7D, 0x22, 0x6D, 0x9F, 0x1C, 0xB7, 0x63, 0x8B, 0x3B, 0x89, 0x93, 0x7F, 0x4A, 0xD0, 0x8D, 0xBC, 
	0xC4, 0xA8, 0x3F, 0xAE, 0xCA, 0x3B, 0x77, 0xAA, 0xDC, 0x8F, 0x4B, 0x44, 0x9B, 0x14, 0x11, 0xFF, 0xA5, 
	0x36, 0x3F, 0x5F, 0x22, 0xA5, 0xE9, 0xAB, 0x2D, 0x13, 0x8C, 0xD8, 0xB3, 0xA5, 0xE6, 0x04, 0xCE, 0xAE, 
	0x56, 0x50, 0x34, 0xB9, 0x2F, 0x84, 0x81, 0x34, 0xB0, 0x56, 0x0F, 0x76, 0x39, 0x4B, 0x50, 0x1C, 0xAC, 
	0xC0, 0xB0, 0xEF, 0x90, 0xFC, 0x18, 0x31, 0x60, 0x96, 0x95, 0xF9, 0xE9, 0xEB, 0x69, 0x16, 0x90, 0xB7, 
	0x6B, 0x30, 0x63, 0x9F, 0x7F, 0xD3, 0xC5, 0xD2, 0x9D, 0xCC, 0x67, 0xDD, 0x43, 0x56, 0xB8, 0xA8, 0x03, 
	0xD2, 0x22, 0x20, 0x73, 0xB7, 0x04, 0x41, 0x5F, 0xF3, 0x56, 0x6B, 0xB3, 0x7B, 0x75, 0xFD, 0x93, 0x39, 
	0xAB, 0x08, 0xB1, 0xD9, 0xAE, 0xC7, 0x7E, 0xEB, 0x6A, 0xF5, 0xB0, 0x5D, 0x17, 0xAE, 0x92, 0x0D, 0xB5, 
	0x90, 0xF4, 0x79, 0xB3, 0x4C, 0xAB, 0x0F, 0xB6, 0x0A, 0xAC, 0x71, 0xD2, 0x3B, 0x70, 0x82, 0x3D, 0x5D, 
	0x87, 0x40, 0x5F, 0xD3, 0x48, 0x8D, 0xAA, 0x68, 0x02, 0x16, 0x51, 0x83, 0xE7, 0xC9, 0x46, 0x55, 0xE8, 
	0xCC, 0x79, 0x1C, 0xFA, 0x79, 0x23, 0x06, 0xF5, 0x2F, 0x81, 0x30, 0x5E, 0xE3, 0x7E, 0x2E, 0x21, 0xD0, 
	0x37, 0x0D, 0xEE, 0x59, 0x02, 0x22, 0xDB, 0x79, 0x6E, 0x87, 0x15, 0x04, 0xB6, 0x54, 0x21, 0xED, 0xE9, 
	0x62, 0x8C, 0x2C, 0xA7, 0x83, 0x66, 0xD0, 0x22, 0x2F, 0xF8, 0x8F, 0x00, 0x03, 0x00, 0x28, 0x27, 0x1D, 
	0x40, 0x28, 0x71, 0x37, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, 
	
};


static bool checkModified(Poco::Net::HTTPServerRequest& request)
{
	Poco::DateTime modified(2018, 9, 21, 7, 25, 39);
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


void HeaderLogo::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("image/png"s);

	if (!(checkModified(request))) return;

	std::ostream& responseStream = response.send();
#line 192 "/Users/guenter/ws/git/my-devices/gateway/src/HeaderLogo.cpsp"

	responseStream.write(reinterpret_cast<const char*>(data), sizeof(data));
}


} } // namespace MyDevices::Gateway
