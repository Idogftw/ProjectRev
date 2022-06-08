#pragma once
#include <functional>
#include <string>
#include <vector>
#include <fstream>

#include "common/system/CmdSys.hpp"
#include "common/Engine.hpp"

namespace Gateway
{
	enum CVarFlags
	{
		//Data Types
		CVarFlag_Bool,
		CVarFlag_Long,
		CVarFlag_Int,
		CVarFlag_Float,
		CVarFlag_String,
		//System
		CVarFlag_System,
		CVarFlag_Render,
		CVarFlag_Audio,
		CVarFlag_Game,
		CVarFlag_GUI,
		//Data Related
		CVarFlag_Cheat,		//CVar is a cheat
		//CVarFlag_NoCheat,	//CVar isn't a cheat
		CVarFlag_Save,		//CVar can be saved to config file
		CVarFlag_NoUser,	//CVar can't be set by a user through console or through config
		CVarFlag_Console	//CVar can only be set through console

	};

	class Engine;
	class CVar;
	class LogSys;

	class CVarSystem
	{
	public:
		CVarSystem(Engine* t_engine);
		~CVarSystem();

		void Init();

		CVar* Find(const std::string& t_name);

		template<typename T>
		void Register(const std::string& t_name, T t_value, int t_flags, const std::string& t_description);

		void RegisterAllCVars();
	private:
		template <typename T>
		void Update(const std::string& t_name, T t_val);
		void Set_f(nlohmann::json t_args);
	private:
		Engine* m_engine;
		std::vector<CVar> m_cvars;
	};

	template<typename T>
	void CVarSystem::Register(const std::string& t_name, T t_value, int t_flags, const std::string& t_description)
	{
		//Check if it exists
		CVar* var = Find(t_name);

		//Exists already
		if(var != nullptr)
		{
			return;
		}

		var = new CVar{ t_name, t_value, t_flags, t_description };

		m_cvars.push_back(*var);
		
		//m_engine->RegisterEvent(EventType_Misc, EventMiscType_CVar, );
	}

	template <typename T>
	void CVarSystem::Update(const std::string& t_name, T t_val)
	{
		CVar* var = Find(t_name);

		if (var == nullptr)
		{
			return;
		}

		var->SetValue(t_val);
		
		nlohmann::json data;
		data["name"] = t_val;

		m_engine->OnEvent(EventType_Misc, EventMiscType_CVar, data);
		
	}

	//@TODO: Temp
	uint64_t PackU64(uint32_t t_val1, uint32_t t_val2);
	uint32_t UnpackU64(uint64_t t_val, bool t_first = true);

	class CVar
	{
	public:
		CVar() {}
		
		template<typename T>
		CVar(const std::string& t_name, T t_value, int t_flags, const std::string& t_description);
		
		void SetName(const std::string& t_name)
		{
			m_name = t_name;
		}

		template <typename T>
		void SetValue(T t_val)
		{
			m_value["val"] = t_val;
		}

		void SetFlags(int t_flags)
		{
			m_flags = t_flags;
		}

		void SetDescription(const std::string& t_description)
		{
			m_description = t_description;
		}

		std::string GetName()
		{
			return m_name;
		}

		template<typename T>
		T GetValue()
		{
			return m_value["val"];
		}

		int GetFlags()
		{
			return m_flags;
		}

		std::string GetDescription()
		{
			return m_description;
		}
	private:
		std::string m_name;
		nlohmann::json m_value;
		int m_flags;
		std::string m_description;
	};

	template<typename T>
	inline CVar::CVar(const std::string& t_name, T t_value, int t_flags, const std::string& t_description)
	{
		m_name = t_name;
		m_value["val"] = t_value;
		m_flags = t_flags;
		m_description = t_description;
	}
};