#pragma once
#include "common/Engine.hpp"
#include "common/system/CVarSys.hpp"

#include "graphics/renderer/Renderer.hpp"

#include "graphics/API/RendererBack.hpp"
#include "graphics/API/OGL/RendererBack_GL.hpp"

#include "graphics/renderer/RenderTypes.hpp"


namespace Gateway
{
	class RendererDeferred : public IRenderer
	{
	public:
		RendererDeferred(Engine* m_engine);
		~RendererDeferred();
		
		bool Init();
	private:
		Engine* m_engine;
	};
};