/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <PorteeCapteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PorteeCapteur.h"

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

double PorteeCapteur::getLatitudeMax()
{
    return latitudeMax;
}
double PorteeCapteur::getLatitudeMin()
{
    return latitudeMin;
}
double PorteeCapteur::getLongitudeMax()
{
    return longitudeMax;
}
double PorteeCapteur::getLongitudeMin()
{
    return longitudeMin;
}
double PorteeCapteur::getLatitudeCentre()
{
    return latitudeCentre;
}
double PorteeCapteur::getLongitudeCentre()
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

PorteeCapteur::PorteeCapteur(double longitude, double latitude, double rayon) : longitudeCentre(longitude), latitudeCentre(latitude)
// Algorithme :
//
{
    //définition des bornes max et min de latitude et longitude notre territoire
    // 1° de latitude = 111,11 Km, on fait donc un produit en croix
    double offSetLat = rayon / 111110;
    // 1° de longitude à 'latitude' degrés de latitude correspond à
    // OneLongitudeDegree mètres. On passe à la méthode Math.Cos
    // des radians
    double oneLongitudeDegree = 111110*cos(latitude * M_PI / 180);
    // Produit en croix pour trouver le nombre de degrés de longitude auquel
    // correspond la longueur de notre rayon
    double offSetLong = rayon / oneLongitudeDegree;

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
