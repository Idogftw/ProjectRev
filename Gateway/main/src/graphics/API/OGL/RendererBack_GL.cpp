#include "graphics/API/OGL/RendererBack_GL.hpp"

namespace Gateway
{
	RendererBack_GL::RendererBack_GL(Engine* t_engine)
		: m_engine(t_engine)
	{
	}

	RendererBack_GL::~RendererBack_GL()
	{
	}

	bool RendererBack_GL::Init()
	{
#if win32
		m_hdc = GetDC(static_cast<HWND>(m_engine->GetPlatform()->GetHandle()));

		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW |
			PFD_SUPPORT_OPENGL |
			PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,
			0, 0, 0, 0, 0, 0,
			8,
			0,
			0,
			0, 0, 0, 0,
			24,
			8,
			0,
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		int pixel_format = ChoosePixelFormat(m_hdc, &pfd);
		if (!pixel_format)
		{
			return false;
		}

		if (!SetPixelFormat(m_hdc, pixel_format, &pfd))
		{
			return false;
		}

		m_gl_ctx = wglCreateContext(m_hdc);
		if (!wglMakeCurrent(m_hdc, m_gl_ctx))
		{
			wglDeleteContext(m_gl_ctx);
			return false;
		}
#endif

		if (!gladLoadGL())
		{
			return false;
		}

		//@TEMP
		glViewport(0, 0, 1280, 720);
		glClearColor(0.2f, 0.3f, 0.1f, 1.f);
		return true;
	}

	void RendererBack_GL::Draw(IVertexBuffer* t_data)
	{

	}

	IProgram* RendererBack_GL::CreateProgram(const std::string& t_name)
	{
		return nullptr;
	}

	IVertexBuffer* RendererBack_GL::CreateVertexBuffer(VertexObjectTypes t_object_type, VertexDrawTypes t_draw_type, VertexStorageTypes t_storage_type)
	{
		return new VertexBuffer_GL(t_object_type, t_draw_type, t_storage_type);
	}
};