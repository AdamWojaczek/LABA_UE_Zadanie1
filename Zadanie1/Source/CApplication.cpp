#include "CApplication.h"

//---------------------------------------------------------------------------------------------------------------------

int CApplication::Run()
{
	bool close = false;
	
	while (!close)
	{
		ShowMenu();
		
		int questId;
		EQuestState questState = SelectQuest(questId);
		switch (questState)
		{
			case EQuestState::CLOSE:
				close = true;
				break;

			case EQuestState::RUN:
				RunQuest(questId);
				break;

			case EQuestState::ERROR: default:
				ios.PrintLine("Wybrano nieprawidlowy numer zadania!");
				ios.WaitForEnter();
		}
	}

	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

void CApplication::ShowMenu()
{
	ios.ClearScreen();
	ios.PrintLine("Kurs Unreal Engine: Zadanie praktyczne 1 - Wprowadzenie do C++");
	ios.PrintSeparatorLine();
	ios.PrintLine("");
	ios.PrintLine("Tablica zadan:");
	ios.PrintLine("[1]\tObliczanie pola kwadratu");
	ios.PrintLine("[2]\tObliczanie sredniej arytmetycznej ocen uzytkownikow");
	ios.PrintLine("[3]\tPrzeliczanie temperatury z Celsjusza na Farenheita");
	ios.PrintLine("[4]\tCzesc Kamil, Kasia, a moze Hej...");
	ios.PrintLine("[5]\tSuma pierwszego i ostatniego elementu tablicy");
	ios.PrintLine("[6]\tSprawdzanie czy liczba jest wieksza od 100 i parzysta...");
	ios.PrintLine("[7]\tGra logiczna - sekretna liczba");
	ios.PrintLine("[8]\tOdwracanie kolejnosc liczb");
	ios.PrintLine("[9]\tPowielanie imienia uzytkownika");
	ios.PrintLine("[10]\tWyswietlanie prostokata ze znakow");
	ios.PrintLine("---");
	ios.PrintLine("[0]\tKoniec programu!");
	ios.PrintLine("");
}

//---------------------------------------------------------------------------------------------------------------------

EQuestState CApplication::SelectQuest(int& questId)
{
	EQuestState result = EQuestState::ERROR;
	ios.Print("Wybierz zadanie: ");
	
	if (ios.ReadInt(questId))
	{
		if (questId == 0)
			result = EQuestState::CLOSE;			
		else if ((questId >= MIN_QUEST_ID) && (questId <= MAX_QUEST_ID))
			result = EQuestState::RUN;
		else
		{
			questId = -1;
			result = EQuestState::ERROR;
		}
	}

	return result;
}

//---------------------------------------------------------------------------------------------------------------------

void CApplication::RunQuest(int questId)
{
	ios.PrintLine("");
	ios.PrintLine(">>> ZADANIE NR " + ss.ValueToStr(questId) + " >>>");
	ios.PrintLine("");

	switch (questId)
	{
		case 1:  CalculateSquareArea();			break;
		case 2:	 CalculateGradeAverage();		break;
		case 3:	 CelsiusToFahrenheit();			break;
		case 4:	 HelloFriend();					break;
		case 5:	 SumFirstAndLastTabElement();	break;
		case 6:	 CheckUserNumber();				break;	
		case 7:	 ios.PrintLine("Zadanie numer (" + ss.ValueToStr(questId) + ") jest w opracowaniu...");	break;
		case 8:	 ios.PrintLine("Zadanie numer (" + ss.ValueToStr(questId) + ") jest w opracowaniu...");	break;
		case 9:	 ios.PrintLine("Zadanie numer (" + ss.ValueToStr(questId) + ") jest w opracowaniu...");	break;
		case 10: ios.PrintLine("Zadanie numer (" + ss.ValueToStr(questId) + ") jest w opracowaniu...");	break;
		
		default:
			ios.PrintLine("Nieprawidlowy numer (" + ss.ValueToStr(questId) + ") zadania");
	}
	ios.PrintLine("");
	ios.PrintLine("<<< ZADANIE NR " + ss.ValueToStr(questId) + " <<<");
	ios.PrintLine("");
	ios.WaitForEnter();
}


// [1] Pobierz od u¿ytkownika d³ugoœæ boku kwadratu i oblicz jego pole, wynik wypisz na ekranie.	
void CApplication::CalculateSquareArea()
{	
	ios.Print("Podaj dlugosc boku kwadratu (liczba calkowita/zmiennoprzecinkowa) [cm]: ");
	
	double value;
	if (ios.ReadDouble(value))
	{
		if (value > 0)
		{
			double area = value * value;
			string log = "Pole kwadratu o boku " + ss.ValueToStr(value, 2) + " cm " +
						 "wynosi " + ss.ValueToStr(area, 2) + " cm2";
			ios.PrintLine(log);
		}
		else
			ios.PrintLine("Podano nieprawidlowa dlugosc boku kwadratu!");
	}
}

// [2] Oblicz œredni¹ arytmetyczn¹ 5 ocen pobranych od u¿ytkownika i wynik wypisz na ekranie.
void CApplication::CalculateGradeAverage()
{
	ios.Print("Podaj liczbe ocen: ");
	int count;
	if (ios.ReadInt(count))
	{
		if (count > 1)
		{
			ios.PrintLine("Oceny podajemy w skali od 0.0 do 10.0");
			std::vector<double> grades(count);
			for (int i = 0; i < count; i++)
			{
				ios.Print("Ocena nr " + ss.ValueToStr(i + 1) + ": ");
				bool readResult;
				double grade;
				do
				{
					readResult = ios.ReadDouble(grade) ? ((grade >= 0.0) && (grade <= 10.0)) : false;
					if (readResult)
						grades[i] = grade;

				} while (!readResult);
			}

			double average = 0.0;
			for (int i = 0; i < count; i++)
				average += grades[i];
			average /= (double)count;

			ios.PrintLine("Srednia z ocena wynosi " + ss.ValueToStr(average, 3) + " (liczba ocen: " + ss.ValueToStr(count) + ")");
		}
		else
			ios.PrintLine("Aby policzyc srednia, nalezy podac prezynajmniej 2 oceny");
	}
}

// [3] Pobierz od u¿ytkownika temperaturê i przelicz j¹ na stopnie Fahrenheita i wynik wypisz na ekranie.
void CApplication::CelsiusToFahrenheit()
{
	ios.Print("Podaj temperature w stopniach Celsjusza: ");

	double celsius;
	if (ios.ReadDouble(celsius))
	{
		double fahrenheit = (celsius * 9.0/5.0) + 32.0;
		string log = "Temperatura " + ss.ValueToStr(celsius, 1) + " st. C to " + ss.ValueToStr(fahrenheit, 1) + " st. F";
		ios.PrintLine(log);
	}
}

// [4] Pobierz od u¿ytkownika imiê - jeœli imiê to Kamil napisz “Czesc kamil”
// jeœli imiê to Kasia napisz “Witaj Kasia”, dla innych imion napisz “Hej”
void CApplication::HelloFriend()
{
	ios.Print("Jak masz na imie? ");
	string name;
	if (ios.ReadString(name) || !name.empty())
	{
		if (ss.StrCompareIC(name, "Kamil"))
			ios.PrintLine("Czesc Kamil");
		else if (ss.StrCompareIC(name, "Kasia"))
			ios.PrintLine("Witaj Kasia");
		else
			ios.PrintLine("Hej " + name);
	}
	else
		ios.PrintLine("Nie podales imienia!");
}

// [5] Zadeklaruj pust¹ tablicê, wprowadŸ dane rêczne a nastêpnie wypisz na ekranie
// sumê pierwszego i ostatniego elementu tablicy.
void CApplication::SumFirstAndLastTabElement()
{
	const unsigned int tabCount = 10;
	int myRandomTable[tabCount] = { 0 };
	
	srand(time(nullptr));
	for (unsigned int i = 0; i < tabCount; i++)
		myRandomTable[i] = (int)(rand() % 1000) - 500;

	ios.Print("Moja losowa tablica: ");
	for (unsigned int i = 0; i < tabCount; i++)
		ios.Print("[" + ss.ValueToStr(myRandomTable[i]) + "] ");

	int sum = myRandomTable[0] + myRandomTable[tabCount - 1];
	ios.PrintLine("\nSUMA pierwszego i ostatniego elementu to: " + ss.ValueToStr(sum));
}

// [6] Pobierz od u¿ytkownika liczbê i sprawdŸ, czy jest wiêksza od 100 i parzysta lub wiêksza od 200
// wypisz na ekranie informacjê zwrotn¹.
void CApplication::CheckUserNumber()
{
	ios.Print("Podaj liczbe calkowita (przytniemy czesc dziesietna): ");
	int value;
	if (ios.ReadInt(value))
	{
		if ((value > 100) && (value % 2 == 0))
			ios.PrintLine("Podana liczba jest WIEKSZA od 100 i PARZYSTA");
		else if (value > 200)
			ios.PrintLine("Podana liczba jest WIEKSZA od 200");
		else if (value > 0)
			ios.PrintLine("Podana liczba jest DODATNIA");
		else if (value < 0)
			ios.PrintLine("Podana liczba jest UJEMNA");
		else if (value == 0)
			ios.PrintLine("Podana liczba to ZERO");
		else
			ios.PrintLine("Tutaj nie wejdziemy :)");
	}
}

//---------------------------------------------------------------------------------------------------------------------
