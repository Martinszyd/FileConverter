#include "Console.h"
#include <iostream>
#include <string>
#include "Konwerter.h"
//#include "KonwerterXML.h"


using namespace std;

Console::Console() {
	cout << "Wpisz nazwê pliku";
	cin >> nazwaPliku;
	/*
	if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "txt")
	{
		Konwerter::Konwerter(nazwaPliku);
	}

	else if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "xml")
	{
		KonwerterXML::KonwerterXML(nazwaPliku);
	}

	else
		throw "Nie odnaleziono pliku o takiej nazwie"; */
}