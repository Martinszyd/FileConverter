#include "KonwerterXML.h"
#include "Console.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

KonwerterXML::KonwerterXML(string nazwaPliku)
{
	ifstream plik;
	ofstream plikWyjsciowy;

	file<> xmlFile(nazwaPliku.c_str());
	xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	plikWyjsciowy.open("testWyjsciowy.txt");
	for (xml_node<> *row = doc.first_node();
		row; row = row->next_sibling()) {

		for (xml_node<> *col = row->first_node();
			col; col = col->next_sibling()) {
			plikWyjsciowy << col->value() << " ";
		}
		plikWyjsciowy << endl;
	}
	plikWyjsciowy.close();
}

