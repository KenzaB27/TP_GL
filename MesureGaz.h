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
    int getGazId();
    string getUnite();
    string getDescription();
    Date getDate();
    double getValeur();
    int getIdCapteur();

    void setGazId(int val);
    void setDate(Date d);
    void setValeur(double val);
    void setIdCapteur(int c);


    

//-------------------------------------------- Constructeurs - destructeur
    MesureGaz ( const MesureGaz & unMesureGaz );

    MesureGaz(int typegaz, Date hr, double v, int c);

    MesureGaz();

    virtual ~MesureGaz ( );

//----------------------------------Attributs

    protected:
    int gazId; //a changer dans le diagramme de classes
    string unite;
    Date date;
    double valeur;
    int idCapteur;
 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
