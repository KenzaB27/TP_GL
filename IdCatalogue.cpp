/*************************************************************************
                           IdCatalogue  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <IdCatalogue> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Date.h"
#include "IdCatalogue.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques
//-------------------------------------------- Constructeurs - destructeur
IdCatalogue::IdCatalogue ( const IdCatalogue & unIdCatalogue )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <IdCatalogue>" << endl;
    #endif
} //----- Fin de IdCatalogue (constructeur de copie)


IdCatalogue::IdCatalogue(int cI, Date dm)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <IdCatalogue>" << endl;
    #endif
    capteurId=cI;
    dateMesure=dm;

} //----- Fin de IdCatalogue

IdCatalogue::IdCatalogue(){
    //Constructeur par défaut ------ l'objet est vide
}

IdCatalogue::~IdCatalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IdCatalogue>" << endl;
#endif
} //----- Fin de ~IdCatalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
