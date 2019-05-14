/*************************************************************************
                           MesureGaz  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <MesureGaz> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Date.h"
#include "MesureGaz.h"
#include "Capteur.h"


//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques

int MesureGaz ::getGazId(){
    return gazId;
}

string MesureGaz::getUnite(){
    return unite;
}

Date MesureGaz::getDate(){
    return date;
}

double MesureGaz::getValeur(){
    return valeur;
}
void MesureGaz::setGazId(int val){
    gazId=val;
}
void  MesureGaz::setDate(Date d){
    date=d;
}
void  MesureGaz::setValeur(double val){
    valeur=val;
}
void  MesureGaz::setCapteur(Capteur c){
    capteur=c;
}

 
//-------------------------------------------- Constructeurs - destructeur
MesureGaz::MesureGaz ( const MesureGaz & unMesureGaz )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <MesureGaz>" << endl;
    #endif



} //----- Fin de MesureGaz (constructeur de copie)


MesureGaz::MesureGaz (int typegaz, Date hr, double v, Capteur c)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <MesureGaz>" << endl;
    #endif
    gazId=typegaz; //(doit faire partie de l'enum) 
    unite = "µg/m3";
    date = hr;
    valeur = v;
    capteur = c;

} //----- Fin de MesureGaz

MesureGaz::MesureGaz(){
    //Constructeur par défaut ------ l'objet est vide
}

MesureGaz::~MesureGaz ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureGaz>" << endl;
#endif
} //----- Fin de ~MesureGaz


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
