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
#include <functional>

//---------------------------------------------Methodes publiques

void Catalogue::Ajouter(IdCatalogue id, vector<MesureGaz> liste){
    pair<IdCatalogue, vector<MesureGaz>> paire;
    paire = make_pair(id, liste);
    map.insert(paire);
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

ostream & operator<<(ostream &out, const Catalogue &catalogue)
{
  for ( auto it = catalogue.map.begin(); it != catalogue.map.end(); ++it ){//enventuellement switcher avec un getMap()
      out << it->first.capteurId << " " <<it->first.dateMesure<< " ";

    for (auto l = it->second.begin(); l != it->second.end(); ++l){
            out << *l << " "; // les itérateurs sont des pointeurs
    }
      out << endl;
  }
  return out;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
