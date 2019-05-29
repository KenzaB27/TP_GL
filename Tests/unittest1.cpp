#include "CppUnitTest.h"
#include "../PorteeCapteur.h"
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
			Logger::WriteMessage("Vérification de scalculs des bornes min et max des portées");
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
			Logger::WriteMessage("Vérification de portée1 contenue dans la portée globale");
			Assert::IsTrue(portee.contient(portee1));
			Logger::WriteMessage("Vérification de portée2  non contenue dans la portée globale");
			Assert::IsTrue(!portee.contient(portee2));
		}

	};
}
