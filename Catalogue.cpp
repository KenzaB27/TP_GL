/*************************************************************************
                           Catalogue  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
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
	


ostream & operator<<(ostream &out, const Catalogue &catalogue)
{
	unordered_map<IdCatalogue, vector<MesureGaz>> map = catalogue.getMap();

	int compteur = 1;

	for (auto itr = map.begin(); itr != map.end(); ++itr)
	{
		out << "Page " << compteur << "du catalogue" <<endl;
		out << itr->first;

		for (int i = 0; i < itr->second.size(); i++)
		{
			out << itr->second[i];
		}
		out << endl;
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
		for (auto i = it->second.begin(); i != it->second.begin(); i++)
		{
			valeurMesures.emplace_back((long double)*i);
		}
		nouvelleMap.emplace(make_pair(it->first.getCapteurId(), valeurMesures));
	}
	return nouvelleMap;
}

unordered_map<IdCatalogue, vector<MesureGaz>> Catalogue::getMap() const
{
	return map;
}

void Catalogue::Ajouter(IdCatalogue i, vector<MesureGaz> m)
{
	bool r = map.emplace(make_pair(i, m)).second;
}


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalogue>" << endl;
    #endif
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue(){
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
