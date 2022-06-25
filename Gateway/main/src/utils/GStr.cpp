#include "utils/GStr.hpp"

namespace Gateway
{
	std::string GetExt(const std::string& t_str)
	{
		int position = t_str.find_last_of(".");

		if (position == std::string::npos)
		{
			return "";
		}

		return t_str.substr(position + 1);
	}

	//uint32_t FastHash(const std::string& t_str)
	//{
	//	uint32_t len = t_str.size();
	//	uint32_t hash = len, tmp;
	//	int32_t rem;
	//	const char* data = t_str.c_str();

	//	if (t_str.empty())
	//	{
	//		return 0;
	//	}

	//	rem = len & 3;
	//	len >>= 2;

	//	/* Main loop */
	//	for (; len > 0; len--) {
	//		hash += get16bits(data);
	//		tmp = (get16bits(data + 2) << 11) ^ hash;
	//		hash = (hash << 16) ^ tmp;
	//		data += 2 * sizeof(uint16_t);
	//		hash += hash >> 11;
	//	}
	//	/* Handle end cases */
	//	switch (rem) {
	//	case 3: hash += get16bits(data);
	//		hash ^= hash << 16;
	//		hash ^= ((signed char)data[sizeof(uint16_t)]) << 18;
	//		hash += hash >> 11;
	//		break;
	//	case 2: hash += get16bits(data);
	//		hash ^= hash << 11;
	//		hash += hash >> 17;
	//		break;
	//	case 1: hash += (signed char)*data;
	//		hash ^= hash << 10;
	//		hash += hash >> 1;
	//	}
	//	/* Force "avalanching" of final 127 bits */
	//	hash ^= hash << 3;
	//	hash += hash >> 5;
	//	hash ^= hash << 4;
	//	hash += hash >> 17;
	//	hash ^= hash << 25;
	//	hash += hash >> 6;

	//	return hash;
	//}
};