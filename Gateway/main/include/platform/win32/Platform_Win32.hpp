#pragma once
#ifdef win32

#include <Windows.h>
#include <windowsx.h>
#include <stdint.h>

#include <json.hpp>

#include "common/Data.hpp"
#include "platform/Platform.hpp"
#include "types/InputTypes.hpp"

namespace Gateway
{
	class Engine;

	class Platform_Win32 : public Platform
	{
	public:
		Platform_Win32(Engine* t_engine);
		~Platform_Win32();

		bool Init();

		/**
		  * Duplicate: See corresponding PumpMessages in Platform.hpp
		  */
		void PumpMessages();

		/**
		  * Duplicate: See corresponding GetHandle in Platform.hpp
		  */
		void* GetHandle() { return m_handle; }
	private:
		static LRESULT CALLBACK Win32_Proc(HWND t_hwnd, uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam);
		LRESULT CALLBACK Win32_Proc_Def(uint32_t t_msg, WPARAM t_wparam, LPARAM t_lparam);
	private:
		void NewSize_E(nlohmann::json t_data);
	private:
		Engine* m_engine;
		HWND m_handle;
		HINSTANCE m_instance;
	};
};

#endif // win32