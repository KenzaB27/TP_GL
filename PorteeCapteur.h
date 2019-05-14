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

    double getLatitudeMax(); 
    double getLatitudeMin(); 
    double getLongitudeMax(); 
    double getLongitudeMin();

    bool contient (PorteeCapteur portee); 

    PorteeCapteur (double longitude, double latitude , double rayon=2);
    // Mode d'emploi :
    //
    // Contrat :
    //
    ~PorteeCapteur(); 
   
    protected:
    double latitudeMax; 
    double latitudeMin; 
    double longitudeMax; 
    double longitudeMin;

};

//----------------------------------------- Types dépendants de <PorteeCapteur>

#endif // PORTEECAPTEUR_H
