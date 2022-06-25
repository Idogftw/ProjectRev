#pragma once

namespace Gateway
{
	enum FileModes
	{
		FileMode_Read,
		FileMode_Write,
		FileMode_Last
	};

	enum SeekModes
	{
		SeekMode_Start,
		SeekMode_Cur,
		SeekMode_End,
		SeekMode_Last
	};

	struct GameSearchPath
	{
		std::string base;
		std::string game;
	};
};