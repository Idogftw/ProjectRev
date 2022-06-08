#include "event/types/EventInput.hpp"

namespace Gateway
{
	EventInput::EventInput()
		: IEventBase(EventType_Input)
	{
		Init();
	}

	EventInput::~EventInput()
	{
		m_events.clear();
	}

	void EventInput::Init()
	{
		for (uint32_t i = 0; i < EventInputType_Last; i++)
		{
			m_events.insert(std::make_pair(static_cast<EventInputTypes>(i), std::vector<event_callback>()));
		}
	}

	void EventInput::RegisterCallback(uint32_t t_type, event_callback t_func)
	{
		auto ev = m_events.find(static_cast<EventInputTypes>(t_type));
		if (ev == m_events.end())
		{
			GINFO("EventInput: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		ev->second.push_back(t_func);
	}

	void EventInput::OnEvent(uint32_t t_type, nlohmann::json t_data)
	{
		auto ev = m_events.find(static_cast<EventInputTypes>(t_type));
		if (ev == m_events.end())
		{
			GINFO("EventInput: EventType %s not registered!", TypeToString(t_type).c_str());
			return;
		}

		for (uint32_t i = 0; i < ev->second.size(); i++)
		{
			ev->second[i](t_data);
		}
	}

	std::string EventInput::TypeToString(uint32_t t_type)
	{
		switch (static_cast<EventInputTypes>(t_type))
		{
		case EventInputType_Key:
			return std::string("Key");
		case EventInputType_KeyUp:
			return std::string("KeyUp");
		case EventInputType_KeyDown:
			return std::string("KeyDown");
		case EventInputType_Mouse:
			return std::string("Mouse");
		case EventInputType_MouseUp:
			return std::string("MouseUp");
		case EventInputType_MouseDown:
			return std::string("MouseDown");
		case EventInputType_Last:
		default:
			GWARN("EventInput: EventInputType_Last or no EventInputType given");
			return std::string("NULL");
		}
	}
};