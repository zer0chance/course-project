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

    difference_sms_plus = 0;
    difference_sms_minus = 0;
    list.sms = 0;

    difference_sms(&difference_sms_plus, &difference_sms_minus, list);

    REQUIRE(difference_sms_plus == 0);
    REQUIRE(difference_sms_minus == 0);
}

TEST_CASE("gb for me")
{
    short difference_gb_plus;
    short difference_gb_minus;
    my_tarif my_list;
    my_list.gb = 7;
    data* list;
    list = new data[1];
    list[0].gb = 8;
    list[0].gb_b = false;

    difference_gb(&difference_gb_plus, &difference_gb_minus, my_list);

    gb_for_me(difference_gb_plus, difference_gb_minus, my_list, list, 0);

    int flag = 0;
    if (list[0].gb_b == true)
        flag = 1;

    REQUIRE(flag == 1);

    my_list.gb = 1;
    list[0].gb = 4;
    list[0].gb_b = false;

    difference_gb(&difference_gb_plus, &difference_gb_minus, my_list);

    gb_for_me(difference_gb_plus, difference_gb_minus, my_list, list, 0);

    flag = 0;
    if (list[0].gb_b == true)
        flag = 1;

    REQUIRE(flag == 0);
}

TEST_CASE("min for me")
{
    short difference_min_plus;
    short difference_min_minus;
    my_tarif my_list;
    my_list.min = 60;
    data* list;
    list = new data[1];
    list[0].min = 100;
    list[0].min_b = false;

    difference_min(&difference_min_plus, &difference_min_minus, my_list);

    min_for_me(difference_min_plus, difference_min_minus, my_list, list, 0);

    int flag = 0;
    if (list[0].min_b == true)
        flag = 1;

    REQUIRE(flag == 1);

    my_list.min = 600;
    list[0].min = 200;
    list[0].min_b = false;

    difference_min(&difference_min_plus, &difference_min_minus, my_list);

    min_for_me(difference_min_plus, difference_min_minus, my_list, list, 0);

    flag = 0;
    if (list[0].min_b == true)
        flag = 1;

    REQUIRE(flag == 0);
}

TEST_CASE("sms for me")
{
    short difference_sms_plus;
    short difference_sms_minus;
    my_tarif my_list;
    my_list.sms = 10;
    data* list;
    list = new data[1];
    list[0].sms = 50;
    list[0].sms_b = false;

    difference_sms(&difference_sms_plus, &difference_sms_minus, my_list);

    sms_for_me(difference_sms_plus, difference_sms_minus, my_list, list, 0);

    int flag = 0;
    if (list[0].sms_b == true)
        flag = 1;

    REQUIRE(flag == 1);

    my_list.sms = 800;
    list[0].sms = 900;
    list[0].sms_b = false;

    difference_sms(&difference_sms_plus, &difference_sms_minus, my_list);

    sms_for_me(difference_sms_plus, difference_sms_minus, my_list, list, 0);

    flag = 0;
    if (list[0].sms_b == true)
        flag = 1;

    REQUIRE(flag == 1);
}

TEST_CASE("quanity")
{

    data* list;
    list = new data[4];
    list[0].sms_b = true;
    list[0].min_b = true;
    list[0].gb_b = true;

    list[1].sms_b = true;
    list[1].min_b = false;
    list[1].gb_b = true;

    list[2].sms_b = false;
    list[2].min_b = false;
    list[2].gb_b = false;

    list[3].sms_b = true;
    list[3].min_b = true;
    list[3].gb_b = true;

    REQUIRE(quantity_my_tarif(list, 4) == 2);

    REQUIRE(quantity_my_tarif(list, 1) == 1);
}

TEST_CASE("bool for me")
{
    short difference_gb_plus;
    short difference_gb_minus;
    short difference_min_plus;
    short difference_min_minus;
    short difference_sms_plus;
    short difference_sms_minus;

    my_tarif my_list;
    my_list.gb = 7;
    my_list.min = 120;
    my_list.sms = 100;
    data* list;
    list = new data[5];

    list[0].gb = 11;
    list[0].min = 180;
    list[0].sms = 150;
    list[0].gb_b = false;

    list[1].gb = 5;
    list[1].min = 120;
    list[1].sms = 90;
    list[1].gb_b = false;

    list[2].gb = 2;
    list[2].min = 130;
    list[2].sms = 110;
    list[2].gb_b = false;

    list[3].gb = 4;
    list[3].min = 110;
    list[3].sms = 190;
    list[3].gb_b = false;

    list[4].gb = 20;
    list[4].min = 100;
    list[4].sms = 174;
    list[4].gb_b = false;

    difference_gb(&difference_gb_plus, &difference_gb_minus, my_list);
    difference_min(&difference_min_plus, &difference_min_minus, my_list);
    difference_sms(&difference_sms_plus, &difference_sms_minus, my_list);

    bool_for_me(difference_gb_plus, difference_gb_minus, difference_min_plus, difference_min_minus, difference_sms_plus,
        difference_sms_minus, my_list, list, 5);

    for (int i = 0; i < 5; i++) {
        int flag_gb = 0, flag_min = 0, flag_sms = 0;
        if (list[i].gb_b == true)
            flag_gb = 1;
        if (list[i].min_b == true)
            flag_min = 1;
        if (list[i].sms_b == true)
            flag_sms = 1;

        REQUIRE(flag_gb == 0);
        REQUIRE(flag_min == 1);
        REQUIRE(flag_sms == 1);
    }
}