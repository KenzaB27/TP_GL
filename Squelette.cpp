/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <PorteeCapteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PorteeCapteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type PorteeCapteur::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
PorteeCapteur & PorteeCapteur::operator = ( const PorteeCapteur & unPorteeCapteur )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PorteeCapteur::PorteeCapteur ( const PorteeCapteur & unPorteeCapteur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PorteeCapteur>" << endl;
#endif
} //----- Fin de PorteeCapteur (constructeur de copie)


PorteeCapteur::PorteeCapteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PorteeCapteur>" << endl;
#endif
} //----- Fin de PorteeCapteur


PorteeCapteur::~PorteeCapteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PorteeCapteur>" << endl;
#endif
} //----- Fin de ~PorteeCapteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es