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
	void SumFirstAndLastTabElement();
	void CheckUserNumber();
	void GuessTheNumber();
	void ReverseData();
	void PrintNameMultipleTimes();
	void DrawRectangle();

public:
	int Run();
};

/*
1.	Pobierz od u¿ytkownika d³ugoœæ boku kwadratu i oblicz jego pole, wynik wypisz na ekranie.
2.	Oblicz œredni¹ arytmetyczn¹ 5 ocen pobranych od u¿ytkownika i wynik wypisz na ekranie.
3.	Pobierz od u¿ytkownika temperaturê i przelicz j¹ na stopnie Fahrenheita i wynik wypisz na ekranie.
4.	Pobierz od u¿ytkownika imiê - jeœli imiê to Kamil napisz “Czesc kamil” jeœli imiê to
	Kasia napisz “Witaj Kasia”, dla innych imion napisz “Hej”
5.	Zadeklaruj pust¹ tablicê, wprowadŸ dane rêczne a nastêpnie wypisz na ekranie sumê pierwszego
	i ostatniego elementu tablicy.
6.	Pobierz od u¿ytkownika liczbê i sprawdŸ, czy jest wiêksza od 100 i parzysta
	lub wiêksza od 200 - wypisz na ekranie informacjê zwrotn¹.
7.	Gra logiczna - zadeklaruj wartoœæ sekretnej liczby (w zakresie 1-10), poproœ u¿ytkownika o zgadniêcie liczby
	i wypisz na ekranie informacjê zwrotn¹ (liczba za ma³a, za du¿a, trafi³eœ)
8.	Wczytaj piêæ liczb od u¿ytkownika i wypisz je na ekranie w odwrotnej kolejnoœci
9.	Pobierz od u¿ytkownika imiê i cyfrê, nastêpnie wypisz na ekranie podane imiê podan¹ liczbê razy.
10.	Zapytaj u¿ytkownika o iloœæ wierszy i iloœæ kolumn, a nastêpnie narysuj taki prostok¹t z *
	przyk³ad: 4 wiersze i 3 kolumny
	* * *
	* * *
	* * *
	* * *
*/