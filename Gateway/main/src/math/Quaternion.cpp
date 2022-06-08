#include "math/Quaternion.hpp"

namespace Gateway
{
	const Quaternion Quaternion::Identity(1.f, 0.f, 0.f, 0.f);

	Quaternion::Quaternion()
	{
	}

	Quaternion::Quaternion(float t_x, float t_y, float t_z, float t_w)
	{
		v = { t_x, t_y, t_z, t_w };
	}

	Quaternion::Quaternion(const Mat4<float>& t_mat)
	{
		//@TODO: Impl Mat to Quat
	}
};