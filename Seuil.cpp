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

void Seuil::afficher() {
	cout<<"min : "<<min<<"  max : "<<max<<" indice : "<<indice<<endl;
}

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
// Algorithme :
//
{
	min=unSeuil.min;
	max=unSeuil.max;
	indice=unSeuil.indice;
	return *this;
} //----- Fin de operator =


ostream & operator << ( ostream & out, const Seuil & unSeuil )
{
	out << "min : " <<unSeuil.min<<" max : "<<unSeuil.max<<" indice : "<<unSeuil.indice<<endl;
	return out;
}//--- Fin de operator <<

bool operator==(const Seuil& seuil1, const Seuil& seuil2)
{
	return ((seuil1.max==seuil2.max) && (seuil1.min == seuil2.min) && (seuil1.indice == seuil2.indice));
}

bool operator!=(const Seuil& seuil1, const Seuil& seuil2)
{
	return ((seuil1.max != seuil2.max) || (seuil1.min != seuil2.min) || (seuil1.indice != seuil2.indice));
}

//-------------------------------------------- Constructeurs - destructeur
Seuil::Seuil ( const Seuil & unSeuil )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Seuil>" << endl;
#endif

    min=unSeuil.min;
    max=unSeuil.max;
    indice=unSeuil.indice;
} //----- Fin de Seuil (constructeur de copie)

Seuil::Seuil()
// Algorithme :
//
{
	min = 0;
	max = 0;
	indice = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Seuil>" << endl;
#endif
} 

Seuil::Seuil(int unMin,int unMax,int unIndice)
// Algorithme :
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
