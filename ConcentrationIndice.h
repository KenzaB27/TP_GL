/*************************************************************************
                           ConcentrationIndice  -  description
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- Interface de la classe <ConcentrationIndice> (fichier ConcentrationIndice.h) ------
#if ! defined ( CONCENTRATIONINDICE_H )
#define CONCENTRATIONINDICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Seuil.h"

//------------------------------------------------------------------------
// Rôle de la classe <Cocentration>
// Cette classe permet d'associer un indice à une concentration donnée pour un gaz donnée 
// Elle sert de structure intermédiaire pour les calculs de l'étude 
//
//------------------------------------------------------------------------

struct ConcentrationIndice
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void setIndice(vector<Seuil> &listeSeuils); 
    // Mode d'emploi : permet de définir l'indice associé à la concentration selon 
	// la liste passée en paramètre 
	// listeSeuils : la liste regroupant les seuils relatifs à un gaz donné
    //
    // Contrat : Acun contrat
    //

//------------------------------------------------- Surcharge d'opérateurs
    
	friend ostream & operator<<(ostream &out, const ConcentrationIndice &concentration); 
	// Mode d'emploi : surcharge de l'opérateur << pour la sortie standard 
	//
	// Contrat : Acun contrat
	//
//-------------------------------------------- Constructeurs - destructeur
	ConcentrationIndice(long double conctra );
    // Mode d'emploi : Constructeur de ConcentrationIndice
    // constra: une concentation 
	//
    // Contrat : Aucun contrat 
    //
	ConcentrationIndice();
	// Mode d'emploi : Constructeur par défaut de ConcentrationIndice
	//
	// Contrat : Aucun contrat 
	//

    virtual ~ConcentrationIndice( );
    // Mode d'emploi : Destrucuteur de ConcentrationIndice
    //
    // Contrat :
    //

public: 
//----------------------------------------------------- Attributs publics
	long double concentration; 
	int indice; 
};
#endif // CONCENTRATIONINDICE_H
