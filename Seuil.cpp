/*************************************************************************
                           Seuil  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Seuil> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Seuil.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
/*ostream& operator<<(ostream & out, Seuil& unSeuil)
{
	cout << "min : " << unSeuil.min<<"  max : "<<unSeuil.max<<" indice : "<< unSeuil.indice;
	return out;
}*/

//----------------------------------------------------- M�thodes publiques
// type Seuil::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
/*Seuil & Seuil::operator = ( const Seuil & unSeuil )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs  - destructeur
Seuil::Seuil ( const Seuil & unSeuil )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Seuil>" << endl;
#endif
} //----- Fin de Seuil (constructeur de copie)


Seuil::Seuil(int unMin,int unMax,int unIndice)
// Algorithme :
//
{
	min = unMin;
	max = unMax;
	indice = unIndice;
#ifdef MAP
    cout << "Appel au constructeur de <Seuil>" << endl;
#endif
} //----- Fin de Seuil


Seuil::~Seuil ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Seuil>" << endl;
#endif
} //----- Fin de ~Seuil


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
