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

void Gestion::AjouterCapteur(Capteur unCapteur, vector <Capteur> &listeCapteurs) {
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

void Gestion::ChangerSeuil(unordered_map<int,vector<Seuil>> &tabSeuil, vector<Seuil> pm10, vector<Seuil> so2, vector<Seuil> no2, vector<Seuil> o3)
{
    vector<Seuil>::iterator itGaz = pm10.begin(); 
    for (vector<Seuil>::iterator it = tabSeuil[PM10].begin(); it != tabSeuil[PM10].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=so2.begin();
    for (vector<Seuil>::iterator it = tabSeuil[SO2].begin(); it != tabSeuil[SO2].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=no2.begin();
    for (vector<Seuil>::iterator it = tabSeuil[NO2].begin(); it != tabSeuil[NO2].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }

    itGaz=o3.begin();
    for (vector<Seuil>::iterator it = tabSeuil[O3].begin(); it != tabSeuil[O3].end(); ++it)
    {
        (*it)=*itGaz;
        ++itGaz;
    }
}
void Gestion::ChangerUnSeuil(unordered_map<int, vector<Seuil>>& tabSeuil, int gaz, Seuil s)
{
	vector<Seuil>::iterator it = tabSeuil[gaz].begin();
	for (int i = 1; i < s.getIndice(); i++)
	{
		++it;
	}
	(*it) = s;
}

void Gestion::MettreEnVeilleCapteur(int  numCapteur, vector <Capteur> &listeCapteurs) {
    bool capteurAbsent = true;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == numCapteur) {
            if (it->etat==0) {
                cerr << "Impossible de mettre en veille le capteur : Capteur n°" << numCapteur
                     << " est déjà en veille" << endl;

            } else {
                it->etat = 0;
            }

            capteurAbsent = false;
            break;
        }
    }

    if (capteurAbsent) {
        cerr << "Impossible de mettre en veille le capteur : Capteur n°" << numCapteur
             << " absent de la liste des capteurs" << endl;
    }
}

void Gestion::RestaurerCapteur(int numCapteur, vector <Capteur> &listeCapteurs) {
    bool capteurAbsent = true;
    for (vector<Capteur>::iterator it = listeCapteurs.begin(); it != listeCapteurs.end(); ++it) {
        if (it->getCapteurId() == numCapteur) {
            if (it->etat) {
                cerr << "Impossible de restaurer le capteur : Capteur n°" << numCapteur
                     << " est déjà en fonctionnement" << endl;

            } else {
                it->etat = 1;
            }

            capteurAbsent = false;
            break;
        }
    }

    if (capteurAbsent) {
        cerr << "Impossible de restaurer le capteur : Capteur n°" << numCapteur
             << " absent de la liste des capteurs" << endl;
    }
}

void Gestion::SupprimerCapteur(int numCapteur, vector <Capteur> &listeCapteurs) {
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

int Gestion::EvaluerCapteur(Catalogue &c, int num) {

	bool defectueux = false;

	unordered_map<IdCatalogue, vector<MesureGaz>> map = c.getMap();
	list<list<pair<long double, Date>>> liste;
	for (auto it = map.begin(); it != map.end(); it++) {
		list<pair<long double, Date>> valeursMesures;
		if (it->first.getCapteurId()==num)
		{
			for (auto i = it->second.begin(); i != it->second.begin(); i++)
			{
				valeursMesures.emplace_back(i->getValeur(),i->getDate());
			}
			liste.emplace_back(valeursMesures);
		}
	}


    return 0;
}

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
 
