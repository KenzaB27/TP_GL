/*************************************************************************
                           ${Capteur}  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
    int getCapteurId();
    string getDescription();
    PorteeCapteur getPortee();
    int getEtat();
//-------------------------------------------- Constructeurs - destructeur

    Capteur(int capteurid, string d, long double lat, long double lon);


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
