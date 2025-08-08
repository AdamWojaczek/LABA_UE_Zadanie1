#include "CStrSupport.h"

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::ValueToStr(int value)
{
	char buf[50] = { 0 };
	sprintf_s(buf, sizeof(buf) / sizeof(char), "%d", value);
	return string(buf);
}

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::ValueToStr(unsigned int value)
{
	char buf[50] = { 0 };
	sprintf_s(buf, sizeof(buf) / sizeof(char), "%u", value);
	return string(buf);
}

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::ValueToStr(double value, unsigned int precision)
{
	if (precision > 15)
		precision = 15;

	char buf[50] = { 0 };
	string mold = string("%.") + ValueToStr(precision) + string("f");
	sprintf_s(buf, sizeof(buf) / sizeof(char), mold.c_str(), value);

	return string(buf);
}

//---------------------------------------------------------------------------------------------------------------------

bool CStrSupport::StrCompareIC(const string& text1, const string& text2)
{
	bool result = false;

	string t1 = StrToUpper(StrTrim(text1));
	string t2 = StrToUpper(StrTrim(text2));

	result = (t1 == t2);

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::StrToUpper(const string& text)
{
	string upperText = "";

	for (int i = 0; i < text.length(); i++)
		upperText += std::toupper(text[i]);

	return upperText;
}

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::StrTrim(const string& text)
{
	string trmText = text;

	trmText.erase(0, trmText.find_first_not_of(" \n\r\t"));
	trmText.erase(trmText.find_last_not_of(" \n\r\t") + 1);

	return trmText;
}

//---------------------------------------------------------------------------------------------------------------------
