#include "CppUnitTest.h"
#include "../PorteeCapteur.h"
#include "../Date.h"
#include "../Seuil.h"
#include "../Capteur.h"
#include "../Gestion.h"
#include "../MesureGaz.h"
#include "../Catalogue.h"
#include "../IdCatalogue.h"

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

	TEST_CLASS(TestUnitaireGestion)
	{
	public:
		TEST_METHOD(TestAjouterCapteur)
		{

			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			Capteur c2 = Capteur(2, "d", 1.02, 32.002);
			vector <Capteur> v;
			Gestion g;

			g.ajouterCapteur(c1, v);
			bool ajoute = false;
			if (find(v.begin(), v.end(), c1) != v.end()) {
				ajoute = true;
			}
			Assert::IsTrue(ajoute);

			g.ajouterCapteur(c1, v);
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
			g.supprimerCapteur(2, v);
			present = false;
			if (find(v.begin(), v.end(), c1) != v.end()) {
				present = true;
			}
			Assert::IsTrue(present);
			present = false;
			g.supprimerCapteur(1, v);
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
			g.mettreEnVeilleCapteur(2, v);
			it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 1);
			g.mettreEnVeilleCapteur(1, v);
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
			g.restaurerCapteur(2, v);
			auto it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 0);
			g.restaurerCapteur(1, v);
			it = find(v.begin(), v.end(), c1);
			Assert::AreEqual(it->getEtat(), 1);
		}

		TEST_METHOD(TestChangerSeuil)
		{

			unordered_map<string, list<Seuil>> umap;
			list<Seuil> PM10;
			list<Seuil> SO2;
			list<Seuil> NO2;
			list<Seuil> O3;
			Gestion g;

			for (int i = 0; i < 10; i++)
			{
				PM10.push_back(Seuil(0, 0, 0));
				SO2.push_back(Seuil(0, 0, 0));
				NO2.push_back(Seuil(0, 0, 0));
				O3.push_back(Seuil(0, 0, 0));
			}

			umap.insert(make_pair("PM10", PM10));
			umap.insert(make_pair("SO2", SO2));
			umap.insert(make_pair("NO2", NO2));
			umap.insert(make_pair("O3", O3));

			list<Seuil> unPM10;
			list<Seuil> unSO2;
			list<Seuil> unNO2;
			list<Seuil> unO3;

			for (int i = 0; i < 10; i++)
			{
				unPM10.push_back(Seuil(i, i, i));
				unSO2.push_back(Seuil(i, i, i));
				unNO2.push_back(Seuil(i, i, i));
				unO3.push_back(Seuil(i, i, i));
			}
			bool diff = false;
			list<Seuil>::iterator itGaz = PM10.begin();
			for (list<Seuil>::iterator it = umap["PM10"].begin(); it != umap["PM10"].end(); ++it)
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
			itGaz = SO2.begin();
			for (list<Seuil>::iterator it = umap["SO2"].begin(); it != umap["SO2"].end(); ++it)
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
			itGaz = NO2.begin();
			for (list<Seuil>::iterator it = umap["NO2"].begin(); it != umap["NO2"].end(); ++it)
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
			itGaz = O3.begin();
			for (list<Seuil>::iterator it = umap["O3"].begin(); it != umap["O3"].end(); ++it)
			{
				if ((*it) != (*itGaz))
				{
					diff = true;
					break;
				}
				++itGaz;
			}

			Assert::IsFalse(diff);

			g.changerSeuil(umap, unPM10, unSO2, unNO2, unO3);

			diff = false;
			itGaz = unPM10.begin();
			for (list<Seuil>::iterator it = umap["PM10"].begin(); it != umap["PM10"].end(); ++it)
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
			for (list<Seuil>::iterator it = umap["SO2"].begin(); it != umap["SO2"].end(); ++it)
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
			for (list<Seuil>::iterator it = umap["NO2"].begin(); it != umap["NO2"].end(); ++it)
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
			for (list<Seuil>::iterator it = umap["O3"].begin(); it != umap["O3"].end(); ++it)
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
			unordered_map<string, list<Seuil>> umap;
			list<Seuil> PM10;
			list<Seuil> SO2;
			list<Seuil> NO2;
			list<Seuil> O3;
			Gestion g;

			for (int i = 0; i < 10; i++)
			{
				PM10.push_back(Seuil(0, 0, 0));
				SO2.push_back(Seuil(0, 0, 0));
				NO2.push_back(Seuil(0, 0, 0));
				O3.push_back(Seuil(0, 0, 0));
			}

			umap.insert(make_pair("PM10", PM10));
			umap.insert(make_pair("SO2", SO2));
			umap.insert(make_pair("NO2", NO2));
			umap.insert(make_pair("O3", O3));
			Seuil s = Seuil(34, 32, 11);
			int num = 4;
			g.changerUnSeuil(umap, "SO2", num, s);
			list<Seuil>::iterator it = umap["SO2"].begin();

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
				
		}

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

}

