#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"

namespace Gateway
{
	class Quaternion
	{
	public:
		Quaternion();
		Quaternion(float t_x, float t_y, float t_z, float t_w);
		Quaternion(const Mat4<float>& t_mat);

		static const Quaternion Identity;
	public:
		Vec4<float> v;
	};
};