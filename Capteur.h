/*************************************************************************
                           Capteur 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier ${file_name}) ------
#if ! defined ( Capteur_H )
#define Capteur_H


//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;
#include "PorteeCapteur.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------ 

class Capteur
{
//----------------------------------------------------------------- PUBLIC
    friend class Gestion;
public:
//----------------------------------------------------- Méthodes publiques
    int getCapteurId() const ;
    // Mode d'emploi : Récupere l'idCapteur d'un capteur
    //Retour : un entier correspondant à l'idCapteur
    // Contrat : Aucun contrat

    string getDescription() const ;
    // Mode d'emploi : Récupere la description d'un capteur
    //Retour : un string correspondant à la description
    // Contrat : Aucun contrat

    PorteeCapteur getPortee() const;
    //Mode d'emploi : Récupere la portee d'un capteur
    //Retour : un PorteeCapteur correspondant à la portée du capteur
    // Contrat : Aucun contrat

    int getEtat() const;
    // Mode d'emploi : Récupere l'état d'un capteur (1 : fonctionne, 0: ne fonctionne pas)
    //Retour : un int correspondant à l'état
    // Contrat : Aucun contrat

	void setEtat(int unEtat);
    // Mode d'emploi : Permet de définir l'état d'un capteur (1 : fonctionne, 0: ne fonctionne pas)
    //Retour : Aucun
    // Contrat : Aucun contrat

	friend ostream & operator<<(ostream &out, const Capteur &capteur); 
	// Mode d'emploi : permet d'afficher le capteur sur la sortie du terminal
    //out : le flux sur lequel afficher le capteur
    //capteur : le capteur à afficher
    //Retour : out, le flux de sortie
    // Contrat : Aucun contrat

	friend bool operator==(const Capteur& capteur1, const Capteur& capteur2);
    // Mode d'emploi : permet de voir si deux capteurs sont égaux
    //capteur1 : le premier capteur à comparer
    //capteur2 : le deuxième capteur à comparer
    //Retour : dépend si les deux capteurs sont égaux ou nous
    // Contrat : Aucun contrat

//-------------------------------------------- Constructeurs - destructeur

    Capteur(int capteurid, string d, long double lat, long double lon);
    // Mode d'emploi : Construit un capteur 
    //capteurid : l'id du capteur
    //d : la description du capteur
    //latitude : la latitude de la position
    //longitude : la longitude de la position
    // Contrat : Aucun contrat

    Capteur();
    // Mode d'emploi : Crée un capteur vide (pas d'attributs)
    // Contrat : Aucun contrat
    //

    virtual ~Capteur ( );
    // Mode d'emploi : Destructeur de la classe 
    //Retour : rien
    // Contrat : Aucun contrat
    //
//----------------------------------Attributs

    protected:
    int capteurId;
    string description;
    int etat;
    PorteeCapteur portee; 

 };

//----------------------------------------- Types dépendants de <Capteur>

#endif // Capteur_H
