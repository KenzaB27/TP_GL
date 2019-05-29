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
	int getMin(); 
	int getMax(); 
	int getIndice();

	void setMin(int mi);
	void setMax( int ma);
	void setIndice(int ind);

	//------------------------------------------- Surcharge d'operateurs --
	Seuil & operator = (const Seuil & Seuil );
	friend ostream & operator << ( ostream & out, const Seuil & Seuil );
	friend bool operator==(const Seuil& seuil1, const Seuil& seuil2);
	friend bool operator!=(const Seuil& seuil1, const Seuil& seuil2);
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
void afficher();

//------------------------------------------------- Surcharge d'opérateurs
    /*Seuil & operator = ( const Seuil & unSeuil );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


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
