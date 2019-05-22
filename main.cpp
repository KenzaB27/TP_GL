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
#include "Gestion.h"
#include "Capteur.h"
#include "PorteeCapteur.h"

//-------------------------------------------------------- Include syst�me
using namespace std;

#include <iostream>
#include <string>

//-------------------------------------------------------- Méthodes publiques

void TestMesureGaz() {
    Date d = Date();
    MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");

    MesureGaz m1 = MesureGaz(0, d, 10, 13, "Capteur13");

    MesureGaz m2 = MesureGaz();

    MesureGaz m3 = MesureGaz(m1);

    cout << m;
    cout << m1;
    cout << m2;
    cout << m3;

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

int main() {
    TestGestion();

}
