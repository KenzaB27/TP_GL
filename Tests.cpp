/*************************************************************************
                           Tests  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <MesureGaz> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Tests.h"
#include "MesureGaz.h"
#include "IdCatalogue.h"
#include "Catalogue.h"
#include "Gestion.h"
#include "Capteur.h"
#include "PorteeCapteur.h"

//-------------------------------------------------------- Include syst�me
using namespace std;

#include <iostream>
#include <string>
#include <iterator> 
#include <list>


//-------------------------------------------------------- Méthodes publiques

void TestMesureGaz(){
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

void TestGestion() {
    Capteur c1 = Capteur(1, "d", 12.012, 32.002);
    Capteur c2 = Capteur(2, "d", 12.012, 32.002);
    Capteur c3 = Capteur(3, "d", 12.012, 32.002);
    Capteur c4 = Capteur(4, "d", 12.012, 32.002);

    vector <Capteur> v;
    Gestion g;
    v.push_back(c1);
    g.ajouterCapteur(c2, v);
    g.ajouterCapteur(c3, v);
    g.mettreEnVeilleCapteur(c3,v);


    for (vector<Capteur>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->getEtat() << endl;
        //process on el...
    }


    for (vector<Capteur>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->getEtat() << endl;
        //process on el...
    }
}

void TestCatalogue(){
    Date d(2019, 2, 1, 10, 12, 55);
   // cout<<d<<endl;
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

    c.Ajouter(id, liste);
    cout<< c.map.find(id)<<endl;

    cout << c << endl;

}

int main(){
    //TestMesureGaz();
    TestCatalogue();
}
