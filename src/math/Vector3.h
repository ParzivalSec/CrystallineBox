#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "Setup.h"

namespace cry
{
	template<typename T>
	struct Vector<3, T>
	{
		union
		{
			struct { T x; T y; T z; };
			struct { T r; T g; T b; };

			T data[3];
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
		{}

		constexpr Vector(T x, T y, T z)
			: x(x)
			, y(y)
			, z(z)
		{}

		template<typename U>
		constexpr explicit Vector(const Vector<3, U>& other)
			: x(static_cast<U>(other.x))
			, y(static_cast<U>(other.y))
			, z(static_cast<U>(other.z))
		{}

		// Operators
		template<typename U>
		constexpr Vector<3, T>& operator=(const Vector<3, U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);
			z = static_cast<T>(other.z);

			return *this;
		}

		// Length function

		static constexpr length_t Length(void) { return 3; }

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
		Vector<3, T> operator+=(const Vector<3, T>& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;

			return *this;
		}

		Vector<3, T> operator-=(const Vector<3, T>& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;

			return *this;
		}

		Vector<3, T> operator*=(const Vector<3, T>& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;

			return *this;
		}

		Vector<3, T> operator/=(const Vector<3, T>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;

			return *this;
		}

		Vector<3, T> operator+=(T scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;

			return *this;
		}

		Vector<3, T> operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;

			return *this;
		}

		Vector<3, T> operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		Vector<3, T> operator/=(T scalar)
		{
			const T rec = static_cast<T>(1) / scalar;

			x *= rec;
			y *= rec;
			z *= rec;

			return *this;
		}
	};

	// Unary operators
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& vec)
	{
		return vec;
	}

	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& vec)
	{
		return Vector<3, T>(-vec.x, -vec.y, -vec.z);
	}

	// Binary operators

	// Scalar
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& lhs, T scalar)
	{
		return Vector<3, T>(lhs.x + scalar, lhs.y + scalar, lhs.z + scalar);
	}

	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& lhs, T scalar)
	{
		return Vector<3, T>(lhs.x - scalar, lhs.y - scalar, lhs.z - scalar);
	}

	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& lhs, T scalar)
	{
		return Vector<3, T>(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
	}

	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& lhs, T scalar)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<3, T>(lhs.x * rec, lhs.y * rec, lhs.z * rec);
	}

	template<typename T>
	Vector<3, T> operator+(T scalar, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(rhs.x + scalar, rhs.y + scalar, rhs.z + scalar);
	}

	template<typename T>
	Vector<3, T> operator-(T scalar, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(rhs.x - scalar, rhs.y - scalar, rhs.z - scalar);
	}

	template<typename T>
	Vector<3, T> operator*(T scalar, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(rhs.x * scalar, rhs.y * scalar, rhs.z * scalar);
	}

	template<typename T>
	Vector<3, T> operator/(T scalar, const Vector<3, T>& rhs)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<3, T>(rhs.x * rec, rhs.y * rec, rhs.z * rec);
	}

	// Same type vector
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}

	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
	}


	using Vector3f = Vector<3, float>;
	using Vector3d = Vector<3, double>;
	using Vector3i = Vector<3, int>;

} // namespace cry

#endif //__VECTOR3_H__