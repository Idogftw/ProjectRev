#include "common/Engine.hpp"

#include "common/system/CVarSys.hpp"
#include "common/system/EventSys.hpp"
#include "common/system/LogSys.hpp"

#include "graphics/renderer/RenderSystem.hpp"

#include "input/Input.hpp"

namespace Gateway
{
	Engine::Engine()
	{
		CreateModules();
	}

	Engine::~Engine()
	{
		delete m_cmd_sys;
		delete m_cvar_sys;
		delete m_event_sys;
		delete m_render_sys;
		delete m_platform;
		delete m_input;
	}

	bool Engine::Init()
	{
		if (!InitModules())
		{
			//ERROR("Engine: Couldn't initialize modules!");
			return false;
		}
		
		RegisterEvent(EventType_Application, EventAppType_Quit, std::bind(&Engine::OnQuit_E, this, std::placeholders::_1));
		//RegisterEvent(EventType_Input, EventInType_Quit, std::bind(&Engine::onquit));

		return true;
	}

	void Engine::Run()
	{
		while (m_running)
		{
			m_platform->PumpMessages();

			if (!m_cmd_sys->Empty())
			{
				m_cmd_sys->ExecuteBuffer();
			}
		
			if (m_input->InputUp(Key_F) && m_input->InputWasDown(Key_F))
			{
				GINFO("F Loser");
			}

			//@TODO: Impl delta time
			OnEvent(EventType_Application, EventAppType_Update, 0);
			
			//@Temp
			m_render_sys->Clear();
		}
	}

	void Engine::Shutdown()
	{
		//Always last
		LogSys::Get()->Shutdown();
	}

	void Engine::CreateModules()
	{
		m_cvar_sys = new CVarSystem(this);
		m_cmd_sys = new CommandSystem;

		m_event_sys = new EventSystem;

		//@TODO: Temp
		m_render_sys = new RenderSystem(this);

		//@TODO: Impl platform switching here
#if win32
		m_platform = new Platform_Win32(this);
#elif linux
		m_platform = new Platform_Linux(this);
#endif

		m_input = new Input(this);
	}

	bool Engine::InitModules()
	{
		//@TODO: Impl Memory Manager
		//@TODO: Impl File System

		LogSys::Get()->Init(m_cvar_sys);

		m_event_sys->RegisterSystem(EventType_Application, new EventApp);
		m_event_sys->RegisterSystem(EventType_Input, new EventInput);
		m_event_sys->RegisterSystem(EventType_Misc, new EventMisc);
		
		m_cmd_sys->Init();

		m_cvar_sys->Init();
		m_cvar_sys->RegisterAllCVars();

		if (!m_platform->Init())
		{
			return false;
		}

		if (!m_render_sys->Init())
		{
			return false;
		}

		if (!m_input->Init())
		{
			return false;
		}

		return true;
	}

	void Engine::RegisterCommand(const std::string& t_name, CmdCallback t_callback, int t_flags, const std::string& t_description)
	{
		m_cmd_sys->Register(t_name, t_callback, t_flags, t_description);
	}
	
	CVar* Engine::FindCVar(const std::string& t_name)
	{
		return m_cvar_sys->Find(t_name);
	}

	void Engine::RegisterEvent(EventTypes m_type, uint32_t m_event, event_callback t_callback)
	{
		auto ev = m_event_sys->GetEventPtr(m_type);

		if (ev == nullptr)
		{
			GWARN("Engine: Event doesn't exist!");
			return;
		}

		ev->RegisterCallback(m_event, t_callback);
	}

	void Engine::OnEvent(EventTypes m_type, uint32_t m_event, nlohmann::json t_data)
	{
		auto ev = m_event_sys->GetEventPtr(m_type);

		if (ev == nullptr)
		{
			GWARN("Engine: Event doesn't exist!");
			return;
		}

		ev->OnEvent(m_event, t_data);
	}

	void Engine::OnQuit_E(nlohmann::json t_data)
	{
		m_running = false;
	}
};