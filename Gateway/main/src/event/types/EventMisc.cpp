#include "event/types/EventMisc.hpp"

namespace Gateway
{
	EventMisc::EventMisc()
		: IEventBase(EventType_Misc)
	{
		Init();
	}

	EventMisc::~EventMisc()
	{
		m_events.clear();
	}

	void EventMisc::Init()
	{
		for (uint32_t i = 0; i < EventMiscType_Last; i++)
		{
			m_events.insert(std::make_pair(static_cast<EventMiscTypes>(i), List<event_callback>()));
		}
	}

	void EventMisc::RegisterCallback(uint32_t t_type, event_callback t_func)
	{
		auto ev = m_events.find(static_cast<EventMiscTypes>(t_type));
		if (ev == m_events.end())
		{
			//INFO("EventInput: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		ev->second.Add(t_func);
	}

	void EventMisc::OnEvent(uint32_t t_type, nlohmann::json t_data)
	{
		auto ev = m_events.find(static_cast<EventMiscTypes>(t_type));
		if (ev == m_events.end())
		{
			//INFO("EventInput: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		for (uint32_t i = 0; i < ev->second.GetCount(); i++)
		{
			ev->second[i](t_data);
		}
	}

	std::string EventMisc::TypeToString(uint32_t t_type)
	{
		switch (static_cast<EventMiscTypes>(t_type))
		{
		case EventMiscType_CVar:
			return std::string("CVar");
		case EventMiscType_Command:
			return std::string("Command");
		case EventMiscType_Last:
		default:
			//WARN("EventInput: EventInputType_Last or no EventInputType given");
			return std::string("NULL");
		}
	}
};