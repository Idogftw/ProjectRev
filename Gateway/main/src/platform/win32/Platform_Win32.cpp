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
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP: {

			nlohmann::json obj;
			obj["key"] = (uint16_t)t_wparam;
			obj["state"] = (t_msg == WM_KEYDOWN || t_msg == WM_SYSKEYDOWN);
			
			//@TODO: Impl modifiers
			//obj["mod"] = getstate

			m_engine->OnEvent(EventType_Input, EventInputType_Key, obj);
		} break;
		case WM_MOUSEMOVE: {
			int32_t x = GET_X_LPARAM(t_lparam);
			int32_t y = GET_Y_LPARAM(t_lparam);

			nlohmann::json obj;
			obj["type"] = EventInputType_MouseMove;
			obj["xpos"] = x;
			obj["ypos"] = y;

			m_engine->OnEvent(EventType_Input, EventInputType_MouseMove, obj);
		} break;
		case WM_MOUSEWHEEL: {
			int32_t delta = GET_WHEEL_DELTA_WPARAM(t_wparam);
			if (delta != 0) {
				delta = (delta < 0) ? -1 : 1;
			}

			nlohmann::json obj;
			obj["type"] = EventInputType_MouseWheel;
			obj["delta"] = delta;

			m_engine->OnEvent(EventType_Input, EventInputType_MouseWheel, obj);
		} break;
		case WM_LBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MBUTTONUP:
		case WM_RBUTTONUP: {
		
			bool pressed = (t_msg == WM_LBUTTONDOWN || t_msg == WM_MBUTTONDOWN || t_msg == WM_RBUTTONDOWN);
			MouseButtons button = MouseButton_Last;
			
			switch (t_msg)
			{
				case WM_LBUTTONDOWN:
				case WM_LBUTTONUP:
					button = MouseButton_Left;
					break;
				case WM_MBUTTONDOWN:
				case WM_MBUTTONUP:
					button = MouseButton_Wheel;
					break;
				case WM_RBUTTONDOWN:
				case WM_RBUTTONUP:
					button = MouseButton_Right;
					break;
			}

			if (button == MouseButton_Last)
				break;

			nlohmann::json obj;
			obj["type"] = EventInputType_Mouse;
			obj["button"] = button;
			obj["state"] = pressed;

			m_engine->OnEvent(EventType_Input, EventInputType_Mouse, obj);

		} break;
		default:
			break;
		}

		return DefWindowProcA(m_handle, t_msg, t_wparam, t_lparam);
	}
};