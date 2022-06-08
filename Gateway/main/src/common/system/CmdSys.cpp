#include "common/system/CmdSys.hpp"
#include "common/system/LogSys.hpp"

namespace Gateway
{
	CommandSystem::CommandSystem()
	{
	}

	CommandSystem::~CommandSystem()
	{
		m_commands.clear();
		m_command_buffer.clear();
	}

	void CommandSystem::Init()
	{
		Register("exec", std::bind(&CommandSystem::Exec_CMD, this, std::placeholders::_1), CmdFlag_System, "Parses a given file which will be read in and then it will execute more commands from the file!");
	}

	void CommandSystem::Register(const std::string& t_name, CmdCallback t_callback, int t_flags, const std::string& t_description)
	{
		uint32_t idx = GetCommandByIdx(t_name);
		if (idx != -1)
		{
			GWARN("CmdSys: Command %s already exists!", t_name.c_str());
			return;
		}

		Command new_cmd;

		std::string tmp_name = t_name;
		std::transform(tmp_name.begin(), tmp_name.end(), tmp_name.begin(), ::tolower);

		new_cmd.name = t_name;
		new_cmd.callback = t_callback;
		new_cmd.flags = t_flags;
		new_cmd.description = t_description;

		m_commands.push_back(new_cmd);
	}

	void CommandSystem::Unregister(const std::string& t_name)
	{
		uint32_t idx = GetCommandByIdx(t_name);
		if (idx != -1)
		{
			m_commands.erase(m_commands.begin() + idx);
		}
	}

	void CommandSystem::Buffer(CmdTypes t_type, const std::string& t_str)
	{
		switch (t_type)
		{
		case CmdType_Exec:
			Execute(TokenizeCmd(t_str));
			break;
		case CmdType_Insert:
			m_command_buffer.push_back(t_str);
			break;
		default:
			break;
		}
	}

	void CommandSystem::ExecuteBuffer()
	{
		for (uint32_t i = 0; i < m_command_buffer.size(); i++)
		{
			nlohmann::json cmd = TokenizeCmd(m_command_buffer[i]);

			Execute(cmd);
		}

		m_command_buffer.clear();
	}

	void CommandSystem::Execute(nlohmann::json t_args)
	{
		if (t_args == nlohmann::json::object())
		{
			GWARN("CmdSys: No arguments present for Execute!");
			return;
		}

		for (uint32_t i = 0; i < m_commands.size(); i++)
		{
			std::string tmp = t_args["name"];

			std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

			if (m_commands[i].name == tmp)
			{
				m_commands[i].callback(t_args);
				return;
			}
		}
	}

	nlohmann::json CommandSystem::TokenizeCmd(const std::string &t_str)
	{
		std::stringstream ss(t_str);
		std::string tmp_str;
		nlohmann::json j;
		int count = 0;

		while (std::getline(ss, tmp_str, ' '))
		{
			//Work on adding find delims
			if (tmp_str.find("\n") != std::string::npos)
			{
				auto it = tmp_str.find("\n");
				tmp_str = tmp_str.substr(0, it + 1);
			}

			if (count == 0)
			{
				j["name"] = tmp_str;
			}
			else
			{
				j["value"].push_back(tmp_str);
			}

			count++;
		}

		return j;
	}

	int CommandSystem::GetCommandByIdx(const std::string& t_name)
	{
		auto it = std::find_if(m_commands.begin(), m_commands.end(), [t_name](const Command& d)
			{
				std::string tmp_name = t_name;
				std::string tmp_struct_name = d.name;

				std::transform(tmp_name.begin(), tmp_name.end(), tmp_name.begin(), ::tolower);
				std::transform(tmp_struct_name.begin(), tmp_struct_name.end(), tmp_struct_name.begin(), ::tolower);

				return tmp_struct_name == tmp_name;
			});

		if (it != m_commands.end())
		{
			return static_cast<int>(it - m_commands.begin());
		}

		return -1;
	}

	void CommandSystem::Exec_CMD(nlohmann::json t_args)
	{
		if (t_args.size() != 2)
		{
			GINFO("CmdSys: exec <filename> : execute a file");
			return;
		}

		std::string name = t_args["value"].at(0);

		std::ifstream file(name);
		if (!file)
		{
			GWARN("Couldn't read file %s, doesn't exist", name.c_str());
			return;
		}

		std::string str;
		while (std::getline(file, str))
		{
			if (str.find("\"") != std::string::npos)
			{
				str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
			}
			Buffer(CmdType_Insert, str);
		}

		file.close();
	}
};