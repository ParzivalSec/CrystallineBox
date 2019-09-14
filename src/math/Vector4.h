#ifndef __VECTOR4_H__
#define __VECTOR4_H__

#include "Setup.h"

namespace cry
{
	template<typename T>
	struct Vector<4, T>
	{
		union
		{
			struct { T x; T y; T z; T w; };
			struct { T r; T g; T b; T a; };

			T data[4];
		};

		// Constructors
		constexpr Vector(void) = default;
		constexpr Vector(const Vector& other) = default;
		constexpr Vector(Vector&& other) = default;
		constexpr Vector& operator=(const Vector& other) = default;
		constexpr Vector& operator=(Vector&& other) = default;
		~Vector(void) = default;

		constexpr explicit Vector(T scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar)
		{}

		constexpr Vector(T x, T y, T z, T w)
			: x(x)
			, y(y)
			, z(z)
			, w(w)
		{}

		template<typename U>
		constexpr explicit Vector(const Vector<4, U>& other)
			: x(static_cast<U>(other.x))
			, y(static_cast<U>(other.y))
			, z(static_cast<U>(other.z))
			, w(static_cast<U>(other.w))
		{}

		// Operators
		template<typename U>
		constexpr Vector<4, T>& operator=(const Vector<4, U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);
			z = static_cast<T>(other.z);
			w = static_cast<T>(other.w);

			return *this;
		}

		// Length function

		static constexpr length_t Length(void) { return 4; }

		// Element access operators

		constexpr T& operator[](length_t idx)
		{
			// TODO [LV]: Add assert as soon as we decided which kind of assert we want to use
			return data[idx];
		}

		constexpr const T& operator[](length_t idx) const
		{
			// TODO [LV]: Add assert as soon as we decided which kind of assert we want to use
			return data[idx];
		}

		// 
		Vector<4, T> operator+=(const Vector<4, T>& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;

			return *this;
		}

		Vector<4, T> operator-=(const Vector<4, T>& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;

			return *this;
		}

		Vector<4, T> operator*=(const Vector<4, T>& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;

			return *this;
		}

		Vector<4, T> operator/=(const Vector<4, T>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;

			return *this;
		}

		Vector<3, T> operator+=(T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;

			return *this;
		}

		Vector<3, T> operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;

			return *this;
		}

		Vector<3, T> operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;

			return *this;
		}

		Vector<3, T> operator/=(T scalar)
		{
			const T rec = static_cast<T>(1) / scalar;

			x *= rec;
			y *= rec;
			z *= rec;
			w *= rec;

			return *this;
		}
	};

	// Unary operators
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& vec)
	{
		return vec;
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& vec)
	{
		return Vector<4, T>(-vec.x, -vec.y, -vec.z, -vec.w);
	}

	// Binary operators

	// Scalar
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& lhs, T scalar)
	{
		return Vector<4, T>(lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar);
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& lhs, T scalar)
	{
		return Vector<4, T>(lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar);
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& lhs, T scalar)
	{
		return Vector<4, T>(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar);
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& lhs, T scalar)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<4, T>(lhs.x * rec, lhs.y * rec, lhs.z * rec, lhs.w * rec);
	}

	template<typename T>
	Vector<4, T> operator+(T scalar, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(rhs.x + scalar, rhs.y + scalar, rhs.z + scalar, rhs.w + scalar);
	}

	template<typename T>
	Vector<4, T> operator-(T scalar, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(rhs.x - scalar, rhs.y - scalar, rhs.z - scalar, rhs.z * scalar);
	}

	template<typename T>
	Vector<4, T> operator*(T scalar, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(rhs.x * scalar, rhs.y * scalar, rhs.z * scalar, rhs.w * scalar);
	}

	template<typename T>
	Vector<4, T> operator/(T scalar, const Vector<4, T>& rhs)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<4, T>(rhs.x * rec, rhs.y * rec, rhs.z * rec, rhs.w * rec);
	}

	// Same type vector
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
	}


	using Vector4f = Vector<4, float>;
	using Vector4d = Vector<4, double>;
	using Vector4i = Vector<4, int>;

} // namespace cry

#endif //__VECTOR4_H__