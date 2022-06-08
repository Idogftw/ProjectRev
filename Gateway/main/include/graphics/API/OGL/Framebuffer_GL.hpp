#pragma once

#include "../base/Framebuffer.hpp"

namespace Gateway
{
	class Framebuffer_GL : public IFramebuffer
	{
	public:
		Framebuffer_GL();
		~Framebuffer_GL();
	};
};