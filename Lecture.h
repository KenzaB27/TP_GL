/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier ${file_name}) ------
#if !defined(XXX_H)
#define XXX_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Lecture>
    //
    //
    //------------------------------------------------------------------------

class Lecture
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode demploi
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Lecture &operator=(const Lecture & unLecture);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Lecture(const Lecture & unLecture);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture();
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

    //----------------------------------------- Types dépendants de <Lecture>

#endif // XXX_H