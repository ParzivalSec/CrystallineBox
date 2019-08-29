#include "StringId.h"
#include <cstring>

using namespace cry;

inline uint64_t GenerateFNV1Hash(const char* string, size_t length, uint64_t hash)
{
	for (size_t byte = 0u; byte < length; ++byte)
	{
		hash ^= static_cast<uint64_t>(string[byte]);
		hash *= FNV1_PRIME;
	}

	return hash;
}

inline uint64_t GenerateFNV1Hash(const char* string, size_t length)
{
	return cry::GenerateFNV1Hash(string, length, FNV1_OFFSET);
}

inline uint64_t GenerateFNV1Hash(const char* string)
{
	return cry::GenerateFNV1Hash(string, strlen(string));
}

bool StringID::operator==(const StringID& other) const
{
	return m_Hash == other.m_Hash;
}

bool StringID::operator!=(const StringID& other) const
{
	return !(*this == other);
}