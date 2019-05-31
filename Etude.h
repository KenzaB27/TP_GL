/*************************************************************************
                           Etude
                             -------------------
    début                : 04/06/2019
    copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan 
									    HAMIDOVIC David - CAVAGNA Margaux 
*************************************************************************/

//---------- Interface de la classe <Etude> (Etude.h) ------
#if ! defined (ETUDE_H)
#define ETUDE_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <math.h>	
#include "Date.h"
#include "Capteur.h"
#include "PorteeCapteur.h"
#include "Catalogue.h"
#include "Seuil.h"
#include "ConcentrationIndice.h"

using namespace std; 

//------------------------------------------------------------------------
// Rôle de la classe <Etude>
// Cette classe implémente toutes les méthodes permettant d'évaluer la qualité 
// de l'air à travers les calculs d'ATMO 
//
//------------------------------------------------------------------------

class Etude 
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    vector<ConcentrationIndice> Evaluer(Catalogue &cat, vector<Capteur> &listCapteur,
								unordered_map<int, vector<Seuil>>&mapSeuils , 
                                long double latitude, long double longitude, Date dateDebut, 
								Date dateFin = Date(), long double rayon = 2000);
	// Mode d'emploi : Permet l'évaluation de la concentration des dofférents gaz O3 PM10 SO2
	// et NO2 ainsi que leurs indices associés, et ce dans un territoire ou point précis, pendant 
	// une durrée donnée délimitée par date de début et date de fin
	// cat : correspond au catalogue stokant les différentes mesures
	// listCapteur : correspond à la liste des capteusr du sysytème
	// mapSeuils: regroupe les différents seuils déterminés par les oragnismes délimitanat les indices des gaz
	// latitude: la latitude du point de calcul ou centre du territoire 
	// longitude: la longitude du point de calcul ou centre du territoire 
	// dateDebut: la date de début de l'évaluation 
	// dateFin : la date de fin de l'évaluation = la date du jour suivant par défaut
	// rayon : le rayon du territoire de calcul = 2000m par défaut
	// Contrat : Aucun contrat 
	//
    int CalculAtmo(vector<ConcentrationIndice>&mesures);
	// Mode d'emploi : renvoir l'indice Atmo correcpondant aux concentrations évaluées par la méthode Evaluer
	// mesures: la lisite des concentrations avec leur indice associé
	//
	// Contrat : Aucun contrat
	//
	unordered_map <int, vector<int>> MesuresTotParCapteurs(Catalogue &c, int nbCapteurs=10);
	// Mode d'emploi : permet de calculer la moyenne des mesures des capteurs pour chacun des gazs
	// c : le catalogue de mesures 
	// nbCapteurs: le nombre de capteurs à évaluer
	//
	// Contrat : Aucun contrat 
	//

	unordered_map < int , int** >  EcartCapteurs(unordered_map <int, vector<int>> mapMoyenne , int nbCapteurs=10);
	// Mode d'emploi : permet de calculer l'ecart entre les mesures des capteurs pour chacun des gazs
	// mapMoyenne : la map des moyennes 
	// Contrat : Aucun contrat 
	//

	bool** DeterminerCapteursSimilaires(unordered_map < int, int** > matriceEcart , double ecart , int nbCappteurs=10 );
	// Mode d'emploi : permet determiner les capteurs similaires selon la precision déterminée par le client
	// matriceEcart : la matrice des ecarts par gaz
	// ecart : l'ecart de tolérance
	// Contrat : Aucun contrat 
	//
	

//-------------------------------------------- Constructeurs - destructeur

    Etude ();
    // Mode d'emploi : Constructeur de la classe 
    //
    // Contrat : Aucun Contrat 
    //

    virtual ~Etude ( );
    // Mode d'emploi : destucteur de la classe 
    //
    // Contrat : Aucun contrat 
    //

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
//protected: 

	vector<ConcentrationIndice> evaluer(Catalogue &cat, vector<int>&listCapteur , 
			unordered_map<int, vector<Seuil>>&mapSeuils, Date dateD, Date dateF = Date());
	// Mode d'emploi : Permet l'évaluation de la concentration des dofférents gaz O3 PM10 SO2
	// et NO2 ainsi que leurs indices associés, et ce dans un territoire ou point précis, pendant 
	// une durrée donnée délimitée par date de début et date de fin
	// cat : correspond au catalogue stokant les différentes mesures
	// listCapteur : correspond à la liste des capteusr du sysytème
	// mapSeuils: regroupe les différents seuils déterminés par les oragnismes délimitanat les indices des gaz
	// dateDebut: la date de début de l'évaluation 
	// dateFin : la date de fin de l'évaluation = la date du jour suivant par défaut
	// rayon : le rayon du territoire de calcul = 2000m par défaut
	// Contrat : Aucun contrat 
	//
	vector<int> getCapteur(vector<Capteur>&listCapteur, long double latitude, long double longitude, long double rayon = 2000);
	// Mode d'emploi: permet de récupérer la liste des id de scapteurs appartenant au territoire de calcul 
	// listCapteur : correspond à la liste des capteurs du sysytème
	// latitude: la latitude du point de calcul ou centre du territoire 
	// longitude: la longitude du point de calcul ou centre du territoire 
	// rayon : le rayon du territoire de calcul = 2000m par défaut
	// Contrat : Aucun contrat 
	// 
	bool comparerMesures(vector<long double> &mes1, vector<long double>&mes2); 
	// Mode d'emploi: permet de comparer 2 liste de mesures
	// mes1 : la liste de mesure 1
	// mes2 : la liste de mesure 2
	// Contrat : Aucun contrat
};
#endif // Etude
