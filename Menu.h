/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier ${file_name}) ------
#if !defined(MENU_H)
#define MENU_H

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Catalogue.h"
#include "Gestion.h"
#include "Etude.h"
#include "Lecture.h"

using namespace std;

//------------------------------------------------------------- Constantes
#define MAX_PARAM_COMMAND 10

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Menu>
//
//
//------------------------------------------------------------------------

class Menu
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void run();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateursp

    //-------------------------------------------- Constructeurs - destructeur
    //-------------------------------------------- Constructeurs - destructeur

    Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

private:
    //------------------------------------------------------- Méthodes privées

    bool traitement(string c);
    // Mode d'emploi : Split la chaine passé en paramètre et lance la fonction adaptée
    //
    // Contrat :
    //

    Date stringToDate(string s);

    void init();

protected:
    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    Catalogue c;
    Gestion g;
    Etude e;
    Lecture l;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Menu>

#endif // Menu