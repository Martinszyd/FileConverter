#include<list>
#include "Konwerter.h"
#include "pch.h"
#include "Console.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"



using namespace std;
using namespace rapidxml;

Konwerter::Konwerter(string nazwaPliku)
{
		if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "txt")
		{
			ifstream plik;
			ofstream plikWyjsciowy;
			plik.open(nazwaPliku);
			
			if (plik.good())
			{
				xml_document <> document;
				
				while (!plik.eof()) {
					xml_node <>* row = document.allocate_node(node_element, "row");
					string str;
					getline(plik, str);
					istringstream buf(str);
					document.append_node(row);
					xml_node <>* col = document.allocate_node(node_element, "col");
					for (string word; buf >> word; ) {
						
						string slowo = word;
						cout << slowo.c_str() << endl;
						//col->value();
						xml_node <>* a = document.clone_node(col);
						a->value(slowo.c_str());
						row->append_node(a);
					}
					
				}
				plikWyjsciowy.open("testWyjsciowy.xml");
				cout << document;
				plikWyjsciowy << document;
				plikWyjsciowy.close();
				plik.close();
			}
			else
				throw "Nie uda³o sie otworzyæ pliku";

		}

		else if (nazwaPliku.substr(nazwaPliku.find_last_of(".") + 1) == "xml")
		{
			rapidxml::file<> xmlFile(nazwaPliku.c_str());
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());

			for (xml_node<> *row = doc.first_node();
				row; row = row->next_sibling()){

				for (xml_node<> *col = row->first_node();
					col; col = col->next_sibling()){
					cout << col->value() << " ";
				}
				cout << endl;
			}


		}
		else cout << "Nieprawid³owy plik";
};


