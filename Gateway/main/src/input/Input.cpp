#include "input/Input.hpp"

namespace Gateway
{
	Input::Input(Engine* t_engine)
		: m_engine(t_engine)
	{
		m_input_states = {};
	}

	Input::~Input()
	{
	}

	bool Input::Init()
	{
		m_engine->RegisterEvent(EventType_Input, EventInputType_Key, std::bind(&Input::OnKey_E, this, std::placeholders::_1));

		m_engine->RegisterEvent(EventType_Input, EventInputType_Mouse, std::bind(&Input::OnMouse_E, this, std::placeholders::_1));
		m_engine->RegisterEvent(EventType_Input, EventInputType_MouseMove, std::bind(&Input::OnMouse_E, this, std::placeholders::_1));
		m_engine->RegisterEvent(EventType_Input, EventInputType_MouseWheel, std::bind(&Input::OnMouse_E, this, std::placeholders::_1));

		m_engine->RegisterEvent(EventType_Application, EventAppType_Update, std::bind(&Input::Update_E, this, std::placeholders::_1));

		return true;
	}

	void Input::Update_E(nlohmann::json t_data)
	{
		memcpy(&m_input_states.Key_Last, &m_input_states.Key_Current, sizeof(KeyboardState));
		memcpy(&m_input_states.Mouse_Last, &m_input_states.Mouse_Current, sizeof(MouseState));
	}

	bool Input::InputDown(uint32_t t_input, DeviceTypes t_type)
	{
		switch (t_type)
		{
		case DeviceType_Keyboard:
			return m_input_states.Key_Current.keys[t_input];
		case DeviceType_Mouse:
			return m_input_states.Mouse_Current.buttons[t_input];
		case DeviceType_Gamepad:
			break;
		}

		return false;
	}

	bool Input::InputUp(uint32_t t_input, DeviceTypes t_type)
	{
		switch (t_type)
		{
		case DeviceType_Keyboard:
			return !m_input_states.Key_Current.keys[t_input];
		case DeviceType_Mouse:
			return !m_input_states.Mouse_Current.buttons[t_input];
		case DeviceType_Gamepad:
			break;
		}

		return false;
	}

	bool Input::InputWasDown(uint32_t t_input, DeviceTypes t_type)
	{
		switch (t_type)
		{
		case DeviceType_Keyboard:
			return m_input_states.Key_Last.keys[t_input];
		case DeviceType_Mouse:
			return m_input_states.Mouse_Last.buttons[t_input];
		case DeviceType_Gamepad:
			break;
		}

		return false;
	}

	bool Input::InputWasUp(uint32_t t_input, DeviceTypes t_type)
	{
		switch (t_type)
		{
		case DeviceType_Keyboard:
			return !m_input_states.Key_Last.keys[t_input];
			break;
		case DeviceType_Mouse:
			return !m_input_states.Mouse_Last.buttons[t_input];
			break;
		case DeviceType_Gamepad:
			break;
		}

		return false;
	}

	Vec2i Input::GetCurrentMousePos()
	{
		return Vec2i(m_input_states.Mouse_Current.x, m_input_states.Mouse_Current.y);
	}

	Vec2i Input::GetLastMousePos()
	{
		return Vec2i(m_input_states.Mouse_Last.x, m_input_states.Mouse_Last.y);
	}

	void Input::OnKey_E(nlohmann::json t_data)
	{
		Keys key = static_cast<Keys>(t_data["key"]);
		bool pressed = static_cast<bool>(t_data["state"]);

		if(m_input_states.Key_Current.keys[key] != pressed)
		{
			m_input_states.Key_Current.keys[key] = pressed;

			m_engine->OnEvent(EventType_Input, pressed ? EventInputType_KeyDown : EventInputType_KeyUp, t_data);
		}
	}

	void Input::OnMouse_E(nlohmann::json t_data)
	{
		int16_t mouse_type = t_data["type"];

		switch (mouse_type)
		{
		case EventInputType_Mouse: {
			MouseButtons button = static_cast<MouseButtons>(t_data["button"]);
			bool pressed = static_cast<bool>(t_data["state"]);

			if (m_input_states.Mouse_Current.buttons[button] != pressed)
			{
				m_input_states.Mouse_Current.buttons[button] = pressed;

				m_engine->OnEvent(EventType_Input, pressed ? EventInputType_MouseDown : EventInputType_MouseUp, t_data);
			}
		} break;
		case EventInputType_MouseMove: {
			int32_t xpos = t_data["xpos"];
			int32_t ypos = t_data["ypos"];

			if (m_input_states.Mouse_Current.x != xpos || m_input_states.Mouse_Current.y != ypos)
			{
				m_input_states.Mouse_Current.x = xpos;
				m_input_states.Mouse_Current.y = ypos;

				m_engine->OnEvent(EventType_Input, EventInputType_MouseMove, t_data);
			}
		} break;
		case EventInputType_MouseWheel: {
			m_engine->OnEvent(EventType_Input, EventInputType_MouseWheel, t_data);
		} break;
		default:
			break;
		}
	}

};