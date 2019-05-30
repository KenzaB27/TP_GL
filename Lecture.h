/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier ${file_name}) ------
#if !defined(LECTURE_H)
#define LECTURE_H

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
#include "Seuil.h"

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

    void Parcourir(Catalogue* c, string fichier);
    // Mode d'emploi : Parcours tout le fichier en ne prenant en compte que les capteurs et la date passés en paramètre
    //
    // Contrat :
    //

    void InitCapteur(vector<Capteur> &l, string fichier);
    // Mode d'emploi : Remplis le vecteur de capteur à partir du fichier passé en paramètre
    //
    // Contrat :
    //

    void InitTypeGaz(string fichier);
    // Mode d'emploi : Initialise la liste des gaz et leur description à partir du fichier passé en paramètre
    //
    // Contrat :
    //

    void InitSeuils(unordered_map<string, list<Seuil>> &l, string fichier);
    // Mode d'emploi : Initialise la liste des gaz et leur description à partir du fichier passé en paramètre
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

private:
    //------------------------------------------------------- Méthodes privées
    void LectureMesure(ifstream &ifs, MesureGaz &mesure);
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

#endif // LECTURE_H