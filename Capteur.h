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
    string getDescription() const ;
    PorteeCapteur getPortee() const;
    int getEtat() const;
	void setEtat(int unEtat);
//-------------------------------------------- Constructeurs - destructeur

    Capteur(int capteurid, string d, long double lat, long double lon);
	friend ostream & operator<<(ostream &out, const Capteur &capteur); 
	
	friend bool operator==(const Capteur& capteur1, const Capteur& capteur2);

    Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur ( );
    // Mode d'emploi :
    //
    // Contrat :
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
