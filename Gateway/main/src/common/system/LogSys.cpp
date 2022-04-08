#include "common/system/LogSys.hpp"
#include "common/system/CVarSys.hpp"

namespace Gateway
{
	LogSys *LogSys::m_instance = nullptr;

	LogSys *LogSys::Get()
	{
		if (m_instance == nullptr) {
			m_instance = new LogSys();
		}
		return m_instance;
	}

	LogSys::LogSys()
		: m_init(false)
	{
	}

	void LogSys::Init(CVarSystem* t_cvar)
	{
		if (m_init)
		{
			return;
		}

		m_cvar_sys = t_cvar;

		m_log_dir = std::string("./");
		m_log_name = GATEWAY_LOG;

		ClearFile();

		m_init = true;

		//INFO("LogSystem: Initialized!");
	}

	void LogSys::Log(std::string t_format, ...)
	{
		va_list args;
		va_start(args, t_format);

		va_list copy_args;
		va_copy(copy_args, args);
		const int iLen = std::vsnprintf(NULL, 0, t_format.c_str(), copy_args);
		va_end(copy_args);

		std::vector<char> buf(iLen + 1);
		vsnprintf(buf.data(), buf.size(), t_format.c_str(), args);
		va_end(args);

		std::string var_msg(buf.data(), buf.size());

		//@TODO: Impl timestamps with messages!
		CVar* var = m_cvar_sys->Find("s_developer");
		/*if (var != nullptr && var.GetValue<int>())
		{
			int mil = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
			if (e_timestamps.GetValue<int>() == 1)
			{
				//Do time stuff for mil
			}
			else
			{

			}
		}*/

		//Impl filesystem
		var = m_cvar_sys->Find("s_save_log");
		if (var != nullptr && var->GetValue<bool>())
		{
			//Temporary file saving
			std::fstream file;
			file.open(m_log_dir + m_log_name, std::ios::app);
			file << var_msg << std::endl;
			file.close();
		}
	}

	//For now these won't do anything but print

	void LogSys::Warn(std::string t_format, ...)
	{
		Log(COLOR_YELLOW "WARNING: " COLOR_RED "%s\n", t_format);
	}

	void LogSys::Error(std::string t_format, ...)
	{
		//@TODO: Impl Error
		Log(COLOR_RED "ERROR: %s\n", t_format);
	}

	void LogSys::Fatal(std::string t_format, ...)
	{
		//@TODO: Impl Fatal
		Log(COLOR_RED "FATAL: %s\n", t_format);
	}	

	void LogSys::DLog(std::string t_format, ...)
	{
		CVar* dev = m_cvar_sys->Find("s_developer");
		if (dev != nullptr && !dev->GetValue<bool>())
		{
			return;
		}

		va_list args;
		va_start(args, t_format);

		va_list copy_args;
		va_copy(copy_args, args);
		const int iLen = std::vsnprintf(NULL, 0, t_format.c_str(), copy_args);
		va_end(copy_args);

		std::vector<char> buf(iLen + 1);
		vsnprintf(buf.data(), buf.size(), t_format.c_str(), args);
		va_end(args);

		std::string var_msg(buf.data(), buf.size());

		Log(COLOR_RED"%s", var_msg);
	}

	void LogSys::DWarn(std::string t_format, ...)
	{
		CVar* dev = m_cvar_sys->Find("s_developer");
		if (dev != nullptr && !dev->GetValue<bool>())
		{
			delete dev;
			return;
		}
		delete dev;
	}

	void LogSys::ClearFile()
	{
		m_log_file.open(m_log_dir + m_log_name, std::ios::out | std::ios::trunc);
		m_log_file.close();
	}

	void LogSys::Shutdown()
	{
		//INFO("LogSystem: Shutting Down!");
		delete m_instance;
	}
};