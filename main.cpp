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

void afficheMatSimilarite(bool**matSimilarite) {
	cout << "Matrices de similarite des capteurs " << endl << endl;
	cout << "     |";
	for (int i = 0; i < 10; i++)
	{
		cout << i << "    |";
	}
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << "    |";
		for (int j = 0; j < 10; j++)
		{
			cout << matSimilarite[i][j] << "    |";
		}
		cout << endl;
	}
	cout << endl;
}
void afficheMatMoyenne(unordered_map<int, vector<long double> >moyenneCapteur) {
	cout << "Moyennes des messures de capteurs par gaz" << endl;
	cout << "Capteur n |    O3    |   PM10   |    SO2    |    NO2    |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (auto x : moyenneCapteur)
	{
		cout << x.first << "         |" <<
			x.second[O3] << "   | " <<
			x.second[PM10] << "  | " <<
			x.second[SO2] << "   | " <<
			x.second[NO2] << "   | " << endl;
	}
	cout << endl;
}
void afficheMatEcart( string gaz, long double** matriceEcartGaz , int nbCapteurs=10) {

	cout << "Matrices des ecarts de mesures capteurs pour le gaz " << gaz << endl << endl;
	cout <<  "    |";
	for (int i = 0; i < nbCapteurs; i++)
	{
		cout << i << "      |";
	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < nbCapteurs; i++)
	{
		cout << i << "   |";
		for (int j = 0; j < nbCapteurs; j++)
		{

			if (i == j)
			{
				cout << matriceEcartGaz[i][j] << "      |";
			}
			else
			{
				cout << matriceEcartGaz[i][j] << '|';
			}
		}
		cout << endl;
	}
	cout << endl; 
}
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
	unordered_map<int , vector<long double> > moyenneCapteur = e.MesuresTotParCapteurs(*c, 10);
	afficheMatMoyenne(moyenneCapteur); 
	unordered_map<int, long double**> matriceEcart = e.EcartCapteurs(moyenneCapteur);
	afficheMatEcart("O3", matriceEcart[O3]); 
	afficheMatEcart("PM10", matriceEcart[PM10]);
	afficheMatEcart("SO2", matriceEcart[SO2]);
	afficheMatEcart("NO2", matriceEcart[NO2]);
	bool ** matSimilarite = e.DeterminerCapteursSimilaires(matriceEcart, 10); 
	afficheMatSimilarite(matSimilarite);
	system("pause"); 
	return 0;
}
