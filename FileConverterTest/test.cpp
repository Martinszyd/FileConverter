
#include "../FileConverter/Konwerter.h"
#include "../FileConverter/Console.h"
#include <string>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

	TEST(ConsoleTest, plikTXT) {
		const string nazwaPliku = "test.txt";
		EXPECT_TRUE(Konwerter::Konwerter(nazwaPliku));
	}


	
		int main(int argc, char **argv) 
		{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	    }