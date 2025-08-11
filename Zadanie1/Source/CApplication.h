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
1.	Pobierz od u�ytkownika d�ugo�� boku kwadratu i oblicz jego pole, wynik wypisz na ekranie.
2.	Oblicz �redni� arytmetyczn� 5 ocen pobranych od u�ytkownika i wynik wypisz na ekranie.
3.	Pobierz od u�ytkownika temperatur� i przelicz j� na stopnie Fahrenheita i wynik wypisz na ekranie.
4.	Pobierz od u�ytkownika imi� - je�li imi� to Kamil napisz �Czesc kamil� je�li imi� to
	Kasia napisz �Witaj Kasia�, dla innych imion napisz �Hej�
5.	Zadeklaruj pust� tablic�, wprowad� dane r�czne a nast�pnie wypisz na ekranie sum� pierwszego
	i ostatniego elementu tablicy.
6.	Pobierz od u�ytkownika liczb� i sprawd�, czy jest wi�ksza od 100 i parzysta
	lub wi�ksza od 200 - wypisz na ekranie informacj� zwrotn�.
7.	Gra logiczna - zadeklaruj warto�� sekretnej liczby (w zakresie 1-10), popro� u�ytkownika o zgadni�cie liczby
	i wypisz na ekranie informacj� zwrotn� (liczba za ma�a, za du�a, trafi�e�)
8.	Wczytaj pi�� liczb od u�ytkownika i wypisz je na ekranie w odwrotnej kolejno�ci
9.	Pobierz od u�ytkownika imi� i cyfr�, nast�pnie wypisz na ekranie podane imi� podan� liczb� razy.
10.	Zapytaj u�ytkownika o ilo�� wierszy i ilo�� kolumn, a nast�pnie narysuj taki prostok�t z *
	przyk�ad: 4 wiersze i 3 kolumny
	* * *
	* * *
	* * *
	* * *
*/