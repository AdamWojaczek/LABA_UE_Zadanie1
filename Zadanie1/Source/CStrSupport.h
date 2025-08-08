#pragma once

#include <string>
using std::string;

class CStrSupport
{
public:
	string ValueToStr(int value);
	string ValueToStr(unsigned int value);
	string ValueToStr(double value, unsigned int precision = 2);
	bool StrCompareIC(const string& text1, const string& text2);
	string StrToUpper(const string& text);
	string StrTrim(const string& text);
};

