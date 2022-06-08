#include "graphics/renderer/RendererDeferred.hpp"

namespace Gateway
{
	RendererDeferred::RendererDeferred(Engine* t_engine)
		: m_engine(t_engine), IRenderer()
	{

	}

	RendererDeferred::~RendererDeferred()
	{
	}

	bool RendererDeferred::Init()
	{

		return true;
	}
};