#pragma once

#include "../EventBase.hpp"
#include "common/system/LogSys.hpp"

namespace Gateway
{
	enum EventMiscTypes
	{
		EventMiscType_CVar,
		EventMiscType_Command,
		EventMiscType_Last
	};

	class EventMisc : public IEventBase
	{
	public:
		EventMisc();
		~EventMisc();

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
		std::map<EventMiscTypes, List<event_callback>> m_events;
	};
};