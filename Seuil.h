/*************************************************************************
                           Seuil 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
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
int getMin();
int getMax();
int getIndice();

void setMin(int mi);
void setMax(int ma);
void setIndice(int ind);


//------------------------------------------------- Surcharge d'opérateurs

Seuil& operator = (const Seuil& Seuil);
// Mode d'emploi :
//	Operateur d'affectation de la classe
//	seuil : le seuil est copié
//	retour : reference sur la date qui a été affectée.
// Contrat :
//	Aucun contrat.
friend ostream& operator << (ostream& out, const Seuil& Seuil);
// Mode d'emploi :
//	Operateur d'insertion de la classe
//	seuil 
//	retour : reference le flux de sortie
// Contrat :
//	Aucun contrat.
friend bool operator==(const Seuil& seuil1, const Seuil& seuil2);
// Mode d'emploi :
//	Operateur d'égalité de la classe
//	seuil 
//	retour : le bool évaluant la réussite
//	ou non du test.
// Contrat :
//	Aucun contrat.
friend bool operator!=(const Seuil& seuil1, const Seuil& seuil2);
// Mode d'emploi :
//	Operateur différent de la classe
//	seuil 
//	retour : le bool évaluant la réussite
//	ou non du test.
// Contrat :
//	Aucun contrat.


//-------------------------------------------- Constructeurs - destructeur
    Seuil ( const Seuil & unSeuil );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Seuil();
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
