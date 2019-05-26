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

vector<long double> Etude::Evaluer(Catalogue &cat, vector<int>&listCapteur , Date dateF, Date dateD)
{
	vector<long double>concentrations;
	int compteur = 0; 

	for (auto it = cat.getMap().begin(); it != cat.getMap().end(); it++)
	{
		for (auto l = listCapteur.begin(); l != listCapteur.end(); l++)
		{
			if (it->first.capteurId == *l && it->second[03].getDate()>=dateD && it->second[03].getDate()<dateF)
			{
				compteur++; 
				concentrations[O3] += it->second[O3].getValeur(); 
				concentrations[SO2] += it->second[SO2].getValeur();
				concentrations[NO2] += it->second[NO2].getValeur();
				concentrations[PM10] += it->second[PM10].getValeur();
			}
		}
	}
	for (auto l = concentrations.begin(); l != concentrations.end(); *l /=compteur, l++); 

	return vector<long double>();
}


vector<int> Etude::getCapteur( vector<Capteur>&listCapteur,long double latitude, long double longitude ,long double rayon){
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

int Etude::calculAtmo(vector<long double>&mesures, unordered_map<int, vector<Seuil>>& tabSeuil)
{
	int indiceO3 = 0; 
	int indiceSO2 = 0;
	int indiceNO2 = 0;
	int indicePM10 = 0;

	for (auto it = tabSeuil[O3].begin(); it != tabSeuil[O3].end(); ++it)
	{
		if (mesures[O3] >= it->getMin() && mesures[O3] <= it->getMax()) {
			indiceO3 = it->getIndice();
		}
	}

	for (auto it = tabSeuil[SO2].begin(); it != tabSeuil[SO2].end(); ++it)
	{
		if (mesures[SO2] >= it->getMin() && mesures[SO2] <= it->getMax()) {
			indiceSO2 = it->getIndice();
		}
	}

	for (auto it = tabSeuil[NO2].begin(); it != tabSeuil[NO2].end(); ++it)
	{
		if (mesures[NO2] >= it->getMin() && mesures[NO2] <= it->getMax()) {
			indiceNO2 = it->getIndice();
		}
	}

	for (auto it = tabSeuil[PM10].begin(); it != tabSeuil[PM10].end(); ++it)
	{
		if (mesures[PM10] >= it->getMin() && mesures[PM10] <= it->getMax()) {
			indicePM10 = it->getIndice(); 
		}
	}
	return max(max(indiceNO2, indiceO3), max(indicePM10, indiceSO2));
}

//-------------------------------------------- Constructeurs - destructeur

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
