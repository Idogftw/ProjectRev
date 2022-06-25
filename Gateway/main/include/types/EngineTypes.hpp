#pragma once

namespace Gateway
{
	#define BitFlag_None	(0x00000000)
	#define BitFlag_All		(0xFFFFFFFF)

	#define BitFlag_0		(0x00000001)
	#define BitFlag_1		(0x00000002)
	#define BitFlag_2		(0x00000004)
	#define BitFlag_3		(0x00000008)
	#define BitFlag_4		(0x00000010)
	#define BitFlag_5		(0x00000020)
	#define BitFlag_6		(0x00000040)
	#define BitFlag_7		(0x00000080)
	#define BitFlag_8		(0x00000100)
	#define BitFlag_9		(0x00000200)
	#define BitFlag_10		(0x00000400)
	#define BitFlag_11		(0x00000800)
	#define BitFlag_12		(0x00001000)
	#define BitFlag_13		(0x00002000)
	#define BitFlag_14		(0x00004000)
	#define BitFlag_15		(0x00008000)

	enum PlatformTypes
	{
		PlatformType_Windows,
		PlatformType_Linux,
		PlatformType_Mac,
		PlatformType_XBX,
		PlatformType_PS,
		PlatformType_Last
	};
	
};