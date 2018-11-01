#include "main.h"
#include "OdczytPliku.h"
#include "Console.h"
#include "Console.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml.hpp"

using namespace std;

OdczytPliku::OdczytPliku()
{

		if (nazwaPliku.find("txt"))
		{
			ifstream plik;
			plik.open(nazwaPliku);
			if (plik.good())
			{
				int cyfry;
				plik >> cyfry;
				string wyrazy;
				plik >> wyrazy;
				plik.close();
			}
			else
				cout << "Nie uda³o sie otworzyæ pliku" << std::endl;
		}
		if (nazwaPliku.find("xml"))
		{

		}
}


