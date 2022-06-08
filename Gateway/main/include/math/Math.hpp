#pragma once
#include <string>

#include "MathTypes.hpp"

namespace Gateway
{
	class Math
	{

	//@TODO: Add comments to all of these and explain what they do
	template<typename T>
	static T ToRad(T t_val)
	{
		return (t_val / 360.f) * G_PI_2;
	}

	template<typename T>
	static T ToDeg(T t_val)
	{
		return (t_val / G_PI_2) * 360.f;
	}

	template<typename T>
	static T Clamp(T t_value, T t_min, T t_max)
	{
		if (t_value > t_max) t_value = t_max;
		else if (t_value < t_min) t_value = t_min;

		return t_value;
	}

	template<typename T>
	inline static T Min(T t_min, T t_max)
	{
		return (t_min < t_max ? t_min : t_max);
	}

	template<typename T>
	inline static T Max(T t_min, T t_max)
	{
		return (t_min > t_max ? t_min : t_max);
	}

	template<typename T>
	inline static T Abs(T t_val)
	{
		std::string name = typeid(t_val).name();

		if (name.find("int") != std::string::npos)
			return abs(t_val);

		return fabs(t_val);
	}

	//===========//
	//Vec2
	//===========//

	inline static Vec2f Vec2Abs(const Vec2f& t_vec);

	inline static Vec2f Vec2Min(const Vec2f& t_veca, const Vec2f& t_vecb);
	inline static Vec2f Vec2Max(const Vec2f& t_veca, const Vec2f& t_vecb);

	//===========//
	//Vec3
	//===========//

	inline static Vec3f Vec3Abs(const Vec3f& t_vec);
			  
	inline static Vec3f Vec3Min(const Vec3f& t_veca, const Vec3f& t_vecb);
	inline static Vec3f Vec3Max(const Vec3f& t_veca, const Vec3f& t_vecb);

	static Vec3f Vec3Cross(const Vec3f& t_veca, const Vec3f& t_vecb);

	static Vec3f Vec3Dot(const Vec3f& t_veca, const Vec3f& t_vecb);
	
	static Vec3f Vec3Angle(const Vec3f& t_veca, const Vec3f& t_vecb);

	//===========//
	//Vec4
	//===========//
	
	//static Vec4f Vec4Cross(const Vec4f& t_veca, const Vec4f& t_vecb);
	
	//static Vec4f Vec4Dot(const Vec4f& t_veca, const Vec4f& t_vecb);

	//static Vec4f Vec4Angle(const Vec4f& t_veca, const Vec4f& t_vecb);

	//===========//
	//Mat4
	//===========//

	//===========//
	//Quat
	//===========//
	};
};