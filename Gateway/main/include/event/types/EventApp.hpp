#pragma once

#include "../EventBase.hpp"
#include "common/system/LogSys.hpp"

namespace Gateway
{
	enum EventAppTypes
	{
		EventAppType_Quit,
		EventAppType_PreUpdate,
		EventAppType_Update,
		EventAppType_PostUpdate,
		EventAppType_NewSize,
		EventAppType_Last
	};

	class EventApp : public IEventBase
	{
	public:
		EventApp();
		~EventApp();

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
		std::map<EventAppTypes, List<event_callback>> m_events;
	};
};