#pragma once
#include <functional>

#include <json.hpp>

//#include "Common/System/LogSystem.hpp"

namespace Gateway
{
	typedef std::function<void(nlohmann::json)> event_callback;

	enum EventTypes
	{
		EventType_Application,	/* System for Application related events: Update, Window related, etc */
		EventType_Input,		/* System for Input: Keyboard, Mouse, etc */
		EventType_Renderer,		/* System for Rendering: API Calls or Rendering */

		EventType_Game,			/* System for Game: Anything the Game sets up as events */

		EventType_Command,		/* System for Command: (!!MAYBE!!) Commands that come from CommandSystem */
		EventType_Last
	};

	class IEventBase
	{
	public:
		IEventBase(EventTypes t_type) : m_ev_type(t_type) {}
		virtual ~IEventBase() {}

		virtual void RegisterCallback(uint32_t t_type, event_callback t_func) = 0;
		virtual void OnEvent(uint32_t t_type, nlohmann::json t_data) = 0;

		virtual std::string TypeToString(uint32_t t_type) = 0;

		EventTypes GetEventType() { return m_ev_type; }
	private:
		virtual void Init() = 0;
	protected:
		EventTypes m_ev_type;
	};
};