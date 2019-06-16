#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tarif.h"

TEST_CASE("Sorting by price")
{
    srand(time(0));
    int size = 5, i;
    data list[size];
    for (i = 0; i < size; i++)
        list[i].price = 50 + rand() % 50;

    int A[size], B[size];

    for (i = 0; i < size; i++)
        A[i] = i;

    SECTION("Index array inititalized correctly")
    {
        REQUIRE(A[0] == 0);
        REQUIRE(A[1] == 1);
        REQUIRE(A[2] == 2);
        REQUIRE(A[3] == 3);
        REQUIRE(A[4] == 4);
    }

    Sort_Price(list, A, size);

    for (i = 0; i < size; i++)
        B[i] = A[size - 1 - i];

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
    srand(time(0));
    int size = 5, i, Total, Sum_1 = 0, Sum_2 = 0, Sum_3 = 0, Sum_4 = 0, Sum_5 = 0, Sum_6 = 0, Sum_7 = 0, Sum_8 = 0;
    data list[size];
    my_tarif input;

    input.gb = 15;
    input.min = 70;
    input.sms = 50;

    Total = input.gb * 25 + input.sms + input.min;

    int A[size];

    for (i = 0; i < size; i++)
        A[i] = i;

    for (i = 0; i < size; i++)
        list[i].gb = 13 + i;
    for (i = 0; i < size; i++)
        list[i].min = 90 - i * 10;
    for (i = 0; i < size; i++)
        list[i].sms = 40 + i * 4;

    Relevance_Sort(input, list, A, size);

    Sum_1 = list[A[0]].gb * 25 + list[A[0]].sms + list[A[0]].min;
    Sum_2 = list[A[1]].gb * 25 + list[A[1]].sms + list[A[1]].min;
    REQUIRE(((Total - Sum_1) * (Total - Sum_1)) <= ((Total - Sum_2) * (Total - Sum_2)));

    Sum_3 = list[A[1]].gb * 25 + list[A[1]].sms + list[A[1]].min;
    Sum_4 = list[A[2]].gb * 25 + list[A[2]].sms + list[A[2]].min;
    REQUIRE(((Total - Sum_3) * (Total - Sum_3)) <= ((Total - Sum_4) * (Total - Sum_4)));

    Sum_5 = list[A[2]].gb * 25 + list[A[2]].sms + list[A[2]].min;
    Sum_6 = list[A[3]].gb * 25 + list[A[3]].sms + list[A[3]].min;
    REQUIRE(((Total - Sum_5) * (Total - Sum_5)) <= ((Total - Sum_6) * (Total - Sum_6)));

    Sum_7 = list[A[3]].gb * 25 + list[A[3]].sms + list[A[3]].min;
    Sum_8 = list[A[4]].gb * 25 + list[A[4]].sms + list[A[4]].min;
    REQUIRE(((Total - Sum_7) * (Total - Sum_7)) <= ((Total - Sum_8) * (Total - Sum_8)));
}

TEST_CASE("difference gb")
{
    short difference_gb_plus = 0;
    short difference_gb_minus = 0;
    my_tarif list;
    list.gb = 13;

    difference_gb(&difference_gb_plus, &difference_gb_minus, list);

    REQUIRE(difference_gb_plus == 5);
    REQUIRE(difference_gb_minus == 2);

    difference_gb_plus = 0;
    difference_gb_minus = 0;
    list.gb = 100;

    difference_gb(&difference_gb_plus, &difference_gb_minus, list);

    REQUIRE(difference_gb_plus == 10);
    REQUIRE(difference_gb_minus == 3);
}

TEST_CASE("difference min")
{
	short difference_min_plus = 0;
    short difference_min_minus = 0;
    my_tarif list;
	list.min = 68;

    difference_min(&difference_min_plus, &difference_min_minus, list);

    REQUIRE(difference_min_plus == 70);
    REQUIRE(difference_min_minus == 20);

    difference_min_plus = 0;
    difference_min_minus = 0;
	list.min = 30;

    difference_min(&difference_min_plus, &difference_min_minus, list);

    REQUIRE(difference_min_plus == 50);
    REQUIRE(difference_min_minus == 30);
}


TEST_CASE("difference sms")
{
	short difference_sms_plus = 0;
    short difference_sms_minus = 0;
    my_tarif list;
	list.sms = 370;

    difference_sms(&difference_sms_plus, &difference_sms_minus, list);

    REQUIRE(difference_sms_plus == 150);
    REQUIRE(difference_sms_minus == 50);
}