#pragma once
#include "RendererDeferred.hpp"

#include "graphics/API/OGL/RendererBack_GL.hpp"
#include "graphics/API/base/VertexBuffer.hpp"

namespace Gateway
{
	class Engine;

	class RenderSystem
	{
	public:
		RenderSystem(Engine* t_engine);
		~RenderSystem();

		bool Init();
		bool CreateRenderer();
		bool CreateBackend();

		void Draw(IVertexBuffer* t_buffer);

		//@TEMP
		void Clear();

		IRenderer* GetRenderer() { return m_renderer; }
		RendererBack* GetBackend() { return m_backend; }
	private:
		IRenderer* m_renderer;
		RendererBack* m_backend;
		Engine* m_engine;
	};
};