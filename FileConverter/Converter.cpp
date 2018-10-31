#include "pch.h"
#include "Converter.h"
#include <fstream>
#include "Console.cpp"

Converter::Converter()
{
	bool wczytajPlik(std::string nazwaPliku)
	{
		std::ifstream plik;
		plik.open(nazwaPliku.c_str());
		if (!plik.good())
			return false;
	}
	else 
	return true;
}

Converter::~Converter()
{
}
