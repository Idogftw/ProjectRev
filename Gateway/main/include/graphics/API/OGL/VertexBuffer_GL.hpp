#pragma once

#include "graphics/API/base/VertexBuffer.hpp"


namespace Gateway
{
	class VertexBuffer_GL : public IVertexBuffer
	{
	public:
		VertexBuffer_GL(VertexObjectTypes m_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes m_storage_type);
		~VertexBuffer_GL();

		void Bind();
		void Unbind();
	private:
		VertexDrawTypes m_draw_type;
	};
};