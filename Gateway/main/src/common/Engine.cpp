#include "common/Engine.hpp"
#include "common/system/CVarSys.hpp"

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
		delete m_platform;
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
		}
	}

	void Engine::Shutdown()
	{
		//Always last
		LogSys::Get()->Shutdown();
	}

	void Engine::CreateModules()
	{
		m_cmd_sys = new CommandSystem;
		m_cvar_sys = new CVarSystem(this);

		m_event_sys = new EventSystem;

		//@TODO: Impl platform switching here
		m_platform = new Platform_Win32(this);
	}

	bool Engine::InitModules()
	{
		//@TODO: Impl Memory Manager
		m_cvar_sys->Init();
		m_cvar_sys->RegisterAllCVars();

		m_cmd_sys->Init();

		if (!m_platform->Init())
		{
			return false;
		}
	
		m_event_sys->RegisterSystem(EventType_Application, new EventApp);
		m_event_sys->RegisterSystem(EventType_Application, new EventInput);

		return true;
	}

	void Engine::RegisterCommand(const std::string& t_name, CmdCallback t_callback, int t_flags, const std::string & t_description)
	{
		m_cmd_sys->Register(t_name, t_callback, t_flags, t_description);
	}
	
	CVar* Engine::FindCVar(const std::string& t_name)
	{
		return m_cvar_sys->Find(t_name);
	}

	void Engine::RegisterEvent(uint32_t m_event, uint32_t m_event_type, event_callback t_callback)
	{
		auto ev = m_event_sys->GetEventPtr(static_cast<EventTypes>(m_event));

		if (ev == nullptr)
		{
			//WARN("Engine: Event doesn't exist!");
			return;
		}

		ev->RegisterCallback(m_event_type, t_callback);
	}
	
	void Engine::OnEvent(uint32_t m_event, uint32_t m_event_type, nlohmann::json t_data)
	{
		auto ev = m_event_sys->GetEventPtr(static_cast<EventTypes>(m_event));

		if (ev == nullptr)
		{
			//WARN("Engine: Event doesn't exist!");
			return;
		}

		ev->OnEvent(m_event_type, t_data);
	}

	void Engine::OnQuit_E(nlohmann::json t_data)
	{
		m_running = false;
	}
};