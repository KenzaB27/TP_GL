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
     long getLatitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long getLongitudeCentre(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long getLatitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long getLatitudeMin(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long getLongitudeMax(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    long getLongitudeMin();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool contient (PorteeCapteur portee); 
    // Mode d'emploi :
    //
    // Contrat :
    //

    PorteeCapteur (long longitude, long latitude , long rayon=2);
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
    long latitudeCentre; 
    long longitudeCentre; 
    long latitudeMax; 
    long latitudeMin; 
    long longitudeMax; 
    long longitudeMin;

};

//----------------------------------------- Types dépendants de <PorteeCapteur>

#endif // PORTEECAPTEUR_H
