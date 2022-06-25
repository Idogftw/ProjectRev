#include "graphics/API/base/VertexBuffer.hpp"

namespace Gateway
{
	BufferObject::BufferObject(VertexBufferTypes t_buffer_type, uint16_t t_stride)
		: m_buffer_type(t_buffer_type), m_stride(t_stride)
	{
	}

	void BufferObject::SetBufferID(uint32_t m_id)
	{
		if (m_buffer_id == m_id)
			return;

		m_buffer_id = m_id;
	}

	uint32_t BufferObject::GetBufferID()
	{
		return m_buffer_id;
	}

	IVertexBuffer::IVertexBuffer(VertexObjectTypes t_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes t_storage_type)
		: m_object_type(t_object_type), m_draw_type(t_draw_type), m_storage_type(t_storage_type)
	{
	}

	IVertexBuffer::~IVertexBuffer()
	{
	}

	void IVertexBuffer::CreateBuffers(uint32_t t_flags, uint16_t t_stride)
	{
		if (t_flags & VertexBufferType_Position)
		{
			m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(VertexBufferType_Position, new BufferObject(VertexBufferType_Position, t_stride)));
		}

		if (t_flags & VertexBufferType_TexCoord)
		{
			m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(VertexBufferType_TexCoord, new BufferObject(VertexBufferType_TexCoord, 2)));
		}

		if (t_flags & VertexBufferType_Normal)
		{
			m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(VertexBufferType_Normal, new BufferObject(VertexBufferType_Normal, t_stride)));
		}

		if (t_flags & VertexBufferType_Tangent)
		{
			m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(VertexBufferType_Tangent, new BufferObject(VertexBufferType_Tangent, t_stride)));
		}

		if (t_flags & VertexBufferType_BiTangent)
		{
			m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(VertexBufferType_BiTangent, new BufferObject(VertexBufferType_BiTangent, t_stride)));
		}

	}

	void IVertexBuffer::CreateBuffer(VertexBufferTypes t_buffer_type, uint16_t t_stride)
	{
		if (m_objects.find(t_buffer_type) != m_objects.end())
		{
			printf("Object exists already!");
			return;
		}

		m_objects.insert(std::pair<VertexBufferTypes, BufferObject*>(t_buffer_type, new BufferObject(t_buffer_type, t_stride)));
	}

	bool IVertexBuffer::HasBuffer(VertexBufferTypes t_buffer_type)
	{
		return m_objects.find(t_buffer_type) != m_objects.end();
	}

	
};