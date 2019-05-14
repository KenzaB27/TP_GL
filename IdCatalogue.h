/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
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

class IdCatalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    int getCapteurId();
    Date getDateMesure();

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

#endif // IdCatalogue_H
