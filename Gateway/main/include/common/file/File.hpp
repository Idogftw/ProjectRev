#pragma once
#include <fstream>
#include <stdint.h>
#include <string>

#include "common/system/LogSys.hpp"

#include "math/Vector.hpp"
#include "math/Matrix.hpp"
#include "math/Quaternion.hpp"

#include "types/FileTypes.hpp"

namespace Gateway
{
	class FileBase
	{
	public:
		FileBase() {}
		virtual ~FileBase() {}

		/**
		  * Name: Create
		  * Desc: Creates the fstream object
		  */
		virtual void Create(const std::string& t_name) = 0;

		/**
		  * Name: Read
		  * Desc: Reads the designated value from the file to the buffer
		  * Param: Buffer to return
		  * Param: Length of the buffer value
		  * Return: Returns what the child class wants to return
		  */
		virtual int32_t Read(void* t_buf, int32_t t_len);
		
		/**
		  * Name: Write
		  * Desc: Writes the designated value to the file from the buffer
		  * Param: Buffer to write from
		  * Param: Length of the buffer value
		  * Return: Returns what the child class wants to return
		  */
		virtual int32_t Write(const void* t_buf, int32_t t_len);

		/**
		  * Name: Length
		  * Desc: Retrieves the length of the file
		  * Return: File size as an int
		  */
		virtual int32_t Length();
		
		/**
		  * Name: Offset
		  * Desc: Retrieves the current offset of the file being used
		  * Return: Offset as an int
		  */
		virtual int32_t Offset();

		/**
		  * Name: Seek
		  * Desc: Sets the pointer of the file to a specific spot
		  * Return: 0 on successful seek and -1 on failure
		  */
		virtual int32_t Seek(int64_t t_offset, SeekModes t_mode);

		/**
		  * Name: Start
		  * Desc: Sets the pointer of the file to the start of the file
		  */
		virtual void SeekStart();

		/**
		  * Name: SetFileMode
		  * Desc: Sets the file mode of reading or writing
		  */
		virtual void SetFileMode(FileModes t_mode);		

		/**
		  * Name: GetName
		  * Desc: Gets the name of the file
		  * Return: String of the name
		  */
		virtual std::string GetName();

		/**
		  * Name: GetPath
		  * Desc: Gets the path of the file
		  * Return: String of the path
		  */
		virtual std::string GetPath();
		
		/**
		  * Name: Read
		  * Desc: Reads the value from the file
		  * Return: Result of value
		  */
		template<typename T>
		T Read()
		{
			T val{};
			Read(&val, sizeof(val));
			return val;
		}

		/**
		  * Name: ReadString
		  * Desc: Reads a string from the file
		  * Return: Result of the child's read method
		  */
		int32_t ReadString(std::string& t_val)
		{
			int32_t length;
			Read(&length, sizeof(length));

			char c;
			while ((int)(c = Read<char>()) != 0)
			{
				t_val += c;
			}
			return 0;
		}

		//@INFO: This could be used in the future over templated Read but its all the same code copied and used so templates are a better use
		//virtual int ReadInt(int32_t& t_val);
		//virtual int ReadUInt(uint32_t& t_val);
		//virtual int ReadShort(int16_t& t_val);
		//virtual int ReadUShort(uint16_t& t_val);
		//virtual int ReadChar(int8_t& t_val);
		//virtual int ReadUChar(uint8_t& t_val);
		//virtual int ReadFloat(float& t_val);
		//virtual int ReadBool(bool& t_val);
		//virtual int ReadString(std::string& t_val);

		virtual int32_t WriteString(const std::string& t_str)
		{
			Write<int32_t>(t_str.length());
			Write(t_str.c_str(), t_str.length());
			return 0;
		}

		template<typename T>
		int32_t Write(const T& t_val)
		{
			int32_t result = Write(&t_val, sizeof(t_val));
			return result;
		}

		template<typename T>
		int32_t WriteArray(const T* t_val, int32_t t_count)
		{
			for (int32_t i = 0; i < t_count; i++)
			{
				Write(&t_val[i]);
			}

			return 0;
		}
	};
};