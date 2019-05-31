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

	Menu m;
	m.init();
	m.run();

/*
    Date d = Date(2019, 02, 01, 10, 12, 55);
    MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");
    MesureGaz m1 = MesureGaz(0, d, 10, 12, "Capteur12");
    //MesureGaz m2 = MesureGaz();

    vector<MesureGaz> liste;
    liste.push_back(m);
	liste.push_back(m1);

	for(int i = 0; i < 2; i++){
		cout << liste[i] << endl;
	}
	
    IdCatalogue id = IdCatalogue(12,d);
    //cout << id;

    Catalogue c;

    c.Ajouter(id, liste);

	//cout << "Reussi l'emplace" <<endl;

	int capteur = c.getMap().find(id)->first.getCapteurId();

	cout<< capteur <<endl;

    int g = c.getMap().find(id)->second[1].getGazId();

    cout << g << endl;
    */

	return 0;
}
