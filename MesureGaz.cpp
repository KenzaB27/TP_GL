/*************************************************************************
                           MesureGaz  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <MesureGaz> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "MesureGaz.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques

id MesureGaz ::getAttributId(){
    return attributId;
}

string MesureGaz::getUnite(){
    return unite;
}

string MesureGaz::getDescription(){
    return description;
}

date MesureGaz::getDate(){
    return Date;
}

double MesureGaz::getValeur(){
    return valeur;
}
 
//-------------------------------------------- Constructeurs - destructeur
MesureGaz::MesureGaz ( const MesureGaz & unMesureGaz )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <MesureGaz>" << endl;
    #endif



} //----- Fin de MesureGaz (constructeur de copie)


MesureGaz::MesureGaz (id typegaz, string u, string d, date hr, double v)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <MesureGaz>" << endl;
    #endif
    attributId=typegaz; //(doit faire partie de l'enum) 
    unite = u;
    description=d;
    Date = hr;
    valeur = v;

} //----- Fin de MesureGaz

MesureGaz::MesureGaz(){
    //Constructeur par défaut ------ l'objet est vide
}

MesureGaz::~MesureGaz ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureGaz>" << endl;
#endif
} //----- Fin de ~MesureGaz


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
