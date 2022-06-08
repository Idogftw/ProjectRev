#pragma once

#include "../EventBase.hpp"

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

		void RegisterCallback(uint32_t t_type, event_callback t_func);
		void OnEvent(uint32_t t_type, nlohmann::json t_data);

		std::string TypeToString(uint32_t t_type);
	private:
		void Init();
	private:
		std::map<EventMiscTypes, std::vector<event_callback>> m_events;
	};
};