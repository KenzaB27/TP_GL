/*************************************************************************
						   Lecture  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
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

//------------------------------------------------------------- Constantes


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
Catalogue Lecture::Parcourir(string fichier)
{
	Catalogue c;

	ifstream monFlux(fichier.c_str());

#ifdef MAP
	cout << "Flux ouvert. " << endl;
	unsigned int iLigne = 0;
#endif // MAP

	while (monFlux.good())
	{
		list<MesureGaz> listeMesure;
		for (int i = 0; i < 4; i++)
		{
			MesureGaz m;
			LectureMesure(monFlux, &m);
			listeMesure.push_back(m);
		}

		// On vérifie la cohérence des données mesurées
		list<MesureGaz>::iterator i;
		int idCapteur = (*listeMesure.begin()).getIdCapteur();
		Date dateMesure = (*listeMesure.begin()).getDate();

		bool same = true;
		
		//Verifie la cohérence des données récupérées
		for (i = listeMesure.begin(); i != listeMesure.end(); i++)
		{
			if ((*i).getIdCapteur() != idCapteur && !((*i).getDate() == dateMesure))
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
			c.Ajouter(index, listeMesure);
		}
	}

	return c;

} //--- Fin de Parcourir


vector<Capteur> Lecture::InitCapteur(string fichierCapteurs)
{
	ifstream monFlux(fichierCapteurs.c_str());
	vector<Capteur> liste;

	if (monFlux)
	{
		string line;
		while (monFlux.good())
		{
			int capteurId;
			string tempString; //utilisé avant le cast
			double latitude;
			double longitude;
			string description;

			// extraction des informations
			getline(monFlux, tempString, ';');
			capteurId = atoi((tempString.substr(tempString.length() - 1, tempString.length())).c_str());

			getline(monFlux, tempString, ';');
			latitude = atof(tempString.c_str());

			getline(monFlux, tempString, ';');
			longitude = atof(tempString.c_str());

			getline(monFlux, description);

			Capteur c(capteurId, description.substr(0, description.length() - 2), latitude, longitude);
			liste.push_back(c);
		}
	}

	return liste;
} //---- Fin de initCapteur

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
			g.description = description.substr(0, description.length() - 2);

			gazDescription[gazId] = g;
		}
	}
}//-- Fin initTypeGaz

//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture(const Lecture & unLecture)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)

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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es

void Lecture::LectureMesure(ifstream &ifs, MesureGaz *mesure)
{

	string dateS;
	int annee;
	int mois;
	int jour;
	int heure;
	int minute;
	double seconde;

	string heureS;
	string sensor;
	string gaz;
	string valueString;
	double value;

	getline(ifs, dateS, 'T');  //La Date
	cout << "Date : " << dateS << endl;
	getline(ifs, heureS, ';'); //L'heure
	cout << "Heure : " << heureS << endl;

	//La date
	string temp = dateS.substr(5, 5);
	mois = atoi((temp.substr(0, 2)).c_str());
	annee = atoi((dateS.substr(0, 4)).c_str());
	jour = atoi((dateS.substr(8, 10)).c_str());

	//L'heure
	heure = atoi((heureS.substr(0, 2)).c_str());
	string temp1 = heureS.substr(3, 3);
	minute = atoi((temp1.substr(0, 2)).c_str());
	seconde = atof((heureS.substr(6, heureS.length())).c_str());

	Date d(annee, mois, jour, heure, minute, seconde);

	cout << annee << "-" << mois << "-" << jour << "-" << "T" << heure << "/" << minute << "/" << seconde << endl;

	//L'id du capteur
	getline(ifs, sensor, ';');
	int sensorid = atoi((sensor.substr(sensor.length() - 1, sensor.length())).c_str());
	cout << "idC : " << sensorid << endl;

	getline(ifs, gaz, ';'); //Type de Gaz
	cout << "idG : " << gaz << endl;

	getline(ifs, valueString); // value
	valueString = valueString.substr(0, valueString.length());
	value = atof(valueString.c_str());
	cout << "value : " << value << endl;
	//On remplit la mesureGaz
	mesure->setGazId(gazMap[gaz]);

	mesure->setDate(d);
	mesure->setValeur(value);

	mesure->setIdCapteur(sensorid);

	mesure->setDescription(gazDescription[gazMap[gaz]].description);
	mesure->setUnite(gazDescription[gazMap[gaz]].unit);

} //--- Fin de LectureMesure

