#pragma once
#include <iostream>
#include <ctime>

/*----------------------------------------------*/
/*       Secundary Methods - Parser.h			*/
/*----------------------------------------------*/


class Parser {

	public:

		Parser();
		~Parser();
	
		static std::string WCharToString(const wchar_t &Value, const unsigned int &MaxCount) {

			if (Value == NULL)
				return NULL;

			char string[30];
			size_t bytesconverted = 0;

			wcstombs_s(&bytesconverted, string, &Value, MaxCount);

			std::string result(string);
			result.resize(bytesconverted);

			return result;
		};

		static wchar_t CharToWchar(const std::string &Value) {

			wchar_t wchartemp = NULL;
			size_t CharConverteds = 0;

			mbstowcs_s(&CharConverteds, &wchartemp, Value.size(), Value.c_str(), Value.size());
			return wchartemp;
		}
};
