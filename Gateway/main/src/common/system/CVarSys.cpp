#include "common/system/CVarSys.hpp"
#include "common/system/LogSys.hpp"

namespace Gateway
{
	CVarSystem::CVarSystem(Engine* t_engine)
		: m_engine(t_engine)
	{
	}

	CVarSystem::~CVarSystem()
	{
		//Hack to clear the memory of the cvars
		std::vector<CVar>().swap(m_cvars);
	}

	void CVarSystem::Init()
	{	
		m_engine->RegisterCommand("set", std::bind(&CVarSystem::Set_f, this, std::placeholders::_1), CVarFlag_System, "Sets a CVar's variable.");
	}

	CVar* CVarSystem::Find(const std::string& t_name)
	{
		for (size_t i = 0; i < m_cvars.size(); i++)
		{
			if (m_cvars[i].GetName() == t_name)
			{
				return &m_cvars[i];
			}
		}

		return nullptr;
	}

	void CVarSystem::RegisterAllCVars()
	{
		//System
		Register("s_save_log", true, CVarFlag_Bool | CVarFlag_System | CVarFlag_Save, "Save logs in to a file.");
		Register("s_timestamps", 0, CVarFlag_Int | CVarFlag_System, "Print the timestamps along with each log, 0 = none, 1 = msec, 2 = sec.");
		Register("s_developer", 0, CVarFlag_Bool | CVarFlag_System | CVarFlag_Save, "Enables developer mode for better debugging.");
	
		//Rendering
		Register("r_width", 1280, CVarFlag_Int | CVarFlag_Render | CVarFlag_Save, "Width of window and viewport.");
		Register("r_height", 720, CVarFlag_Int | CVarFlag_Render | CVarFlag_Save, "Height of window and viewport.");
		Register("r_rendertype", RendererType_Deferred, CVarFlag_Int | CVarFlag_Render | CVarFlag_Save, "Which renderer to use for engine.");
		Register("r_api", RendererAPIType_GL, CVarFlag_Render | CVarFlag_Int | CVarFlag_Save, "Type of hardware renderer used by the engine.");

		//Audio

		//GUI
	}

	void CVarSystem::Set_f(nlohmann::json t_args)
	{
		if (t_args["value"].size() < 2)
		{
			GINFO("CVarSys: set <cvar_name> <value> : set a cvar");
			return;
		}

		/*CVar* var = Find(t_args["value"].at(0));
		if (var == nullptr)
		{
			//LOG_WARN("CVar not found");
			return;
		}

		if (var->GetFlags() & (CVarFlag_NoUser))
		{
			//LOG_INFO("CVar can't be set through config");
			return;
		}*/

		Update(t_args["value"].at(0), t_args["value"].at(1));
	}

	//@TODO: Temp
	uint64_t PackU64(uint32_t t_val1, uint32_t t_val2)
	{
		return ((uint64_t)t_val1) << 32 | t_val2;
	}

	uint32_t UnpackU64(uint64_t t_val, bool t_first)
	{
		return t_first ? ((t_val >> 32) & 0xFFFFFFFFLL) : (t_val & 0xFFFFFFFFLL);
	}
};