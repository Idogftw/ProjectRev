#pragma once

#ifdef win32
	#include "platform/win32/Platform_Win32.hpp"
#elif linux
	#include "platform/win32/Platform_Linux.hpp"
#elif macos
	#include "platform/win32/Platform_Mac.hpp"
#endif // win32

#include "common/system/LogSys.hpp"
#include "common/system/CmdSys.hpp"

#include "common/system/EventSys.hpp"
#include "event/types/EventApp.hpp"
#include "event/types/EventInput.hpp"

namespace Gateway
{
	class CVar;
	class CVarSystem;

	class Engine
	{
	public:
		Engine();
		~Engine();

		bool Init();
		void Run();
		void Shutdown();

		void CreateModules();
		bool InitModules();

		//System Interfaces for calling functions to register stuff that is within other modules that way there
		//doesn't need to be a lot of passing of pointers of other classes to another thing, the engine class pointer can 
		//simply be passed and used as an interface to other classes
		void RegisterCommand(const std::string& t_name, CmdCallback t_callback, int t_flags, const std::string& t_description);
		
		template <typename T>
		void RegisterCVar(const std::string& t_name, T t_value, int t_flags, const std::string& t_description);
		CVar* FindCVar(const std::string& t_name);
		
		void RegisterEvent(uint32_t m_event, uint32_t m_event_type, event_callback t_callback);
		void OnEvent(uint32_t m_event, uint32_t m_event_type, nlohmann::json t_data);

		//Since it's interfaced with functions above, might not need these getters
		//CommandSystem* GetCmdSys() { return m_cmd_sys; }
		//EventSystem* GetEventSys() { return m_event_sys; }
	private:
		void OnQuit_E(nlohmann::json t_data);
	private:
		CommandSystem* m_cmd_sys;
		CVarSystem* m_cvar_sys;
		EventSystem* m_event_sys;
		bool m_running;

		//@TEMP
		Platform* m_platform;
	};

	template<typename T>
	inline void Engine::RegisterCVar(const std::string& t_name, T t_value, int t_flags, const std::string & t_description)
	{
		m_cvar_sys->Register(t_name, t_value, t_flags, t_description);
	}
};