#pragma once

namespace Gateway
{
	enum VertexObjectTypes
	{
		VertexObjectType_Array,
		VertexObjectType_Buffer,
		VertexObjectType_Last
	};

	enum VertexDrawTypes
	{
		VertexDrawType_Tri,
		VertexDrawType_TriFan,
		VertexDrawType_Line,
		VertexDrawType_LineLoop,
		VertexDrawType_Last
	};

	enum VertexStorageTypes
	{
		VertexStorageType_Static,
		VertexStorageType_Dynamic,
		VertexStorageType_Stream,
		VertexStorageType_Last
	};

	enum VertexBufferTypes
	{
		VertexBufferType_Position,
		VertexBufferType_Normal,
		VertexBufferType_TexCoord,
		VertexBufferType_Tangent,
		VertexBufferType_BiTangent,
		VertexBufferType_Last
	};

	enum ProgramTypes
	{
		ProgramType_GL,
		ProgramType_VK,
		ProgramType_Last
	};

	enum ShaderTypes
	{
		ShaderType_Vertex,
		ShaderType_Fragment,
		ShaderType_Geometry,
		ShaderType_Compute,
		ShaderType_Last
	};

	enum ShaderBufferTypes
	{
		ShaderBufferType_Position,
		ShaderBufferType_Normal,
		ShaderBufferType_Color0,
		ShaderBufferType_Color1,
		ShaderBufferType_Texture0,
		ShaderBufferType_Texture1,
		ShaderBufferType_Texture2,
		ShaderBufferType_Last
	};
};