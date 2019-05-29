/*************************************************************************
                           Etude  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Etude> (fichier ${file_name}) ------
#if ! defined (ETUDE_H)
#define ETUDE_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <math.h>	
#include "Date.h"
#include "Capteur.h"
#include "PorteeCapteur.h"
#include "Catalogue.h"
#include "Seuil.h"

using namespace std; 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Etude>
//
//
//------------------------------------------------------------------------

class Etude 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	vector<long double> Evaluer(Catalogue &cat, vector<Capteur>&listCapteur, 
		long double latitude, long double longitude, Date dateDebut, long double rayon = 2000, Date dateFin = Date());
	int CalculAtmo(vector <long double>&mesures, unordered_map<int, vector<Seuil>>& tabSeuil);
	unordered_map <int, vector<int>> DetecterCapteursSimilaires(Catalogue &c, int nbCapteurs);
//------------------------------------------------- Surcharge d'opérateursp

//-------------------------------------------- Constructeurs - destructeur
//-------------------------------------------- Constructeurs - destructeur

    Etude ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Etude ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	vector<long double> evaluer(Catalogue &cat, vector<int>&listCapteur, Date dateD, Date dateF);
	vector<int> getCapteur(vector<Capteur>&listCapteur, long double latitude, long double longitude, long double rayon = 2000);
	bool comparerMesures(vector<long double> &mes1, vector<long double>&mes2); 
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

//----------------------------------------- Types dépendants de <Etude>

#endif // Etude
