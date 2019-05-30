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
	//l.InitSeuils(mapSeuil,"../../Seuils.csv"); 

	unordered_map<IdCatalogue, vector<MesureGaz>> map;
	Date dateD(2017, 01, 01, 0, 1, 20.6090000); 
	/*Etude e; 
	vector <int> capteurs = e.getCapteur(listeCapteurs, 11.9072994016611, 11.9072994016611); 
	for (int i = 0; i < capteurs.size(); i++)
	{
		cout << capteurs[i] << endl; 
	}
	/*vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD); 
	for (int i = 0; i < 4; i++)
	{
		cout << listeConcIndice[i]; 
	}*/
	system("pause");

	return 0;
}
