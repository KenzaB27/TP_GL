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

string MesureGaz::getDescription()
{
    return description;
}

Date MesureGaz::getDate(){
    return date;
}

int MesureGaz::getIdCapteur(){
    return idCapteur;
}

long double MesureGaz::getValeur(){
    return valeur;
}
void MesureGaz::setGazId(int val){
    gazId=val;
}
void  MesureGaz::setDate(Date d){
    date=d;
}
void  MesureGaz::setValeur(long double val){
    valeur=val;
}
void  MesureGaz::setIdCapteur(int c){
    idCapteur = c;
}

void MesureGaz::setUnite(string u)
{
    unite = u;
}

void MesureGaz::setDescription(string d)
{
    description = d;
}

//------------------------------------------------- Surcharge d'operateurs

ostream & operator<<(ostream &out, const MesureGaz &mesureGaz)
{
	out << mesureGaz.gazId << " " << mesureGaz.valeur << " " << mesureGaz.unite << " " << mesureGaz.description << " " << mesureGaz.idCapteur << " " <<mesureGaz.date << endl;
	return out; 
}
MesureGaz::operator long double() const
{
	return valeur; 
}

//-------------------------------------------- Constructeurs - destructeur



MesureGaz::MesureGaz(int typegaz, Date hr, long double v, int c, string d)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <MesureGaz>" << endl;
    #endif
    gazId=typegaz; //(doit faire partie de l'enum) 
    description = d;
    date = hr;
    valeur = v;
    unite="microg/m3";
    idCapteur = c;

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
