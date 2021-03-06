/*************************************************************************
                           PorteeCapteur  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <PorteeCapteur> (fichier ${file_name}) ------
#if ! defined ( Tests_h )
#define Tests_h

#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <MesureGaz>
//
//
//------------------------------------------------------------------------ 

//----------------------------------------------------------------- PUBLIC
class Tests
{

public:
//----------------------------------------------------- Méthodes publiques

    void TestMesureGaz();

    int main();

    void TestCatalogue();

	void TestGestion();

    void TestChangerSeuil();
 
//------------------------------------------------- Surcharge d'operateurs
  
    //-------------------------------------------- Constructeurs - destructeur

//----------------------------------Attributs:
 };

//----------------------------------------- Types dépendants de <MesureGaz>

#endif // MesureGaz_H
