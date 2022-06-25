#pragma once

namespace Gateway
{
	class Platform
	{
	public:
		virtual ~Platform() {}

		virtual bool Init() = 0;

		/**
		  * Name: PumpMessages
		  * Desc: Handles the pumping of messages from the OS
		  */
		virtual void PumpMessages() = 0;

		/**
		  * Name: GetHandle
		  * Desc: Retrieves the platform specific window handle
		  * Return: Handle to the platform - IE HWND or platform equivalent
		  */
		virtual void* GetHandle() = 0;
	};
};