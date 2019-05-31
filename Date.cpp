#define _CRT_SECURE_NO_WARNINGS
/*************************************************************************
                           Date 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/
//---------- Realisation de la classe <Date> ----------

////////////////////////////////////////////////////////////////////// INCLUDES
//--------------------------------------------------------- Includes systeme --
#include <iostream>
#include <algorithm>    // std::any_of
#include <array>
#include <ctime>
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

Date Date::precedent()
{
	array<int, 7> phalange = {1, 3, 5, 7, 8, 10, 12}; //mois de 31 jours
	array<int, 7> normal = {4, 6, 9, 11}; //mois de 30 jours
	Date jourPrecedent = *this;

	if(this->jour == 1) // Si on est le premier jour d'un mois on repasse au mois précédent
	{
		if(this->mois != 1)
		{
			if(find(phalange.begin(), phalange.end(), this->mois-1) != phalange.end()) // Si le mois précédent est un mois de 31 jours
			{
				jourPrecedent.jour = 31;
			}
			else if (find(normal.begin(), normal.end(), this->mois - 1) != normal.end()) // Si c'est un mois de 30 jours
			{
				jourPrecedent.jour = 30;
			}
			else if(this->mois-1 == 2)
			{
				if(this->annee % 4 != 0)
				{
					jourPrecedent.jour = 28;
				}
				if (this->annee % 4 == 0)
				{
					jourPrecedent.jour = 29;
				}
			}
			jourPrecedent.mois--;
		}
		else { //on est le premier janvier
			jourPrecedent.jour = 31;
			jourPrecedent.mois = 12;
			jourPrecedent.annee--;
		}
	}
	else
	{
		jourPrecedent.jour--;
	}

	return jourPrecedent;
}

Date Date::now()
{
	Date nowDate = *this;
	time_t now = time(0);
	tm *gmtm = gmtime(&now);

	this->annee = gmtm->tm_year+1970;
	this->mois = gmtm->tm_mon+1;
	this->jour = gmtm->tm_mday;
	this->heure = gmtm->tm_hour;
	this->minutes = gmtm->tm_min;
	this->secondes = (double)gmtm->tm_sec;

	return nowDate;
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

Date::Date(string s)
{
#ifdef MAP
	cout << "Construction Date : heure=" << heure << " minutes="
		 << minutes << endl;
#endif

	// string to date
	string datePart = s.substr(0, s.find("T"));
	string heurePart = s.substr(s.find("T") + 1, s.length());

	//Traitement de la date
	string delimiter = "-";
	auto pos = datePart.find(delimiter);
	string temp = datePart.substr(0, pos);
	annee = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	pos = datePart.find(delimiter);
	temp = datePart.substr(0, pos);
	mois = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	pos = datePart.find(delimiter);
	temp = datePart.substr(0, pos);
	jour = atoi(temp.c_str());
	datePart.erase(0, pos + delimiter.length());

	//Traitement de l'heure
	delimiter = ":";
	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	heure = atoi(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	minutes = atoi(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

	pos = heurePart.find(delimiter);
	temp = heurePart.substr(0, pos);
	secondes = atof(temp.c_str());
	heurePart.erase(0, pos + delimiter.length());

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
