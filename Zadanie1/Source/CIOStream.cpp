#include "CIOStream.h"

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::ClearScreen()
{
	system("cls");
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::Print(const string& text)
{
	std::cout << text;
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::PrintLine(const string& text)
{
	std::cout << text << std::endl;
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::WaitForEnter()
{
	PrintLine("Nacisnij ENTER...");
	ClearInput();
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::ClearInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadInt(int& value)
{
	bool result = false;
	string text;

	if (ReadString(text) && ss.StrToInt(text, value))
		result = true;
	else
		PrintLine("Wprowadzona wartosc jest pusta lub nie jest liczba calkowita!");

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadInt(const string& info, int& value)
{
	Print(info + " ");
	return ReadInt(value);
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadDouble(double& value)
{
	bool result = false;
	string text;
	
	if (ReadString(text) && ss.StrToDouble(text, value))
		result = true;
	else
		PrintLine("Wprowadzona wartosc jest pusta lub nie jest liczba rzeczywista!");

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadDouble(const string& info, double& value)
{
	Print(info + " ");
	return ReadDouble(value);
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadString(string& text)
{
	std::getline(std::cin, text);
	return !text.empty();
}

//---------------------------------------------------------------------------------------------------------------------

bool CIOStream::ReadString(const string& info, string& text)
{
	Print(info + " ");
	return ReadString(text);
}

//---------------------------------------------------------------------------------------------------------------------
