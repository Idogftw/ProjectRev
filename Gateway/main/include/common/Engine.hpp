#pragma once

#ifdef win32
	#include "platform/win32/Platform_Win32.hpp"
#elif linux
	#include "platform/win32/Platform_Linux.hpp"
#elif macos
	#include "platform/win32/Platform_Mac.hpp"
#endif // win32

#include "common/system/FileSys.hpp"
#include "common/system/CmdSys.hpp"

#include "event/types/EventApp.hpp"
#include "event/types/EventInput.hpp"
#include "event/types/EventMisc.hpp"

#include "types/RenderTypes.hpp"

/**
  * Brief: The formatting of all classes is as follows, only public methods will receive a large comment for
		   its use, as they are publicly accessed and need info on how to use them.
  class ClassName
	public:
		PublicMethods
	private:
		PrivateMethods
	private:
		EventSystem/CommandSystem methods
	private:
		PrivateMembers
*/

namespace Gateway
{
	class LogSys;
	class CVar;
	class CVarSystem;
	class RenderSystem;
	class EventSystem;
	class Input;
	class FileBase;
	class FileSystem;

	class Engine
	{
	public:
		Engine();
		~Engine();

		//===========//
		//Methods
		//===========//

		bool Init(const std::string& t_cmd_line);
		void Run();
		void Shutdown();

		void ParseCommandLine(const std::string& t_cmd_line);
		//===========//
		//Interfaces
		//===========//

		/**
		  * Duplicate: See corresponding Register in CmdSys.hpp
		  */
		void RegisterCommand(const std::string& t_name, CmdCallback t_callback, int32_t t_flags, const std::string& t_description);
		
		/**
		  * Duplicate: See corresponding Register in CVarSys.hpp
		  */
		template <typename T>
		void RegisterCVar(const std::string& t_name, T t_value, int32_t t_flags, const std::string& t_description);
		
		/**
		  * Duplicate: See corresponding Find in CVarsys.hpp
		  */
		CVar* FindCVar(const std::string& t_name);
		
		/**
		  * Name: RegisterEvent
		  * Desc: Registers an event for a specific system
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: Specific type of event from specific EventTypes system - see any Event[NAME].hpp enumeration
		  * Param: Function to call when event is fired
		  */
		void RegisterEvent(EventTypes m_type, uint32_t m_event, event_callback t_callback);
		
		/**
		  * Duplicate: See corresponding OnEvent in EventBase.hpp
		  */
		void OnEvent(EventTypes m_type, uint32_t m_event, nlohmann::json t_data);

		//===========//
		//Getters
		//===========//

		FileSystem* GetFileSystem() { return m_file_sys; }
		Platform* GetPlatform() { return m_platform; }
	private:
		void CreateModules();
		bool InitModules(const std::string& t_cmd_line);
		void CreatePlatform();
	private:
		void OnQuit_E(nlohmann::json t_data);
	private:
		CommandSystem* m_cmd_sys;
		CVarSystem* m_cvar_sys;
		EventSystem* m_event_sys;
		RenderSystem* m_render_sys;
		FileSystem* m_file_sys;
		Input* m_input;
		bool m_running;

		//@TEMP
		Platform* m_platform;
	};

	template<typename T>
	inline void Engine::RegisterCVar(const std::string& t_name, T t_value, int32_t t_flags, const std::string & t_description)
	{
		m_cvar_sys->Register(t_name, t_value, t_flags, t_description);
	}
};