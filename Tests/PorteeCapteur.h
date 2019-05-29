/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( PORTEECAPTEUR_H )
#define PORTEECAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <math.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//------------------------------------------------------------------------
// Rôle de la classe <PorteeCapteur>
//
//
//------------------------------------------------------------------------

class PorteeCapteur 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
     long double getLatitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLongitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLatitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLatitudeMin(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLongitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLongitudeMin();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool contient (PorteeCapteur portee); 
    // Mode d'emploi :
    //
    // Contrat :
    //

    PorteeCapteur (long double longitude, long double latitude , long double rayon=2000);
    // Mode d'emploi :
    //
    // Contrat :
    //
    PorteeCapteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~PorteeCapteur(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
   
    protected:
	long double longitudeCentre;
    long double latitudeCentre;  
    long double latitudeMax; 
    long double latitudeMin; 
    long double longitudeMax; 
    long double longitudeMin;

};

//----------------------------------------- Types dépendants de <PorteeCapteur>

#endif // PORTEECAPTEUR_H
