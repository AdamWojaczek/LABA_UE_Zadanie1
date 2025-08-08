#pragma once

#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CIOStream
{
public:
	void ClearScreen();
	
	void Print(const string& text);
	void PrintLine(const string& text);
	void PrintSeparatorLine();
	void WaitForEnter();
	
	void ClearInput();
	bool ReadInt(int& value);
	bool ReadDouble(double& value);
	bool ReadString(string& text);

};

