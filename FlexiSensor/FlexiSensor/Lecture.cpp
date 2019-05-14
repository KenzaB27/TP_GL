/*************************************************************************
						   Lecture  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Lecture> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Lecture::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
Lecture & Lecture::operator=(const Lecture & unLecture)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture(const Lecture & unLecture)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)

Lecture::Lecture()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Lecture>" << endl;
#endif
} //----- Fin de Lecture

Lecture::~Lecture()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
