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

	enum VertexShaderTypes
	{
		VertexShaderType_Position,
		VertexShaderType_Normal,
		VertexShaderType_Color0,
		VertexShaderType_Color1,
		VertexShaderType_Texture0,
		VertexShaderType_Texture1,
		VertexShaderType_Texture2,
		VertexShaderType_Last
	};
};