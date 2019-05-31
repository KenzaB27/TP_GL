/*************************************************************************
						   ConcentrationIndice
							 -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- R�alisation de la classe <ConcentrationIndice> (ConcentrationIndice.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "ConcentrationIndice.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------- M�thodes publiques
void ConcentrationIndice::setIndice(vector<Seuil>& listeSeuils)
{
	for (auto it = listeSeuils.begin(); it != listeSeuils.end(); ++it)
	{
		/*cout << "debugindice"  << it->getMin() << endl; 
		cout << "debugConcentration" << concentration << endl; */
		if (concentration >= it->getMin() && concentration <= it->getMax()) {
			/*cout << "debugindice" << it->getIndice() << endl;*/ 
			indice = it->getIndice();
		}
	}
}// fin de setIndice

//------------------------------------------------- Surcharge d'op�rateurs

ostream & operator<<(ostream &out, const ConcentrationIndice &concentration)
{
	out << concentration.concentration << " ug/m3 - indice ATMO : " << concentration.indice << endl; 
	return out; 
}// fin de operator<< 

//-------------------------------------------- Constructeurs - destructeur
ConcentrationIndice::ConcentrationIndice(long double constra):concentration(constra)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ConcentrationIndice

ConcentrationIndice::ConcentrationIndice() 
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ConcentrationIndice


ConcentrationIndice::~ConcentrationIndice()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~ConcentrationIndice


