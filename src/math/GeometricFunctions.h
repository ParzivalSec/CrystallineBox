#ifndef __GEOMETRIC_FUNCTIONS_H__
#define __GEOMETRIC_FUNCTIONS_H__

#include "Setup.h"
#include <cmath>

namespace cry
{
	template<typename T>
	T Dot(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	template<typename T>
	T Dot(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template<typename T>
	T Dot(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	template<typename T>
	Vector<3, T> Cross(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>
			(
				lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x
				);
	}

	template<length_t length, typename T>
	T SquaredMagnitude(const Vector<length, T>& v)
	{
		return Dot(v, v);
	}

	template<length_t length, typename T>
	T Magnitude(const Vector<length, T>& v)
	{
		return sqrt(SquaredMagnitude(v));
	}

	template<typename T>
	T Distance(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Magnitude(rhs - lhs);
	}
	/*
	 * Reflecting a vector along an axis is done by subtracting twice the
	 * projection (part of v that's parallel to axis) onto axis from the 
	 * vector.
	 */

	template<length_t length, typename T>
	Vector<length, T> ReflectAlongAxis(const Vector<length, T>& v, const Vector<length, T>& axis)
	{
		return v - 2 * axis * Dot(v, axis);
	}

	template<length_t length, typename T>
	Vector<3, T> Normalized(const Vector<length, T>& v)
	{
		const T rec = static_cast<T>(1) / Magnitude(v);
		return v * rec;
	}

	template<length_t length, typename T>
	void Normalize(Vector<length, T>& v)
	{
		const T rec = static_cast<T>(1) / Magnitude(v);

		v.x *= rec;
		v.y *= rec;
		v.z *= rec;
	}

	/*
	 * The scalar triple product returns a scalar number that describes the volume of the 
	 * parallelepiped spanned by the three vectors a, b and c. This works out because the
	 * volume of this figure is based an the area of the base (a x b) multiplied by the
	 * height of the figure (c * cos(angle)) which combined yields the formula Dot((a x b), c) 
	 */

	template<typename T>
	T ScalarTripleProduct(const Vector<3, T>& a, const Vector<3, T>& b, const Vector<3, T>& c)
	{
		return Dot(Cross(a, b), c);
	}

	template<typename T>
	Vector<3, T> VectorTripleProduct(const Vector<3, T>& a, const Vector<3, T>& b, const Vector<3, T>& c)
	{
		return b * Dot(a, c) - c * Dot(a, b);
	}
}

#endif // __GEOMETRIC_FUNCTIONS_H__
