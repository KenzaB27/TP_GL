/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Gestion.h"
#include "Etude.h"
#include "Catalogue.h"
#include "Seuil.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Menu::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Menu::run()
{
	string inputLine = "";

	do
	{
		// Lecture de la commande utlisateur 
		cout << ">";
		cin >> inputLine;

		//Traitement de la commande 
		if(!traitement(inputLine)) 
			cout << "commande inexistante, tapez 'help' pour la liste des commandes" << endl;

	} while (inputLine.compare("exit"));
	
}



//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Menu>" << endl;
#endif

} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Menu>" << endl;
#endif
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
void Menu::init()
{

}


bool Menu::traitement(string input)
{
	string delimiter =  " ";

	string s = input;
	size_t pos = 0;
	string token;
	
	string argList[MAX_PARAM_COMMAND]; 
	int i = 0;

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		argList[i] = token;
		s.erase(0, pos + delimiter.length());
		i++;
	}
	argList[i] = token;


	if (argList[0].compare("")) //Cas ou acune commande n'est insérée
	{
		return true;
	}



	if(argList[0].compare("search"))
	{
		//Param a mettre -r -d si date et rayon, sinon que latitude et longitude
		//Ordre lat(1) long(2) -r(3) -d(4) rayon(5) dateD(6) dateF(7)
		long double lat;
		long double lon;
		double rayon;
		Date dateD;
		Date dateF;

		lat = atof(argList[1].c_str());
		lon = atof(argList[2].c_str());

		if (argList[3].compare("-r"))
		{
			if (argList[4].compare("-d"))
			{
				rayon = atof(argList[5].c_str());
				dateD = stringToDate(argList[6]);
				dateF = stringToDate(argList[7]);

				//TODO: Appel recherche
				
				
			}
			rayon = atof(argList[4].c_str());

			//TODO: Appel recherche
		}
		else if (argList[3].compare("-d"))
		{
			dateD = stringToDate(argList[4]);
			dateF = stringToDate(argList[5]);

			//TODO: Appel recherche

		}

		//TODO: Appel recherche

	}



	if (argList[0].compare("stats"))
	{
		
	}

	if (argList[0].compare("sensor"))
	{
		if (argList[1].compare("add"))
		{
			
		}

		if (argList[1].compare("remove"))
		{
			//Numero capteur en argList[2]
		}

		if (argList[1].compare("exclude"))
		{

		}

		if (argList[1].compare("include"))
		{

		}
	}

	if (argList[0].compare("param"))
	{
		
	}

	if (argList[0].compare("test"))
	{

	}
}



Date Menu::stringToDate(string s)
{
	// string to date
	int annee;
	int mois;
	int jour;
	int heure;
	int minute;
	long double seconde;

	string datePart = s.substr(0, s.find("T"));
	string heurePart = s.substr(s.find("T") + 1, s.length());

	//Traitement de la date
	string delimiter = "-";
	auto pos = datePart.find(delimiter);
	string temp = datePart.substr(0, pos);
	annee = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	pos = datePart.find(delimiter);
	temp = datePart.substr(0, pos);
	mois = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	pos = datePart.find(delimiter);
	temp = datePart.substr(0, pos);
	jour = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	//Traitement de l'heure
	delimiter = ":";
	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	heure = atoi(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	minute = atoi(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	seconde = atof(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

	Date d(annee, mois, jour, heure, minute, seconde);

	return d;
}