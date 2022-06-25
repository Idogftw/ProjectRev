#pragma once
#include <fstream>
#include <functional>
#include <sstream>

#include <json.hpp>

#include "containers/List.hpp"

namespace Gateway
{
	class LogSys;

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
		int32_t flags;
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

		/**
		  * Name: Register
		  * Desc: Registers a command and its properties and adds to the array of commands
		  * Param: Name of the command
		  * Param: The function to call
		  * Param: Flags for command - see CmdFlags enumeration
		  * Param: Description of the command
		  */
		void Register(const std::string& t_name, CmdCallback t_callback, int32_t t_flags, const std::string& t_description);
		
		/**
		  * Name: Unregister
		  * Desc: Unregisters the command
		  * Param: Name of the command
		  */
		void Unregister(const std::string& t_name);

		void Buffer(CmdTypes t_type, const std::string& t_str);

		void ExecuteBuffer();

		/**
		  * Name: GetCommandByIdx
		  * Desc: Gets the command by an index using the name of the command
		  * Param: Name of the command
		  * Return: Returns the index of the command in the array
		  */
		int32_t GetCommandByIdx(const std::string& t_name);

		bool Empty() { return !m_command_buffer.GetCount(); }
	private:
		nlohmann::json TokenizeCmd(const std::string& t_str);
		void Execute(nlohmann::json t_args);
	private:
		void Exec_CMD(nlohmann::json t_args);
	private:
		List<Command> m_commands;
		List<std::string> m_command_buffer;
	};

	
};