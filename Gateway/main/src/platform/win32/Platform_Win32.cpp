#include "platform/win32/Platform_Win32.hpp"
#include "common/Engine.hpp"
#include "common/system/CVarSys.hpp"

namespace Gateway
{

	Platform_Win32::Platform_Win32(Engine* t_engine)
		: m_engine(t_engine)
	{
	}

	Platform_Win32::~Platform_Win32()
	{
		if (m_handle)
		{
			DestroyWindow(m_handle);
			m_handle = nullptr;
		}
	}

	bool Platform_Win32::Init()
	{
		m_instance = GetModuleHandleA(NULL);

		WNDCLASSA wc = {};
		wc.style = CS_DBLCLKS;
		wc.lpfnWndProc = Win32_Proc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_instance;
		wc.hIcon = LoadIcon(m_instance, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // NULL; // Manage the cursor manually
		wc.hbrBackground = NULL;
		wc.lpszClassName = WIN32_CLASS_NAME;
	
		if (!RegisterClassA(&wc))
		{
			//@TODO: Logging
			return false;
		}

		uint32_t window_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
		uint32_t window_ex_style = WS_EX_APPWINDOW;

		window_style |= WS_MAXIMIZEBOX;
		window_style |= WS_MINIMIZEBOX;
		window_style |= WS_THICKFRAME;

		int width = m_engine->FindCVar("r_width")->GetValue<int>();
		int height = m_engine->FindCVar("r_height")->GetValue<int>();

		m_handle = CreateWindowExA(
			window_ex_style, WIN32_CLASS_NAME, GAME_NAME,
			window_style, CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			0, 0, m_instance, NULL);

		if(!m_handle)
		{
			return false;
		}

		SetWindowLongPtrA(m_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

		ShowWindow(m_handle, SW_SHOW);
		UpdateWindow(m_handle);

		//@TEMP
		if (!InitGL())
		{
			ShowWindow(m_handle, SW_HIDE);
			DestroyWindow(m_handle);
			m_handle = NULL;
			return false;
		}

		SetForegroundWindow(m_handle);
		SetFocus(m_handle);

		return true;
	}

	void Platform_Win32::PumpMessages()
	{
		MSG message;
		while (PeekMessageA(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//@TEMP
		glClear(GL_COLOR_BUFFER_BIT);
		SwapBuffers(m_hdc);
	}

	bool Platform_Win32::InitGL()
	{
		m_hdc = GetDC(m_handle);

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

		if (!gladLoadGL())
		{
			return false;
		}

		glViewport(0, 0, 1280, 720);
		glClearColor(0.2f, 0.3f, 0.1f, 1.f);
		return true;

	}

	void Platform_Win32::OnNewSize(nlohmann::json t_data)
	{
		
	}

	LRESULT CALLBACK Platform_Win32::Win32_Proc(HWND t_hwnd, uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam)
	{
		Platform_Win32* parent = reinterpret_cast<Platform_Win32*>(GetWindowLongPtrA(t_hwnd, GWLP_USERDATA));

		if (parent)
		{
			return static_cast<Platform_Win32*>(parent)->Win32_Proc_Def(t_msg, t_wparam, t_lparam);
		}

		return DefWindowProcA(t_hwnd, t_msg, t_wparam, t_lparam);
	}

	LRESULT Platform_Win32::Win32_Proc_Def(uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam)
	{
		switch (t_msg)
		{
		case WM_ERASEBKGND:
			// Notify the OS that erasing will be handled by the application to prevent flicker.
			return 1;
		case WM_CLOSE:
			m_engine->OnEvent(EventType_Application, EventAppType_Quit, nlohmann::json::object());
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			break;
		}

		return DefWindowProcA(m_handle, t_msg, t_wparam, t_lparam);
	}
};