/*************************************************************************
                           PorteeCapteur
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( PORTEECAPTEUR_H )
#define PORTEECAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <math.h>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes
#define _USE_MATH_DEFINES
//#ifndef M_PI
#define M_PI 3.14159265358979323846
//#endif
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <PorteeCapteur>
// Permet d'implémenter la portée d'un capteur délimitée par un carré 
// de coordonnees latMin latMax LongMin longMax 
//
//------------------------------------------------------------------------

class PorteeCapteur 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
     long double getLatitudeCentre()const; 
    // Mode d'emploi : getter de la latitude du centre 
    //
    // Contrat : Aucun  contrat 
    //
    long double getLongitudeCentre()const; 
    // Mode d'emploi :getter de la longitude du centre 
    //
    // Contrat :Aucun  contrat 
    //
    long double getLatitudeMax() const; 
    // Mode d'emploi : getter de la latitude max 
    //
    // Contrat :Aucun  contrat 
    //
    long double getLatitudeMin()const; 
    // Mode d'emploi : getter de la latitude min 
    //
    // Contrat :Aucun  contrat 
    //
    long double getLongitudeMax()const; 
    // Mode d'emploi : getter de la longitude max 
    //
    // Contrat :Aucun  contrat 
    //
    long double getLongitudeMin()const;
    // Mode d'emploi : getter de la longitude min 
    //
    // Contrat :Aucun  contrat 
    //

    bool contient (PorteeCapteur portee); 
    // Mode d'emploi : permet de vérifier si un capteur de portee (portee) est contenu 
	// la portee courante du territoire
    //
    // Contrat :Aucun  contrat 
    //

//------------------------------------------------- Surcharge d'opérateurs

	friend ostream & operator <<(ostream &out, const PorteeCapteur &portee);
	// Mode d'emploi : surcharge de l'opérateur << pour la sortie standard 
	//
	// Contrat : Acun contrat
	//

//-------------------------------------------- Constructeurs - destructeur
    PorteeCapteur (long double longitude, long double latitude , long double rayon=2000);
    // Mode d'emploi :
    // longitude : la longitude du centre 
	// latitude : la latitue du centre 
	// rayon : le rayon du terriroire
    // Contrat :Aucun  contrat 
    //
    PorteeCapteur();
    // Mode d'emploi : Construteur par defaut de PorteeCapteur 
    //
    // Contrat :Aucun  contrat 
    //

    ~PorteeCapteur(); 
    // Mode d'emploi : Destructeur de PorteeCapteur
    //
    // Contrat :Aucun  contrat 
    //
   
protected:
//----------------------------------------------------- Attributs protégés 
	long double longitudeCentre;
    long double latitudeCentre;  
    long double latitudeMax; 
    long double latitudeMin; 
    long double longitudeMax; 
    long double longitudeMin;
};
#endif // PORTEECAPTEUR_H
