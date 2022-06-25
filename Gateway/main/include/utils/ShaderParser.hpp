#pragma once
#include "common/system/FileSys.hpp"
#include "common/file/File.hpp"

/*
The idea of parsing is to
*/

namespace Gateway
{
	//@TEMP
	struct VarContainer
	{

	};
	//@TEMP

	enum ParserKeywords
	{
		ParserKeyword_If,
		ParserKeyword_ElseIf,
		ParserKeyword_Else,
		ParserKeyword_EndIf,
		ParserKeyword_Define,
		ParserKeyword_Include,
		ParserKeyword_Last,
	};

	enum ParserSymbols
	{
		ParserSymbol_Keyword,
		ParserSymbol_Operator,
		ParserSymbol_Variable,
		ParserSymbol_Text,
		ParserSymbol_Last,
	};

	class ShaderParser
	{
	public:
		ShaderParser();
		~ShaderParser();

		//Parse the file, file name, output buffer
		void Parse(const std::string& t_input, std::string* t_output);

		void NextSymbol();
	private:
		std::string* m_input;
		std::string* m_output;
	};
};