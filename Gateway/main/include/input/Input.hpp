#pragma once

#include "common/Engine.hpp"
#include "types/InputTypes.hpp"
#include "types/MathTypes.hpp"

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

		/**
		  * Name: InputDown
		  * Desc: Checks if a specific input from a DeviceTypes enumeration is down
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: Specific type of device- see any DeviceTypes enumeration
		  * Return: Boolean if input is down 
		  */
		bool InputDown(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);
		
		/**
		  * Name: InputUp
		  * Desc: Checks if a specific input from a DeviceTypes enumeration is up
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: Specific type of device- see any DeviceTypes enumeration
		  * Return: Boolean if input is up
		  */
		bool InputUp(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);

		/**
		  * Name: InputWasDown
		  * Desc: Checks if a specific input from a DeviceTypes enumeration was down last frame
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: Specific type of device- see any DeviceTypes enumeration
		  * Return: Boolean of if input was down
		  */
		bool InputWasDown(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);

		/**
		  * Name: InputWasUp
		  * Desc: Checks if a specific input from a DeviceTypes enumeration was up last frame
		  * Param: Type of event system - see EventTypes enumeration
		  * Param: Specific type of device- see any DeviceTypes enumeration
		  * Return: Boolean of if input was up
		  */
		bool InputWasUp(uint32_t t_input, DeviceTypes t_type = DeviceType_Keyboard);

		/**
		  * Name: GetCurrentMousePos
		  * Desc: Returns the current Mouse Position
		  * Return: Vector of X position and Y position
		  */
		Vec2i GetCurrentMousePos();

		/**
		  * Name: GetLastMousePos
		  * Desc: Returns the last frame Mouse Position
		  * Return: Vector of X position and Y position
		  */
		Vec2i GetLastMousePos();

	private:
		void Update_E(nlohmann::json t_data);
		void OnKey_E(nlohmann::json t_data);
		void OnMouse_E(nlohmann::json t_data);
	private:
		Engine* m_engine;
		InputStates m_input_states;
	};
};