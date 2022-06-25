#pragma once
#include <string>

#include "types/GraphicTypes.hpp"

namespace Gateway
{
	class IShader
	{
	public:
		IShader(const std::string& t_name, ShaderTypes t_type)
			: m_name(t_name), m_type(t_type)
		{

		}
		virtual ~IShader() {}

		const std::string& GetName() { return m_name; }
		virtual uint32_t GetHandle() { return 0; }
	private:
		std::string m_name;
		ShaderTypes m_type;
	};
};