#include "CIOStream.h"

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::ClearScreen()
{
	system("cls");
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::Print(const string& text)
{
	cout << text;
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::PrintLine(const string& text)
{
	cout << text << endl;
}

//---------------------------------------------------------------------------------------------------------------------

void CIOStream::PrintSeparatorLine()
{
	PrintLine("--------------------------------------------------------------");
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
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool CIOStream::ReadInt(int& value)
{
	bool result = false;
	string text;

	try
	{
		std::getline(cin, text);
		value = std::stoi(text);
		result = true;
	}
	catch (const std::exception& e)
	{
		PrintLine("Wprowadzona wartosc nie jest liczba calkowita (" + string(e.what()) + ")!");	
	}

	return result;
}

bool CIOStream::ReadDouble(double& value)
{
	bool result = false;
	string text;

	try
	{
		std::getline(cin, text);

//		std::size_t pos = text.find(',');
//		if (pos != std::string::npos)
//			text.replace(pos, 1, ".");
		
		value = std::stod(text);
		result = true;
	}
	catch (const std::exception& e)
	{
		PrintLine("Wprowadzona wartosc nie jest liczba rzeczywista (" + string(e.what()) + ")!");
	}

	return result;
}

bool CIOStream::ReadString(string& text)
{
	std::getline(cin, text);
	return !text.empty();
}

//---------------------------------------------------------------------------------------------------------------------
