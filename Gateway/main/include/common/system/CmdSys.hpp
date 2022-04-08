#pragma once
#include <fstream>
#include <functional>
#include <sstream>

#include <json.hpp>

namespace Gateway
{
	typedef std::function<void(nlohmann::json)> CmdCallback;

	enum CmdFlags
	{
		CmdFlag_System,
		CmdFlag_Renderer,
		CmdFlag_Sound,
		CmdFlag_Game,
		CmdFlag_Last
	};

	enum CmdTypes
	{
		CmdType_Exec,
		CmdType_Insert
	};

	struct Command
	{
		std::string name;
		CmdCallback callback;
		int flags;
		std::string description;
	};

	//All command functions will have a suffix of CMD. ex: Exec_CMD
	//This is just to help figure out whats a function for a class and whats a command for that class

	class CommandSystem
	{
	public:
		CommandSystem();
		~CommandSystem();

		void Init();

		void Register(const std::string& t_name, CmdCallback t_callback, int t_flags, const std::string& t_description);
		void Unregister(const std::string& t_name);

		void Buffer(CmdTypes t_type, const std::string& t_str);

		void ExecuteBuffer();

		void Execute(nlohmann::json t_args);

		nlohmann::json TokenizeCmd(const std::string& t_str);

		int GetCommandByIdx(const std::string& t_name);

		bool Empty() { return !m_command_buffer.size(); }
	private:
		void Exec_CMD(nlohmann::json t_args);
	private:
		std::vector<Command> m_commands;
		std::vector<std::string> m_command_buffer;
	};

	
};