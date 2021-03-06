#pragma once
#include <chrono>
#include <fstream>
#include <vector>

#include "common/system/LogSys.hpp"
#include "common/Engine.hpp"
#include "containers/List.hpp"

#define GATEWAY_LOG "Gateway.log"

#define GINFO(msg, ...)  Gateway::LogSys::Get()->Log(msg, __VA_ARGS__) 
#define GWARN(msg, ...)  Gateway::LogSys::Get()->Warn(msg, __VA_ARGS__)
#define GERR(msg, ...) Gateway::LogSys::Get()->Error(msg,  __VA_ARGS__)
#define GFATAL(msg, ...) Gateway::LogSys::Get()->Fatal(msg,  __VA_ARGS__)

#define GDINFO(msg, ...)  Gateway::LogSys::Get()->DLog(msg, __VA_ARGS__)
#define GDWARN(msg, ...)  Gateway::LogSys::Get()->DWarn(msg, __VA_ARGS__)

#define COLOR_DEFAULT				"^0"
#define COLOR_RED					"^1"
#define COLOR_GREEN					"^2"
#define COLOR_YELLOW				"^3"
#define COLOR_BLUE					"^4"
#define COLOR_CYAN					"^5"
#define COLOR_ORANGE				"^6"
#define COLOR_WHITE					"^7"
#define COLOR_GRAY					"^8"
#define COLOR_BLACK					"^9"

namespace Gateway
{
	class CVar;
	class CVarSystem;

	class LogSys
	{
	public:
		void Init(CVarSystem* t_cvar);

		void Log(std::string t_format, ...);

		void Warn(std::string t_format, ...);

		void Error(std::string t_format, ...);
		void Fatal(std::string t_format, ...);

		void DLog(std::string t_format, ...);
		void DWarn(std::string t_format, ...);

		void ClearFile();

		void Shutdown();

		static LogSys* Get();
	private:
		LogSys();
		LogSys(const LogSys&) = delete;
		LogSys(LogSys&&) = delete;
		void operator=(const LogSys&) = delete;
		void operator=(LogSys&&) = delete;
	private:
		static LogSys* m_instance;
		CVarSystem* m_cvar_sys;
		std::fstream m_log_file;
		std::string m_log_dir;
		std::string m_log_name;
		List<std::string> m_warnings;
		bool m_init;
	};
};