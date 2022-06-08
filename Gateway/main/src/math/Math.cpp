#include "math/Math.hpp"

namespace Gateway
{
	//===========//
	//Vec2
	//===========//

	Vec2f Math::Vec2Abs(const Vec2f& t_vec)
	{
		return Vec2f(Abs(t_vec.x), Abs(t_vec.y));
	}

	Vec2f Math::Vec2Min(const Vec2f& t_veca, const Vec2f& t_vecb)
	{
		return Vec2f(Min(t_veca.x, t_vecb.x), Min(t_veca.y, t_vecb.y));
	}

	Vec2f Math::Vec2Max(const Vec2f& t_veca, const Vec2f& t_vecb)
	{
		return Vec2f(Max(t_veca.x, t_vecb.x), Max(t_veca.y, t_vecb.y));
	}

	//===========//
	//Vec3
	//===========//

	Vec3f Math::Vec3Abs(const Vec3f& t_vec)
	{
		return Vec3f(Abs(t_vec.x), Abs(t_vec.y), Abs(t_vec.z));
	}

	Vec3f Math::Vec3Min(const Vec3f& t_veca, const Vec3f& t_vecb)
	{
		return Vec3f(Min(t_veca.x, t_vecb.x), Min(t_veca.y, t_vecb.y), Min(t_veca.z, t_vecb.z));
	}

	Vec3f Math::Vec3Max(const Vec3f& t_veca, const Vec3f& t_vecb)
	{
		return Vec3f(Max(t_veca.x, t_vecb.x), Max(t_veca.y, t_vecb.y), Max(t_veca.z, t_vecb.z));
	}

	Vec3f Math::Vec3Cross(const Vec3f& t_veca, const Vec3f& t_vecb)
	{
		Vec3f product;

		product.x = t_veca.y * t_vecb.z - t_veca.z * t_vecb.y;
		product.y = t_veca.z * t_vecb.x - t_veca.x * t_vecb.z;
		product.z = t_veca.x * t_vecb.y - t_veca.y * t_vecb.x;

		return product;
	}

	Vec3f Math::Vec3Dot(const Vec3f& t_veca, const Vec3f& t_vecb)
	{
		return (t_veca.x * t_vecb.x + t_veca.y * t_vecb.y + t_veca.z * t_vecb.z);
	}

	Vec3f Math::Vec3Angle(const Vec3f& t_veca, const Vec3f& t_vecb)
	{
		return Vec3f();
	}

	//===========//
	//Vec4
	//===========//

	//===========//
	//Mat4
	//===========//

	//===========//
	//Quat
	//===========//
};