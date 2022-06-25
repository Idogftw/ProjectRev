#pragma once

#include "../EventBase.hpp"
#include "common/system/LogSys.hpp"

namespace Gateway
{
	enum EventInputTypes
	{
		EventInputType_Key,
		EventInputType_KeyDown,
		EventInputType_KeyUp,
		EventInputType_Mouse,
		EventInputType_MouseMove,
		EventInputType_MouseWheel,
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

		/**
		  * Duplicate: See corresponding RegisterCallback in EventBase.hpp
		  */
		void RegisterCallback(uint32_t t_type, event_callback t_func);

		/**
		  * Duplicate: See corresponding OnEvent in EventBase.hpp
		  */
		void OnEvent(uint32_t t_type, nlohmann::json t_data);

		/**
		  * Duplicate: See corresponding TypeToString in EventBase.hpp
		  */
		std::string TypeToString(uint32_t t_type);
	private:
		void Init();
	private:
		std::map<EventInputTypes, List<event_callback>> m_events;
	};
};