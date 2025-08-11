#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "CStrSupport.h"

using std::string;

//---------------------------------------------------------------------------------------------------------------------

class CIOStream
{
private:
	CStrSupport ss;

public:
	void ClearScreen();
	
	void Print(const string& text);
	void PrintLine(const string& text);
	void WaitForEnter();
	
	void ClearInput();
	
	bool ReadInt(int& value);
	bool ReadInt(const string& info, int& value);
	
	bool ReadDouble(double& value);
	bool ReadDouble(const string& info, double& value);
	
	bool ReadString(string& text);
	bool ReadString(const string& info, string& text);
};

//---------------------------------------------------------------------------------------------------------------------
