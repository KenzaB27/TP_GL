/*************************************************************************
                           MesureGaz 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( MesureGaz_H )
#define MesureGaz_H

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"
#include "Capteur.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
enum id{O3, NO2, SO2, PM10};
//------------------------------------------------------------------------ 
// Rôle de la classe <MesureGaz>
//
//
//------------------------------------------------------------------------ 

class MesureGaz
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int getGazId() const;
  // Mode d'emploi : récupère le gazId d'une MesureGaz
  //Retour : un int correspondant au gazId
  // Contrat : Aucun contrat 

    string getUnite() const;
  // Mode d'emploi : récupère l'unité d'une MesureGaz
  //Retour : un string correspondant a l'unité
  // Contrat : Aucun contrat    

    string getDescription() const;
  // Mode d'emploi : récupère la description d'une MesureGaz
  //Retour : un string correspondant a la description
  // Contrat : Aucun contrat  

    Date getDate() const;
  // Mode d'emploi : récupère la date d'une MesureGaz
  //Retour : une Date correspondant a la date
  // Contrat : Aucun contrat

    long double getValeur() const;
 // Mode d'emploi : récupère la valeur d'une MesureGaz
  //Retour : un long double correspondant a la valeur
  // Contrat : Aucun contrat

    int getIdCapteur() const;
 // Mode d'emploi : récupère le idCapteur d'une MesureGaz
  //Retour : un int correspondant a l'IdCapteur
  // Contrat : Aucun contrat

    void setGazId(int val);
 // Mode d'emploi : définit l'id d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    void setDate(Date d);
 // Mode d'emploi : définit la date d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    void setValeur(long double val);
 // Mode d'emploi : définit la valeur d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    void setIdCapteur(int c);
 // Mode d'emploi : définit l'IdCapteur d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    void setDescription(string d);
 // Mode d'emploi : définit la description d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    void setUnite(string u);
 // Mode d'emploi : définit l'unité d'une MesureGaz
  //Retour : aucun
  // Contrat : Aucun contrat

    //------------------------------------------------- Surcharge d'operateurs
    friend ostream &operator<<(ostream &out, const MesureGaz &mesureGaz);
 // Mode d'emploi : affcihe une MesureGaz sur la sortie
 //out : le flux sur lequel afficher la MesureGaz
 //mesureGaz : la MesureGaz à afficher
  //Retour : aucun
  // Contrat : Aucun contrat

	operator long double()const;

    //-------------------------------------------- Constructeurs - destructeur
    MesureGaz(int typegaz, Date hr, long double v, int c, string d);
    // Mode d'emploi : Construit une MesureGaz 
    //typegaz : le type de gaz
    //hr : la date de la mesure
    //v : la valeur du gaz
    //c : l'IdCapteur
    //d : la description
    // Contrat : Aucun contrat

    MesureGaz();
   // Mode d'emploi : Crée une MesureGaz vide (pas d'attributs)
    // Contrat : Aucun contrat
    //

    virtual ~MesureGaz ( );
    // Mode d'emploi : Destructeur de la MesureGaz
    // Contrat : Aucun contrat
    //


//----------------------------------Attributs

    protected:
    int gazId; //a changer dans le diagramme de classes
    string unite;
    string description;
    Date date;
    long double valeur;
    int idCapteur;
 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
