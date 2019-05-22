/*************************************************************************
                           Gestion  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Gestion> (fichier Gestion.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Gestion.h"
#include "Capteur.h"
#include "PorteeCapteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Gestion::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

/*void Gestion::creerUtilisateur(Utilisateur unUtilisateur)
{

}

void Gestion::supprimerUtilisateur(Utilisateur unUtilisateur)
{

}*/

void Gestion::ajouterCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs)
{


}

void Gestion::changerSeuil(Seuil unSeuil)
{

}


void Gestion::mettreEnVeilleCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs)
{
    for (vector<Capteur>::iterator it = listeCapteurs.begin() ; it != listeCapteurs.end(); ++it)
    {
        if(it->getCapteurId()==unCapteur.getCapteurId())
        {
            
        }
    }
}

void Gestion::restaurerCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs)
{

}

void Gestion::supprimerCapteur(int numCapteur, vector<Capteur> listeCapteurs)
{
    for (vector<Capteur>::iterator it = listeCapteurs.begin() ; it != listeCapteurs.end(); ++it)
    {
        if(it->getCapteurId() ==numCapteur)
        {
            listeCapteurs.erase(it);
        }
    }
}

int Gestion::evaluerCapteur(Capteur)
{

    return 0;
}
//------------------------------------------------- Surcharge d'op�rateurs
/*
Gestion & Gestion::operator = ( const Gestion & unGestion )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Gestion::Gestion ( const Gestion & unGestion )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Gestion>" << endl;
#endif
} //----- Fin de Gestion (constructeur de copie)


Gestion::Gestion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Gestion>" << endl;
#endif
} //----- Fin de Gestion


Gestion::~Gestion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Gestion>" << endl;
#endif
} //----- Fin de ~Gestion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
 
