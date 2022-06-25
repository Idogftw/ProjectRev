#pragma once

#include <memory>

namespace Gateway
{
	template <typename T>
	class Mat4
	{
	public:
		inline Mat4()
		{
		}

		inline Mat4(T t_00, T t_01, T t_02, T t_03,
			T t_10, T t_11, T t_12, T t_13,
			T t_20, T t_21, T t_22, T t_23,
			T t_30, T t_31, T t_32, T t_33)
		{
			mv[0][0] = t_00;
			mv[0][1] = t_01;
			mv[0][2] = t_02;
			mv[0][3] = t_03;
			mv[1][0] = t_10;
			mv[1][1] = t_11;
			mv[1][2] = t_12;
			mv[1][3] = t_13;
			mv[2][0] = t_20;
			mv[2][1] = t_21;
			mv[2][2] = t_22;
			mv[2][3] = t_23;
			mv[3][0] = t_30;
			mv[3][1] = t_31;
			mv[3][2] = t_32;
			mv[3][3] = t_33;
		}

		inline Mat4(const Mat4& mat)
		{
			memcpy(&mv[0][0], &mat.mv[0][0], sizeof(mv));
		}

		static const Mat4<T> Identity;
		static const Mat4<T> Zero;

		//===========//
		//Pointer
		//===========//

		operator T*()
		{
			return (&mv[0][0]);
		}

		//===========//
		//Bool
		//===========//

		inline bool operator==(const Mat4<T>& t_mat) const
		{
			return (mv[0][0] == t_mat.mv[0][0] &&
					mv[0][1] == t_mat.mv[0][1] &&
					mv[0][2] == t_mat.mv[0][2] &&
					mv[0][3] == t_mat.mv[0][3] &&
					mv[1][0] == t_mat.mv[1][0] &&
					mv[1][1] == t_mat.mv[1][1] &&
					mv[1][2] == t_mat.mv[1][2] &&
					mv[1][3] == t_mat.mv[1][3] &&
					mv[2][0] == t_mat.mv[2][0] &&
					mv[2][1] == t_mat.mv[2][1] &&
					mv[2][2] == t_mat.mv[2][2] &&
					mv[2][3] == t_mat.mv[2][3] &&
					mv[3][0] == t_mat.mv[3][0] &&
					mv[3][1] == t_mat.mv[3][1] &&
					mv[3][2] == t_mat.mv[3][2] &&
					mv[3][3] == t_mat.mv[3][3]);
		}

		inline bool operator!=(const Mat4<T>& t_mat)
		{
			return !(*this == t_mat);
		}

		//===========//
		//Method
		//===========//

		inline Mat4<T> GetRotation() const
		{
			return Mat4<T>(mv[0][0], mv[0][1], mv[0][2], 0,
						   mv[1][0], mv[1][1], mv[1][2], 0,
						   mv[2][0], mv[2][1], mv[2][2], 0,
						   0, 0, 0, 1);
		}

		inline Mat4<T> GetTranspose() const
		{
			return Mat4<T>(mv[0][0], mv[1][0], mv[2][0], mv[3][0],
						   mv[0][1], mv[1][1], mv[2][1], mv[3][1],
						   mv[0][2], mv[1][2], mv[2][2], mv[3][2],
						   mv[0][3], mv[1][3], mv[2][3], mv[3][3])
		}

		//===========//
		//Vec 3 Types
		//===========//

		/**
		  * Name: GetRight
		  * Desc: Retrieves the right vector from the matrix
		  * Return: Vec3 of the right vector
		  */
		inline Vec3<T> GetRight() const
		{
			return Vec3<T>(mv[0][0], mv[0][1], mv[0][2])
		}

		/**
		  * Name: SetRight
		  * Desc: Sets the right vector in the matrix
		  */
		inline void SetRight(const Vec3<T>& t_vec)
		{
			mv[0][0] = t_vec.x;
			mv[0][1] = t_vec.y;
			mv[0][2] = t_vec.z;
		}

		/**
		  * Name: GetUp
		  * Desc: Retrieves the up vector from the matrix
		  * Return: Vec3 of the up vector
		  */
		inline Vec3<T> GetUp() const
		{
			return Vec3<T>(mv[1][0], mv[1][1], mv[1][2])
		}

		/**
		  * Name: SetUp
		  * Desc: Sets the up vector in the matrix
		  */
		inline void SetUp(const Vec3<T>& t_vec)
		{
			mv[1][0] = t_vec.x;
			mv[1][1] = t_vec.y;
			mv[1][2] = t_vec.z;
		}

		/**
		  * Name: GetForward
		  * Desc: Retrieves the forward vector from the matrix
		  * Return: Vec3 of the forward vector
		  */
		inline Vec3<T> GetForward() const
		{
			return Vec3<T>(mv[2][0], mv[2][1], mv[2][2])
		}

		/**
		  * Name: SetForward
		  * Desc: Sets the forward vector in the matrix
		  */
		inline void SetForward(const Vec3<T>& t_vec)
		{
			mv[2][0] = t_vec.x;
			mv[2][1] = t_vec.y;
			mv[2][2] = t_vec.z;
		}

		/**
		  * Name: GetTranslation
		  * Desc: Retrieves the translation vector from the matrix
		  * Return: Vec3 of the translation vector
		  */
		inline Vec3<T> GetTranslation() const
		{
			return Vec3<T>(mv[0][3], mv[1][3], mv[2][3])
		}

		/**
		  * Name: SetTranslation
		  * Desc: Sets the translation vector in the matrix
		  */
		inline void SetTranslation(const Vec3<T>& t_vec)
		{
			mv[0][3] = t_vec.x;
			mv[1][3] = t_vec.y;
			mv[2][3] = t_vec.z;
		}

	public:
		union
		{
			T mv[4][4];
			T v[16];
		};
	};
};