
#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

using namespace std;

class Console
{
public:
	string nazwaPliku;

	Console();
	string getNazwaPliku() { return nazwaPliku; }

};
#endif

