#pragma once
#include <fstream>

#include <glad/glad.h>

#include "graphics/API/base/Shader.hpp"

namespace Gateway
{
	class Shader_GL : public IShader
	{
	public:
		Shader_GL(const std::string& t_name, ShaderTypes t_type);
		~Shader_GL();

		bool CreateFromFile(const std::string& t_file);
		//bool CreateFromString(const);

		const std::string& FileToString(const std::string& t_file);

		uint32_t GetHandle() { return m_handle; }
	private:
		uint32_t GetShaderTypeGL(ShaderTypes t_type);
	private:
		uint32_t m_handle;
	};
};