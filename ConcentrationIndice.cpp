/*************************************************************************
                           ConcentrationIndice  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <ConcentrationIndice> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ConcentrationIndice.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs

ostream & operator<<(ostream &out, const ConcentrationIndice &concentration)
{
	out << concentration.concentration << " ug/m3 - indice ATMO : " << concentration.indice << endl; 
	return out; 
}

void ConcentrationIndice::setIndice(vector<Seuil>& listeSeuils)
{
	for (auto it = listeSeuils.begin(); it != listeSeuils.end(); ++it)
	{
		if (concentration >= it->getMin() && concentration <= it->getMax()) {
			indice = it->getIndice();
		}
	}
}

//-------------------------------------------- Constructeurs - destructeur
ConcentrationIndice::ConcentrationIndice(long double constra):concentration(constra)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur


ConcentrationIndice::~ConcentrationIndice( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


