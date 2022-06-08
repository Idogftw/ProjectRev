#pragma once

namespace Gateway
{
	template <typename T>
	class Vec2
	{
	public:
		Vec2() : x(0), y(0) {}
		Vec2(T t_val) : x(t_val), y(t_val) {}
		Vec2(T t_x, T t_y) : x(t_x), y(t_y) {}
		Vec2(const Vec2<T>& t_vec) : x(t_vec.x), y(t_vec.y) {}
	
		//===========//
		//Copy
		//===========//

		inline Vec2<T>& operator=(const Vec2& t_vec)
		{
			x = t_vec.x;
			y = t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator=(const T t_val)
		{
			x = t_val;
			y = t_val;
			return *this;
		}

		//===========//
		//Bool
		//===========//

		inline bool operator==(const Vec2<T>& t_vec) const
		{
			return (x == t_vec.x && y == t_vec.y);
		}

		inline bool operator!=(const Vec2<T>& t_vec) const
		{
			return (x != t_vec.x || y != t_vec.y);
		}

		//===========//
		//Arithmetic
		//===========//

		inline Vec2<T>& operator+(const Vec2& t_vec) const
		{
			x += t_vec.x;
			y += t_vec.y;
			return *this;
		}
		
		inline Vec2<T>& operator-(const Vec2& t_vec) const
		{
			x -= t_vec.x;
			y -= t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator*(const Vec2& t_vec) const
		{
			x *= t_vec.x;
			y *= t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator/(const Vec2& t_vec) const
		{
			x /= t_vec.x;
			y /= t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator+=(const Vec2& t_vec)
		{
			x += t_vec.x;
			y += t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator-=(const Vec2& t_vec)
		{
			x -= t_vec.x;
			y -= t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator*=(const Vec2& t_vec)
		{
			x *= t_vec.x;
			y *= t_vec.y;
			return *this;
		}

		inline Vec2<T>& operator/=(const Vec2& t_vec)
		{
			x /= t_vec.x;
			y /= t_vec.y;
			return *this;
		}

		//===========//
		//Methods
		//===========//

		inline T Length() const
		{
			return sqrt(x * x + y * y);
		}

		inline T LengthSqr() const
		{
			return (x * x + y * y);
		}

		inline T Normalize()
		{
			T length = LengthSqr();

			T invlength = 1.0f / length;

			if (lenght > 1e-08)
			{
				x *= InvLength;
				y *= InvLength;
			}

			return length;
		}

	public:
		T x, y;
	};

	template <typename T>
	class Vec3
	{
	public:
		Vec3() : x(0), y(0), z(0) {}
		Vec3(T t_val) : x(t_val), y(t_val), z(t_val) {}
		Vec3(T t_x, T t_y, T t_z) : x(t_x), y(t_y), z(t_z) {}
		Vec3(const Vec3<T>& t_vec) : x(t_vec.x), y(t_vec.y), z(t_vec.z) {}

		//===========//
		//Copy
		//===========//

		inline Vec3<T>& operator=(const Vec3<T>& t_vec)
		{
			x = t_vec.x;
			y = t_vec.y;
			z = t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator=(const T t_val)
		{
			x = t_val.x;
			y = t_val.y;
			z = t_val.z;
			return *this;
		}

		//===========//
		//Bool
		//===========//

		inline bool operator==(const Vec3<T>& t_vec) const
		{
			return (x == t_vec.x && y == t_vec.y && z == t_vec.z);
		}

		inline bool operator!=(const Vec3<T>& t_vec) const
		{
			return (x != t_vec.x || y != t_vec.y || z != t_vec.z);
		}

		inline bool operator<(const Vec3<T>& t_vec) const
		{
			//If x != new vec return x < t_vec.x
			//else if y!= new vec return y < t_vex.y
			//else return z < t_vec.z
			return (x != t_vec.x ? x < t_vec.x 
				 : (y != t_vec.y ? y < t_vec.y
				 : z < t_vec.z));
		}

		inline bool operator>(const Vec3<T>& t_vec) const
		{
			//If x != new vec return x > t_vec.x
			//else if y!= new vec return y > t_vex.y
			//else return z > t_vec.z
			return (x != t_vec.x ? x > t_vec.x
				 : (y != t_vec.y ? y > t_vec.y
				 : z > t_vec.z));
		}

		//===========//
		//Arithmetic
		//===========//

		inline Vec3<T>& operator+(const Vec3& t_vec) const
		{
			x += t_vec.x;
			y += t_vec.y;
			z += t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator-(const Vec3& t_vec) const
		{
			x -= t_vec.x;
			y -= t_vec.y;
			z -= t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator*(const Vec3& t_vec) const
		{
			x *= t_vec.x;
			y *= t_vec.y;
			z *= t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator/(const Vec3& t_vec) const
		{
			x /= t_vec.x;
			y /= t_vec.y;
			z /= t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator+=(const Vec3& t_vec)
		{
			x += t_vec.x;
			y += t_vec.y;
			z += t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator-=(const Vec3& t_vec)
		{
			x -= t_vec.x;
			y -= t_vec.y;
			z -= t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator*=(const Vec3& t_vec)
		{
			x *= t_vec.x;
			y *= t_vec.y;
			z *= t_vec.z;
			return *this;
		}

		inline Vec3<T>& operator/=(const Vec3& t_vec)
		{
			x /= t_vec.x;
			y /= t_vec.y;
			z /= t_vec.z;
			return *this;
		}

		//===========//
		//Methods
		//===========//

		inline T Length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		inline T LengthSqr() const
		{
			return (x * x + y * y + z * z);
		}

		inline T Normalize()
		{
			T length = LengthSqr();

			T invlength = 1.0f / length;

			if (lenght > 1e-08)
			{
				x *= InvLength;
				y *= InvLength;
				z *= InvLength;
			}

			return length;
		}

		public:
			T x, y, z;
	};

	template <typename T>
	class Vec4
	{
	public:
		Vec4() : x(0), y(0), z(0), w(0) {}
		Vec4(T t_val) : x(t_val), y(t_val), z(t_val), w(t_val) {}
		Vec4(T t_x, T t_y, T t_z, T t_w) : x(t_x), y(t_y), z(t_z), w(t_w) {}
		Vec4(const Vec3<T>& t_vec, T t_w) : x(t_vec.x), y(t_vec.y), z(t_vec.z), w(t_w)  {}
		Vec4(const Vec4<T>& t_vec) : x(t_vec.x), y(t_vec.y), z(t_vec.z), w(t_vec.w) {}

		//===========//
		//Copy
		//===========//

		inline Vec4<T>& operator=(const Vec4<T>& t_vec)
		{
			x = t_vec.x;
			y = t_vec.y;
			z = t_vec.z;
			w = t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator=(const T t_val)
		{
			x = t_val.x;
			y = t_val.y;
			z = t_val.z;
			w = t_val.w;
			return *this;
		}

		//===========//
		//Bool
		//===========//

		inline bool operator==(const Vec4<T>& t_vec) const
		{
			return (x == t_vec.x && y == t_vec.y && z == t_vec.z && w == t_vec.w);
		}

		inline bool operator!=(const Vec4<T>& t_vec) const
		{
			return (x != t_vec.x || y != t_vec.y || z != t_vec.z || w != t_vec.w);
		}

		inline bool operator<(const Vec4<T>& t_vec) const
		{
			//If x != new vec return x < t_vec.x
			//else if y != new vec return y < t_vex.y
			//else if z != new vec return z < t_vec.z
			//else return w < t_vec.w
			return (x != t_vec.x ? x < t_vec.x
				 : (y != t_vec.y ? y < t_vec.y
				 : (z != t_vec.z ? z < t_vec.z
				 : w < t_vec.w)));
		}

		inline bool operator>(const Vec4<T>& t_vec) const
		{
			//If x != new vec return x > t_vec.x
			//else if y != new vec return y > t_vex.y
			//else if z != new vec return z > t_vec.z
			//else return w > t_vec.w
			return (x != t_vec.x ? x > t_vec.x
				 : (y != t_vec.y ? y > t_vec.y
				 : (z != t_vec.z ? z > t_vec.z
				 : w > t_vec.w)));
		}

		//===========//
		//Arithmetic
		//===========//

		inline Vec4<T>& operator+(const Vec4& t_vec) const
		{
			x += t_vec.x;
			y += t_vec.y;
			z += t_vec.z;
			w += t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator-(const Vec4& t_vec) const
		{
			x -= t_vec.x;
			y -= t_vec.y;
			z -= t_vec.z;
			w -= t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator*(const Vec4& t_vec) const
		{
			x *= t_vec.x;
			y *= t_vec.y;
			z *= t_vec.z;
			w *= t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator/(const Vec4& t_vec) const
		{
			x /= t_vec.x;
			y /= t_vec.y;
			z /= t_vec.z;
			w /= t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator+=(const Vec4& t_vec)
		{
			x += t_vec.x;
			y += t_vec.y;
			z += t_vec.z;
			w += t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator-=(const Vec4& t_vec)
		{
			x -= t_vec.x;
			y -= t_vec.y;
			z -= t_vec.z;
			return *this;
		}

		inline Vec4<T>& operator*=(const Vec4& t_vec)
		{
			x *= t_vec.x;
			y *= t_vec.y;
			z *= t_vec.z;
			w *= t_vec.w;
			return *this;
		}

		inline Vec4<T>& operator/=(const Vec4& t_vec)
		{
			x /= t_vec.x;
			y /= t_vec.y;
			z /= t_vec.z;
			w /= t_vec.w;
			return *this;
		}

		//===========//
		//Methods
		//===========//

		inline T Length() const
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		inline T LengthSqr() const
		{
			return (x * x + y * y + z * z + w * w);
		}

		inline T Normalize()
		{
			T length = LengthSqr();

			T invlength = 1.0f / length;

			if (lenght > 1e-08)
			{
				x *= InvLength;
				y *= InvLength;
				z *= InvLength;
				w *= InvLength;
			}

			return length;
		}

	public:
		T x, y, z, w;
	};
};