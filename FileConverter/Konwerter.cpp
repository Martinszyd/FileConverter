#include "Konwerter.h"
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

Konwerter::Konwerter(string nazwaPliku)
{
	ifstream plik;
	ofstream plikWyjsciowy;

		if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "txt")
		{
			plik.open(nazwaPliku);
			
			if (plik.good())
			{
				xml_document <> document;
				
				while (!plik.eof()) 
				{
					xml_node <>* row = document.allocate_node(node_element, "row");
					string str;
					getline(plik, str);
					istringstream buf(str);
					document.append_node(row);
					for (string word; buf >> word; ) 
					{
						xml_node <>* col = document.allocate_node(node_element, "col");
						col->value(document.allocate_string(word.c_str()));
						row->append_node(col);
					}

				}
				plikWyjsciowy.open("testWyjsciowy.xml");
				plikWyjsciowy << document;
				plikWyjsciowy.close();
				plik.close();
			}
			else
				throw "Nie uda³o sie otworzyæ pliku";
		}
			
		else if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "xml")
		{

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
		else
			throw "Nie odnaleziono pliku o takiej nazwie";
};


