/*************************************************************************
                           Capteur 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Capteur.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques

int Capteur::getCapteurId()const
{
    return capteurId;
}

string Capteur::getDescription()const
{
    return description;
}

PorteeCapteur Capteur::getPortee()const {
    return portee; 
}
int Capteur::getEtat()const 
{
    return etat;
}

void Capteur::setEtat(int unEtat)
{
	etat = unEtat;
}

ostream & operator<<(ostream & out, const Capteur & capteur)
{
	out << capteur.getCapteurId(); 
	//" " << mesureGaz.description << " " << mesureGaz.idCapteur << " " <<mesureGaz.date << endl;
	return out;
}

bool operator==(const Capteur& capteur1, const Capteur& capteur2)
{
	return (capteur1.capteurId == capteur2.capteurId);
};

//-------------------------------------------- Constructeurs - destructeur



Capteur::Capteur (int capteurid, string d, long double lat, long double lon)
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
