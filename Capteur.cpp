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

PorteeCapteur Capteur::getPortee(){
    return portee; 
}
int Capteur::getEtat()
{
    return etat;
}
void Capteur::definirPortee(double latitude, double longitude){

}

//-------------------------------------------- Constructeurs - destructeur



Capteur::Capteur (int capteurid, string d, double lat, double lon)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif

    capteurId=capteurid;
    description = d;
    portee =PorteeCapteur(lat,lon); 
    etat = 1; //Etat = 1 signifie que le capteur marche, Etat = 0 signifie qu'il ne marche plus. Quand on ajoute un capteur, 
            //on fait l'hypothèse que celui ci marche, d'où on initialise la valeur à 1.
} //----- Fin de Capteur


Capteur::Capteur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur

Capteur::~Capteur()
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
