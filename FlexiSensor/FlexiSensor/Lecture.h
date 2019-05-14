/*************************************************************************
						   Lecture  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier ${file_name}) ------
#if !defined(XXX_H)
#define XXX_H

	//--------------------------------------------------- Interfaces utilis�es

	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//------------------------------------------------------------------------
	// R�le de la classe <Lecture>
	//
	//
	//------------------------------------------------------------------------

class Lecture
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode demploi
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s
};

//----------------------------------------- Types d�pendants de <Lecture>

#endif // XXX_H#pragma once
