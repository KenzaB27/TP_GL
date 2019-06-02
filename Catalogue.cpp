/*************************************************************************
                           Catalogue
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <Catalogue> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Date.h"
#include "Catalogue.h"
#include <list>


//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>
#include <utility>

//---------------------------------------------Methodes publiques



ostream & operator <<(ostream &out, const Catalogue &catalogue)
{
	unordered_map<IdCatalogue, vector<MesureGaz>> map = catalogue.getMap();

	int compteur = 1;

	for (auto itr = map.begin(); itr != map.end(); ++itr)
	{
		out << "Page " << compteur << " du catalogue" <<endl;

		out << itr->first;

		for (unsigned int i = 0; i < itr->second.size(); i++)
		{
			out << itr->second[i];
		}
		out<< "---------------------------------------------------------------";
		compteur++;
	}

	return out;
}


Catalogue::operator unordered_multimap<int, vector<long double>>() const
{
	unordered_multimap<int, vector<long double>> nouvelleMap;

	for (auto it = map.begin(); it != map.end(); it++) {
		vector<long double > valeurMesures;
		for (unsigned int i = 0 ; i < 4 ; i++)
		{
			valeurMesures.emplace_back(it->second[i]);
		}
		nouvelleMap.emplace(make_pair(it->first.getCapteurId(), valeurMesures));
	}
	return nouvelleMap;
}


unordered_map<IdCatalogue, vector<MesureGaz>> Catalogue::getMap() const
{
	return map;
}//Fin de getMap

void Catalogue::Ajouter(IdCatalogue i, vector<MesureGaz> m)
{
	map.emplace(make_pair(i, m));
}


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut de <Catalogue>" << endl;
	#endif
    //Constructeur par défaut ------ l'objet est vide
}

Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
