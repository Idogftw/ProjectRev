#pragma once
#include <map>
#include <vector>

#include "common/system/LogSys.hpp"
#include "event/EventBase.hpp"

namespace Gateway
{
	//All events will have a suffix of E. ex: OnQuit_E
	//This is just to help figure out whats a function for a class and whats a command for that class

	class EventSystem
	{
	public:
		EventSystem();
		~EventSystem();

		/**
		  * Name: RegisterSystem
		  * Desc: Registers an event system
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: System to add
		  */
		void RegisterSystem(EventTypes t_type, IEventBase* m_event);

		/**
		  * Name: GetEventPtr
		  * Desc: Retrieves the pointer to the specified event system by enumeration
		  * Param: Type of event system - see EventTypes enumeration
		  * Return: IEventBase pointer
		  */
		IEventBase* GetEventPtr(EventTypes t_type);

		/**
		  * Name: TypeToString
		  * Desc: Returns a corresponding string from the EventTypes enumeration
		  * Param: Type of event system - see EventTypes enumeration
		  * Return: String name of corresponding EventTypes enumeration
		  */
		std::string TypeToString(EventTypes t_type);
	private:
		std::map<EventTypes, IEventBase*> m_events;
	};
};