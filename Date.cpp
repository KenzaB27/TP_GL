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
#include <algorithm>    // std::any_of
#include <array>
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
	array<int, 7> phalange = { 1,3,5,7,8,10,12};
	array<int, 7> normal = {4,6,9,11};
	Date jourSuivant = *this;
	if ((find(phalange.begin(), phalange.end(), this->mois) != phalange.end() && this->jour == 31) ||
		(find(normal.begin(), normal.end(), this->mois) != normal.end() && this->jour == 30)||
		(this->mois == 2 && ((this->annee % 4 == 0 && this->jour == 29) || (this->annee % 4 != 0 && this->jour == 28))))
	{
		jourSuivant.mois++;
		jourSuivant.jour = 1;
		if (this->mois == 12)
		{
			jourSuivant.mois = 1;
			jourSuivant.annee++;
		}
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
	return false; 
}//--- Fin de operator <


bool Date::operator >= ( const Date & date ) const
{
	return ! ( *this < date );
}
bool Date::operator<=(const Date & date) const
{
	return (*this < date ||*this == date); 
}
//--- Fin de operator >=



ostream & operator << ( ostream & out, const Date & date )
{
	out << date.annee<<"/"<<date.mois<<"/"<<date.jour<<" "<<date.heure << ":" << date.minutes <<":" << date.secondes << endl;
	return out;
}//--- Fin de operator <<

bool operator==(const Date &date1, const Date &date2)
{
	return (date1.annee==date2.annee && date1.mois == date2.mois && date1.jour == date2.jour
			&& date1.heure == date2.heure && date1.minutes == date2.minutes && date1.jour == date2.jour);
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
