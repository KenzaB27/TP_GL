/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ------
#if ! defined ( UTILISATEUR_H )
#define UTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    /*Utilisateur & operator = ( const Utilisateur & unUtilisateur );
    // Mode d'emploi :
    //
    // Contrat :
    //
     */


//-------------------------------------------- Constructeurs - destructeur
    Utilisateur ( const Utilisateur & unUtilisateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
string mail;
string password;
bool isAdmin;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Utilisateur>

#endif // UTILISATEUR_H
