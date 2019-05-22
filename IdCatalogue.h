/*************************************************************************
                           idCatalogue
                             -------------------
    début                : 14/05/2019
    copyright            : (C) 2019 par Margaux Cavagna
*************************************************************************/

#if ! defined ( IdCatalogue_H )
#define IdCatalogue_H

#include <iostream>
#include <string>
#include <functional>
using namespace std;
#include "Date.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <IdCatalogue>
//
//
//------------------------------------------------------------------------ 

struct IdCatalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	friend bool operator == (const IdCatalogue & unIdCatalogue1, const IdCatalogue & unIdCatalogue2);
//-------------------------------------------- Constructeurs - destructeur
    IdCatalogue ( const IdCatalogue & unIdCatalogue );

    IdCatalogue(int cI, Date dm);

    IdCatalogue();

    virtual ~IdCatalogue ( );

//----------------------------------Attributs
    int capteurId;
    Date dateMesure;

 };

//----------------------------------------- Types dépendants de <IdCatalogue>
namespace std {
  template<>
  class hash<IdCatalogue> {
  public:
      size_t operator()(const IdCatalogue &k) const
      {
          size_t h1 = hash<int>()(k.capteurId);
          size_t h2 = hash<int>()(k.dateMesure.annee)^hash<int>()(k.dateMesure.mois) 
					^ hash<int>()(k.dateMesure.jour)^hash<int>()(k.dateMesure.heure) 
					^ hash<int>()(k.dateMesure.minutes)^hash<double>()(k.dateMesure.secondes);
          return h1 ^ ( h2 << 1 );
      }
  };
}
#endif // IdCatalogue_H
