/*************************************************************************
                           Etude  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Etude> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <algorithm>    // std::any_of
//------------------------------------------------------ Include personnel
#include "Etude.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Etude::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

vector<double> Etude::Evaluer(Catalogue cat, vector<int>listCapteur , Date dateF, Date dateD)
{
	vector<double>concentrations;
	int compteur = 0; 

	for (auto it = cat.getMap().begin(); it != cat.getMap().end(); it++)
	{
		for (auto l = listCapteur.begin(); l != listCapteur.end(); l++)
		{
			if (it->first.capteurId == *l )
			{
				compteur++; 
				concentrations[O3] += it->second[O3].getValeur(); 
				concentrations[SO2] += it->second[SO2].getValeur();
				concentrations[NO2] += it->second[NO2].getValeur();
				concentrations[PM10] += it->second[PM10].getValeur();
			}
		}
	}
	for (auto l = concentrations.begin(); l != concentrations.end(); *l / compteur, l++); 

	return vector<double>();
}

vector<int> Etude::getCapteur( vector<Capteur>listCapteur,double latitude, double longitude ,double rayon){
    PorteeCapteur territoire (latitude, longitude, rayon); 
    vector<int> capteurTerritoire; 
    for ( auto it=listCapteur.begin(); it!=listCapteur.end(); it++)
    {
        if (territoire.contient(it->getPortee())){
            capteurTerritoire.push_back(it->getCapteurId()); 
        }
    }
    return capteurTerritoire; 
}
//------------------------------------------------- Surcharge d'op�rateurs
Etude & Etude::operator = ( const Etude & unEtude )
// Algorithme :
//
{
	return *this; 
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Etude::Etude ( const Etude & unEtude )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Etude>" << endl;
#endif
} //----- Fin de Etude (constructeur de copie)


Etude::Etude ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Etude>" << endl;
#endif
} //----- Fin de Etude


Etude::~Etude ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Etude>" << endl;
#endif
} //----- Fin de ~Etude


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
