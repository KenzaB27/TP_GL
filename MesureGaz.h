/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( MesureGaz_H )
#define MesureGaz_H

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Capteur.h"

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
    id getGazId();
    string getUnite();
    string getDescription();
    Date getDate();
    double getValeur();

    void setGazId(id val);
    void setDate(Date d);
    void setValeur(double val);
    void setCapteur(Capteur c);


    

//-------------------------------------------- Constructeurs - destructeur
    MesureGaz ( const MesureGaz & unMesureGaz );

    MesureGaz(id typegaz, Date hr, double v, Capteur c);

    MesureGaz();

    virtual ~MesureGaz ( );

//----------------------------------Attributs

    protected:
    id gazId; //a changer dans le diagramme de classes
    string unite;
    Date date;
    double valeur;
    Capteur capteur;

 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
