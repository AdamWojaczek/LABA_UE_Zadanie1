#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "CIOStream.h"
#include "CStrSupport.h"

using std::string;

enum class EQuestState { ERROR, CLOSE, RUN };

class CApplication
{	
private:	
	const int MIN_QUEST_ID = 1;
	const int MAX_QUEST_ID = 10;

	CIOStream ios;
	CStrSupport ss;

	void ShowMenu();
	EQuestState SelectQuest(int &questId);
	void RunQuest(int questId);
	void CalculateSquareArea();
	void CalculateGradeAverage();
	void CelsiusToFahrenheit();
	void HelloFriend();

public:
	int Run();
};

