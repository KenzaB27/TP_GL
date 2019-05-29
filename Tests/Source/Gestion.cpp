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

void Gestion::ajouterCapteur(Capteur unCapteur, vector <Capteur> &listeCapteurs) {
    bool dejaPresent = false;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == unCapteur.getCapteurId()) {
            dejaPresent = true;
            break;
        }
    }

    if (dejaPresent == true) {
        cerr << "Impossible d'ajouter le capteur : Capteur n°" << unCapteur.capteurId << " déjà présent" << endl;
    } else {
        listeCapteurs.push_back(unCapteur);
    }

}

void Gestion::changerSeuil(unordered_map<string,list<Seuil>> &tabSeuil, list<Seuil> PM10, list<Seuil> SO2, list<Seuil> NO2, list<Seuil> O3)
{
    list<Seuil>::iterator itGaz = PM10.begin();
    for (list<Seuil>::iterator it = tabSeuil["PM10"].begin(); it != tabSeuil["PM10"].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=SO2.begin();
    for (list<Seuil>::iterator it = tabSeuil["SO2"].begin(); it != tabSeuil["SO2"].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=NO2.begin();
    for (list<Seuil>::iterator it = tabSeuil["NO2"].begin(); it != tabSeuil["NO2"].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=O3.begin();
    for (list<Seuil>::iterator it = tabSeuil["O3"].begin(); it != tabSeuil["O3"].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }
}


void Gestion::mettreEnVeilleCapteur(Capteur unCapteur, vector <Capteur> &listeCapteurs) {
    bool capteurAbsent = true;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == unCapteur.getCapteurId()) {
            if (it->etat==0) {
                cerr << "Impossible de mettre en veille le capteur : Capteur n°" << unCapteur.capteurId
                     << " est déjà en veille" << endl;

            } else {
                it->etat = 0;
            }

            capteurAbsent = false;
            break;
        }
    }

    if (capteurAbsent) {
        cerr << "Impossible de mettre en veille le capteur : Capteur n°" << unCapteur.capteurId
             << " absent de la liste des capteurs" << endl;
    }
}

void Gestion::restaurerCapteur(Capteur unCapteur, vector <Capteur> &listeCapteurs) {
    bool capteurAbsent = true;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == unCapteur.getCapteurId()) {
            if (it->etat) {
                cerr << "Impossible de restaurer le capteur : Capteur n°" << unCapteur.capteurId
                     << " est déjà en fonctionnement" << endl;

            } else {
                it->etat = 1;
            }

            capteurAbsent = false;
            break;
        }
    }

    if (capteurAbsent) {
        cerr << "Impossible de restaurer le capteur : Capteur n°" << unCapteur.capteurId
             << " absent de la liste des capteurs" << endl;
    }
}

void Gestion::supprimerCapteur(int numCapteur, vector <Capteur> &listeCapteurs) {
    bool capteurAbsent = true;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == numCapteur) {
            listeCapteurs.erase(it);
            capteurAbsent = false;
            break;
        }
    }

    if (capteurAbsent) {
        cerr << "Impossible de supprimer le capteur : Capteur n°" << numCapteur << " absent de la liste des capteurs"
             << endl;
    }
}

int Gestion::evaluerCapteur(Capteur) {

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
Gestion::Gestion(const Gestion &unGestion)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Gestion>" << endl;
#endif
} //----- Fin de Gestion (constructeur de copie)


Gestion::Gestion()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Gestion>" << endl;
#endif
} //----- Fin de Gestion


Gestion::~Gestion()
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
 
