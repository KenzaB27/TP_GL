/*************************************************************************
                           Gestion  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Gestion> (fichier Gestion.h) ------
#if ! defined ( GESTION_H )
#define GESTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Capteur.h"
#include "Catalogue.h"
#include "Seuil.h"
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gestion>
//
//
//------------------------------------------------------------------------

class Gestion 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
// type Méthode ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
//void supprimerUtilisateur(Utilisateur unUtilisateur);
//void creerUtilisateur(Utilisateur unUtilisateur);
void SupprimerCapteur(int numCapteur, vector<Capteur> &listeCapteurs);
int EvaluerCapteur(Catalogue &c, int num);
void AjouterCapteur(Capteur unCapteur, vector<Capteur> &listeCapteurs);
void MettreEnVeilleCapteur(int numCapteur, vector<Capteur>& listeCapteurs);
void RestaurerCapteur(int numCapteur, vector<Capteur>& listeCapteurs);
void ChangerSeuil(unordered_map<int, vector<Seuil>> &tabSeuil, vector<Seuil> pm10,
	vector<Seuil> so2, vector<Seuil> no2, vector<Seuil> o3);
void ChangerUnSeuil(unordered_map<int, vector<Seuil>>& tabSeuil, int gaz, Seuil s);





//------------------------------------------------- Surcharge d'opérateurs
/*
Gestion & operator = ( const Gestion & unGestion );
// Mode d'emploi :
//
// Contrat :
//
*/

//-------------------------------------------- Constructeurs - destructeur
Gestion ( const Gestion & unGestion );
// Mode d'emploi (constructeur de copie) :
//
// Contrat :
//

Gestion ( );
// Mode d'emploi :
//
// Contrat ://

virtual ~Gestion ( );
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Gestion>

#endif // GESTION_H
