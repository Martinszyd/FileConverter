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
		
};


