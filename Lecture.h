/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier ${file_name}) ------
#if !defined(XXX_H)
#define XXX_H

    //--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "Date.h"
#include "MesureGaz.h"
#include "Capteur.h"
#include "Catalogue.h"

//------------------------------------------------------------------ Types
/*enum id
{
    O3,
    SO2,
    NO2,
    PM10
};*/

struct gazInfos
{
    int id;
    string unit;
    string description;
};

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture
{
    //----------------------------------------------------------------- PUBLIC

public:    
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode demploi
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Lecture(const Lecture & unLecture);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Catalogue Parcourir(string fichier);
    // Mode d'emploi : Parcours tout le fichier en ne prenant en compte que les capteurs et la date passés en paramètre
    //
    // Contrat :
    //

    vector<Capteur> InitCapteur(string fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void InitTypeGaz(string fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

private:
    //------------------------------------------------------- Méthodes privées
    void LectureMesure(ifstream &ifs, MesureGaz *mesure);
    // Mode d'emploi : Parcours tout le fichier et le stocke dans un catalogue
    //
    // Contrat :
    //
    

protected:
    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    unordered_map<string, id> gazMap;
    gazInfos gazDescription[4];

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés
};

    //----------------------------------------- Types dépendants de <Lecture>

#endif // XXX_H