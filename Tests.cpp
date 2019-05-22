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
    cout<<m;

    m.setUnite("zizi");
    cout<<m;
}

void TestCatalogue(){
    Date d = Date();
    MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");
    MesureGaz m1 = MesureGaz(0, d, 10, 13, "Capteur13");
    MesureGaz m2 = MesureGaz();

    list<MesureGaz> liste;
    liste.push_back(m);
    liste.push_back(m1);
    liste.push_back(m2);

    IdCatalogue id = IdCatalogue(12, d);

    Catalogue c = Catalogue();

    c.Ajouter(id, liste);

    cout << c;

}

int main(){
    TestMesureGaz();
    TestCatalogue();



}
