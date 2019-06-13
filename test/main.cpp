#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "tarif.h"

TEST_CASE("Sorting by price")
{
	int size = 5, i;
	data list[size];
	for (i = 0; i < size; i++) list[i].price = 50 + rand()%50;

	int A[size], B[size];
		
	for (i = 0; i < size; i++) A[i] = i;

	SECTION("Index array inititalized correctly")
	{
		REQUIRE(A[0] == 0);
		REQUIRE(A[1] == 1);
		REQUIRE(A[2] == 2);
		REQUIRE(A[3] == 3);
		REQUIRE(A[4] == 4);
	}

	Sort_Price(list, A, size);

	for (i = 0; i < size; i++) B[i] = A[size - 1 - i];

	SECTION("Sort by price up complites correctly")
	{
		REQUIRE(list[A[0]].price <= list[A[1]].price);
		REQUIRE(list[A[1]].price <= list[A[2]].price);
		REQUIRE(list[A[2]].price <= list[A[3]].price);
		REQUIRE(list[A[3]].price <= list[A[4]].price);
	}

	SECTION("Sort by price down complites correctly")
	{
		REQUIRE(list[B[0]].price >= list[B[1]].price);
		REQUIRE(list[B[1]].price >= list[B[2]].price);
		REQUIRE(list[B[2]].price >= list[B[3]].price);
		REQUIRE(list[B[3]].price >= list[B[4]].price);
	}
}


TEST_CASE("Sorting by relevance")
{
	int size = 5, i;
	data list[size];

	int A[size]
		
	for (i = 0; i < size; i++) A[i] = i;
		
	for (i = 0; i < size; i++) list[i].price = 50 + rand()%50;
}