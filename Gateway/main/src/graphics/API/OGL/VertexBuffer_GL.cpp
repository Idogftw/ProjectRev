#include "graphics/API/OGL/VertexBuffer_GL.hpp"

namespace Gateway
{
	VertexBuffer_GL::VertexBuffer_GL(VertexObjectTypes m_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes m_storage_type)
		: m_draw_type(t_draw_type), IVertexBuffer(m_object_type, t_draw_type, m_storage_type)
	{
	}

	VertexBuffer_GL::~VertexBuffer_GL()
	{
	}
	void VertexBuffer_GL::Bind()
	{
	}
	void VertexBuffer_GL::Unbind()
	{
	}
};