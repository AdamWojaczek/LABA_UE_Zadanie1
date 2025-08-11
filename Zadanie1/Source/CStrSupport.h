#pragma once

#include <string>
using std::string;

//---------------------------------------------------------------------------------------------------------------------

class CStrSupport
{
public:
	string ValueToStr(int value);
	string ValueToStr(double value, unsigned int precision = 2);
	
	bool StrToInt(const string& text, int& value);
	bool StrToDouble(const string& text, double& value);

	bool StrCompareIC(const string& text1, const string& text2);
	
	void StrToUpper(string& text);
	void StrTrim(string& text);
	int Replace(string& text, char oldChar, char newChar);
};

//---------------------------------------------------------------------------------------------------------------------
