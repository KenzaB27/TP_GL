/*************************************************************************
                           IdCatalogue  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <IdCatalogue> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE
#include "Date.h"
#include "IdCatalogue.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>


//---------------------------------------------Methodes publiques

int IdCatalogue::getCapteurId() const{
    return capteurId;
}

Date IdCatalogue::getDateMesure() const{
    return dateMesure;
}

bool operator==(const IdCatalogue & unIdCatalogue1, const IdCatalogue & unIdCatalogue2)
{
	if (unIdCatalogue1.capteurId == unIdCatalogue2.capteurId && unIdCatalogue1.dateMesure == unIdCatalogue2.dateMesure)
	{
		return true;
	}
	return false;
}

ostream & operator<<(ostream &out, const IdCatalogue &idCatalogue)
{
	out << idCatalogue.capteurId << " " << idCatalogue.dateMesure << endl;
	return out; 
}


IdCatalogue::IdCatalogue(int cI, Date dm)
{
    #ifdef MAP
        cout << "Appel au constructeur de <IdCatalogue>" << endl;
    #endif

    capteurId=cI;
    dateMesure=dm;

} //----- Fin de IdCatalogue

IdCatalogue::IdCatalogue(){
    //Constructeur par défaut ------ l'objet est vide
}

IdCatalogue::~IdCatalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IdCatalogue>" << endl;
#endif
} //----- Fin de ~IdCatalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
