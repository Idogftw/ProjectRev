#pragma once
#include <functional>

#include <json.hpp>

namespace Gateway
{
	typedef std::function<void(nlohmann::json)> event_callback;

	enum EventTypes
	{
		EventType_Application,	/* System for Application related events: Update, Window related, etc */
		EventType_Input,		/* System for Input: Keyboard, Mouse, etc */
		EventType_Renderer,		/* System for Rendering: API Calls or Rendering */

		EventType_Game,			/* System for Game: Anything the Game sets up as events */

		EventType_Misc,			/* System for Miscellaneous events, like CVars updated, commands, etc */
		EventType_Last
	};

	//@TODO: Implement a priority system so certain callbacks take priority over others, like engine would be
	//lowest priority and say renderer highest when quitting

	class IEventBase
	{
	public:
		IEventBase(EventTypes t_type) : m_ev_type(t_type) {}
		virtual ~IEventBase() {}

		/**
		  * Name: RegisterCallback
		  * Desc: Registers an event for a specific system
		  * Param: Specific type of event from specific EventTypes system - see any Event[NAME].hpp enumeration
		  * Param: Function to call when event is fired
		  */
		virtual void RegisterCallback(uint32_t t_type, event_callback t_func) = 0;
		
		/**
		  * Name: OnEvent
		  * Desc: Fires off event for system
		  * Param: Specific type of event from specific EventTypes system - see any Event[NAME].hpp enumeration
		  * Param: Data to be passed to each callback function
		  */
		virtual void OnEvent(uint32_t t_type, nlohmann::json t_data) = 0;

		/**
		  * Name: TypeToString
		  * Desc: Returns a corresponding string from the EventTypes enumeration
		  * Param: Type of event - see any Event[Name].hpp enumeration
		  * Return: String name of corresponding Event[Name].hpp enumeration
		  */
		virtual std::string TypeToString(uint32_t t_type) = 0;

		/**
		  * Name: GetEventType
		  * Desc: Returns the EventTypes enumeration of the inherited event system
		  * Return: EventTypes enumeration value
		  */
		EventTypes GetEventType() { return m_ev_type; }
	private:
		virtual void Init() = 0;
	protected:
		EventTypes m_ev_type;
	};
};