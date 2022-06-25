#include "common/system/FileSys.hpp"

#include "common/file/FileBinary.hpp"

namespace Gateway
{
	FileSystem::FileSystem(Engine* t_engine)
		: m_engine(t_engine)
	{
	}

	FileSystem::~FileSystem()
	{
	}

	bool FileSystem::Init()
	{
		//FileSystem
		m_engine->RegisterCVar("fs_base_path", "", CVarFlag_String | CVarFlag_FileSystem | CVarFlag_Console, "Base path of the game.");
		m_engine->RegisterCVar("fs_save_path", "", CVarFlag_String | CVarFlag_FileSystem | CVarFlag_Console, "Save path of the game.");
		m_engine->RegisterCVar("fs_mod_path", "", CVarFlag_String | CVarFlag_FileSystem | CVarFlag_Console, "Mod path.");

		SetupGameDir(BASE_DIR);

		std::string path = m_engine->FindCVar("fs_mod_path")->GetValue<std::string>();
		if (!path.empty() && path.compare(BASE_DIR))
		{
			SetupGameDir(path);
		}

		return true;
	}

	void FileSystem::AddGameDir(const std::string& t_dir, const std::string& t_game)
	{
		for (int32_t i = 0; i < m_search_paths.GetCount(); i++)
		{
			if (m_search_paths[i].base.compare(t_dir) == 0 && m_search_paths[i].game.compare(t_game) == 0)
			{
				return;
			}
		}

		m_search_paths.Add(GameSearchPath{ t_dir, t_game });

		//@TODO: Add files from paths to resource file
	}

	void FileSystem::SetupGameDir(const std::string& t_dir)
	{
		std::string path = m_engine->FindCVar("fs_base_path")->GetValue<std::string>();
		if (!path.empty())
		{
			AddGameDir(path, t_dir);
		}

		path = m_engine->FindCVar("fs_save_path")->GetValue<std::string>();
		if (!path.empty())
		{
			AddGameDir(path, t_dir);
		}
	}
};