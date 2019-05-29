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

bool Menu::traitement(string input)
{
	string delimiter =  " ";
	string command = input.substr(0, input.find(delimiter));
	string content = input.substr(input.find(delimiter), input.length());

	if (input.compare("")) //Cas ou acune commande n'est insérée
	{
		return true;
	}

	if(input.compare("search"))
	{

	}

	if (input.compare("stats"))
	{
		
	}

	if (input.compare("sensor"))
	{
		string param = content.substr(0, input.find(delimiter));

		if (param.compare("add"))
		{

		}

		if (param.compare("remove"))
		{

		}

		if (param.compare("exclude"))
		{

		}

		if (param.compare("include"))
		{

		}
	}

	if (input.compare("param"))
	{
		
	}
}