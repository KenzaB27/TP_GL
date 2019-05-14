/*************************************************************************
                           Seuil  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Seuil> (fichier ${file_name}) ------
#if ! defined ( Seuil_H )
#define Seuil_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Seuil>
//
//
//------------------------------------------------------------------------ 

class Seuil
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
    /*Seuil & operator = ( const Seuil & unSeuil );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


//-------------------------------------------- Constructeurs - destructeur
    /*Seuil ( const Seuil & unSeuil );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
	Seuil(int unMin,int unMax,int unIndice);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Seuil ( );
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

private:
//------------------------------------------------------- Attributs privés
	int min;
	int max;
	int indice;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Seuil>

#endif // Seuil_H
