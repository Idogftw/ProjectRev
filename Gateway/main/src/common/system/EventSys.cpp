#include "common/system/EventSys.hpp"

namespace Gateway
{
	EventSystem::EventSystem()
	{
	}

	EventSystem::~EventSystem()
	{
		for (auto it = m_events.begin(); it != m_events.end(); ++it)
		{
			//GDEL(it->second);
			delete it->second;
		}

		m_events.clear();
	}

	void EventSystem::RegisterSystem(EventTypes t_type, IEventBase* m_event)
	{
		if (m_events.find(t_type) != m_events.end())	
		{
			//WARN("EventSystem: System %s already exists!", TypeToString(t_type).c_str());
			return;
		}

		m_events.insert(std::make_pair(t_type, m_event));
	}

	IEventBase* EventSystem::GetEventPtr(EventTypes t_type)
	{
		auto ev = m_events.find(t_type);
		return (ev != m_events.end() ? ev->second : nullptr);
	}

	std::string EventSystem::TypeToString(EventTypes t_type)
	{
		switch (t_type)
		{
		case EventType_Application:
			return std::string("Application");
		case EventType_Input:
			return std::string("Input");
		case EventType_Renderer:
			return std::string("Renderer");
		case EventType_Game:
			return std::string("Game");
		case EventType_Command:
			return std::string("Command");
		case EventType_Last:
		default:
			//WARN("EventSystem: EventType_Last or no EventType given");
			return std::string();
		}
	}
};