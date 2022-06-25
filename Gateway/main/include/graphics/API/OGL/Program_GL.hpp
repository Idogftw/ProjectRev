#pragma once

#include <glad/glad.h>

#include "graphics/API/base/Program.hpp"
#include "graphics/API/OGL/Shader_GL.hpp"

namespace Gateway
{
	class Program_GL : public IProgram
	{
	public:
		Program_GL(const std::string& t_name);
		~Program_GL();

		void Attach();

		void Bind();
		void Unbind();

		void SetShader(ShaderTypes t_type, IShader* t_shader);
		IShader* GetShader(ShaderTypes t_type);

		void SetInt(const std::string& t_name, int t_val);
		void SetFloat(const std::string& t_name, float t_val);
		void SetVec2f(const std::string& t_name, float t_x, float t_y);
		void SetVec3f(const std::string& t_name, float t_x, float t_y, float t_z);
		void SetVec4f(const std::string& t_name, float t_x, float t_y, float t_z, float t_w);
		void SetMat4f(const std::string& t_name, const Mat4f& t_mat);

		void SetVec2f(const std::string& t_name, const Vec2f& t_vec);
		void SetVec3f(const std::string& t_name, const Vec3f& t_vec);
		void SetVec4f(const std::string& t_name, const Vec4f& t_vec);
	private:
		uint32_t m_handle;
	};
};