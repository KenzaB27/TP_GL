/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <PorteeCapteur>
//
//
//------------------------------------------------------------------------ 

class PorteeCapteur : public Ancetre
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
    PorteeCapteur & operator = ( const PorteeCapteur & unPorteeCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PorteeCapteur ( const PorteeCapteur & unPorteeCapteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PorteeCapteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PorteeCapteur ( );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <PorteeCapteur>

#endif // XXX_H