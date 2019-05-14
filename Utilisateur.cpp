/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Utilisateur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Utilisateur::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
/*Utilisateur & Utilisateur::operator = ( const Utilisateur & unUtilisateur )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
