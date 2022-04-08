#pragma once

#include "../EventBase.hpp"

namespace Gateway
{
	enum EventInputTypes
	{
		EventInputType_Key,
		EventInputType_KeyDown,
		EventInputType_KeyUp,
		EventInputType_Mouse,
		EventInputType_MouseDown,
		EventInputType_MouseUp,
		EventInputType_Button,
		EventInputType_ButtonUp,
		EventInputType_ButtonDown,
		EventInputType_Last
	};

	class EventInput : public IEventBase
	{
	public:
		EventInput();
		~EventInput();

		void RegisterCallback(uint32_t t_type, event_callback t_func);
		void OnEvent(uint32_t t_type, nlohmann::json t_data);

		std::string TypeToString(uint32_t t_type);
	private:
		void Init();
	private:
		std::map<EventInputTypes, std::vector<event_callback>> m_events;
	};
};