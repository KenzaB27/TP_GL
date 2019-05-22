/*************************************************************************
                           Catalogue
                             -------------------
    début                : 14/05/2019
    copyright            : (C) 2019 par Margaux Cavagna
*************************************************************************/

#if ! defined ( Catalogue_H )
#define Catalogue_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator> 
#include <list>
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
    void Ajouter(IdCatalogue id, list<MesureGaz> liste);
//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );

    Catalogue();

    virtual ~Catalogue ( );
    friend ostream &operator<<(ostream &out, const Catalogue &catalogue);

//----------------------------------Attributs

    public:
    unordered_map<IdCatalogue,list<MesureGaz>> map;


 };

//----------------------------------------- Types dépendants de <Catalogue>

#endif // Catalogue_H
