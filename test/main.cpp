#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "tarif.h"

TEST_CASE("Sorting by price")
{
	int size = 5;
	data list[size];
	for (int i = 0; i < size; i++) list[i].price = 50 + rand()%50;

	int A[size];
		
	for (int i = 0; i < size; i++) A[i] = i;

	SECTION("Index array inititalized correctly")
	{
		REQUIRE(A[0] == 0);
		REQUIRE(A[1] == 1);
		REQUIRE(A[2] == 2);
		REQUIRE(A[3] == 3);
		REQUIRE(A[4] == 4);
	}

	//Sort_Price(data* list, int* A, int size);

    /*const float x1 = 1;
    const float y1 = 1;
    const float x2 = 1;
    const float y2 = 11;
    const float x3 = 11;
    const float y3 = 1;
    const float P = 20 + sqrt(200);

    REQUIRE(Area(x1, y1, x2, y2, x3, y3, P) == 50);*/
}