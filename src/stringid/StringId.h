#ifndef __STRING_ID_H__
#define __STRING_ID_H__

/*
* Compile-time hashed strings based in an article from "Game Engine Gems 3 - Stefan Reinalter"
*
* With the code below it is possible to hash string, both at compile- and runtime. This technique can
* come in handy for places where performance is a key concern. Costly string comparisons can be replaced
* by integer-integer comparisons and the hashing needed for this is done during compilation.
*/

// The MIT License(MIT)
// 
// Copyright(c) 2015 Stefan Reinalter
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdint>

namespace cry
{
	static constexpr uint64_t FNV1_OFFSET = 14695981039346656037u;
	static constexpr uint64_t FNV1_PRIME= 1099511628211u;

	/*
	 * The following three 'GenerateFNV1Hash' functions calculate an Fowler-Noll-Vo-1 hash
	 * of an const char* at runtime. They hashing algorithm is based on an offset value and
	 * a prime value which are XOR'ed and multiplied into the hash.
	 */
	uint64_t GenerateFNV1Hash(const char* string, size_t length, uint64_t hash);
	uint64_t GenerateFNV1Hash(const char* string, size_t length);
	uint64_t GenerateFNV1Hash(const char* string);

	/*
	 * The following two struct templates are a small template meta-program to calculate the
	 * same FNV1 hash as the run-time functions above do. It works by recursion and the 
	 * struct template specialized to 0u is the termination marker. 
	 */
	template <size_t C>
	struct Hash
	{
		template<size_t N>
		static constexpr uint64_t Generate(const char (&str)[N])
		{
			return (Hash<C - 1>::Generate(str) ^ static_cast<uint64_t>(str[C - 1])) * FNV1_PRIME;
		}
	};

	template<>
	struct Hash<0u>
	{
		template<size_t N>
		static constexpr uint64_t Generate(const char (&str)[N])
		{
			return FNV1_OFFSET;
		}
	};

	/*
	 * The 'HashHelper' serves as a helper template to decide whether the hash needs to be
	 * computed at run-time or can be done at compile-time. This unifies the interface for
	 * hashing string, independent if the input is a string literal or a run-time string.
	 */
	template<typename T>
	struct HashHelper {};

	template<>
	struct HashHelper<const char*>
	{
		static uint64_t Generate(const char* str)
		{
			return GenerateFNV1Hash(str);
		}
	};

	template<size_t N>
	struct HashHelper<char [N]>
	{
		static constexpr uint64_t Generate(const char (&str)[N])
		{
			return Hash<N - 1u>::Generate(str);
		}
	};

	template<typename T>
	static constexpr uint64_t GenerateHash(const T& str)
	{
		return HashHelper<T>::Generate(str);
	}

	/*
	 * The StringId class allows for passing of hashed strings between functions. The
	 * non-explicit, template CTOR allows for this behavior. Later versions of this will
	 * also support some kind of string collection to keep track of already hashes string.
	 * This will help with finding duplicates and to return the right string from the hash
	 * if it is needed.
	 */

	class StringID
	{
	public:
		template<typename T>
		StringID(const T& str)
			: m_Hash(GenerateHash(str))
		{}

		bool operator==(const StringID& other) const;
		bool operator!=(const StringID& other) const;

		uint64_t GetHash(void) const { return m_Hash; }
	
	private:
		uint64_t m_Hash = 0u;
	};

}

#endif // __STRING_ID_H__