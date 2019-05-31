/*************************************************************************
						   Etude
							 -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <Etude> (Etude.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <algorithm>    // std::any_of
//------------------------------------------------------ Include personnel
#include "Etude.h"

//----------------------------------------------------- M�thodes publiques

vector<ConcentrationIndice> Etude::Evaluer(Catalogue &cat, vector<Capteur> &listCapteur, unordered_map<int, vector<Seuil>>&mapSeuils,  long double latitude, long double longitude, Date dateDebut, Date dateFin, long double rayon)
{
	vector<int>listIdCapteurs = getCapteur(listCapteur, latitude, longitude, rayon);
	vector<ConcentrationIndice> mesures (0);
	if (listIdCapteurs.size()==0)
	{
		cout << "Ce territoire n'est pas couvert par le reseau de capteurs" << endl;
	}
	else
	{
		mesures = evaluer(cat, listIdCapteurs, mapSeuils, dateDebut, dateFin);
		if (mesures.size() == 0)
		{
			cout << "Aucune mesure pour la date choisie" << endl;
		}
	}
	return mesures;
}// Fin de Evaluer 

int Etude::CalculAtmo(vector<ConcentrationIndice>&mesures)
{
	
	if (mesures.size()>0)
	{
		return max(max(mesures[NO2].indice, mesures[O3].indice), max(mesures[PM10].indice, mesures[SO2].indice));
	}
	else
	{
		return 0; 
	}
}//Fin de calcul Atmo 

unordered_map<int,vector<int>> Etude::MesuresTotParCapteurs(Catalogue & c, int nbCapteurs)
{	
	unordered_map<int, vector<int>> mesuresCapteurs;
	unordered_multimap<int,vector<long double>> catalogueReduit = (unordered_multimap<int, vector<long double>>) c;
	for (int i = 0; i < nbCapteurs-1; i++)
	{	
		vector<int> mesuresTotales = { 0,0,0,0,0 };
		mesuresCapteurs.emplace(make_pair(i, mesuresTotales));
		auto range1= catalogueReduit.equal_range(i);
		for (auto it = range1.first ; it!= range1.second ; it++)
		{
			
			mesuresCapteurs[i][O3] += it->second[03]; 
			mesuresCapteurs[i][SO2] += it->second[SO2];
			mesuresCapteurs[i][NO2] += it->second[NO2];
			mesuresCapteurs[i][PM10] += it->second[PM10];
			mesuresCapteurs[i][4] ++; // compteur
		}
	}
	return mesuresCapteurs; 
}
unordered_map<int, int**> Etude::EcartCapteurs(unordered_map<int, vector<int>> mapMoyenne, int nbCapteurs)
{
	unordered_map<int, int**>mapEcartCapteurs; 
	for (int j = 0; j < 4; j++)
	{
		int ** matriceEcartGaz = new int *[nbCapteurs];
		for (int i = 0; i < nbCapteurs; i++)
		{
			matriceEcartGaz[i] = new int[nbCapteurs];
		}
		mapEcartCapteurs.emplace(make_pair(j, matriceEcartGaz));
	}
	for (int i = 0; i < nbCapteurs; i++){
		for (int k = 0; k < nbCapteurs; k++)
		{
			mapEcartCapteurs[O3][i][k] = abs(mapMoyenne[k][03] - mapMoyenne[i][03]);
			mapEcartCapteurs[PM10][i][k] = abs(mapMoyenne[k][PM10] - mapMoyenne[i][PM10]);
			mapEcartCapteurs[NO2][i][k] = abs(mapMoyenne[k][NO2] - mapMoyenne[i][NO2]);
			mapEcartCapteurs[SO2][i][k] = abs(mapMoyenne[k][SO2] - mapMoyenne[i][SO2]);
		}
			
	}
	return mapEcartCapteurs; 
}
bool ** Etude::DeterminerCapteursSimilaires(unordered_map<int, int**> matriceEcart, double ecart , int nbCapteurs)
{
	bool ** matSimilarite = new bool *[nbCapteurs];
	for (int i = 0; i < nbCapteurs; i++)
	{
		matSimilarite[i] = new bool[nbCapteurs];
	}
	for (int i = 0; i < nbCapteurs; i++) {
		for (int k = 0; k < nbCapteurs; k++)
		{
			if (matriceEcart[O3][i][k] + matriceEcart[PM10][i][k] + matriceEcart[NO2][i][k] + matriceEcart[SO2][i][k] <= 4 * ecart)
			{
				matSimilarite[i][k] = 1; 
			}
		}
	}
	return matSimilarite; 
}
//fin de DetecterCapteursSimilaires

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
vector<ConcentrationIndice> Etude::evaluer(Catalogue &cat, vector<int>&listCapteur,
	unordered_map<int, vector<Seuil>>&mapSeuils, Date dateD, Date dateF)
{
	if (dateF == Date())
	{
		dateF = dateD.suivant(); 
	}
	vector<ConcentrationIndice>concentrations;
	concentrations.emplace_back(ConcentrationIndice(0)); 
	concentrations.emplace_back(ConcentrationIndice(0));
	concentrations.emplace_back(ConcentrationIndice(0));
	concentrations.emplace_back(ConcentrationIndice(0));
	int compteur = 0;
	unordered_map<IdCatalogue, vector<MesureGaz>> map = cat.getMap();

	for (auto it = map.begin(); it != map.end(); it++)
	{
		for (auto l = listCapteur.begin(); l != listCapteur.end(); l++)
		{
		
			if (it->first.getCapteurId() == *l && it->second[03].getDate()>= dateD && it->second[03].getDate()< dateF)
			{
				
				compteur++;
				concentrations[O3].concentration += it->second[O3].getValeur();
				concentrations[SO2].concentration += it->second[SO2].getValeur();
				concentrations[NO2].concentration += it->second[NO2].getValeur();
				concentrations[PM10].concentration += it->second[PM10].getValeur();
			}
		}
	}
	cout << compteur << endl; 
	if (compteur == 0)
	{
		concentrations = vector<ConcentrationIndice>(0);
	}
	else
	{
		cout << "Le fichier comporte " << compteur << "mesures" << endl; 
		for (auto l = concentrations.begin(); l != concentrations.end(); l->concentration /= compteur, l++);
		concentrations[O3].setIndice(mapSeuils[O3]);
		concentrations[SO2].setIndice(mapSeuils[SO2]);
		concentrations[NO2].setIndice(mapSeuils[NO2]);
		concentrations[PM10].setIndice(mapSeuils[PM10]);
	}
	
	return concentrations;
}// fin de evaluer 


vector<int> Etude::getCapteur(vector<Capteur>&listCapteur, long double latitude, long double longitude, long double rayon) {
	PorteeCapteur territoire(latitude, longitude, rayon);
	vector<int> capteurTerritoire = {};
	bool capteurFound = false; 
	for (auto it = listCapteur.begin(); it != listCapteur.end(); it++)
	{
		if (territoire.contient(it->getPortee())) {
			cout << "capteurAjoute" << endl; 
			capteurTerritoire.push_back(it->getCapteurId());
			capteurFound = true; 
		}
	}
	return capteurTerritoire;
}// fin de getCapteur

bool Etude::comparerMesures(vector<long double>&mes1, vector<long double>&mes2)
{
	if (mes1[O3] == mes2[03] && mes1[SO2] == mes2[SO2] && mes1[NO2] == mes2[NO2] && mes1[PM10] == mes2[PM10])
	{
		return true; 
	}
	return false;
}// fin de comparerMesures

