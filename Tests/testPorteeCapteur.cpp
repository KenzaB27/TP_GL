#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PorteeCapteur.h"
#include <iostream>
using namespace std; 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFlexiSensor
{		
	TEST_CLASS(testPorteeCapteur)
	{
	public:
		
		TEST_METHOD(verifPorteeCapteurContient)
		{
			PorteeCapteur portee(38.3884286616875, 24.9593580676985);
			PorteeCapteur portee1(38.45, 24.32);
			Assert::IsTrue (portee.contient(portee1)); 
		}
	};
}