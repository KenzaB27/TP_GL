/*************************************************************************
                           Catalogue 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

#if ! defined ( Catalogue_H )
#define Catalogue_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator> 
#include <vector>
#include <functional>
using namespace std;

#include "IdCatalogue.h"
#include "MesureGaz.h"
#include "Date.h"


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------ 

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	unordered_map<IdCatalogue, vector<MesureGaz>> getMap() const; 

	void Ajouter(IdCatalogue i, vector<MesureGaz> m);
		
//----------------------------------------------------- Surcharges d'opérateurs
	friend ostream &operator<<(ostream &out, const Catalogue &catalogue);
	operator unordered_multimap<int, vector<long double>>() const;
//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );

    Catalogue();

    virtual ~Catalogue ( );
   
//----------------------------------Attributs

    protected:
    
    unordered_map<IdCatalogue,vector<MesureGaz>> map;


 };

//----------------------------------------- Types dépendants de <Catalogue>

#endif // Catalogue_H
