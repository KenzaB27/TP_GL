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
#include <vector>
#include <math.h>
#include "Date.h"
#include "Capteur.h"
#include "PorteeCapteur.h"
#include "Catalogue.h"
#include "Seuil.h"

using namespace std;

//------------------------------------------------------------- Constantes

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

protected:
    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Menu>

#endif // Menu