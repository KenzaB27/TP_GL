/*************************************************************************
                           Menu 
                             -------------------
	début                : 04/06/2019
	copyright            : (C) 2019 par BOUZID Kenza    - JEANNE Nathan
										HAMIDOVIC David - CAVAGNA Margaux
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Gestion.h"
#include "Etude.h"
#include "Catalogue.h"
#include "Seuil.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Menu::run()
{
	string inputLine = "";

	do
	{
		// Lecture de la commande utlisateur 
		cout << ">";
		//cin >> inputLine;
		getline(cin, inputLine);

		//Traitement de la commande 
		if(!traitement(inputLine)) 
			cout << "commande inexistante, tapez 'help' pour la liste des commandes" << endl;

	} while (inputLine.compare("exit"));
	
}


//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Menu>" << endl;
#endif

	c = new Catalogue();

} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Menu>" << endl;
#endif
	delete c;
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes privées


bool Menu::traitement(string input)
{	
	vector<string> argList; //Liste des arguments passés dans la commande (les -s)
	unordered_map<string,string> valueList; //Liste des valeurs des paramètres passés dans la commande (les -r=X)

	split(argList, valueList, input);


	if (argList.empty()) return true;

	if (commande(argList, "exit")) return true;

	if (commande(argList, "help")) //------------------------------------- Page d'aide des commandes
	{
		try
		{
			vector<string> listeCommandes;
			l.getCommandes(listeCommandes, "../Fichiers/commandes.csv");

			cout << "[help] Liste des commandes disponibles : " << endl;
			for (unsigned int i = 0; i < listeCommandes.size(); i++)
			{
				cout << "\t" << listeCommandes[i] << endl;
			}
		}
		catch (const std::exception&)
		{
			cout << "[help] erreur lors de l'affichage de la liste des commandes" << endl;
		}
		

		return true;
	}


	if(commande(argList, "atmo")) //------------------------------------- Etude de l'ATMO
	{
		// On a toujours -lat= et -long= 
		// La date si elle n'est pas mise est celle d'hier
		// Param a mettre -r -d si date et rayon, sinon que latitude et longitude 
		// -dateF=  pour date de fin & -dateD= pour date début
		// Format de date : YYYY-MM-DDTHH:MM:SS.SSSSSSSS
		// -s si valeurs a afficher
		

		long double lat = atof(valueList.find("-lat")->second.c_str());
		long double lon = atof(valueList.find("-long")->second.c_str());;
		
		double rayon = commande(argList, "-r") ? atof(valueList.find("-r")->second.c_str()) : 2000;
		
		Date dateD;
		Date dateF;
		dateF = commande(argList, "-d") ? Date(valueList.find("-dateF")->second.c_str()) : dateF.precedent();
		dateD = commande(argList, "-d") ? Date(valueList.find("-dateD")->second.c_str()) : dateF.now();
			
		if (commande(argList, "-s"))
		{
			try
			{
				cout << "[atmo] " << endl;
				vector<ConcentrationIndice> result = e.Evaluer(*c, listeCapteurs, tabSeuils, lat, lon, dateD, dateF, rayon);
				afficherSousIndiceAtmo(result);
			}
			catch (const std::exception&)
			{
				cout << "[atmo] erreur lors de l'affichage des valeurs" << endl;
			}
			
		}
		else
		{
			try
			{
				vector<ConcentrationIndice> mesures = e.Evaluer(*c, listeCapteurs, tabSeuils, lat, lon, dateD, dateF, rayon);
				int atmo = e.CalculAtmo(mesures);
				cout << "L'indice ATMO à la date " << dateF << "est " << atmo << endl;
			}
			catch (const std::exception&)
			{
				cout << "[atmo] erreur lors du calcul de l'atmo" << endl;
			}
			
		}

		return true;
	}


	if (commande(argList, "stats")) //----------------------------------- Etude des statistiques
	{
		// Commande de la forme : stats -n=3 pour l'etude de 3 capteurs
		try
		{
			int n = commande(argList, "-n") ? atoi(valueList.find("-n")->second.c_str()) : 10;
			string gaz = valueList.find("-gaz")->second;

			cout << "[stats] Calculs en cours..." << endl;

			unordered_map<int, vector<long double> > moyenneCapteur = e.MesuresTotParCapteurs(*c, n);
			afficheMatMoyenne(moyenneCapteur);
			unordered_map<int, long double**> matriceEcart = e.EcartCapteurs(moyenneCapteur);

			if (valueList.find("-gaz")->second == "a") //On étudie tous les gaz
			{
				bool ** matSimilarite = e.DeterminerCapteursSimilaires(matriceEcart, 10);
				afficheMatSimilarite(matSimilarite, "Tous", 10);
			}
			else {
				double ecart = atof(valueList.find("-e")->second.c_str());
				bool ** matSimilarite = e.DeterminerCapteursSimilairesParGaz(matriceEcart[l.getGazName()[gaz]], ecart);

				afficheMatEcart(gaz, matriceEcart[l.getGazName()[gaz]]);
				afficheMatSimilarite(matSimilarite, gaz, ecart);

			}
		}
		catch (const std::exception&)
		{
			cout << "[stats] erreur lors des calculs de statistique" << endl;
		}
		

		return true;
	}

	if (commande(argList, "sensor")) //---------------------------------- Gestion des capteurs
	{
		if (commande(argList, "add"))
		{
			try
			{
				long double lat = atof(valueList.find("-lat")->second.c_str());
				long double lon = atof(valueList.find("-long")->second.c_str());;
				string description = valueList.find("-d")->second;
				int cId = atoi(valueList.find("-id")->second.c_str());

				Capteur c(cId, description, lat, lon); // Creation d'un nouveau capteur à partir des paramètres passés
				cout << "[sensor] Ajout d'un nouveau capteur" << "..." << endl;
				g.AjouterCapteur(c, listeCapteurs);
			}
			catch (const std::exception&)
			{
				cout << "[sensor] erreur lors de l'ajout du capteur" << endl;
			}
			
		}

		if (commande(argList, "remove"))		
		{
			try
			{
				int cId = atoi(valueList.find("-id")->second.c_str());
				cout << "[sensor] Suppresion du capteur numero " << cId << "..." << endl;
				g.SupprimerCapteur(cId, listeCapteurs);
			}
			catch (const std::exception&)
			{
				cout << "[sensor] erreur lors de la suppression du capteur" << endl;
			}
			
		}

		if (commande(argList, "exclude"))
		{
			try
			{
				int cId = atoi(valueList.find("-id")->second.c_str());
				cout << "[sensor] Mise en quarantaine du capteur numero " << cId << "..." << endl;
				g.MettreEnVeilleCapteur(cId, listeCapteurs);
			}
			catch (const std::exception&)
			{
				cout << "[sensor] erreur lors de l'exclusion du capteur" << endl;
			}
		}

		if (commande(argList, "include"))
		{
			try
			{
				int cId = atoi(valueList.find("-id")->second.c_str());
				cout << "[sensor] Inclusion du capteur numero " << cId << "..." << endl;
				g.RestaurerCapteur(cId, listeCapteurs);
			}
			catch (const std::exception&)
			{
				cout << "[sensor] erreur lors de l'inclusion du capteur" << endl;
			}
			
		}

		if (commande(argList, "evaluate"))
		{
			try
			{
				int cId = atoi(valueList.find("-id")->second.c_str());
				cout << "[sensor] Evaluation du capteur numero " << cId << "..." << endl;
				g.EvaluerCapteur(*c, cId);
			}
			catch (const std::exception&)
			{
				cout << "[sensor] erreur lors de l'évaluation du capteur" << endl;
			}
			
		}

		if (commande(argList, "print"))
		{
			
			if (listeCapteurs.size()==0)
			{
				cout << "[sensor] aucun capteurs disponibles" << endl;
			}
			else
			{
				cout << "[sensor]" << endl;
				for (unsigned int i = 0; i < listeCapteurs.size(); i++)
				{
					cout << listeCapteurs[i] << endl;
				}
			}
			
		}
		return true;
	}

	if (commande(argList, "seuil")) //----------------------------------- Gestion du seuil
	{
		if (commande(argList, "print"))
		{
			cout << "[seuils]" << "\n" << endl;
			AfficherSeuils(tabSeuils);
		}
		else
		{
			try
			{
				int gazId = l.getGazName()[valueList.find("-gazId")->second];
				int min = atoi(valueList.find("-min")->second.c_str());
				int max = atoi(valueList.find("-max")->second.c_str());
				int indice = atoi(valueList.find("-indice")->second.c_str());

				Seuil s(min, max, indice);

				cout << "[seuils] Modification du seuil de " << gazId << " en cours..." << endl;

				g.ChangerUnSeuil(tabSeuils, gazId, s);
			}
			catch (const std::exception&)
			{
				cout << "[seuils] erreur lors de la mise à jour des seuils" << endl;
			}
				
		}

		return true;
	}

	if (commande(argList, "run")) //------------ Gestion de la lecture et de l'initialisation 
	{
		string fichierMesures = "../Fichiers/fichier1000.csv";
		string fichierCapteurs = "../Fichiers/capteurComplet.csv";
		string fichierGaz = "../Fichiers/gazTest.csv";
		string fichierSeuils = "../Fichiers/Seuils.csv";

		if (!firstRun) //Si ça n'est pas le premier lancement on vide les listes pour les reremplir
		{
			listeCapteurs.clear();
			c->getMap().clear();
			tabSeuils.clear();
		}

		if (commande(argList, "-define")) 
		{
			fichierMesures = valueList.find("-m")->second;
			fichierCapteurs = valueList.find("-c")->second;
			fichierGaz = valueList.find("-g")->second;
			fichierSeuils = valueList.find("-s")->second;
		}
		
		

		if(firstRun) firstRun = false; //On est passé au moins 1 fois

		try
		{
			cout << "[run] Lecture des fichiers" << endl;
			// Initialisation des seuils, capteurs et gaz
			l.InitSeuils(tabSeuils, fichierSeuils);
			l.InitCapteur(listeCapteurs, fichierCapteurs);
			l.InitTypeGaz(fichierGaz);

			l.Parcourir(c, fichierMesures); //Remplissage du catalogue
		}
		catch (const std::exception&)
		{
			cout << "[run] erreur lors de la lecture des fichiers" << endl;
		}
		

		return true;
	}

	return false;
}

void Menu::AfficherSeuils(unordered_map<int, vector<Seuil>> &umap)
{
	cout << "Indice   |   SO2   |   NO2  |   O3   |   PM   |" << endl;

	auto itPM10 = umap[PM10].rbegin();
	auto itSO2 = umap[SO2].rbegin();
	auto itNO2 = umap[NO2].rbegin();
	auto itO3 = umap[O3].rbegin();

	for (int i = 10; i >= 1; i--)
	{
		cout << i << "        |   " << itSO2->getMin() << "-" << itSO2->getMax() << "   |   "
			<< itNO2->getMin() << "-" << itNO2->getMax() << "   |   "
			<< itO3->getMin() << "-" << itO3->getMax() << "   |   "
			<< itPM10->getMin() << "-" << itPM10->getMax() << "   |   " << endl;
		++itPM10;
		++itSO2;
		++itNO2;
		++itO3;

	}
}

bool Menu::commande(vector<string> c, string s) 
{
	return find(c.begin(), c.end(), s) != c.end();
}

void Menu::split(vector<string> &argList, unordered_map<string, string> &valueList, string s)
{

	string delimiter = " ";
	size_t pos = 0;
	string token;
	char prefix = '-';

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);

		if (token[0] == prefix) //si forme -a ou -aa=555
		{
			size_t pos1 = token.find("=");

			if (pos1 != std::string::npos) // forme -a=66
			{
				string t = token.substr(0, pos1);
				token.erase(0, pos1 + delimiter.length());
				argList.push_back(t);
				valueList.emplace(make_pair(t, token));
			}
			else {
				argList.push_back(token);
			}
		}
		else {
			argList.push_back(token);
		}

		s.erase(0, pos + delimiter.length());
	}
	if (s[0] == prefix) //si forme -a ou -aa=555
	{
		size_t pos1 = s.find("=");

		if (pos1 != std::string::npos) // forme -a=66
		{
			string t = s.substr(0, pos1);
			s.erase(0, pos1 + delimiter.length());
			argList.push_back(t);
			valueList.emplace(make_pair(t, s));
		}
		else {
			argList.push_back(s);
		}
	}
	else {
		argList.push_back(s);
	}
}
void Menu::afficheMatSimilarite(bool**matSimilarite, string gaz, double precision) {
	cout << "Matrices de similarite des capteurs pour le gaz " << gaz << "  avec un ecart tolere de: " << precision << endl << endl;
	cout << "     |";
	for (unsigned int i = 0; i < 10; i++)
	{
		cout << i << "    |";
	}
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		cout << i << "    |";
		for (int j = 0; j < 10; j++)
		{
			cout << matSimilarite[i][j] << "    |";
		}
		cout << endl;
	}
	cout << endl;
}
void Menu::afficheMatMoyenne(unordered_map<int, vector<long double> >moyenneCapteur) {
	cout << "Moyennes des messures de capteurs par gaz" << endl;
	cout << "Capteur n |    O3    |   PM10   |    SO2    |    NO2    |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (auto x : moyenneCapteur)
	{
		cout << x.first << "         |" <<
			x.second[O3] << "   | " <<
			x.second[PM10] << "  | " <<
			x.second[SO2] << "   | " <<
			x.second[NO2] << "   | " << endl;
	}
	cout << endl;
}
void Menu::afficheMatEcart(string gaz, long double** matriceEcartGaz, int nbCapteurs ) {

	cout << "Matrices des ecarts de mesures capteurs pour le gaz " << gaz << endl << endl;
	cout << "    |";
	for ( int i = 0; i < nbCapteurs; i++)
	{
		cout << i << "      |";
	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	for ( int i = 0; i < nbCapteurs; i++)
	{
		cout << i << "   |";
		for (int j = 0; j < nbCapteurs; j++)
		{

			if (i == j)
			{
				cout << matriceEcartGaz[i][j] << "      |";
			}
			else
			{
				cout << matriceEcartGaz[i][j] << '|';
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Menu::afficherSousIndiceAtmo(vector<ConcentrationIndice> listeConcIndice)
{
	int atmo = e.CalculAtmo(listeConcIndice);
	if (atmo != 0)
	{
		cout << "PM10: " << listeConcIndice[PM10];
		cout << "SO2: " << listeConcIndice[SO2];
		cout << "NO2: " << listeConcIndice[NO2];
		cout << "O3: " << listeConcIndice[O3];
	}
}
