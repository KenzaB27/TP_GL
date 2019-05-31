/*************************************************************************
                           Seuil  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Seuil> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Seuil.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies



//----------------------------------------------------- M�thodes publiques

int Seuil::getMin()
{
	return min;
}

int Seuil::getMax()
{
	return max;
}


int Seuil::getIndice()
{
	return indice;
}

void Seuil::setMin(int mi)
{
	min = mi;
}

void Seuil::setMax(int ma)
{
	max = ma; 
}

void Seuil::setIndice(int ind)
{
	indice = ind; 
}


//------------------------------------------------- Surcharge d'op�rateurs
Seuil & Seuil::operator = ( const Seuil & unSeuil )
// Algorithme : Affecte tout les attributs du deuxième
// Seuil dans le premier.
//
{
	min=unSeuil.min;
	max=unSeuil.max;
	indice=unSeuil.indice;
	return *this;
} //----- Fin de operator =


ostream & operator << ( ostream & out, const Seuil & unSeuil )
// Algorithme : Affiche les attributs de Seuil
{
	out << "min : " <<unSeuil.min<<" max : "<<unSeuil.max<<" indice : "<<unSeuil.indice<<endl;
	return out;
}//--- Fin de operator <<

bool operator==(const Seuil& seuil1, const Seuil& seuil2)
// Algorithme : Test l'égalité entre tout les attributs et 
// retourne vrai si les attributs sont égaux entre eux.
{
	return ((seuil1.max==seuil2.max) && (seuil1.min == seuil2.min) && (seuil1.indice == seuil2.indice));
}//--- Fin de operator ==

bool operator!=(const Seuil& seuil1, const Seuil& seuil2)
// Algorithme : Test l'égalité entre tout les attributs et 
// retourne vrai aux moins 1 attribut est différent.
{
	return ((seuil1.max != seuil2.max) || (seuil1.min != seuil2.min) || (seuil1.indice != seuil2.indice));
}//--- Fin de operator !=

//-------------------------------------------- Constructeurs - destructeur
Seuil::Seuil ( const Seuil & unSeuil )
// Algorithme : Constructeur de copie, fait une copie
// en profondeur des attributs d'un Seuil à l'autre.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Seuil>" << endl;
#endif

    min=unSeuil.min;
    max=unSeuil.max;
    indice=unSeuil.indice;
} //----- Fin de Seuil (constructeur de copie)

Seuil::Seuil()
// Algorithme : Constructeur par défaut, tout les attributs 
// sont mis à zéro.
{
	min = 0;
	max = 0;
	indice = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Seuil>" << endl;
#endif
}  //----- Fin de Seuil (constructeur par défaut)

Seuil::Seuil(int unMin,int unMax,int unIndice)
// Algorithme : Constructeur de Seuil
//
{
	min = unMin;
	max = unMax;
	indice = unIndice;
#ifdef MAP
    cout << "Appel au constructeur de <Seuil>" << endl;
#endif
} //----- Fin de Seuil


Seuil::~Seuil ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Seuil>" << endl;
#endif
} //----- Fin de ~Seuil


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
