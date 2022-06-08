#pragma once

#include <stdint.h>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"

namespace Gateway
{
	#define G_PI		3.1415926535f
	#define G_PI_2		2.0f * G_PI
	#define G_HALF_PI	0.5f * G_PI
	#define G_QRT_PI	0.25f * G_PI
	#define G_DEG2RAD	G_PI / 180.0f
	#define G_RAD2DEG	180.0f / G_PI

	#define G_SEC2MS	1000.0f
	#define G_MS2SEC	0.001f

	#define G_INF		1e30f

	#define G_EPSILON	0.0001f

	typedef Vec2<float> Vec2f;
	typedef Vec2<int> Vec2i;

	typedef Vec3<float> Vec3f;
	typedef Vec3<uint8_t> Vec3uc;
	typedef Vec3<uint16_t> Vec3us;
	typedef Vec3<uint32_t> Vec3ui;
	typedef Vec3<uint64_t> Vec3ul;

	typedef Vec3<int8_t> Vec3c;
	typedef Vec3<int16_t> Vec3s;
	typedef Vec3<int32_t> Vec3i;
	typedef Vec3<int64_t> Vec3l;

	typedef Vec4<float> Vec4f;

	typedef Mat4<float> Mat4f;

	template<>
	const Mat4f Mat4f::Identity(1,0,0,0,
								0,1,0,0,
								0,0,1,0,
								0,0,0,1);
	template<>
	const Mat4f Mat4f::Zero(0,0,0,0,
							0,0,0,0,
							0,0,0,0,
							0,0,0,0);

	
};