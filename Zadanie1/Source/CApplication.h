#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "CIOStream.h"
#include "CStrSupport.h"

using std::string;

enum class EQuestState { ERROR, CLOSE, RUN };

//---------------------------------------------------------------------------------------------------------------------

class CApplication
{	
private:	
	const int MIN_QUEST_ID = 1;
	const int MAX_QUEST_ID = 10;

	CIOStream ios;							// nak³adka na operacje we/wy
	CStrSupport ss;							// operacje pomocnicze na std::string

	void ShowMenu();
	EQuestState SelectQuest(int &questId);
	void RunQuest(int questId);

	// metody realizuj¹ce poszczególne zadania
	void CalculateSquareArea();
	void CalculateGradeAverage();
	void CelsiusToFahrenheit();
	void HelloFriend();
	void SumFirstAndLastTabElement();
	void CheckUserNumber();
	void GuessTheNumber();
	void ReverseData();
	void PrintNameMultipleTimes();
	void DrawRectangle();

public:
	int Run();
};

//---------------------------------------------------------------------------------------------------------------------
