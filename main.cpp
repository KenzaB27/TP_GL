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
	unordered_map<IdCatalogue, vector<MesureGaz>> map;
	Date dateD(2019, 01, 01, 0, 1, 20.6090000);
	Etude e;
	vector<int> listeIdCapteur = e.getCapteur(listeCapteurs, 11.9072994016611, 18.2016632092193, 1000000);
	vector<ConcentrationIndice> listeConcIndice = e.evaluer(*c, listeIdCapteur,mapSeuil,dateD);
	int atmo = e.CalculAtmo(listeConcIndice); 
	if (atmo!=0)
	{
		cout << "PM10: " << listeConcIndice[PM10];
		cout << "SO2: " << listeConcIndice[SO2];
		cout << "NO2: " << listeConcIndice[NO2];
		cout << "O3: " << listeConcIndice[O3];


		cout << "L'atmo au point au 01-01-2017 est : " << atmo << endl;
	}

	
	/*for (int i = 0; i < listeIdCapteur.size(); i++)
	{
		cout << listeIdCapteur[i]; 
	}*/
	system("pause");
   

	
	return 0;
}
