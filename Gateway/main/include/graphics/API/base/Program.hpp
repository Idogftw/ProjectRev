#pragma once
#include <string>

#include "types/GraphicTypes.hpp"
#include "graphics/API/base/Shader.hpp"

#include "types/MathTypes.hpp"

namespace Gateway
{
	class IProgram
	{
	public:
		IProgram(const std::string& t_name) : m_name(t_name) { memset(m_shaders, NULL, sizeof(m_shaders)); }
		virtual ~IProgram() {
			for (uint32_t i = 0; i < ShaderType_Last; i++)
			{

			}
		}

		virtual void Attach() = 0;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		const std::string& GetName() { return m_name; }

		virtual void SetShader(ShaderTypes t_type, IShader* t_shader) = 0;
		virtual IShader* GetShader(ShaderTypes t_type) = 0;

		virtual void SetInt(const std::string& t_name, int t_val) = 0;
		virtual void SetFloat(const std::string& t_name, float t_val) = 0;
		virtual void SetVec2f(const std::string& t_name, float t_x, float t_y) = 0;
		virtual void SetVec3f(const std::string& t_name, float t_x, float t_y, float t_z) = 0;
		virtual void SetVec4f(const std::string& t_name, float t_x, float t_y, float t_z, float t_w) = 0;
		virtual void SetMat4f(const std::string& t_name, const Mat4f& t_mat) = 0;
		
		virtual void SetVec2f(const std::string& t_name, const Vec2f& t_vec) = 0; 
		virtual void SetVec3f(const std::string& t_name, const Vec3f& t_vec) = 0;
		virtual void SetVec4f(const std::string& t_name, const Vec4f& t_vec) = 0;
	private:
		std::string m_name;
	protected:
		IShader* m_shaders[4];
	};
};