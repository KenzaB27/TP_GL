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
#include <fstream>
#include <string>
#include <stdlib.h>

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

Lecture::Lecture(string f):fichier(f)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif

    gazMap["O3"] = O3;
    gazMap["SO2"] = SO2;
    gazMap["NO2"] = NO2;
    gazMap["PM10"] = PM10;


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

void Lecture::initCapteur(ifstream &ifs)
{


}


Catalogue Lecture::parcourir(list<Capteur> listeCapteurs, Date debut, Date fin)
{
    Catalogue c;

    ifstream monFlux(fichier.c_str());

    #ifdef MAP
        cout << "Flux ouvert. " << endl;
        unsigned int iLigne = 0;
    #endif // MAP

    
    while (monFlux.good())
    {
        list<MesureGaz> listeMesure;
        for (int i = 0; i < 4; i++)
        {
            MesureGaz m;
            LectureMesure(monFlux, &m);

            if (ValideRecherche(listeCapteurs, debut, fin))
            {
                listeMesure.push_back(m);
            }
        }

        if(listeMesure.size() == 4 ) c->Ajouter(Liste);

    }
    
} //--- Fin de Parcourir

void Lecture::LectureMesure(ifstream &ifs, MesureGaz *mesure)
{
    string date;
    string heure;
    string sensor;
    string gaz;
    string valueString;
    double value;

    getline(ifs, date, 'T'); //La Date
    getline(ifs, heure, ';'); //L'heure

    Date d(date, heure);

    //L'id du capteur 
    getline(ifs, sensor, ';');
    int sensorid = atoi((sensor.substr(sensor.length() - 1, sensor.length())).c_str());

    getline(ifs, gaz, ';'); //Type de Gaz

    getline(ifs, valueString, ';'); // value
    value = atof(valueString.c_str());

    mesure->setGazId(gazMap[gaz]);
    mesure->setDate(d); 
    mesure->setValeur(value);
    mesure->setCapteur();
}