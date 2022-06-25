#include "graphics/API/ogl/Program_GL.hpp"

namespace Gateway
{
	Program_GL::Program_GL(const std::string& t_name)
		: IProgram(t_name)
	{
		m_handle = glCreateProgram();
	}

	Program_GL::~Program_GL()
	{
		for (uint32_t i = 0; i < ShaderType_Last; i++)
		{
			if (m_shaders[i])
			{
				glDetachShader(m_handle, m_shaders[i]->GetHandle());
			}
		}

		glDeleteProgram(m_handle);
	}

	void Program_GL::Attach()
	{
	}

	void Program_GL::Bind()
	{
		glUseProgram(m_handle);
	}

	void Program_GL::Unbind()
	{
		glUseProgram(0);
	}

	void Program_GL::SetShader(ShaderTypes t_type, IShader* t_shader)
	{
		if (!t_shader)
			return;

		m_shaders[t_type] = t_shader;
	}

	IShader* Program_GL::GetShader(ShaderTypes t_type)
	{
		return m_shaders[t_type];
	}

	void Program_GL::SetInt(const std::string & t_name, int t_val)
	{
		glUniform1i(glGetUniformLocation(m_handle, t_name.c_str()), t_val);
	}

	void Program_GL::SetFloat(const std::string & t_name, float t_val)
	{
		glUniform1f(glGetUniformLocation(m_handle, t_name.c_str()), t_val);
	}

	void Program_GL::SetVec2f(const std::string & t_name, float t_x, float t_y)
	{
		glUniform2f(glGetUniformLocation(m_handle, t_name.c_str()), t_x, t_y);
	}

	void Program_GL::SetVec3f(const std::string & t_name, float t_x, float t_y, float t_z)
	{
		glUniform3f(glGetUniformLocation(m_handle, t_name.c_str()), t_x, t_y, t_z);
	}

	void Program_GL::SetVec4f(const std::string & t_name, float t_x, float t_y, float t_z, float t_w)
	{
		glUniform4f(glGetUniformLocation(m_handle, t_name.c_str()), t_x, t_y, t_z, t_w);
	}

	void Program_GL::SetMat4f(const std::string& t_name, const Mat4f& t_mat)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_handle, t_name.c_str()), 1, GL_FALSE, t_mat.v);
	}

	void Program_GL::SetVec2f(const std::string& t_name, const Vec2f& t_vec)
	{
		glUniform2fv(glGetUniformLocation(m_handle, t_name.c_str()), 1, t_vec.vec);
	}

	void Program_GL::SetVec3f(const std::string& t_name, const Vec3f& t_vec)
	{
		glUniform3fv(glGetUniformLocation(m_handle, t_name.c_str()), 1, t_vec.vec);
	}

	void Program_GL::SetVec4f(const std::string& t_name, const Vec4f& t_vec)
	{
		glUniform4fv(glGetUniformLocation(m_handle, t_name.c_str()), 1, t_vec.vec);
	}
};