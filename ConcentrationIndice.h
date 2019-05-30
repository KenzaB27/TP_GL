/*************************************************************************
                           ConcentrationIndice  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <ConcentrationIndice> (fichier ConcentrationIndice.h) ------
#if ! defined ( CONCENTRATIONINDICE_H )
#define CONCENTRATIONINDICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Seuil.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------

class ConcentrationIndice
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void setIndice(vector<Seuil> &listeSeuils); 
// type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    
	friend ostream & operator<<(ostream &out, const ConcentrationIndice &concentration); 

//-------------------------------------------- Constructeurs - destructeur
	ConcentrationIndice(long double constra );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ConcentrationIndice( );
    // Mode d'emploi :
    //
    // Contrat :
    //

public: 
//----------------------------------------------------- Attributs protégés
	long double concentration; 
	int indice; 

};

//----------------------------------------- Types dépendants de <Utilisateur>

#endif // CONCENTRATIONINDICE_H
