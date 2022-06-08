#pragma once

namespace Gateway
{
	enum RendererAPITypes
	{
		RendererAPIType_None,
		RendererAPIType_GL,	//OpenGL
		RendererAPIType_VK,	//Vulkan
		RendererAPIType_XB,	//Xbox
		RendererAPIType_PS,	//PS
	};

	enum RendererTypes
	{
		RendererType_None,
		RendererType_Deferred,
		RendererType_ForwardPlus
	};
};