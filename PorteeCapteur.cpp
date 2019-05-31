/*************************************************************************
                           PorteeCapteur 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <PorteeCapteur> (fichier PorteeCapteur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "PorteeCapteur.h"
//------------------------------------------------- Surcharge d'op�rateurs
ostream & operator<<(ostream & out, const PorteeCapteur & portee)
{
	out << "LatitudeCentre :" << portee.getLatitudeCentre() << " LongitudeCentre : " << portee.getLongitudeCentre() << endl;
	out << "LatitudeMax:" << portee.getLatitudeMin() << " LatitudeMin : " << portee.getLatitudeMax() << endl;
	out << "LongitudeMax:" << portee.getLongitudeMin() << " LongitudeMin : " << portee.getLongitudeMax() << endl;
	return out;
}
//----------------------------------------------------- M�thodes publiques
long double PorteeCapteur::getLatitudeMax()const
{
    return latitudeMax;
}// Fin getLatitudeMax 

long double PorteeCapteur::getLatitudeMin()const
{
    return latitudeMin;
}// Fin getLatitudeMin

long double PorteeCapteur::getLongitudeMax()const
{
    return longitudeMax;
}// Fin getLongitudeMax

long double PorteeCapteur::getLongitudeMin()const
{
    return longitudeMin;
}//Fin getLongitudeMin

long double PorteeCapteur::getLatitudeCentre()const
{
    return latitudeCentre;
}// Fin getLatitudeCentre

long double PorteeCapteur::getLongitudeCentre()const
{
    return longitudeCentre;
}// Fin LongitudeCentre 

bool PorteeCapteur::contient(PorteeCapteur portee)
{
    if ((portee.latitudeCentre >= latitudeMin && portee.latitudeCentre <= latitudeMax) && (portee.longitudeCentre >= longitudeMin || portee.longitudeCentre <= longitudeMax))
    {
        return true;
    }
    else if (((portee.latitudeMin >= latitudeMin && portee.latitudeMin <= latitudeMax) ||
              (portee.latitudeMax >= latitudeMin && portee.latitudeMax <= latitudeMax)) &&
             ((portee.longitudeMin > longitudeMin && portee.longitudeMax < longitudeMax) ||
              (portee.longitudeMin > longitudeMin && portee.longitudeMax < longitudeMax)))
    {
        return true;
    }
    else
    {
        return false;
    }
}// fin contient 

PorteeCapteur::PorteeCapteur(long double longitude, long double latitude, long double rayon) :longitudeCentre(longitude), latitudeCentre(latitude)
// Algorithme :
//
{
    //définition des bornes max et min de latitude et long doubleitude notre territoire
    // 1° de latitude = 111,11 Km, on fait donc un produit en croix
    long double offSetLat = rayon / 111110.;
    // 1° de long doubleitude à 'latitude' degrés de latitude correspond à
    // Onelong doubleitudeDegree mètres. On passe à la méthode Math.Cos
    // des radians
    long double oneLongitudeDegree = 111110*cos(latitude * M_PI / 180);
    // Produit en croix pour trouver le nombre de degrés de long doubleitude auquel
    // correspond la long doubleueur de notre rayon
	long double offSetLong = rayon / oneLongitudeDegree;

    latitudeMax = latitude + offSetLat;
    latitudeMin = latitude - offSetLat;
	longitudeMax = longitude + offSetLong;
	longitudeMin = longitude - offSetLong;
    
#ifdef MAP
    cout << "Appel au constructeur de <PorteeCapteur>" << endl;
#endif
} //----- Fin de PorteeCapteur

PorteeCapteur::PorteeCapteur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <PorteeCapteur>" << endl;
#endif
} //----- Fin de ~PorteeCapteur

PorteeCapteur::~PorteeCapteur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PorteeCapteur>" << endl;
#endif
} //----- Fin de ~PorteeCapteur

