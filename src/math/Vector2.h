#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "Setup.h"

namespace cry
{
	template<typename T>
	struct Vector<2, T>
	{
		union
		{
			struct { T x; T y; };
			struct { T r; T g; };

			T data[2];
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
		{}

		constexpr Vector(T x, T y)
			: x(x)
			, y(y)
		{}

		template<typename U>
		constexpr explicit Vector(const Vector<2, U>& other)
			: x(static_cast<U>(other.x))
			, y(static_cast<U>(other.y))
		{}

		// Operators
		template<typename U>
		constexpr Vector<2, T>& operator=(const Vector<2, U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);

			return *this;
		}

		// Length function

		static constexpr length_t Length(void) { return 2; }

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
		Vector<2, T> operator+=(const Vector<2, T>& rhs)
		{
			x += rhs.x;
			y += rhs.y;

			return *this;
		}

		Vector<2, T> operator-=(const Vector<2, T>& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;

			return *this;
		}

		Vector<2, T> operator*=(const Vector<2, T>& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;

			return *this;
		}

		Vector<2, T> operator/=(const Vector<2, T>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;

			return *this;
		}

		Vector<2, T> operator+=(T scalar)
		{
			x += scalar;
			y += scalar;

			return *this;
		}

		Vector<2, T> operator-=(T scalar)
		{
			x -= scalar;
			y -= scalar;

			return *this;
		}

		Vector<2, T> operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;

			return *this;
		}

		Vector<2, T> operator/=(T scalar)
		{
			const T rec = static_cast<T>(1) / scalar;

			x *= rec;
			y *= rec;

			return *this;
		}
	};

	// Unary operators
	template<typename T>
	Vector<2, T> operator+(const Vector<2, T>& vec)
	{
		return vec;
	}

	template<typename T>
	Vector<2, T> operator-(const Vector<2, T>& vec)
	{
		return Vector<2, T>(-vec.x, -vec.y);
	}

	// Binary operators

	// Scalar
	template<typename T>
	Vector<2, T> operator+(const Vector<2, T>& lhs, T scalar)
	{
		return Vector<2, T>(lhs.x + scalar, lhs.y + scalar);
	}

	template<typename T>
	Vector<2, T> operator-(const Vector<2, T>& lhs, T scalar)
	{
		return Vector<2, T>(lhs.x - scalar, lhs.y - scalar);
	}

	template<typename T>
	Vector<2, T> operator*(const Vector<2, T>& lhs, T scalar)
	{
		return Vector<2, T>(lhs.x * scalar, lhs.y * scalar);
	}

	template<typename T>
	Vector<2, T> operator/(const Vector<2, T>& lhs, T scalar)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<2, T>(lhs.x * rec, lhs.y * rec);
	}

	template<typename T>
	Vector<2, T> operator+(T scalar, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(rhs.x + scalar, rhs.y + scalar);
	}

	template<typename T>
	Vector<2, T> operator-(T scalar, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(rhs.x - scalar, rhs.y - scalar);
	}

	template<typename T>
	Vector<2, T> operator*(T scalar, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(rhs.x * scalar, rhs.y * scalar);
	}

	template<typename T>
	Vector<2, T> operator/(T scalar, const Vector<2, T>& rhs)
	{
		const T rec = static_cast<T>(1) / scalar;
		return Vector<2, T>(rhs.x * rec, rhs.y * rec);
	}

	// Same type vector
	template<typename T>
	Vector<2, T> operator+(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	template<typename T>
	Vector<2, T> operator-(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	template<typename T>
	Vector<2, T> operator*(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(lhs.x * rhs.x, lhs.y * rhs.y);
	}

	template<typename T>
	Vector<2, T> operator/(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return Vector<2, T>(lhs.x / rhs.x, lhs.y / rhs.y);
	}


	using Vector2f = Vector<2, float>;
	using Vector2d = Vector<2, double>;
	using Vector2i = Vector<2, int>;

} // namespace cry

#endif //__VECTOR2_H__