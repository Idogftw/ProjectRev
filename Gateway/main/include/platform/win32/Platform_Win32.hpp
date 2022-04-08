#pragma once
#ifdef win32

#include <Windows.h>
#include <stdint.h>

#include "common/Data.hpp"
#include "platform/Platform.hpp"
#include <json.hpp>

//@TEMP
#include <glad/glad.h>

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
		
		//@Temp
		bool InitGL();
	private:
		void OnNewSize(nlohmann::json t_data);
		static LRESULT CALLBACK Win32_Proc(HWND t_hwnd, uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam);
	private:
		HWND m_handle;
		HINSTANCE m_instance;
		Engine* m_engine;
		
		//@Temp
		HGLRC m_gl_ctx;
		HDC m_hdc;
	};
};

#endif // win32