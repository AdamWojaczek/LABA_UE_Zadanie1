#include "CStrSupport.h"

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::ValueToStr(int value)
{
	char buf[50] = { 0 };
	sprintf_s(buf, sizeof(buf) / sizeof(char) - 1, "%d", value);
	return string(buf);
}

//---------------------------------------------------------------------------------------------------------------------

string CStrSupport::ValueToStr(double value, unsigned int precision)
{
	if (precision > 15)
		precision = 15;

	char buf[50] = { 0 };
	string pattern = string("%.") + ValueToStr((int)precision) + string("f");
	sprintf_s(buf, sizeof(buf) / sizeof(char) - 1, pattern.c_str(), value);

	return string(buf);
}

//---------------------------------------------------------------------------------------------------------------------

bool CStrSupport::StrToInt(const string& text, int& value)
{
	bool result = false;

	try
	{
		value = std::stoi(text);
		result = true;
	}
	catch (const std::exception)
	{
	}

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

bool CStrSupport::StrToDouble(const string& text, double& value)
{
	bool result = false;
	string textCopy = text;

	Replace(textCopy, ',', '.');
	try
	{			
		value = std::stod(textCopy);
		result = true;
	}
	catch (const std::exception)
	{
		if (Replace(textCopy, '.', ',') > 0)
		{
			try
			{
				value = std::stod(textCopy);
				result = true;
			}
			catch (const std::exception)
			{
			}
		}
	}

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

bool CStrSupport::StrCompareIC(const string& text1, const string& text2)
{
	string t1 = text1, t2 = text2;

	StrTrim(t1);
	StrToUpper(t1);

	StrTrim(t2);
	StrToUpper(t2);

	return (t1 == t2);
}

//---------------------------------------------------------------------------------------------------------------------

void CStrSupport::StrToUpper(string& text)
{
	for (int i = 0; i < text.length(); i++)
		text[i] = std::toupper(text[i]);
}

//---------------------------------------------------------------------------------------------------------------------

void CStrSupport::StrTrim(string& text)
{
	text.erase(0, text.find_first_not_of(" \n\r\t"));
	text.erase(text.find_last_not_of(" \n\r\t") + 1);
}

//---------------------------------------------------------------------------------------------------------------------

int CStrSupport::Replace(string& text, char oldChar, char newChar)
{
	int counter = 0;
	std::size_t pos;
	
	do
	{
		pos = text.find(oldChar);
		if (pos != std::string::npos)
		{
			text.replace(pos, 1, string(1, newChar));
			counter++;
		}
	} while (pos != std::string::npos);

	return counter;
}

//---------------------------------------------------------------------------------------------------------------------
