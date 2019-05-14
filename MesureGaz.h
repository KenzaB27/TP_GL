/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( MesureGaz_H )
#define MesureGaz_H

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
enum id{O3, SO2, NO2, PM10};
//------------------------------------------------------------------------ 
// Rôle de la classe <MesureGaz>
//
//
//------------------------------------------------------------------------ 

class MesureGaz
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    id getAttributId();
    string getUnite();
    string getDescription();
    Date getDate();
    double getValeur();

//-------------------------------------------- Constructeurs - destructeur
    MesureGaz ( const MesureGaz & unMesureGaz );

    MesureGaz(id typegaz, string u, string d, Date hr, double v);

    MesureGaz();

    virtual ~MesureGaz ( );

//----------------------------------Attributs

    protected:
    id attributId;
    string unite;
    string description;
    Date date;
    double valeur;

 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
