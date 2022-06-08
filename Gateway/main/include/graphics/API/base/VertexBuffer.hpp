#pragma once
#include <map>
#include <stdint.h>
#include <vector>

#include "graphics/API/GraphicTypes.hpp"

namespace Gateway
{
	class BufferObject
	{
	public:
		BufferObject(VertexBufferTypes t_buffer_type, uint16_t t_stride);
	
		void SetBufferID(uint32_t m_id);
		uint32_t GetBufferID();
	public:
		VertexObjectTypes m_object_type;
		VertexBufferTypes m_buffer_type;
		uint16_t m_stride;
	private:
		uint32_t m_buffer_id;
		std::vector<float> m_values;
	};

	class IVertexBuffer
	{
	public:
		IVertexBuffer(VertexObjectTypes t_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes t_storage_type);
		~IVertexBuffer();

		void CreateBuffers(uint32_t t_flags, uint16_t t_stride);
		void CreateBuffer(VertexBufferTypes t_buffer_type, uint16_t t_stride);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		bool HasBuffer(VertexBufferTypes t_buffer_type);
	private:
		VertexObjectTypes m_object_type;
		VertexDrawTypes m_draw_type;
		VertexStorageTypes m_storage_type;
		std::map<VertexBufferTypes, BufferObject*> m_objects;
	};
};