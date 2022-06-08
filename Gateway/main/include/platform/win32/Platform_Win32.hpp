#pragma once
#ifdef win32

#include <Windows.h>
#include <windowsx.h>
#include <stdint.h>

#include <json.hpp>

#include "common/Data.hpp"
#include "input/InputTypes.hpp"
#include "platform/Platform.hpp"

namespace Gateway
{
	class Engine;

	class Platform_Win32 : public Platform
	{
	public:
		Platform_Win32(Engine* t_engine);
		~Platform_Win32();

		LRESULT CALLBACK Win32_Proc_Def(uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam);

		bool Init();
		void PumpMessages();
		void* GetHandle() { return m_handle; }
	private:
		void OnNewSize(nlohmann::json t_data);
		static LRESULT CALLBACK Win32_Proc(HWND t_hwnd, uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam);
	private:
		Engine* m_engine;
		HWND m_handle;
		HINSTANCE m_instance;
	};
};

#endif // win32