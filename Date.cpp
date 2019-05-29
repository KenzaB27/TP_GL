/******************************************************************************
		Date - Conteneur pour une date (ici HH:MM)

	debut		: 
	copyright	: (C) 2018 par 
	e-mail		: 
******************************************************************************/
//---------- Realisation de la classe <Date> ----------

////////////////////////////////////////////////////////////////////// INCLUDES
//--------------------------------------------------------- Includes systeme --
#include <iostream>

using namespace std;

//------------------------------------------------------ Includes personnels --
#include "Date.h"

//------------------------------------------------------------------ CONSTANTES


//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
//-------------------------------------------------- Surcharge d'operateurs --
Date & Date::operator = ( const Date & date )
{
	jour=date.jour; 
	mois=date.mois; 
	annee=date.annee; 
	heure = date.heure;
	minutes = date.minutes;
	secondes=date.secondes;
	return *this;
}//--- FIn de operator =


Date Date::suivant()
{
	Date jourSuivant = *this;
	if ((this->mois == 2 && (this->annee % 4 == 0 && this->jour == 29) || (this->annee % 4 != 0 && this->jour == 28)) 
		|| (this->mois != 2 && (this->mois % 2 == 1 && this->jour == 31) || (this->mois % 2 == 0 && this->jour == 30)))
	{
		jourSuivant.mois++;
		jourSuivant.jour = 1;
	}
	else if (this->mois == 12) 
	{
		jourSuivant.annee ++; 
	}
	else {
		jourSuivant.jour++; 
	}
	return jourSuivant; 
}

bool Date::operator < ( const Date & date ) const
{
	if ( annee < date.annee )
	{
		return true;
	}
	else if ( annee == date.annee )
	{
		if(mois<date.mois)
		{
			return true; 
		}
		else if (mois==date.mois)
		{
			if (jour<date.jour)
			{
				return true; 
			}
			else if (jour==date.jour)
			{
				if (heure<date.heure)
				{
					return true; 
				}
				else if (heure==date.heure)
				{
					if (minutes<date.minutes)
					{
						return true; 
					}
					else if (minutes==date.minutes)
					{
							return secondes<date.secondes ; 
					}
				}
			}
		}
	}
	else
	{
		return false;
	}
}//--- Fin de operator <


bool Date::operator >= ( const Date & date ) const
{
	return ! ( *this < date );
}
bool Date::
operator<=(const Date & date) const
{
	return (*this < date || *this == date); 
}
//--- Fin de operator >=



ostream & operator << ( ostream & out, const Date & date )
{
	out << date.annee<<"/"<<date.mois<<"/"<<date.jour<<" "<<date.heure << ":" << date.minutes <<":" << date.secondes << endl;
	return out;
}//--- Fin de operator <<

bool operator==(const Date &date1, const Date &date2)
{
	return date1>=date2; 
} //--- Fin de operator ==

//---------------------------------------------- Constructeurs - Destructeur --
Date::Date(int lannee, int lmois, int ljour, int lHeure, int lesMinutes, long double lesSecondes) : annee(lannee),
																							   mois(lmois), jour(ljour), heure(lHeure), minutes(lesMinutes), secondes(lesSecondes)
{
#ifdef MAP
	cout << "Construction Date : heure=" << heure << " minutes="
		<< minutes << endl;
#endif
}//--- Fin de Date

Date::Date(string date, string temps)
{
#ifdef MAP
	cout << "Construction Date : heure=" << heure << " minutes="
		 << minutes << endl;
#endif
} //--- Fin de Date

/*Date::Date ( const Date & date ) : heure(date.heure), minutes(date.minutes) 
{
#ifdef MAP
	cout << "Construction Date par copie" << endl;
#endif
}//--- Fin de Date*/

Date::Date() 
{
#ifdef MAP
	cout << "Construction Date par copie" << endl;
#endif
}//--- Fin de Date


Date::~Date ()
{
#ifdef MAP
	cout << "Destruction Date par copie" << endl;
#endif
}//--- Fin de ~Date
///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --
