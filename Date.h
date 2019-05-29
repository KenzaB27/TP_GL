/******************************************************************************
		Date - Conteneur pour une date (ici HH:MM)

	debut		: 2019-01-16
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Interface de la classe <Date> ----------
#ifndef DATE_H
#define DATE_H

////////////////////////////////////////////////////////// Interfaces utilisees
#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types


//-----------------------------------------------------------------------------
//	Role de la classe <Date>
//		Permet de stocker une date sous la forme d'une heure et de minutes.
//		Permet de comparer des dates entres elles.
//-----------------------------------------------------------------------------
struct Date
{

//////////////////////////////////////////////////////////////////////// PUBLIC
public :
	//----------------------------------------------- Methodes publiques --
	//------------------------------------------- Surcharge d'operateurs --
	Date & operator = (const Date & date );
	// Mode d'emploi :
	//	Operateur d'affectation de la classe
	//	date : la date a copier
	//	retour : reference sur la date qui a ete affectee.
	// Contrat :
	//	Aucun contrat.

	Date suivant(); 

	bool operator < ( const Date & date ) const;
	// Mode d'emploi :
	//	Permet de comparer la date entre deux dates. Compare heure et minutes.
	//	date : la date a comparer
	//	retour : suivant le resultat de la comparaison
	// Contrat :
	//	Aucun contrat.

	bool operator >= ( const Date & date ) const;
	// Mode d'emploi :
	//	Permet de comparer la date entre deux dates. Compare heure et minutes.
	//	date : la date a comparer
	//	retour : suivant le resultat de la comparaison
	// Contrat :
	//	Aucun contrat.
	bool operator <= (const Date & date) const;

	friend bool operator==(const Date &date1 , const Date &date2);
	// Mode d'emploi :
	//	Permet de comparer la date entre deux dates. Compare heure et minutes.
	//	date : la date a comparer
	//	retour : suivant le resultat de la comparaison
	// Contrat :
	//	Aucun contrat.

	friend ostream & operator << ( ostream & out, const Date & date );
	// Mode d'emploi :
	//	Permet d'afficher une date a l'ecran (ou dans un fichier)
	//	out : le flux de sortie sur lequel on affiche la date
	//	date : la date a afficher
	//	retour : le flux de sortie (out)
	// Contrat :
	//	Aucun contrat.


	//-------------------------------------- Constructeurs - Destructeur --
	Date (int lannee,int lmois, int ljour,int lHeure , int lesMinutes, long double lesSecondes);
	// Mode d'emploi :
	//	Permet de creer une date
	//	lHeure : l'heure de la date.
	//	lesMinutes : les minutes de la date.
	//  lesSecondes : les secondes de la date 
	// Contrat:
	//	Aucun contrat.

	Date(string date, string heure);
	// Mode d'emploi :
	//	Permet de creer une date à partir d'un string contenant jour-mois-année
	// Et d'un autre string contenant heure:minute:secondes
	// Contrat:
	//	Aucun contrat.

	//Date ( const Date & date );
	// Mode d'emploi :
	//	Constructeur de copie de la classe Date.
	//	date : la date a copier.
	// Contrat :
	//	Aucun contrat.

	Date();


	virtual ~Date();
	// Mode d'emploi :
	//	Destructeur de la classe Date.
	// Contrat :
	//	Aucun contrat.

	//----------------------------------------------- Attributs publics --
	int jour; 
	int mois; 
	int annee; 
	int heure;		
	int minutes;
	long double secondes; 	

};

//-------------------------- Autres definitions dependantes de Date --------

#endif // ifndef DATE_H
