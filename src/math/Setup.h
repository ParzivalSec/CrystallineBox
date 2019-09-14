#ifndef __SETUP_H__
#define __SETUP_H__

namespace cry
{
	/*
	 * Every function return a length does so by returning a length_t typed
	 * return value. Users can force this to be size_t, otherwise it will
	 * default to int for simplicity.
	 */

#if defined(MATH_FORCE_LENGTH_SIZE_T)
	using length_t = size_t;
#else
	using length_t = int;
#endif

	/*
	 * If the compiler supports the 'constexpr' keyword we expose a constexpr
	 * function for getting the element count of an array. Otherwise we will
	 * provide a non-constexpr variant using the sizeof function.
	 */

#if defined(CRY_HAS_CONSTEXPR)
	template<typename T, size_t N>
	constexpr size_t CountOf(T const (&arr)[N])
	{
		return N;
	}

#define CRY_COUNT_OF(arr) cry::CountOf(arr)
#else
#define CRY_COUNT_OF(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

	template<length_t length, typename T> struct Vector;
}

#endif // __SETUP_H__