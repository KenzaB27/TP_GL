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
enum id{O3, NO2, SO2, PM10};
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
    long double getValeur();
    int getIdCapteur();

    void setGazId(int val);
    void setDate(Date d);
    void setValeur(long double val);
    void setIdCapteur(int c);
    void setDescription(string d);
    void setUnite(string u);

    //------------------------------------------------- Surcharge d'operateurs
    friend ostream &operator<<(ostream &out, const MesureGaz &mesureGaz);
	operator long double()const;
    //-------------------------------------------- Constructeurs - destructeur
    MesureGaz(int typegaz, Date hr, long double v, int c, string d);

    MesureGaz();

    virtual ~MesureGaz ( );

//----------------------------------Attributs

    protected:
    int gazId; //a changer dans le diagramme de classes
    string unite;
    string description;
    Date date;
    long double valeur;
    int idCapteur;
 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
