/*************************************************************************
                           Capteur  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Capteur.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques

int Capteur::getCapteurId()
{
    return capteurId;
}

string Capteur::getDescription()
{
    return description;
}

int Capteur::getLatitude()
{
    return latitude;
}

int Capteur::getLongitude()
{
    return longitude;
}

int Capteur::getEtat()
{
    return etat;
}

//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur ( const Capteur & unCapteur )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Capteur>" << endl;
    #endif



} //----- Fin de Capteur (constructeur de copie)


Capteur::Capteur (int capteurid, string d, double lat, double lon)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif

    capteurId=capteurid;
    description = d;
    latitude = lat;
    longitude = lon;

    etat = 1; //Etat = 1 signifie qu ele capteur marche, Etat = 0 signifie qu'il ne marche plus. Quand on ajoute un capteur, 
                //on fait l'hypothèse que celui ci marche, d'où on initialise la valeur à 1.
} //----- Fin de Capteur

Capteur::Capteur(){
    //Constructeur par défaut ------ l'objet est vide
}

Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
