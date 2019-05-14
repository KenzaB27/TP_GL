/*************************************************************************
                           Etude  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Etude> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Etude.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Etude::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
void Etude::Evaluer(double latitude, double longitude, Date dateF, Date dateD, double rayon){

}
vector<Capteur> Etude::getCapteur( vector<Capteur>listCapteur,double latitude, double longitude ,double rayon = 0 ){
    PorteeCapteur territoire (latitude, longitude, rayon); 
    vector<Capteur> capteurTerritoire; 
    for ( vector<Capteur>::iterator it=listCapteur.begin(); it!=listCapteur.end(); it++)
    {
        if (territoire.contient(it->getPortee())){
            capteurTerritoire.push_back(it); 
        }
    }
    return capteurTerritoire; 
}
//------------------------------------------------- Surcharge d'op�rateurs
Etude & Etude::operator = ( const Etude & unEtude )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Etude::Etude ( const Etude & unEtude )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Etude>" << endl;
#endif
} //----- Fin de Etude (constructeur de copie)


Etude::Etude ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Etude>" << endl;
#endif
} //----- Fin de Etude


Etude::~Etude ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Etude>" << endl;
#endif
} //----- Fin de ~Etude


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
