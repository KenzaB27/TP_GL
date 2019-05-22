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

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//-------------------------------------------------------- Méthodes publiques

void TestMesureGaz(){
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
    cout<<m;

    m.setUnite("zizi");
    cout<<m;
}

int main(){
    TestMesureGaz();

}
