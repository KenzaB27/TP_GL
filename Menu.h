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
#include <vector>
#include "Capteur.h"

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

	bool commande(vector<string> c, string s);
	// Mode d'emploi : Verifie si la commande appartient au vecteur de paramètres passés 
	//

	void split(vector<string> &argList, unordered_map<string, string> valueList, string s);
	// Mode d'emploi : split un string de commande en paramètres et valeurs (les -r et -val=value)

    void init();

protected:
    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    Catalogue c;
    Gestion g;
    Etude e;
    Lecture l;
    vector<Capteur> listeCapteurs;
	unordered_map<int, vector<Seuil>> tabSeuils;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Menu>

#endif // Menu