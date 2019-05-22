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

void Catalogue::Ajouter(IdCatalogue id, list<MesureGaz> liste){
    pair<IdCatalogue, list<MesureGaz>> paire;
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
	out << mesureGaz.gazId << " " << mesureGaz.valeur << " " << mesureGaz.unite << " " << mesureGaz.description << " " << mesureGaz.idCapteur << " " <<mesureGaz.date << endl;
	return out; 
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
