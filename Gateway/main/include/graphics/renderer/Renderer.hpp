#pragma once
#include "graphics/API/RendererBack.hpp"

namespace Gateway
{
	class IRenderer
	{
	public:
		IRenderer() {}
		virtual ~IRenderer() {}

		virtual bool Init() = 0;
	};
};