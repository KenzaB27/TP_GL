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
	vector<long double> Evaluer (Catalogue &cat, vector<int>&listCapteur, Date dateF, Date dateD);
    vector<int> getCapteur(vector<Capteur>&listCapteur, long double latitude, long double longitude, long double rayon=2000);
	int calculAtmo(vector<long double>&mesures , unordered_map<int, vector<Seuil>> &tabSeuil);

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
