#pragma once
#if win32
#include <Windows.h>
#endif
#include <glad/glad.h>

#include "common/Engine.hpp"

#include "graphics/API/RendererBack.hpp"
#include "graphics/API/OGL/VertexBuffer_GL.hpp"

namespace Gateway
{
	class RendererBack_GL : public RendererBack
	{
	public:
		RendererBack_GL(Engine* t_engine);
		~RendererBack_GL();

		bool Init();

		IVertexBuffer* CreateVertexBuffer(VertexObjectTypes t_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes t_storage_type);
		//@TEMP
		void Clear() {
			glClear(GL_COLOR_BUFFER_BIT);
			SwapBuffers(m_hdc);
		}
	private:
		Engine* m_engine;
#if win32
		HGLRC m_gl_ctx;
		HDC m_hdc;
#endif
	};
};