/*************************************************************************
                           Lecture 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <Lecture> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Lecture.h"
#include "IdCatalogue.h"
#include "MesureGaz.h"
#include "Date.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Lecture::Parcourir(Catalogue* c, string fichier)
{
	ifstream monFlux(fichier.c_str());

#ifdef MAP
	cout << "Flux ouvert. " << endl;
	unsigned int iLigne = 0;
#endif // MAP

	if (monFlux)
	{
		while (monFlux.good())
		{
			vector<MesureGaz> listeMesure;
			for (unsigned int i = 0; i < 4; i++)
			{
				MesureGaz m;
				LectureMesure(monFlux, m);
				listeMesure.push_back(m);
			}

			// On vérifie la cohérence des données mesurées
			int idCapteur = (*listeMesure.begin()).getIdCapteur();
			Date dateMesure = (*listeMesure.begin()).getDate();

			bool same = true;

			//Verifie la cohérence des données récupérées
			for (auto i = listeMesure.begin(); i != listeMesure.end(); i++)
			{

				if ((*i).getIdCapteur() != idCapteur)
				{
					same = false;
					break;
				#ifdef MAP
					cout << "Erreurs lors de la composition de 4 valeurs " << endl;
					unsigned int iLigne = 0;
				#endif // MAP
				}
			}

			if (same)
			{
				IdCatalogue index(idCapteur, dateMesure);
				c->Ajouter(index, listeMesure);
			}
		}
	}

} //--- Fin de Parcourir

void Lecture::InitCapteur(vector<Capteur> &liste, string fichierCapteurs)
{
	ifstream monFlux(fichierCapteurs.c_str());

	if (monFlux)
	{
		string line;
		unsigned int i = 0;
		while (monFlux.good())
		{
			int capteurId;
			string tempString; //utilisé avant le cast
			long double latitude;
			long double longitude;
			string description;

			// extraction des informations
			getline(monFlux, tempString, ';');
			capteurId = atoi((tempString.substr(tempString.length() - 1, tempString.length())).c_str());

			getline(monFlux, tempString, ';');

			latitude = atof(tempString.c_str());

			getline(monFlux, tempString, ';');

			longitude = atof(tempString.c_str());

			getline(monFlux, description);


			Capteur c(capteurId, description.substr(0, description.length() - 1), latitude, longitude);
			liste.push_back(c);
			i++;
		}
	}
} //---- Fin de InitCapteur

void Lecture::InitTypeGaz(string fichierGaz)
{
	ifstream monFlux(fichierGaz.c_str());

	if (monFlux)
	{
		while (monFlux.good())
		{
			string gazName;
			int gazId;
			string unit;
			string description;

			getline(monFlux, gazName, ';');
			gazId = gazMap[gazName];

			getline(monFlux, unit, ';');
			getline(monFlux, description);
			
			gazInfos g;
			g.id = gazId;
			g.unit = unit;
			g.description = description.substr(0, description.length() - 1);

			gazDescription[gazId] = g;
		}
	}
}//-- Fin InitTypeGaz

void Lecture::InitSeuils(unordered_map<int, vector<Seuil>> &l, string fichier)
{
	ifstream monFlux(fichier.c_str());

	if (monFlux)
	{
		l.clear();
		while (monFlux.good())
		{
			vector<Seuil> liste;
			int gazId;
			for (unsigned int i = 0; i < 10; i++)
			{
				int indice;
				int min;
				int max;
				string temp;

				getline(monFlux, temp, ';');
				gazId = gazMap[temp];

				getline(monFlux, temp, ';');
				indice = atoi(temp.c_str());

				getline(monFlux, temp, ';');
				min = atoi(temp.c_str());

				getline(monFlux, temp);
				max = atoi(temp.substr(0, temp.length() - 1).c_str());

				Seuil s(min, max, indice);

				liste.emplace_back(s);
			}
			l.emplace(make_pair(gazId, liste));
		}
	}
} //--- Fin InitSeuils


unordered_map<string, id> Lecture::getGazName()
{
	return gazMap;
} //--- Fin de getGazName


void Lecture::getCommandes(vector<string> &v, string fichier)
{
	ifstream monFlux(fichier.c_str());

	if (monFlux)
	{
		while (monFlux.good())
		{
			string temp;
			getline(monFlux, temp);
			v.push_back(temp);
		}
	}
}


//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Lecture>" << endl;
#endif

	gazMap["O3"] = O3;
	gazMap["SO2"] = SO2;
	gazMap["NO2"] = NO2;
	gazMap["PM10"] = PM10;

} //----- Fin de Lecture

Lecture::~Lecture()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- M�thodes priv�es

void Lecture::LectureMesure(ifstream &ifs, MesureGaz &mesure)
{

	string dateS;
	string sensor;
	string gaz;
	string valueString;
	long double value;

	// La date
	getline(ifs, dateS, ';');
	Date d(dateS);

	//L'id du capteur
	getline(ifs, sensor, ';');
	int sensorid = atoi((sensor.substr(sensor.length() - 1, sensor.length())).c_str());

	// Le nom du gaz
	getline(ifs, gaz, ';');

	// La valeur mesurée
	getline(ifs, valueString); 
	valueString = valueString.substr(0, valueString.length());
	value = atof(valueString.c_str());

	//On remplit la mesureGaz
	mesure.setGazId(gazMap[gaz]);
	mesure.setDate(d);
	mesure.setValeur(value);
	mesure.setIdCapteur(sensorid);
	mesure.setDescription(gazDescription[gazMap[gaz]].description);
	mesure.setUnite(gazDescription[gazMap[gaz]].unit);

} //--- Fin de LectureMesure
