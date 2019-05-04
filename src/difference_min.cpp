#include "tarif.h"

void difference_min(short *difference_min_plus, short *difference_min_minus, my_tarif my_list)
{
    if (my_list.min == 0) {
        *difference_min_plus = 0;  //plus-na skoka predlagayt bol'she chem nado
        *difference_min_minus = 0;////plus-na skoka predlagayt men'she chem nado
    }
    if ((my_list.min > 0) && (my_list.min <= 50)) {
        *difference_min_plus = 10;
        *difference_min_minus = 0;
    }
    if ((my_list.min > 50) && (my_list.min <= 150)) {
        *difference_min_plus = 20;
        *difference_min_minus = 10;
    }
    if ((my_list.min > 150) && (my_list.min <= 300)) {
        *difference_min_plus = 40;
        *difference_min_minus = 20;
    }
    if ((my_list.min > 300) && (my_list.min <=500)) {
        *difference_min_plus = 50;
        *difference_min_minus =20;
    }
}