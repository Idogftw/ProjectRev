#pragma once

#include "InputTypes.hpp"
#include "common/Engine.hpp"
#include "math/MathTypes.hpp"

namespace Gateway
{
	struct KeyboardState
	{
		bool keys[Key_Last];
	};

	struct MouseState
	{
		int32_t x;
		int32_t y;
		bool buttons[MouseButton_Last];
	};

	struct InputStates
	{
		KeyboardState Key_Current;
		KeyboardState Key_Last;
		MouseState Mouse_Current;
		MouseState Mouse_Last;
	};

	class Input
	{
	public:
		Input(Engine* t_engine);
		~Input();

		bool Init();
		void Update(nlohmann::json t_data);

		bool InputDown(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);
		bool InputUp(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);
		bool InputWasDown(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);
		bool InputWasUp(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);

		Vec2i GetCurrentMousePos();
		Vec2i GetLastMousePos();

	private:
		void OnKey_E(nlohmann::json t_data);
		void OnMouse_E(nlohmann::json t_data);
	private:
		Engine* m_engine;
		InputStates m_input_states;
	};
};