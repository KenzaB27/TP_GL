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

size_t Date_hash( const Date & date )
{
    return hash<int>()(date.annee)^hash<int>()(date.mois)^hash<int>()(date.jour)^hash<int>()(date.heure)^hash<int>()(date.minutes)^hash<int>()(date.secondes);
}

struct IdCatalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

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
          size_t h2 = Date_hash(k.dateMesure);
          return h1 ^ ( h2 << 1 );
      }
  };
}
#endif // IdCatalogue_H
