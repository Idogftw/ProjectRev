#pragma once

#include "base/Framebuffer.hpp"
#include "base/Texture.hpp"
#include "base/VertexBuffer.hpp"

namespace Gateway
{
	class RendererBack
	{
	public:
		RendererBack() {}
		virtual ~RendererBack() {}

		virtual bool Init() = 0;

		//@TEMP
		virtual void Clear() = 0;
		//virtual void SwapBuffers() = 0;

		//@TODO: Implement in inherited classes
		//virtual IFramebuffer* CreateFramebuffer() = 0;
		//virtual ITexture* CreateTexture() = 0;
		//virtual IOcclusionQuery* CreateQuery() = 0;
		virtual IVertexBuffer* CreateVertexBuffer(VertexObjectTypes m_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes m_storage_type) = 0;
		//virtual Shader* CreateShader() = 0;
	};
};