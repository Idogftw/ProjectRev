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

		void RegisterCallback(uint32_t t_type, event_callback t_func);
		void OnEvent(uint32_t t_type, nlohmann::json t_data);

		std::string TypeToString(uint32_t t_type);
	private:
		void Init();
	private:
		std::map<EventAppTypes, std::vector<event_callback>> m_events;
	};
};