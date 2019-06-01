/*************************************************************************
                           Menu 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
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
// Gère l'affichage,a la récupération et le traitement des demande de l'utilisateur 
//
//------------------------------------------------------------------------

class Menu
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques    
    void run();
    // Mode d'emploi : Lance le programme et lis les commandes
    //
    // Contrat :
    //

	void init();
	// Mode d'emploi : Initialise le Menu et les classes de gaz, capteur, seuils et le parcousr
	//
	// Contrat :
	//

    //-------------------------------------------- Constructeurs - destructeur

    Menu();
    // Mode d'emploi : Créer un nouveau menu
    //
    // Contrat :
    //

    virtual ~Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

private:
    //------------------------------------------------------- Méthodes privées

    bool traitement(string c);
    // Mode d'emploi : lance la fonction adaptée à la commande passée
    //
    // Contrat :
    //

	bool commande(vector<string> c, string s);
	// Mode d'emploi : Verifie si la commande appartient au vecteur de paramètres passés 
	//
	// Contrat :
	//

	void split(vector<string> &argList, unordered_map<string, string> &valueList, string s);
	void afficheMatSimilarite(bool**matSimilarite, string gaz, double precision);
	void afficheMatMoyenne(unordered_map<int, vector<long double>> moyenneCapteur );
	void afficheMatEcart(string gaz, long double ** matriceEcartGaz, int nbCapteurs =10);
	void afficherSousIndiceAtmo(vector<ConcentrationIndice> listeConcIndice);
	// Mode d'emploi : split un string de commande en paramètres et valeurs (les -r et -val=value)
	//
	// Contrat :
	//
    
	void AfficherSeuils(unordered_map<int, vector<Seuil>>& umap);
	// Mode d'emploi : Affiche les seuils de calcul de l'ATMO
	//
	// Contrat :
	//


private:
    //------------------------------------------------------- Attributs privés
    Catalogue* c;
    Gestion g;
    Etude e;
    Lecture l;
    vector<Capteur> listeCapteurs;
	unordered_map<int, vector<Seuil>> tabSeuils;

};

//----------------------------------------- Types dépendants de <Menu>

#endif // Menu