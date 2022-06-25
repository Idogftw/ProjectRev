#pragma once
#include "File.hpp"

namespace Gateway
{
	class FileBinary : public FileBase
	{
	public:
		FileBinary();
		~FileBinary();

		/**
		  * Duplicate: See corresponding Read in File.hpp
		  */
		virtual void Create(const std::string& t_name);

		/**
		  * Duplicate: See corresponding Read in File.hpp
		  */
		virtual int32_t Read(void* t_buf, int32_t t_len);

		/**
		  * Duplicate: See corresponding Write in File.hpp
		  */
		virtual int32_t Write(const void* t_buf, int32_t t_len);

		/**
		  * Duplicate: See corresponding Length in File.hpp
		  */
		virtual int32_t Length();

		/**
		  * Duplicate: See corresponding Seek in File.hpp
		  */
		virtual int32_t Seek(int64_t t_offset, SeekModes t_mode);

		/**
		  * Duplicate: See corresponding Start in File.hpp
		  */
		virtual void SeekStart();

		/**
		  * Duplicate: See corresponding SetFileMode in File.hpp
		  */
		virtual void SetFileMode(FileModes t_mode);

		/**
		  * Duplicate: See corresponding GetName in File.hpp
		  */
		virtual std::string GetName();

		/**
		  * Duplicate: See corresponding GetPath in File.hpp
		  */
		virtual std::string GetPath();

	private:
		std::string m_name;
		std::string m_path;
		int32_t m_offset;
		int32_t m_file_size;
		FileModes m_mode;
		std::fstream m_file;
	};
};