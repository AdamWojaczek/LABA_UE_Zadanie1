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
			case EQuestState::CLOSE:	close = true;			break;
			case EQuestState::RUN:		RunQuest(questId);		break;
			case EQuestState::ERROR:
			default:
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
	string quests = string("--------------------------------------------------------------") +
					"\n\nTablica zadan:" +
					"\n[1]\tObliczanie pola kwadratu" +
					"\n[2]\tObliczanie sredniej arytmetycznej ocen" +
					"\n[3]\tPrzeliczanie temperatury z Celsjusza na Farenheita" +
					"\n[4]\tCzesc, Witaj, Hej" +
					"\n[5]\tSuma pierwszego i ostatniego elementu tablicy" +
					"\n[6]\tSprawdzanie czy liczba jest wieksza od 100 i parzysta..." +
					"\n[7]\tGra logiczna - sekretna liczba" +
					"\n[8]\tOdwracanie kolejnosci liczb" +
					"\n[9]\tWielokrotne drukowanie imienia" +
					"\n[10]\tWyswietlanie prostokata ze znakow" +
					"\n---" +
					"\n[0]\tKoniec programu!\n";
	ios.PrintLine(quests);
}

//---------------------------------------------------------------------------------------------------------------------

EQuestState CApplication::SelectQuest(int& questId)
{
	EQuestState result = EQuestState::ERROR;
	
	if (ios.ReadInt("Wybierz zadanie:", questId))
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
		case 7:	 GuessTheNumber();				break;
		case 8:	 ReverseData();					break;
		case 9:	 PrintNameMultipleTimes();		break;
		case 10: DrawRectangle();				break;
		
		default:
			ios.PrintLine("Nieprawidlowy numer (" + ss.ValueToStr(questId) + ") zadania");
	}
	
	ios.PrintLine("");
	ios.PrintLine("<<< ZADANIE NR " + ss.ValueToStr(questId) + " <<<");

	ios.WaitForEnter();
}

//---------------------------------------------------------------------------------------------------------------------
// [1] Pobierz od u¿ytkownika d³ugoœæ boku kwadratu i oblicz jego pole, wynik wypisz na ekranie.

void CApplication::CalculateSquareArea()
{	
	double value;
	if (ios.ReadDouble("Podaj dlugosc boku kwadratu (liczba calkowita/rzeczywista) [cm]:", value) && (value > 0))
	{
		double area = value * value;
		string log = "Pole kwadratu o boku " + ss.ValueToStr(value, 1) + " cm " +
					 "wynosi " + ss.ValueToStr(area, 2) + " cm2";
		ios.PrintLine(log);
	}
	else
		ios.PrintLine("Podano nieprawidlowa dlugosc boku kwadratu!");
}

//---------------------------------------------------------------------------------------------------------------------
// [2] Oblicz œredni¹ arytmetyczn¹ 5 ocen pobranych od u¿ytkownika i wynik wypisz na ekranie.

void CApplication::CalculateGradeAverage()
{
	int count;
	if (ios.ReadInt("Podaj liczbe ocen do wyznaczenia sredniej:", count) && (count > 1))
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
				else
					ios.Print("Nieprawidlowa wartosc, powtorz: ");
			} while (!readResult);
		}

		double arithmeticMean = 0.0;
		for (int i = 0; i < count; i++)
			arithmeticMean += grades[i];
		arithmeticMean /= (double)count;

		ios.PrintLine("Srednia z ocena wynosi " + ss.ValueToStr(arithmeticMean, 2) +
					  " (liczba ocen: " + ss.ValueToStr(count) + ")");
	}
	else
		ios.PrintLine("Aby policzyc srednia, nalezy podac przynajmniej 2 oceny");
}

//---------------------------------------------------------------------------------------------------------------------
// [3] Pobierz od u¿ytkownika temperaturê i przelicz j¹ na stopnie Fahrenheita i wynik wypisz na ekranie.

void CApplication::CelsiusToFahrenheit()
{
	double celsius;
	if (ios.ReadDouble("Podaj temperature w stopniach Celsjusza:", celsius))
	{
		double fahrenheit = (celsius * 9.0/5.0) + 32.0;
		string log = "Temperatura " + ss.ValueToStr(celsius, 1) + " st. C == " +
					 ss.ValueToStr(fahrenheit, 1) + " st. F";
		ios.PrintLine(log);
	}
}

//---------------------------------------------------------------------------------------------------------------------
// [4] Pobierz od u¿ytkownika imiê - jeœli imiê to Kamil napisz “Czesc kamil”
// jeœli imiê to Kasia napisz “Witaj Kasia”, dla innych imion napisz “Hej”

