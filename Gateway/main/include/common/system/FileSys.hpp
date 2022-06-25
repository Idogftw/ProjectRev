#pragma once
#include <string>

#include "common/Engine.hpp"
#include "common/file/File.hpp"
#include "common/system/CVarSys.hpp"

#include "containers/List.hpp"

namespace Gateway
{
	class FileBinary;
	struct GameSearchPath;

	class FileSystem
	{
	public:
		FileSystem(Engine* t_engine);
		~FileSystem();

		bool Init();

		//void ReadFileToBuffer(const std::string& t_file);

		/**
		  * Name: AddGameDir
		  * Desc: Adds a directory to the search path for assets
		  * Param: Directory path
		  * Param: File location
		  */
		void AddGameDir(const std::string& t_dir, const std::string& t_game);
	private:
		void SetupGameDir(const std::string& t_dir);
	private:
		Engine* m_engine;
		List<GameSearchPath> m_search_paths;
	};
};