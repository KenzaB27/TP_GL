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
#include "../Etude.h"

#include <iterator> 
#include <list>
#include <unordered_map>

using namespace std; 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitaire
{
	TEST_MODULE_INITIALIZE(ModuleInit)
	{
		Logger::WriteMessage("Initialisation du module.");
	}
	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("Nettoyage du module");
	}
	TEST_CLASS(TestUnitairePorteeCapteur)
	{
	public:
		TEST_METHOD(TestPorteeCapteurMinMax)
		{
			Logger::WriteMessage("V�rification des calculs des bornes min et max des port�es");
			PorteeCapteur portee1(-19.4789835505555, -35.2425725968753, 20000);
			PorteeCapteur portee2(-38.3884286616875, -24.9593580676985, 20000);
			PorteeCapteur portee3(-44.5357010278551, -40.5272071485069, 20000);
			PorteeCapteur portee4(18.9026808524051, -60.4696149986561, 20000);
			PorteeCapteur listPortees[] = {portee1,portee2,portee3,portee4};
			for (int i = 0; i < 4; i++) {
				Assert::IsTrue(listPortees[i].getLatitudeCentre() > listPortees[i].getLatitudeMin() &&
					listPortees[i].getLatitudeCentre() < listPortees[i].getLatitudeMax());
			}
		}
		TEST_METHOD(TestPorteeCapteurContient)
		{
			PorteeCapteur portee(-38.3884286616875, -24.9593580676985,20000);
			PorteeCapteur portee1(-38.40,-25.00);
			PorteeCapteur portee2(45,96, 10.46);
			Logger::WriteMessage("V�rification port�e1 contenue dans la port�e globale");
			Assert::IsTrue(portee.contient(portee1));
			Logger::WriteMessage("V�rification port�e2  non contenue dans la port�e globale");
			Assert::IsTrue(!portee.contient(portee2));
		}

	};
	TEST_CLASS(TestUnitaireDate)
	{
	public:
		TEST_METHOD(TestJourSuivant)
		{
			Logger::WriteMessage("Test basic du jour suivant");
			Date d1(2017, 1, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()==Date(2017, 1, 2, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 29 fevrier 2016");
			d1=Date(2016, 2, 29, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()== Date(2016, 3, 1, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 28 fevrier 2019");
			d1 = Date(2019, 2, 28, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant() == Date(2019, 3, 1, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 30 Avril 2016");
			d1=Date(2016, 4, 30, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()==Date(2016, 5,1 , 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 31 Mars 2016");
			d1 = Date(2016, 3, 31, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()==Date(2016, 4, 1, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 31 D�cembre 2016");
			d1 = Date(2016, 12, 31, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()==Date(2017, 1, 1, 0, 25, 25.3));
		}

		TEST_METHOD(TestJourPrecedent)
		{
			Logger::WriteMessage("Test basic du jour precedent");
			Date d1(2017, 1, 13, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2017, 1, 12, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 1 mars 2016");
			d1 = Date(2016, 3, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2016, 2, 29, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 1 mars 2019");
			d1 = Date(2019, 3, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2019, 2, 28, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 1 mai 2016");
			d1 = Date(2016, 5, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2016, 4, 30, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 1 avril 2016");
			d1 = Date(2016, 4, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2016, 3, 31, 0, 25, 25.3));
			Logger::WriteMessage("Test jour suivant 1 janvier 2017");
			d1 = Date(2017, 1, 1, 0, 25, 25.3);
			Assert::IsTrue(d1.precedent() == Date(2016, 12, 31, 0, 25, 25.3));
		}
		TEST_METHOD(TestOperateurEgalite)
		{
			Date d1(2017, 1, 1, 0, 25, 25.3);
			Date d2 (2016, 3, 31, 0, 25, 25.3);
			Logger::WriteMessage("Test de l'op�rateur ==");
			Assert::IsTrue(d1==d1);
			Assert::IsFalse(d1 == d2);
			Logger::WriteMessage("Test de l'op�rateur >=");
			Assert::IsTrue(d1 >= d2); 
			Logger::WriteMessage("Test de l'op�rateur <");
			Assert::IsFalse(d1 < d2); 
			Logger::WriteMessage("Test de l'op�rateur <=");
			Assert::IsFalse(d1 <= d2);
		}

	};
	
	TEST_CLASS(TestUnitaireMesureGaz)
	{
	public:
		TEST_METHOD(TestMesureGaz)
		{
			Date d = Date(2019, 02, 01, 10, 12, 55);
   			MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");
			MesureGaz m1 = MesureGaz(0, d, 10, 13, "Capteur13");
			MesureGaz m2 = MesureGaz();

			Logger::WriteMessage("Test des valeurs du mesuresGaz");
			Assert::IsTrue(m.getGazId() == 0);
			Assert::IsTrue(m1.getGazId() == O3);

			Logger::WriteMessage("Test du bon fonctionnement des dates");
			Assert::IsTrue(m.getDate() == d);

			Logger::WriteMessage("Test methode setValeur");
			m.setValeur(23);
			Assert::IsTrue(m.getValeur()==23);

			Logger::WriteMessage("Test methode setDescription");
			m.setDescription("test");
			Assert::IsFalse(m.getDescription()=="Capteur12");

			Logger::WriteMessage("Test methode setUnite");
			m.setUnite("test");
			Assert::IsFalse(m.getUnite().compare("µg/m3")==0);
		}
	};

	TEST_CLASS(TestUnitaireSeuil)
	{
	public:
		TEST_METHOD(TestOperateurEgalite)
		{
			Seuil s1 = Seuil(1, 2, 3);
			Seuil s2 = Seuil(1, 2, 3);
			Seuil s3 = Seuil(1, 2, 4);
			Logger::WriteMessage("Test de l'op�rateur ==");
			Assert::IsTrue(s1== s2);
			Assert::IsFalse(s3 == s2);
		}

		TEST_METHOD(TestOperateurNotEqual)
		{
			Seuil s1 = Seuil(1, 2, 3);
			Seuil s2 = Seuil(1, 2, 3);
			Seuil s3 = Seuil(1, 2, 4);
			Logger::WriteMessage("Test de l'op�rateur !=");
			Assert::IsTrue(s1 != s3);
			Assert::IsFalse(s1 != s2);
		}


	};
	TEST_CLASS(TestUnitaireEtude)
	{
		TEST_METHOD(TestCalculAtmo)
		{
			Etude e; 
		}

	};
	TEST_CLASS(TestUnitaireGestion)
	{
	public:
		TEST_METHOD(TestAjouterCapteur)
		{

			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			Capteur c2 = Capteur(2, "d", 1.02, 32.002);
			vector <Capteur> v;
			Gestion g;

			g.AjouterCapteur(c1, v);
			bool ajoute = false;
			if (find(v.begin(), v.end(), c1) != v.end()) {
				ajoute = true;
			}
			Assert::IsTrue(ajoute);

			g.AjouterCapteur(c1, v);
			int size = v.size();
			Assert::AreEqual(1, size);			
		}
		TEST_METHOD(TestSupprimerCapteur)
		{
			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			vector <Capteur> v;
			Gestion g;
			v.push_back(c1);
			bool present = false;
			if (find(v.begin(), v.end(), c1) != v.end()) {
				present = true;
			}
			Assert::IsTrue(present);
			g.SupprimerCapteur(2, v);
			present = false;
			if (find(v.begin(), v.end(), c1) != v.end()) {
				present = true;
			}
			Assert::IsTrue(present);
			present = false;
			g.SupprimerCapteur(1, v);
			if (find(v.begin(), v.end(), c1) != v.end()) {
				present = true;
			}
			Assert::IsFalse(present);
		}

		TEST_METHOD(TestMettreEnVeilleCapteur)
		{
			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			vector <Capteur> v;
			Gestion g;
			v.push_back(c1);
			auto it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 1);
			g.MettreEnVeilleCapteur(2, v);
			it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 1);
			g.MettreEnVeilleCapteur(1, v);
			it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 0);

		}

		TEST_METHOD(TestRestaurerCapteur)
		{
			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			vector <Capteur> v;
			Gestion g;
			c1.setEtat(0);
			Assert::AreEqual(c1.getEtat(), 0);
			v.push_back(c1);
			g.RestaurerCapteur(2, v);
			auto it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 0);
			g.RestaurerCapteur(1, v);
			it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 1);
		}

		TEST_METHOD(TestChangerSeuil)
		{

			unordered_map<int, vector<Seuil>> umap;
			vector<Seuil> pm10;
			vector<Seuil> so2;
			vector<Seuil> no2;
			vector<Seuil> o3;
			Gestion g;

			for (int i = 0; i < 10; i++)
			{
				pm10.push_back(Seuil(0, 0, 0));
				so2.push_back(Seuil(0, 0, 0));
				no2.push_back(Seuil(0, 0, 0));
				o3.push_back(Seuil(0, 0, 0));
			}

			umap.insert(make_pair(PM10, pm10));
			umap.insert(make_pair(SO2, so2));
			umap.insert(make_pair(NO2, no2));
			umap.insert(make_pair(O3, o3));

			vector<Seuil> unPM10;
			vector<Seuil> unSO2;
			vector<Seuil> unNO2;
			vector<Seuil> unO3;

			for (int i = 0; i < 10; i++)
			{
				unPM10.push_back(Seuil(i, i, i));
				unSO2.push_back(Seuil(i, i, i));
				unNO2.push_back(Seuil(i, i, i));
				unO3.push_back(Seuil(i, i, i));
			}
			bool diff = false;
			vector<Seuil>::iterator itGaz = pm10.begin();
			for (vector<Seuil>::iterator it = umap[PM10].begin(); it != umap[PM10].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}
			Assert::IsFalse(diff);
			diff = false;
			itGaz = so2.begin();
			for (vector<Seuil>::iterator it = umap[SO2].begin(); it != umap[SO2].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);
			diff = false;
			itGaz = no2.begin();
			for (vector<Seuil>::iterator it = umap[NO2].begin(); it != umap[NO2].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);

			diff = false;
			itGaz = o3.begin();
			for (vector<Seuil>::iterator it = umap[O3].begin(); it != umap[O3].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);

			g.ChangerSeuil(umap, unPM10, unSO2, unNO2, unO3);

			diff = false;
			itGaz = unPM10.begin();
			for (vector<Seuil>::iterator it = umap[PM10].begin(); it != umap[PM10].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}
			Assert::IsFalse(diff);
			diff = false;
			itGaz = unSO2.begin();
			for (vector<Seuil>::iterator it = umap[SO2].begin(); it != umap[SO2].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);
			diff = false;
			itGaz = unNO2.begin();
			for (vector<Seuil>::iterator it = umap[NO2].begin(); it != umap[NO2].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);
			diff = false;
			itGaz = unO3.begin();
			for (vector<Seuil>::iterator it = umap[O3].begin(); it != umap[O3].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);
		}

		TEST_METHOD(TestChangerUnSeuil)
		{
			unordered_map<int, vector<Seuil>> umap;
			vector<Seuil> pm10;
			vector<Seuil> so2;
			vector<Seuil> no2;
			vector<Seuil> o3;
			Gestion g;

			for (int i = 0; i < 10; i++)
			{
				pm10.push_back(Seuil(0, 0, 0));
				so2.push_back(Seuil(0, 0, 0));
				no2.push_back(Seuil(0, 0, 0));
				o3.push_back(Seuil(0, 0, 0));
			}

			umap.insert(make_pair(PM10, pm10));
			umap.insert(make_pair(SO2, so2));
			umap.insert(make_pair(NO2, no2));
			umap.insert(make_pair(O3, o3));
			Seuil s = Seuil(34, 33, 4);
			int num = 4;
			g.ChangerUnSeuil(umap, SO2, s);
			vector<Seuil>::iterator it = umap[SO2].begin();

			for (int i = 1; i < num; i++)
			{
				++it;
			}
			bool ajoute = false;
			if ((*it) == s) 
			{
				ajoute = true;
			}
			Assert::IsTrue(ajoute);
		}
	};

	TEST_CLASS(TestUnitaireCatalogue)
	{
	public:
	
		/*
		TEST_METHOD(TestConstructionCatalogue)
		{
			Date d = Date(2019, 02, 01, 10, 12, 55);
    		MesureGaz m = MesureGaz(O3, d, 10.95, 12, "Capteur12");
    		MesureGaz m1 = MesureGaz(0, d, 10, 12, "Capteur12");

			IdCatalogue id = IdCatalogue(12,d);

			list<MesureGaz> liste;
    		liste.push_back(m);
   			liste.push_back(m1);
			
			Catalogue c;

    		c.getMap().emplace(id, liste);

			Logger::WriteMessage("Tes  idCatalogue dans le catalogue");
			Assert::IsTrue(c.getMap().find(id)->first.getCapteurId()==id.getCapteurId());

			Logger::WriteMessage("Test liste mesure dans le catalogue");
			Assert::IsTrue(c.getMap().find(id)->second.getGazId()==0);//checker si le second.begin() fonctionne correctement	
				
		}*/

		TEST_METHOD(TestIdCatalogue)
		{
			Date d = Date(2019, 02, 01, 10, 12, 55);
			IdCatalogue id = IdCatalogue(12,d);

			Logger::WriteMessage("Test fonctionnement date IdCatalogue");
			Assert::IsTrue(id.getDateMesure()==d);
		
			Logger::WriteMessage("Test fonctionnement id IdCatalogue");
			Assert::IsTrue(id.getCapteurId()==12);
		}

		
	};

	TEST_CLASS(TestUnitaireLecture)
	{
	public:

		TEST_METHOD(TestInitCapteur)
		{
			Logger::WriteMessage("Test fonctionnement initialisation des capteurs");

			vector<Capteur> liste;
			Lecture l;
			l.InitCapteur(liste , "../Fichiers/capteurs.csv");

			Capteur c1(0, "abba", -19.4789835505555, -35.2425725968753);
			Capteur c2(1, "", -38.3884286616875, -24.9593580676985);

			vector<Capteur> capteurTest;
			capteurTest.push_back(c1);
			capteurTest.push_back(c2);

			for (unsigned int i = 0; i < capteurTest.size(); i++)
			{
				Assert::AreEqual(c1.getCapteurId(), liste.front().getCapteurId());
				Assert::AreEqual(c1.getDescription().c_str(), liste.front().getDescription().c_str());
				Assert::AreEqual(c1.getEtat(), liste.front().getEtat());
			}
			

			Logger::WriteMessage("Fin Test fonctionnement initialisation des capteurs");
		}
		
		TEST_METHOD(TestParcourirFichier)
		{
			Logger::WriteMessage("Test fonctionnement parcours fichier de mesures");

			Catalogue* c = new Catalogue();
			Lecture l;

			l.InitTypeGaz("../Fichiers/gazTest.csv");
			l.Parcourir(c, "../Fichiers/valuesTest.csv");

			Date d = Date(2017, 01, 01, 0, 1, 20.6090000);
			MesureGaz m = MesureGaz(O3, d, 17.8902017543936, 0, "concentration d'ozone");
			MesureGaz m2 = MesureGaz(SO2, d, 13.6449094925285, 0, "concentration de dioxyde de soufre");
			MesureGaz m1 = MesureGaz(NO2, d, 42.4807462361763, 0, "concentration de dioxyde d'azote");
			MesureGaz m3 = MesureGaz(PM10, d, 1.55796479844986, 0, "concentration de particules fines");

			IdCatalogue id = IdCatalogue(0, d);

			vector<MesureGaz> liste;
			liste.push_back(m);
			liste.push_back(m1);
			liste.push_back(m2);
			liste.push_back(m3);

			Catalogue cTest;

			cTest.getMap().emplace(make_pair(id, liste));

			unordered_map<IdCatalogue, vector<MesureGaz>> map = c->getMap();
			auto it = map.begin();

			Assert::AreEqual(it->first.getCapteurId(), 0);
			Date dd = it->first.getDateMesure();

			Assert::IsTrue(it->first.getDateMesure()==d);

			
			auto ll = liste.begin();
			for (auto l = it->second.begin(); l != it->second.end(); ++l)
			{
				Assert::IsTrue(l->getValeur()==ll->getValeur());
				Assert::AreEqual(l->getDescription(), ll->getDescription());
				Assert::AreEqual(l->getGazId(), ll->getGazId());
				Assert::AreEqual(l->getIdCapteur(), ll->getIdCapteur());
				Assert::AreEqual(l->getUnite(), ll->getUnite());
				Assert::IsTrue(l->getDate() == ll->getDate());
				++ll;
			}


			Logger::WriteMessage("Fin test fonctionnement parcours fichier de mesures");
		}

		
		TEST_METHOD(TestGenerationSeuils)
		{
			Logger::WriteMessage("Test fonctionnement parcours et génération des seuils à partir du csv");

			Lecture l;
			unordered_map<int, vector<Seuil>> listeSeuils;

			l.InitSeuils(listeSeuils, "../Fichiers/Seuils.csv");

			Assert::IsTrue(listeSeuils.size() == 4);

			for (auto x : listeSeuils)
			{
				Assert::IsTrue(x.second.size() == 10);
				for (int i = 0; i < 10; i++)
				{
					Assert::IsTrue(x.second[i].getMin() >= 0 && x.second[i].getMin() <= 200000);
					Assert::IsTrue(x.second[i].getMax() >= 0 && x.second[i].getMax() <= 200000);
				}
			}

			Logger::WriteMessage("Fin test fonctionnement génération et lecture seuils");
		}

	};

}

