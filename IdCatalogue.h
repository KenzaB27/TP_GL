/*************************************************************************
                           IdCatalogue 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
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
  // Mode d'emploi : permet d'afficher de comparer deux idCatalogue
  //unIdCatalogue1 : le premier IdCatalogue à comparer
  //unIdCatalogue2 : le deuxième IdCatalogue à comparer
  //Retour : dépend si les IdCatalogue sont identiques
  // Contrat : Aucun contrat
  
	friend ostream &operator<<(ostream &out, const IdCatalogue &idCatalogue);
  // Mode d'emploi : affiche un IdCatalogue sur la sortie
  //out : le flux sur lequel afficher l'IdCatalogue
  //idCatalogue : l'IdCatalogue à afficher
  //Retour : out, le flux de sortie
  // Contrat : Aucun contrat

	int getCapteurId() const;
  // Mode d'emploi : récupère le capteurId de l'idCatalogue
  //Retour : un int correspondant au capteurId
  // Contrat : Aucun contrat

	Date getDateMesure() const;
  // Mode d'emploi : récupère la date de mesure de l'IdCatalogue
  //Retour : la dateMesure de l'IdCatalogue
  // Contrat : Aucun contrat
//-------------------------------------------- Constructeurs - destructeur

    IdCatalogue(int cI, Date dm);
  // Mode d'emploi : constructeur d'un IdCatalogue
  //cI : le capteurId de l'IdCatalogue
  //dm : la DateMesure de l'IdCatalogue
  // Contrat : Aucun contrat
	
    IdCatalogue();
  // Mode d'emploi : constructeur d'un IdCatalogue
  //cI : le capteurId de l'IdCatalogue
  //dm : la DateMesure de l'IdCatalogue
  // Contrat : Aucun contrat

    virtual ~IdCatalogue ( );
    // Mode d'emploi : destructeur d'un IdCatalogue
    //Contrat : aucun contrat
  

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
					^ hash<int>()(k.getDateMesure().minutes)^hash<int>()((int)k.getDateMesure().secondes);
          
		return h1 ^ ( h2 << 1 );

      }
  };
}

// Mode d'emploi : fonction de hachage des idCatalogue
//Contrat : aucun contrat

#endif // IdCatalogue_H
