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
	vector<string> argList;
	unordered_map<string,string> valueList;

	split(argList, valueList, input);


	if (argList.empty()) //Cas ou acune commande n'est insérée
	{
		return true;
	}

	if(commande(argList, "atmo"))
	{
		//On a toujours lat et long 
		//La date si elle n'est pas mise est celle d'hier
		//Param a mettre -r -d si date et rayon, sinon que latitude et longitude 
		// -s si valeurs a afficher
		
		long double lat = atof(valueList.find("-lat")->second.c_str());
		long double lon = atof(valueList.find("-long")->second.c_str());;
		
		double rayon = commande(argList, "-r") ? atof(valueList.find("-r")->second.c_str()) : 2000;
		
		Date dateD;
		Date dateF;
		dateF = commande(argList, "-d") ? Date(valueList.find("-dateF")->second.c_str()) : dateF.precedent();
		dateD = commande(argList, "-d") ? Date(valueList.find("-dateD")->second.c_str()) : dateF.now();
			
		if (commande(argList, "-s"))
		{
			//TODO : Affichage valeurs mesure
			//e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF);
		}
		else
		{
			//vector<ConcentrationIndice> mesures = e.Evaluer(c, listeCapteurs, lat, lon, dateD, dateF);
			//cout << "[atmo] " << e.CalculAtmo(mesures, tabSeuils) << endl;
		}
	}


	if (commande(argList, "stats"))
	{
		//TODO : capteurs similaires
	}

	if (commande(argList, "sensor"))
	{
		if (commande(argList, "add"))
		{
			//g.ajouterCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (commande(argList, "remove"))		{
			//g.supprimerCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (commande(argList, "exclude"))
		{
			//g.mettreEnVeilleCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}

		if (commande(argList, "include"))
		{
			//g.restaurerCapteur(atoi(argList[2].c_str()), listeCapteurs);
		}
	}

	if (commande(argList, "seuil"))
	{
		//TODO : gestion modification des seuils
	}

}

void AfficherSeuils(unordered_map<int, list<Seuil>>& umap)
{
	cout << "Indice   |   SO2   |   NO2  |   O3   |   PM   |" << endl;

	auto itPM10 = umap[PM10].rbegin();
	auto itSO2 = umap[SO2].rbegin();
	auto itNO2 = umap[NO2].rbegin();
	auto itO3 = umap[O3].rbegin();

	for (int i = 10; i >= 1; i--)
	{
		cout << i << "        |   " << itSO2->getMin() << "-" << itSO2->getMax() << "   |   "
			<< itNO2->getMin() << "-" << itNO2->getMax() << "   |   "
			<< itO3->getMin() << "-" << itO3->getMax() << "   |   "
			<< itPM10->getMin() << "-" << itPM10->getMax() << "   |   " << endl;
		++itPM10;
		++itSO2;
		++itNO2;
		++itO3;

	}
}

bool Menu::commande(vector<string> c, string s) 
{
	return find(c.begin(), c.end(), s) != c.end();
}

void Menu::split(vector<string> &argList, unordered_map<string, string> valueList, string s)
{
	string delimiter = " ";
	size_t pos = 0;
	string token;
	char prefix = '-';

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);

		if (token[0] == prefix) //si forme -a ou -aa=555
		{
			size_t pos1 = token.find("=");

			if (pos1 != std::string::npos) // forme -a=66
			{
				string t = token.substr(0, pos1);
				token.erase(0, pos1 + delimiter.length());
				argList.push_back(t);
				valueList.emplace(make_pair(t, token));
			}
			else {
				argList.push_back(token);
			}
		}
		else {
			argList.push_back(token);
		}

		s.erase(0, pos + delimiter.length());
	}
	if (s[0] == prefix) //si forme -a ou -aa=555
	{
		size_t pos1 = s.find("=");

		if (pos1 != std::string::npos) // forme -a=66
		{
			string t = s.substr(0, pos1);
			s.erase(0, pos1 + delimiter.length());
			argList.push_back(t);
			valueList.emplace(make_pair(t, s));
		}
		else {
			argList.push_back(s);
		}
	}
	else {
		argList.push_back(s);
	}
}