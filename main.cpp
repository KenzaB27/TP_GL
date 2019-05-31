#include <stdlib.h>
#include "Lecture.h"
#include "Etude.h"

int main()
{
	/*

	TESTS EN COURS ----------- */


	Catalogue* c = new Catalogue();
	Lecture l;
	vector<Capteur> listeCapteurs;
	unordered_map <int, vector<Seuil>> mapSeuil; 
	l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
	l.InitTypeGaz("../../Fichiers/gazTest.csv");
	l.Parcourir(c, "../../Fichiers/fichier1000.csv");
	l.InitSeuils(mapSeuil,"../../Seuils.csv");
	cout << mapSeuil.size() << endl;
	for (auto x : mapSeuil)
	{
		cout << x.first; 
		for (int i = 0; i < 10; i++)
		{
			cout << x.second[i] << endl; 
		}

	}
	unordered_map<IdCatalogue, vector<MesureGaz>> map;
	Date dateD(2017, 01, 01, 0, 1, 20.6090000); 
	Etude e; 
	vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD); 
	cout << "PM10: " << listeConcIndice[PM10];
	cout << "SO2: " << listeConcIndice[SO2];
	cout << "NO2: " << listeConcIndice[NO2];
	cout << "O3: " << listeConcIndice[O3];

	
	system("pause");

	return 0;
}
