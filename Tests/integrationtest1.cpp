#include "CppUnitTest.h"
#include "../PorteeCapteur.h"
#include "../Date.h"
#include "../Seuil.h"
#include "../Lecture.h"
#include "../Capteur.h"
#include "../Gestion.h"
#include "../MesureGaz.h"
#include "../Catalogue.h"
#include "../IdCatalogue.h"
#include "../ConcentrationIndice.h"
#include "../Etude.h"
//#include "../Etude.h"

#include <iterator> 
#include <list>
#include <unordered_map>

using namespace std; 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestIntegration
{
	TEST_MODULE_INITIALIZE(ModuleInit)
	{
		Logger::WriteMessage("Initialisation du module.");
	}
	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("Nettoyage du module");
	}
	TEST_CLASS(TestIntegrationConcentrationIndice)
	{
	public:
		TEST_METHOD(TestIndice)
		{
			Logger::WriteMessage("Test de calcul des sous indices atmo");
			Lecture l;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			vector<ConcentrationIndice> listeConcIndice(4);
			listeConcIndice[PM10] = ConcentrationIndice(7.5);
			listeConcIndice[SO2] = ConcentrationIndice(45);
			listeConcIndice[NO2] = ConcentrationIndice(200);
			listeConcIndice[O3] = ConcentrationIndice(105);

			listeConcIndice[O3].setIndice(mapSeuil[O3]);
			listeConcIndice[PM10].setIndice(mapSeuil[PM10]);
			listeConcIndice[SO2].setIndice(mapSeuil[SO2]);
			listeConcIndice[NO2].setIndice(mapSeuil[NO2]);

			Assert::IsTrue(listeConcIndice[PM10].indice == 1);
			Assert::IsTrue(listeConcIndice[SO2].indice == 2);
			Assert::IsTrue(listeConcIndice[NO2].indice == 8);
			Assert::IsTrue(listeConcIndice[O3].indice == 5);
		}
	};
	TEST_CLASS(TestIntegrationEtude)
	{
	public:
		TEST_METHOD(TestEvaluer_CalculAtmo_Point_Jour)
		{

			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2017, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD);

			Assert::IsTrue(listeConcIndice[PM10].indice == 4);
			Assert::IsTrue(listeConcIndice[SO2].indice == 5);
			Assert::IsTrue(listeConcIndice[NO2].indice == 8);
			Assert::IsTrue(listeConcIndice[O3].indice == 6);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 8);
		}
		TEST_METHOD(TestEvaluer_CalculAtmo_Point_Periode)
		{
			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2017, 01, 01, 0, 1, 20.6090000);
			Date dateF(2018, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD, dateF);

			Assert::IsTrue(listeConcIndice[PM10].indice == 4);
			Assert::IsTrue(listeConcIndice[SO2].indice == 5);
			Assert::IsTrue(listeConcIndice[NO2].indice == 8);
			Assert::IsTrue(listeConcIndice[O3].indice == 6);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 8);
		}
		TEST_METHOD(TestEvaluer_CalculAtmo_Point_Jour_Aucun_Capteur)
		{
			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2017, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 0.0, 0.0, dateD);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 0);
		}
		TEST_METHOD(TestEvaluer_CalculAtmo_Point_Jour_Aucune_Mesure)
		{
			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2019, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 0);
		}
		TEST_METHOD(TestEvaluer_CalculAtmo_Territoire_Jour)
		{
			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2017, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD, Date(), 1000000);

			Assert::IsTrue(listeConcIndice[PM10].indice == 4);
			Assert::IsTrue(listeConcIndice[SO2].indice == 5);
			Assert::IsTrue(listeConcIndice[NO2].indice == 8);
			Assert::IsTrue(listeConcIndice[O3].indice == 5);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 8);
		}
		TEST_METHOD(TestEvaluer_CalculAtmo_Territoire_Periode)
		{
			Catalogue* c = new Catalogue();
			Lecture l;
			vector<Capteur> listeCapteurs;
			unordered_map <int, vector<Seuil>> mapSeuil;
			l.InitCapteur(listeCapteurs, "../../Fichiers/capteurComplet.csv");
			l.InitTypeGaz("../../Fichiers/gazTest.csv");
			l.Parcourir(c, "../../Fichiers/fichier1000.csv");
			l.InitSeuils(mapSeuil, "../../Fichiers/Seuils.csv");
			unordered_map<IdCatalogue, vector<MesureGaz>> map;
			Date dateD(2017, 01, 01, 0, 1, 20.6090000);
			Date dateF(2018, 01, 01, 0, 1, 20.6090000);
			Etude e;
			vector<ConcentrationIndice> listeConcIndice = e.Evaluer(*c, listeCapteurs, mapSeuil, 11.9072994016611, 18.2016632092193, dateD, dateF, 1000000);

			Assert::IsTrue(listeConcIndice[PM10].indice == 4);
			Assert::IsTrue(listeConcIndice[SO2].indice == 5);
			Assert::IsTrue(listeConcIndice[NO2].indice == 8);
			Assert::IsTrue(listeConcIndice[O3].indice == 5);

			Assert::IsTrue(e.CalculAtmo(listeConcIndice) == 8);
		}


	};
}
