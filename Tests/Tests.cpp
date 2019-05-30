/*************************************************************************
                           Tests  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <MesureGaz> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Tests.h"
#include "../MesureGaz.h"
#include "../IdCatalogue.h"
#include "../Catalogue.h"
#include "../Gestion.h"
#include "../Capteur.h"
#include "../PorteeCapteur.h"

//-------------------------------------------------------- Include syst�me
using namespace std;

//#include <iostream>
//#include <string>
#include <iterator> 
#include <list>
#include <unordered_map>


//-------------------------------------------------------- Méthodes publiques

void Tests::TestMesureGaz(){
    Date d = Date(2019, 02, 01, 10, 12, 55);
    MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");

    MesureGaz m1 = MesureGaz(0, d, 10, 13, "Capteur13");

    MesureGaz m2 = MesureGaz();

    cout << m;
    cout << m1;
    cout << m2;

    m.setValeur(23);
    cout << m;

    m.setDescription("Salut");
    cout << m;

    m.setUnite("zizi");
    cout << m;
}

void Tests::TestGestion() {
    Capteur c1 = Capteur(1, "d", 12.012, 32.002);
    Capteur c2 = Capteur(2, "d", 12.012, 32.002);
    Capteur c3 = Capteur(3, "d", 12.012, 32.002);
    Capteur c4 = Capteur(4, "d", 12.012, 32.002);

    vector <Capteur> v;
    Gestion g;
    v.push_back(c1);
    g.AjouterCapteur(c2, v);
    g.AjouterCapteur(c3, v);
    g.MettreEnVeilleCapteur(3,v);


    for (vector<Capteur>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->getEtat() << endl;
        //process on el...
    }


    for (vector<Capteur>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->getEtat() << endl;
        //process on el...
    }
}
/*
void Tests::TestCatalogue(){
    Date d = Date(2019, 02, 01, 10, 12, 55);
    MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");
    MesureGaz m1 = MesureGaz(0, d, 10, 12, "Capteur12");
    //MesureGaz m2 = MesureGaz();

    list<MesureGaz> liste;
    liste.push_back(m);
    liste.push_back(m1);
    //liste.push_back(m2);

    IdCatalogue id = IdCatalogue(12,d);
    cout << id;

    Catalogue c;

    c.getMap().emplace(id, liste);

    cout << c << endl;

}*/


void Tests::TestChangerSeuil()

{
    unordered_map<string,list<Seuil>> umap;
    list<Seuil> PM10;
    list<Seuil> SO2;
    list<Seuil> NO2;
    list<Seuil> O3;

    for(int i=0;i<10;i++)
    {
        PM10.push_back(Seuil(i,i,i));
        SO2.push_back(Seuil(i,i,i));
        NO2.push_back(Seuil(i,i,i));
        O3.push_back(Seuil(i,i,i));
    }

    umap.insert(make_pair("PM10",PM10));
    umap.insert(make_pair("SO2",SO2));
    umap.insert(make_pair("NO2",NO2));
    umap.insert(make_pair("O3",O3));

    for (list<Seuil>::iterator it = umap["PM10"].begin(); it != umap["PM10"].end(); ++it) {
        cout <<"d"<<endl;
    }
}



int main() {
	//TestMesureGaz();
	//TestCatalogue();
	//TestChangerSeuil();

	return 0;


}