#include "common/file/File.hpp"

namespace Gateway
{
	int32_t FileBase::Read(void* t_buf, int32_t t_len)
	{
		GFATAL("FileBase::Read: Cannot read from FileBase");
		return 0;
	}

	int32_t FileBase::Write(const void* t_buf, int32_t t_len)
	{
		GFATAL("FileBase::Write: Cannot write to FileBase");
		return 0;
	}

	int32_t FileBase::Length()
	{
		return 0;
	}

	int32_t FileBase::Offset()
	{
		return 0;
	}

	int32_t FileBase::Seek(int64_t t_offset, SeekModes t_mode)
	{
		return -1;
	}

	void FileBase::SeekStart()
	{
		Seek(0, SeekMode_Start);
	}

	void FileBase::SetFileMode(FileModes t_mode)
	{
	}

	std::string FileBase::GetName()
	{
		return {};
	}

	std::string FileBase::GetPath()
	{
		return {};
	}
};