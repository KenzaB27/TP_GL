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
    // Mode d'emploi : Permet de récuperer la map du catalogue
    //Retour : une unordered map de IdCatalogue et mesuresGaz
	// Contrat : aucun contrat
	//

	void Ajouter(IdCatalogue i, vector<MesureGaz> m);
	// Mode d'emploi : Permet d'ajouter des données dans le catalogue
	//i : l'idCatalogue a ajouter
    // m : le vector de mesures Gaz associé
    // Retour : aucun
	// Contrat : aucun
	//
//----------------------------------------------------- Surcharges d'opérateurs
	friend ostream &operator<<(ostream &out, const Catalogue &catalogue);
    // Mode d'emploi : Affiche un catalogue en sortie grâce à l'opérateur de sortie <<
    //Out : le flux de sortie sur lequel afficher
    //Catalogue : le catalogue à afficher
	//Retour : le flux de sortie (out)
	// Contrat : aucun
	//

	operator unordered_multimap<int, vector<long double>>() const;
    // Mode d'emploi :
	//
	// Contrat :
	//
//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi : Crée un catalogue vide : par définition, un catalogue n'a aucune donnée quand on l'initialise.
	//
	// Contrat : aucun
	//

    virtual ~Catalogue ( );
   // Mode d'emploi : Permet de détruire un catalogue
	//
	// Contrat : aucun
	//
//----------------------------------Attributs

    protected:

    unordered_map<IdCatalogue,vector<MesureGaz>> map;


 };

#endif // Catalogue_H
