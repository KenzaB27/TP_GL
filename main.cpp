#include <stdlib.h>
#include "Lecture.h"

int main()
{
	/*

	TESTS EN COURS ----------- */


	Catalogue* c = new Catalogue();
	Lecture l;
	vector<Capteur> listeCapteurs;
	l.InitCapteur(listeCapteurs, "../..capteurs.csv");
	l.InitTypeGaz("../../Fichiers/gazTest.csv");
	l.Parcourir(c, "../../Fichiers/fichier1000.csv");

	unordered_map<IdCatalogue, vector<MesureGaz>> map;

	for (int i = 0; i < listeCapteurs.size(); ++i)
	{
		//cout << listeCapteurs[i] << endl;
	}

	system("pause");

	return 0;
}
