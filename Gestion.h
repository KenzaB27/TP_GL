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
#include "Seuil.h"
#include <vector>
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
void supprimerCapteur(int numCapteur, vector<Capteur> listeCapteurs);
void ajouterCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs);
void restaurerCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs);
void mettreEnVeilleCapteur(Capteur unCapteur, vector<Capteur> listeCapteurs);
int evaluerCapteur(Capteur unCapteur);
void changerSeuil(Seuil unSeuil);


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
// Contrat :
//

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
