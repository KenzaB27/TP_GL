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
#include "IdCatalogue.h"

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
            listeMesure.push_back(m);
        }

        // On vérifie la cohérence des données mesurées
        list<MesureGaz>::iterator i;
        int idCapteur = (*listeMesure.begin()).getIdCapteur();
        Date dateMesure = (*listeMesure.begin()).getDate();

        bool same = true;
        for (i = listeMesure.begin(); i != listeMesure.end(); i++)
        {
            if ((*i).getIdCapteur() != idCapteur && !((*i).getDate() == dateMesure))
            {
                same = false;
                break;
                #ifdef MAP
                    cout << "Erreurs lors de la composition de 4 valeurs " << endl;
                    unsigned int iLigne = 0;
                #endif // MAP
            }
        }
         
        if(same)
        {
            IdCatalogue index(idCapteur, dateMesure);
            if (listeMesure.size() == 4)
                c.Ajouter(index, listeMesure);
        }
    
    }
    
} //--- Fin de Parcourir

void Lecture::LectureMesure(ifstream &ifs, MesureGaz *mesure)
{
    string dateD;
    string heure;
    string sensor;
    string gaz;
    string valueString;
    double value;

    getline(ifs, dateD, 'T'); //La Date
    getline(ifs, heure, ';'); //L'heure

    Date d(dateD, heure);

    //L'id du capteur 
    getline(ifs, sensor, ';');
    int sensorid = atoi((sensor.substr(sensor.length() - 1, sensor.length())).c_str());

    getline(ifs, gaz, ';'); //Type de Gaz

    getline(ifs, valueString, ';'); // value
    value = atof(valueString.c_str());

    //On remplit la mesureGaz
    mesure->setGazId(gazMap[gaz]);
    mesure->setDate(d); 
    mesure->setValeur(value);
    mesure->setIdCapteur(sensorid);

} //--- Fin de LectureMesure
