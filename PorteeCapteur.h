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
     double getLatitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    double getLongitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    double getLatitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    double getLatitudeMin(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    double getLongitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    double getLongitudeMin();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool contient (PorteeCapteur portee); 
    // Mode d'emploi :
    //
    // Contrat :
    //

    PorteeCapteur (double longitude, double latitude , double rayon=2000);
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
    double latitudeCentre; 
    double longitudeCentre; 
    double latitudeMax; 
    double latitudeMin; 
    double longitudeMax; 
    double longitudeMin;

};

//----------------------------------------- Types dépendants de <PorteeCapteur>

#endif // PORTEECAPTEUR_H
