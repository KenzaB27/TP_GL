/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <PorteeCapteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>

//------------------------------------------------------ Include personnel
#include "PorteeCapteur.h"
using namespace std;
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type PorteeCapteur::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

long double PorteeCapteur::getLatitudeMax()
{
    return latitudeMax;
}
long double PorteeCapteur::getLatitudeMin()
{
    return latitudeMin;
}
long double PorteeCapteur::getLongitudeMax()
{
    return longitudeMax;
}
long double PorteeCapteur::getLongitudeMin()
{
    return longitudeMin;
}
long double PorteeCapteur::getLatitudeCentre()
{
    return latitudeCentre;
}
long double PorteeCapteur::getLongitudeCentre()
{
    return longitudeCentre;
}

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
}

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
