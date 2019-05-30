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

	



	cout << *c << endl;
	
	system("pause");
	
	return 0;
}