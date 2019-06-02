/*************************************************************************
                           Lecture 
                             -------------------
	début                : 01/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
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

struct gazInfos // Informations d'un gaz : son id, son unité et sa description
{
    int id;
    string unit;
    string description;
};

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
// Cette classe permet de parcourir un fichier et de remplir la structure adapatée : 
//    - Remplissage d'un Catalogue pour la liste des mesures 
//    - Remplissage d'un vector pour la liste des Capteurs
//    - Remplissage d'une map pour la descriptions des gazs
//    - Remplissage d'une map pour les seuils des différents gazs
//
//------------------------------------------------------------------------

class Lecture
{
    //----------------------------------------------------------------- PUBLIC

public:    
    //----------------------------------------------------- Méthodes publiques
    unordered_map<string, id> getGazName();
    // Mode demploi : Renvoi une map contenant les informations des gaz étudiés
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
    // Mode d'emploi : Parcours tout le fichier et le stocke dans le Catalogue passé en paramètre
	//				   c : Pointeur sur le Catalogue à remplir
	//				   fichier : fichier contenant les valeurs
    //
    // Contrat :
    //

    void InitCapteur(vector<Capteur> &l, string fichier);
    // Mode d'emploi : Remplis le vecteur de capteur à partir du fichier passé en paramètre
	//				   l : vecteur de capteurs à remplir
	//				   fichier : fichier contenant les capteurs
    //
    // Contrat :
    //

    void InitTypeGaz(string fichier);
    // Mode d'emploi : Initialise la liste des gaz et leur description à partir du fichier passé en paramètre
	//				   fichier : fichier contenant les capteurs
    //
    // Contrat :
    //

    void InitSeuils(unordered_map<int, vector<Seuil>> &l, string fichier);
    // Mode d'emploi : Initialise la liste des gaz et leur description à partir du fichier passé en paramètre
	//				   l : map de seuils par gaz à remplir
	//				   fichier : fichier contenant les seuils
    //
    // Contrat :
    //

	void getCommandes(vector<string> &v, string fichier);
	// Mode d'emploi : Recupère la liste des commande et les insère dans le vecteur
	//				   v : vecteur de commandes possibles
	//				   fichier : fichier contenant les seuils
	//
	// Contrat :
	//

    //------------------------------------------------------------------ PRIVE
private:
    //------------------------------------------------------- Méthodes privées
    void LectureMesure(ifstream &ifs, MesureGaz &mesure);
    // Mode d'emploi : Parcours tout le fichier et le stocke dans un catalogue
	//				   ifs : flux entrant du fichier à lire et traiter
	//				   mesure : mesure gaz à remplir avec les informations du flux
    //
    // Contrat :
    //
    

private:
    //------------------------------------------------------- Attributs privés
    unordered_map<string, id> gazMap; // Permet de gérer le cast des string de nom de gaz en leur ID
    gazInfos gazDescription[4]; //Description des 4 gazs étudiés

};

    //----------------------------------------- Types dépendants de <Lecture>

#endif // LECTURE_H