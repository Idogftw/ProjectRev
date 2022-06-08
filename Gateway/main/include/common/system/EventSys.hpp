#pragma once
#include <map>
#include <vector>

#include "common/system/LogSys.hpp"
#include "event/EventBase.hpp"
//#include "Common/Memory/MemoryManager.hpp"

namespace Gateway
{
	//All events will have a suffix of E. ex: OnQuit_E
	//This is just to help figure out whats a function for a class and whats a command for that class

	class EventSystem
	{
	public:
		EventSystem();
		~EventSystem();

		void RegisterSystem(EventTypes t_type, IEventBase* m_event);

		IEventBase* GetEventPtr(EventTypes t_type);

		std::string TypeToString(EventTypes t_type);
	private:
		std::map<EventTypes, IEventBase*> m_events;
	};
};