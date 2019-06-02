/*************************************************************************
                           Menu
                             -------------------
	début                : 01/06/2019
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
#include <iomanip>
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
    // Mode d'emploi : Lance le programme et lis attends les commandes de l'utilisateur
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
	//				   c :  string contenant la commande saisie
	//				   return true si la commande a pu être traitée, false sinon
    //
    // Contrat :
    //

	bool commande(vector<string> c, string s);
	// Mode d'emploi : Verifie si la commande appartient au vecteur de paramètres passés
	//				   c : un vecteur des paramètres passés dans la commande 
	//				   s : paramètre recherché
	//				   Renvoi true si le paramètre a été saisi, false sinon 
	//
	// Contrat :
	//

	void split(vector<string> &argList, unordered_map<string, string> &valueList, string s);
  // Mode d'emploi : split un string de commande en paramètres et valeurs (les -r et -val=value)
	//				 argList : vecteur des arguments passés dans la commande (-a)
	//				 valueList : map des arguments et des valeurs passés dans la commande (-a=8=
	// Contrat :
	//
  
	void afficheMatSimilarite(bool**matSimilarite, string gaz, double precision);
	// Mode d'emploi : Affiche la matrice de similarité des capteurs
	//				   gaz : le gaz étudié à afficher
	//				   precision : la précision des écart à la moyenne utilisée lors de l'étude
	//
	// Contrat :
	//

	void afficheMatMoyenne(unordered_map<int, vector<long double>> moyenneCapteur );
	// Mode d'emploi : Affiche la matrice des moyenne pour chacun des gazs
	//				   moyenneCapteur : vecteur des moyennes de chacun des gazs
	//
	// Contrat :
	//

	void afficheMatEcart(string gaz, long double ** matriceEcartGaz, int nbCapteurs = 10);
	// Mode d'emploi : Affiche la matrice de écarts à la moyenne
	//				   nbCapteurs : nombre de capteurs étudiés
	//				   matriceEcartGaz : matrice des ecart à la moyenne de chacun des gazs
	//
	// Contrat :
	//

	void afficherSousIndiceAtmo(vector<ConcentrationIndice> listeConcIndice);
	// Mode d'emploi : affiche les valeurs des indices de chacun des gazs prises
	//				   en compte sur la période étudiée lors du calcul de l'ATMO
	//				   listeConcIndice : liste des valeurs obtenues lors de l'étude de l'atmo
	//
	// Contrat :
	//

	void AfficherSeuils(unordered_map<int, vector<Seuil>>& umap);
	// Mode d'emploi : Affiche les seuils de calcul de l'ATMO
	//				   umap : map des seuils par gaz
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
	bool firstRun = true;
};

//----------------------------------------- Types dépendants de <Menu>

#endif // Menu
