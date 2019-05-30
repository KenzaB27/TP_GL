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

	string fichierCapteurs = "";
	string fichierGaz = "";
	string fichierMesures = "";
	l.InitCapteur(listeCapteurs ,fichierCapteurs);
	l.InitTypeGaz(fichierGaz);
	//l.Parcourir(c, fichierMesures);

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

	if(argList[0].compare("atmo"))
	{
		//On a toujours lat et long 
		//La date si elle n'est pas mise est celle d'hier
		//Param a mettre -r -d si date et rayon, sinon que latitude et longitude
		//Ordre lat(1) long(2) -r(3) -d(4) rayon(5) dateD(6) dateF(7)
		long double lat;
		long double lon;
		double rayon;
		Date dateD;
		Date dateF;
		dateF = dateF.now();
		dateD = dateF.precedent();

		lat = atof(argList[1].c_str());
		lon = atof(argList[2].c_str());

		if (argList[3].compare("-r"))
		{
			if (argList[4].compare("-d"))
			{
				rayon = atof(argList[5].c_str());
				dateD = Date(argList[6]);
				dateF = Date(argList[7]);

				e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF, rayon);
			}
			else
			{
				rayon = atof(argList[4].c_str());
				e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF, rayon);
			}
		}
		else if (argList[3].compare("-d"))
		{
			dateD = Date(argList[4]);
			dateF = Date(argList[5]);

			e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF);
		}
		else 
		{
			e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF);
		}
	}


	if (argList[0].compare("stats"))
	{
		//TODO : capteurs similaires
	}

	if (argList[0].compare("sensor"))
	{
		if (argList[1].compare("add"))
		{
			//g.ajouterCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (argList[1].compare("remove"))
		{
			g.supprimerCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (argList[1].compare("exclude"))
		{
			g.mettreEnVeilleCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (argList[1].compare("include"))
		{
			g.restaurerCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}
	}

	if (argList[0].compare("seuil"))
	{
		//TODO : gestion modification des seuils
	}
}
