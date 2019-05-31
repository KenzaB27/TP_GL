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
//		Permet la gestion des capteurs et des seuils
//		de l'application.
//------------------------------------------------------------------------

class Gestion 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

void SupprimerCapteur(int numCapteur, vector<Capteur> &listeCapteurs);
// Mode d'emploi :
//	Supprime un Capteur du vector de Capteur grâce
//	à l'id du capteur passé en paramètre
// Contrat :
//	Aucun contrat 

int EvaluerCapteur(Catalogue &c, int num);
// Mode d'emploi :
//	Evalue un capteur et renvoie un entier
//	selon si le capteur est défaillant
// Contrat :
//	Aucun contrat

void AjouterCapteur(Capteur unCapteur, vector<Capteur> &listeCapteurs);
// Mode d'emploi :
//	Ajoute un Capteur dans le vector de Capteur passé
//	en paramètre.
// Contrat :
//	Aucun contrat

void MettreEnVeilleCapteur(int numCapteur, vector<Capteur>& listeCapteurs);
// Mode d'emploi :
//	Met en veille un capteur dans le vector grâce
//	à l'id du capteur passé en paramètre
// Contrat :
//	Aucun contrat

void RestaurerCapteur(int numCapteur, vector<Capteur>& listeCapteurs);
// Mode d'emploi :
//	Restaure un capteur dans le vector grâce
//	à l'id du capteur passé en paramètre
// Contrat :
//	Aucun contrat

void ChangerSeuil(unordered_map<int, vector<Seuil>> &tabSeuil, vector<Seuil> pm10,
	vector<Seuil> so2, vector<Seuil> no2, vector<Seuil> o3);
// Mode d'emploi :
//	Change touts les seuils de l'unordered map
//	passé en paramètre
// Contrat :
//	Les données sont supposés valides et conformes au tableau
//	de l'indice ATMO au niveau de la taille et de la cohérence
//	des données.

void ChangerUnSeuil(unordered_map<int, vector<Seuil>>& tabSeuil, int gaz, Seuil s);
// Mode d'emploi :
//	Change un seuil de l'unordered map
//	passé en paramètre
// Contrat :
//	Les données sont supposés valides et conformes au tableau
//	de l'indice ATMO au niveau de la taille et de la cohérence
//	des données.




//------------------------------------------------- Surcharge d'opérateurs

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
