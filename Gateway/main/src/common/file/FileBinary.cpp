#include "common/file/FileBinary.hpp"

namespace Gateway
{
	FileBinary::FileBinary()
		: m_name("none"), m_file_size(0), m_mode(FileMode_Last)
	{
	}

	FileBinary::~FileBinary()
	{
		if (m_file)
		{
			m_file.close();
		}
	}

	void FileBinary::Create(const std::string& t_name)
	{
		m_name = t_name;

		//Auto read file if no mode set
		if (m_mode == FileMode_Last)
		{
			m_file.open(m_name, std::fstream::in | std::fstream::binary);
			return;
		}

		m_file.open(m_name, (m_mode == FileMode_Read ? std::fstream::in : std::fstream::out) | std::fstream::binary);
	}

	int32_t FileBinary::Read(void* t_buf, int32_t t_len)
	{
		m_file.read(reinterpret_cast<char*>(t_buf), t_len);
		//Seek(t_len, SeekMode_Cur);
		return 0;
	}

	int32_t FileBinary::Write(const void* t_buf, int32_t t_len)
	{
		m_file.write(static_cast<const char*>(t_buf), t_len);
		return 0;
	}

	int32_t FileBinary::Length()
	{
		return m_file_size;
	}

	int32_t FileBinary::Seek(int64_t t_offset, SeekModes t_mode)
	{
		int32_t ret_val = -1;

		std::fstream::_Seekdir dir;

		dir = (t_mode == SeekMode_Start) ? std::fstream::beg : (t_mode == SeekMode_Cur) ? std::fstream::cur : std::fstream::end;
		
		if (m_mode == FileMode_Read)
		{
			m_file.seekp(t_offset, dir);
		}
		else
		{
			m_file.seekg(t_offset, dir);
		}

		return ret_val;
	}

	void FileBinary::SeekStart()
	{
		Seek(0, SeekMode_Start);
	}

	void FileBinary::SetFileMode(FileModes t_mode)
	{
		m_mode = t_mode;
	}

	std::string FileBinary::GetName()
	{
		return m_name;
	}

	std::string FileBinary::GetPath()
	{
		return m_path;
	}
};