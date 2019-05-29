#include "CppUnitTest.h"
#include "../PorteeCapteur.h"
#include "../Date.h"
#include "../Seuil.h"
#include "../Capteur.h"
#include "../Gestion.h"

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
			Logger::WriteMessage("Vérification des calculs des bornes min et max des portées");
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
			Logger::WriteMessage("Vérification portée1 contenue dans la portée globale");
			Assert::IsTrue(portee.contient(portee1));
			Logger::WriteMessage("Vérification portée2  non contenue dans la portée globale");
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
			Logger::WriteMessage("Test jour suivant 31 Décembre 2016");
			d1 = Date(2016, 12, 31, 0, 25, 25.3);
			Assert::IsTrue(d1.suivant()==Date(2017, 1, 1, 0, 25, 25.3));
		}
		TEST_METHOD(TestOperateurEgalite)
		{
			Date d1(2017, 1, 1, 0, 25, 25.3);
			Date d2 (2016, 3, 31, 0, 25, 25.3);
			Logger::WriteMessage("Test de l'opérateur ==");
			Assert::IsTrue(d1==d1);
			Assert::IsFalse(d1 == d2);
			Logger::WriteMessage("Test de l'opérateur >=");
			Assert::IsTrue(d1 >= d2); 
			Logger::WriteMessage("Test de l'opérateur <");
			Assert::IsFalse(d1 < d2); 
			Logger::WriteMessage("Test de l'opérateur <=");
			Assert::IsFalse(d1 <= d2);
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
			Logger::WriteMessage("Test de l'opérateur ==");
			Assert::IsTrue(s1== s1);
			Assert::IsFalse(s3 == s2);
		}


	};

	TEST_CLASS(TestUnitaireGestion)
	{
	public:
		TEST_METHOD(TestAjouterCapteur)
		{

			Capteur c1 = Capteur(1, "d", 12.012, 32.002);
			Capteur c2 = Capteur(2, "d", 1.02, 32.002);
			Capteur c3 = Capteur(3, "d", 4.32, 32.002);
			Capteur c4 = Capteur(4, "d", 111.23, 32.002);

			vector <Capteur> v;
			Gestion g;
			g.ajouterCapteur(c1, v);
			bool ajoute = false;/*
			if (find(v.begin(), v.end(), c1) != v.end()) {
				ajoute = true;
			}
			Assert::IsTrue(ajoute);
			*/

			
		}

	};
}
