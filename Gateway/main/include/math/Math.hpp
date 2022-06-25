#pragma once

#include "types/MathTypes.hpp"

namespace Gateway
{
	class Math
	{
	public:
		/**
		  * Name: ToRad
		  * Desc: Converts the value provided to radians
		  * Param: Value to be converted
		  * Return: Converted value
		  */
		template<typename T>
		static T ToRad(T t_val)
		{
			return (t_val / 360.f) * G_PI_2;
		}

		/**
		  * Name: ToDef
		  * Desc: Converts the value provided to degress
		  * Param: Value to be converted
		  * Return: Converted value
		  */
		template<typename T>
		static T ToDeg(T t_val)
		{
			return (t_val / G_PI_2) * 360.f;
		}

		/**
		  * Name: Clamp
		  * Desc: Clamps two values provided
		  * Param: Value to be clamped
		  * Param: Minimum value
		  * Param: Maximum value
		  * Return: Newly clamped Value
		  */
		template<typename T>
		static T Clamp(T t_value, T t_min, T t_max)
		{
			if (t_value > t_max) t_value = t_max;
			else if (t_value < t_min) t_value = t_min;

			return t_value;
		}

		/**
		  * Name: Min
		  * Desc: Chooses the minimum value between two provided values
		  * Param: Minimum value
		  * Param: Maximum value
		  * Return: Minimum value of the two provided values
		  */
		template<typename T>
		inline static T Min(T t_min, T t_max)
		{
			return (t_min < t_max ? t_min : t_max);
		}

		/**
		  * Name: Max
		  * Desc: Chooses the maximum value between two provided values
		  * Param: Minimum value
		  * Param: Maximum value
		  * Return: Maximum value of the two provided values
		  */
		template<typename T>
		inline static T Max(T t_min, T t_max)
		{
			return (t_min > t_max ? t_min : t_max);
		}

		/**
		  * Name: Abs
		  * Desc: Returns the absolute value of a variable
		  * Param: Value to be converted
		  * Return: Absolute value of variable
		  */
		template<typename T>
		inline static T Abs(T t_val)
		{
			if (typeid(t_val) == typeid(int))
			{
				return abs(t_val);
			}

			return fabs(t_val);
		}

		//===========//
		//Vec2
		//===========//

		/**
		  * Duplicate: See corresponding Abs function above
		  */
		inline static Vec2f Vec2Abs(const Vec2f& t_vec);

		/**
		  * Duplicate: See corresponding Min function above
		  */
		inline static Vec2f Vec2Min(const Vec2f& t_veca, const Vec2f& t_vecb);
		/**
		  * Duplicate: See corresponding Max function above
		  */
		inline static Vec2f Vec2Max(const Vec2f& t_veca, const Vec2f& t_vecb);

		//===========//
		//Vec3
		//===========//

		/**
		  * Duplicate: See corresponding Abs function above
		  */
		inline static Vec3f Vec3Abs(const Vec3f& t_vec);
			  
		/**
		  * Duplicate: See corresponding Min function above
		  */
		inline static Vec3f Vec3Min(const Vec3f& t_veca, const Vec3f& t_vecb);
		/**
		  * Duplicate: See corresponding Max function above
		  */
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