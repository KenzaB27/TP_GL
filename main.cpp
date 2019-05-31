#include <stdlib.h>
#include "Lecture.h"
#include "Menu.h"
//#include "Tests.h"
#include "MesureGaz.h"
#include "IdCatalogue.h"
#include "Catalogue.h"
#include "Gestion.h"
#include "Capteur.h"
#include "PorteeCapteur.h"
#include <vector>
#include <algorithm>

int main()
{
/*
	Menu m;
	m.init();
	m.run();*/

    
	Catalogue* c = new Catalogue();
	Lecture l;
	vector<Capteur> listeCapteurs;
	unordered_map <int, vector<Seuil>> mapSeuil;
	l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
	l.InitTypeGaz("../../Fichiers/gazTest.csv");
	l.Parcourir(c, "../../Fichiers/fichier1000.csv");
	l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");

	cout << mapSeuil.size() << endl;
	/*for (auto x : mapSeuil)
	{
		cout << x.first;
		for (int i = 0; i < 10; i++)
		{
			cout << x.second[i] << endl;
		}

	}*/
	Etude e; 
	unordered_map<int , vector<int> >capteursSimilaires = e.MesuresTotParCapteurs(*c, 10);
	cout << capteursSimilaires.size() << endl; 
	for (auto x : capteursSimilaires)
	{
		cout << "Capteur n:" << x.first   << " Compteur de mesures: " << x.second[4]<< endl ; 
		cout << "O3 " <<(double) x.second[O3]/ x.second[4] << "-";
		cout << "PM10 " << (double)x.second[PM10] / x.second[4] << "-";
		cout << "SO2 " << (double)x.second[SO2] / x.second[4] << "-";
		cout << "NO2 " << (double)x.second[NO2] / x.second[4] << endl;
	}


	system("pause"); 
	return 0;
}
