#pragma once

namespace Gateway
{
	//@TODO: Implement Memory manager
	enum MemoryTags
	{
		MemoryTag_Class,

	};

	struct MemoryBlock
	{
		void* data;
	};

	class Memory
	{
	private:
		void* m_data;
	};
};