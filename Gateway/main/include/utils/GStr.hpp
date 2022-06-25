#pragma once
#include <string>

namespace Gateway
{
	#define get16bits(d) (*((const uint16_t *) (d)))

	static std::string GetExt(const std::string& t_str);

	// Use from Paul Hsieh's Fast Hash, code from https://chromium.googlesource.com/chromium/src/base/+/master/third_party/superfasthash/superfasthash.c
	//static uint32_t FastHash(const std::string& t_str);
};