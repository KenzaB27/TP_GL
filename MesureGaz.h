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


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 

    struct date {
        int jour;
        int mois;
        int annee;
        int secondes;
        int minutes;
        int heures;
    };

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
    date getDate();
    double getValeur();

//-------------------------------------------- Constructeurs - destructeur
    MesureGaz ( const MesureGaz & unMesureGaz );

    MesureGaz(id typegaz, string u, string d, date hr, double v);

    MesureGaz();

    virtual ~MesureGaz ( );

//----------------------------------Attributs

    protected:
    id attributId;
    string unite;
    string description;
    date Date;
    double valeur;

 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
