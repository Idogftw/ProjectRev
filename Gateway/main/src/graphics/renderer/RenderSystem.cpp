#include "graphics/renderer/RenderSystem.hpp"
#include "common/Engine.hpp"

namespace Gateway
{
	RenderSystem::RenderSystem(Engine* t_engine)
		: m_engine(t_engine)
	{
	}

	RenderSystem::~RenderSystem()
	{
	}

	bool RenderSystem::Init()
	{
		if (!CreateBackend())
		{
			return false;
		}

		if (!CreateRenderer())
		{
			return false;
		}

		m_backend->Init();

		m_renderer->Init();
		return true;
	}

	void RenderSystem::Clear()
	{
		m_backend->Clear();
	}

	bool RenderSystem::CreateRenderer()
	{
		switch (m_engine->FindCVar("r_rendertype")->GetValue<int>())
		{
		case RendererType_Deferred:
			m_renderer = new RendererDeferred(m_engine);
			break;
		case RendererType_ForwardPlus:
		default:
			return false;
		}

		return true;
	}
	bool RenderSystem::CreateBackend()
	{
		switch (m_engine->FindCVar("r_api")->GetValue<int>())
		{
		case RendererAPIType_GL:
			m_backend = new RendererBack_GL(m_engine);
			break;
		case RendererAPIType_VK:
		case RendererAPIType_XB:
		case RendererAPIType_PS:
		default:
			return false;
		}

		return true;
	}

	void RenderSystem::Draw(IVertexBuffer* t_buffer)
	{
	}
};