void CApplication::HelloFriend()
{
	string name;
	if (ios.ReadString("Jak masz na imie?", name) || !name.empty())
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

//---------------------------------------------------------------------------------------------------------------------
// [5] Zadeklaruj pust¹ tablicê, wprowadŸ dane rêczne a nastêpnie wypisz na ekranie
// sumê pierwszego i ostatniego elementu tablicy.

void CApplication::SumFirstAndLastTabElement()
{
	const unsigned int tabCount = 10;
	int myRandomTable[tabCount] = { 0 };
	
	srand((int)time(nullptr));
	for (unsigned int i = 0; i < tabCount; i++)
		myRandomTable[i] = (int)(rand() % 1000) - 500;

	ios.Print("Moja losowa tablica: ");
	for (unsigned int i = 0; i < tabCount; i++)
		ios.Print("[" + ss.ValueToStr(myRandomTable[i]) + "] ");

	int sum = myRandomTable[0] + myRandomTable[tabCount - 1];
	ios.PrintLine("\nSUMA pierwszego i ostatniego elementu to: " + ss.ValueToStr(sum));
}

//---------------------------------------------------------------------------------------------------------------------
// [6] Pobierz od u¿ytkownika liczbê i sprawdŸ, czy jest wiêksza od 100 i parzysta lub wiêksza od 200
// wypisz na ekranie informacjê zwrotn¹.

void CApplication::CheckUserNumber()
{
	int value;
	if (ios.ReadInt("Podaj liczbe calkowita:", value))
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
// [7] Gra logiczna - zadeklaruj wartoœæ sekretnej liczby(w zakresie 1 - 10), poproœ u¿ytkownika o zgadniêcie liczby
// i wypisz na ekranie informacjê zwrotn¹ (liczba za ma³a, za du¿a, trafi³eœ)

void CApplication::GuessTheNumber()
{
	bool result = false;
	
	srand((int)time(nullptr));
	int secretNumber = (int)(rand() % 10) + 1;
	int counter = 0, number = -1;

	ios.PrintLine("Zgadnij sekretna liczbe calkowita z zakresu od 1 do 10 [0 - koniec gry]");
	while (!result && (number != 0))
	{
		if (ios.ReadInt("Podaj liczbe [proba nr " + ss.ValueToStr(++counter) + "]:", number))
		{
			if ((number > 0) && (number < 11))
			{
				if (number == secretNumber)
				{
					ios.PrintLine("*** Gratuluje! Prawidlowo zgadles sekretna liczbe ***");
					result = true;					
				}
				else if (number > secretNumber)
					ios.PrintLine("[>] Za duza");
				else
					ios.PrintLine("[<] Za mala");
			}
			else if (number == 0)
				ios.PrintLine("Opuszczasz gre...");
			else
				ios.PrintLine("Nieprawidlowa wartosc!");
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
// [8] Wczytaj piêæ liczb od u¿ytkownika i wypisz je na ekranie w odwrotnej kolejnoœci

void CApplication::ReverseData()
{
	const int maxNumbers = 5;
	int numbers[maxNumbers];

	ios.PrintLine("Podaj " + ss.ValueToStr(maxNumbers) + " dowolnych liczb calkowitych [ENTER - zatwierdza]");
	int i = 0;
	while (i < maxNumbers)
	{
		if (ios.ReadInt(numbers[i]))
			i++;	
		else
			ios.Print("Nieprawidlowa wartosc, powtorz: ");
	}
	
	ios.Print("Wprowadzone liczby (od poczatku): ");
	for (int i = 0; i < maxNumbers; i++)
		ios.Print("[" + ss.ValueToStr(numbers[i]) + "] ");
	ios.PrintLine("");
	ios.Print("Wprowadzone liczby (od konca): ");
	for (int i = maxNumbers - 1; i > -1; i--)
		ios.Print("[" + ss.ValueToStr(numbers[i]) + "] ");
	ios.PrintLine("");
}

//---------------------------------------------------------------------------------------------------------------------
// [9] Pobierz od u¿ytkownika imiê i cyfrê, nastêpnie wypisz na ekranie podane imiê podan¹ liczbê razy.

void CApplication::PrintNameMultipleTimes()
{
	string name;	
	int number;
	const int myMax = 50;

	if (ios.ReadString("Podaj imie:", name) &&
		ios.ReadInt("Ile raz wypisac je na ekranie?", number) && (number > 0))
	{			
		if (number <= myMax)
		{
			string row = "", col = "";
			for (int i = 0; i < number; i++)
			{
				row += name + " ";
				col += "\n" + name;
			}
			ios.PrintLine("\n- POZIOMO -\n" + row);
			ios.PrintLine("\n- PIONOWO -" + col);
		}
		else
			ios.PrintLine(ss.ValueToStr(number) + " razy? Bez przesady. Proponuje maksymalnie " +
							ss.ValueToStr(myMax) + " powtorzen.");
	}
	else
		ios.PrintLine("Jak nie chcesz, to nie wypisze");
}

//---------------------------------------------------------------------------------------------------------------------
/* [10] Zapytaj u¿ytkownika o iloœæ wierszy i iloœæ kolumn, a nastêpnie narysuj taki prostok¹t z *
	przyk³ad: 4 wiersze i 3 kolumny
	***
	***
	***
	***
*/

void CApplication::DrawRectangle()
{
	bool result = false;
	int rows = 0, cols = 0;
	char symbol = '*';
	string buffer = "";

	if (ios.ReadInt("Podaj liczbe wierszy [ENTER]:", rows) && (rows > 0) &&
		ios.ReadInt("Podaj liczbe kolumn [ENTER]:", cols) && (cols > 0) &&
		ios.ReadString("Podaj znak wypelnienia [ENTER]:", buffer))
	{
		ss.StrTrim(buffer);
		if (buffer.length() > 0)
		{
			symbol = buffer[0];
			result = true;
		}
	}

	if (result)
	{
		for (int i = 0; i < rows; i++)
		{
			ios.PrintLine("");
			for (int j = 0; j < cols; j++)
				ios.Print(string(1, symbol));
		}
		ios.PrintLine("");
	}
	else
		ios.PrintLine("Podales bledne dane!");
}

//---------------------------------------------------------------------------------------------------------------------
