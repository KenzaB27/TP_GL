#include <iostream>
#include "Catalogue.h"
#include "Lecture.h"

int main()
{
	/*

	TESTS EN COURS ----------- */


	Catalogue* c = new Catalogue();
	Lecture l;

	l.InitTypeGaz("../Fichiers/gazTest.csv");
	l.Parcourir(c, "../Fichiers/valuesTest.csv");

	unordered_map<IdCatalogue, vector<MesureGaz>> map;
	map = c->getMap();


	cout << map.size() << endl;

	for (auto itr = map.begin(); itr != map.end(); itr++)
	{
		cout << "index dans le main : " << endl;
		cout << itr->first << endl;

		cout << "valeurs dans le main :" << endl;
		for (int i = 0; i < itr->second.size(); i++)
		{
			cout << itr->second[i] << endl;
		}
	}



	//cout << c << endl;
	
	system("pause");
	
	return 0;
}