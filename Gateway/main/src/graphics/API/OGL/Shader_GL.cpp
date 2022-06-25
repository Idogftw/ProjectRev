#include "graphics/API/OGL/Shader_GL.hpp"

namespace Gateway
{
	Shader_GL::Shader_GL(const std::string& t_name, ShaderTypes t_type)
		: IShader(t_name, t_type)
	{
		m_handle = glCreateShader(GetShaderTypeGL(t_type));
	}

	Shader_GL::~Shader_GL()
	{
		glDeleteShader(m_handle);
	}

	const std::string& Shader_GL::FileToString(const std::string & t_file)
	{
		//@TODO: Use filesystem to get shader file
		std::string tempFile = "assets/" + t_file;
		tempFile += ".glsl";

		std::fstream shaderFile(tempFile);
		std::string stringReturn;

		if (shaderFile)
		{
			stringReturn.assign((std::istreambuf_iterator<char>(shaderFile)), std::istreambuf_iterator<char>());
		}

		return stringReturn;
	}

	uint32_t Shader_GL::GetShaderTypeGL(ShaderTypes t_type)
	{
		switch (t_type)
		{
		case ShaderType_Vertex:
			return GL_VERTEX_SHADER;
		case ShaderType_Fragment:
			return GL_FRAGMENT_SHADER;
		case ShaderType_Geometry:
			return GL_GEOMETRY_SHADER;
		case ShaderType_Compute:
			return GL_COMPUTE_SHADER;
		}

		return GL_VERTEX_SHADER;
	}
};