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


//-------------------------------------------- Constructeurs - destructeur

vector<ConcentrationIndice> Etude::Evaluer(Catalogue &cat, vector<Capteur> &listCapteur, unordered_map<int, vector<Seuil>>&mapSeuils,  long double latitude, long double longitude, Date dateDebut, Date dateFin, long double rayon)
{
	vector<int> listeCapteur = getCapteur(listCapteur, latitude, longitude, rayon); 
	return evaluer(cat, listeCapteur, mapSeuils, dateDebut, dateFin);
}

int Etude::CalculAtmo(vector<ConcentrationIndice>&mesures)
{
	return max(max(mesures[NO2].indice, mesures[O3].indice), max(mesures[PM10].indice, mesures[SO2].indice));
}

unordered_map<int,vector<int>> Etude::DetecterCapteursSimilaires(Catalogue & c, int nbCapteurs)
{	
	unordered_map<int, vector<int>> capteursSimilaires;
	unordered_multimap<int,vector<long double>> catalogueReduit = (unordered_multimap<int, vector<long double>>) c;
	for (int i = 0; i < nbCapteurs-1; i++)
	{	
		auto range1= catalogueReduit.equal_range(i);
		int size1 = distance(range1.first, range1.second);
		for (int j = i + 1; j < nbCapteurs; j++)
		{
			auto range2 = catalogueReduit.equal_range(j);
			int size2 = distance(range1.first, range1.second);
			if (size1 == size2)
			{
				int count = 0; 
				for (auto it1 = range1.first , it2 = range2.first; it1 != range1.second && it2 != range2.second; ++it1 , ++it2)
				{
					if (comparerMesures(it1->second, it2->second))
					{
						count++; 
					}
				}
				if (count == size1)
				{
					capteursSimilaires[i].emplace_back(j); 
				}
			}
		}
	}
	return capteursSimilaires; 
}





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
vector<ConcentrationIndice> Etude::evaluer(Catalogue &cat, vector<int>&listCapteur, unordered_map<int, vector<Seuil>>&mapSeuils, Date dateD, Date dateF)
{
	if (dateF == Date())
	{
		dateF = dateD.suivant(); 
	}
	vector<ConcentrationIndice>concentrations;
	int compteur = 0;

	for (auto it = cat.getMap().begin(); it != cat.getMap().end(); it++)
	{
		for (auto l = listCapteur.begin(); l != listCapteur.end(); l++)
		{
			if (it->first.getCapteurId() == *l && it->second[03].getDate() >= dateD && it->second[03].getDate() <= dateF)
			{
				compteur++;
				concentrations[O3].concentration += it->second[O3].getValeur();
				concentrations[SO2].concentration += it->second[SO2].getValeur();
				concentrations[NO2].concentration += it->second[NO2].getValeur();
				concentrations[PM10].concentration += it->second[PM10].getValeur();
			}
		}
	}
	for (auto l = concentrations.begin(); l != concentrations.end(); l->concentration /= compteur, l++);
	concentrations[O3].setIndice(mapSeuils[O3]); 
	concentrations[SO2].setIndice(mapSeuils[SO2]);
	concentrations[NO2].setIndice(mapSeuils[NO2]); 
	concentrations[PM10].setIndice(mapSeuils[PM10]);
	return concentrations;
}


vector<int> Etude::getCapteur(vector<Capteur>&listCapteur, long double latitude, long double longitude, long double rayon) {
	PorteeCapteur territoire(latitude, longitude, rayon);
	vector<int> capteurTerritoire;
	for (auto it = listCapteur.begin(); it != listCapteur.end(); it++)
	{
		if (territoire.contient(it->getPortee())) {
			cout << "capteurAJoutee" << endl; 
			capteurTerritoire.push_back(it->getCapteurId());
		}
	}
	return capteurTerritoire;
}

bool Etude::comparerMesures(vector<long double>&mes1, vector<long double>&mes2)
{
	if (mes1[O3] == mes2[03] && mes1[SO2] == mes2[SO2] && mes1[NO2] == mes2[NO2] && mes1[PM10] == mes2[PM10])
	{
		return true; 
	}
	return false;
}



//------------------------------------------------------- M�thodes priv�es
