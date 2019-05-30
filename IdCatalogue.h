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
	friend ostream &operator<<(ostream &out, const IdCatalogue &idCatalogue);

	int getCapteurId() const;

	Date getDateMesure() const;

//-------------------------------------------- Constructeurs - destructeur

    IdCatalogue ( const IdCatalogue & unIdCatalogue );

    IdCatalogue(int cI, Date dm);
	
    IdCatalogue();

    virtual ~IdCatalogue ( );

//----------------------------------Attributs

  protected:
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
          size_t h1 = hash<int>()(k.getCapteurId());
          size_t h2 = hash<int>()(k.getDateMesure().annee)^hash<int>()(k.getDateMesure().mois) 
					^ hash<int>()(k.getDateMesure().jour)^hash<int>()(k.getDateMesure().heure) 
					^ hash<int>()(k.getDateMesure().minutes)^hash<long double>()(k.getDateMesure().secondes);
          return h1 ^ ( h2 << 1 );
      }
  };
}
#endif // IdCatalogue_H
