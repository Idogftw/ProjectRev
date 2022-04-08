#pragma once

namespace Gateway
{
	class Platform
	{
	public:
		virtual ~Platform() {}

		virtual bool Init() = 0;
		virtual void PumpMessages() = 0;

		virtual void* GetHandle() = 0;
	};
};