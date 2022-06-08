#include "event/types/EventApp.hpp"

namespace Gateway
{
	EventApp::EventApp()
		: IEventBase(EventType_Application)
	{
		Init();
	}

	EventApp::~EventApp()
	{
		m_events.clear();
	}

	void EventApp::Init()
	{
		for (uint32_t i = 0; i < EventAppType_Last; i++)
		{
			m_events.insert(std::make_pair(static_cast<EventAppTypes>(i), std::vector<event_callback>()));
		}
	}

	void EventApp::RegisterCallback(uint32_t t_type, event_callback t_func)
	{
		auto ev = m_events.find(static_cast<EventAppTypes>(t_type));
		if (ev == m_events.end())
		{
			GINFO("EventApp: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		ev->second.push_back(t_func);
	}

	void EventApp::OnEvent(uint32_t t_type, nlohmann::json t_data)
	{
		auto ev = m_events.find(static_cast<EventAppTypes>(t_type));
		if (ev == m_events.end())
		{
			GINFO("EventApp: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		for (uint32_t i = 0; i < ev->second.size(); i++)
		{
			ev->second[i](t_data);
		}
	}

	std::string EventApp::TypeToString(uint32_t t_type)
	{
		switch (static_cast<EventAppTypes>(t_type))
		{
		case EventAppType_Quit:
			return std::string("Quit");
		case EventAppType_Update:
			return std::string("Update");
		case EventAppType_Last:
		default:
			GWARN("EventApp: EventAppType_Last or no EventAppType given");
			return std::string();
		}
	}
};