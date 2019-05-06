#include "tarif.h"

void difference_gb(short* difference_gb_plus, short* difference_gb_minus, my_tarif my_list)
{
    if (my_list.gb == 0) {
        *difference_gb_plus = 0; //plus-na skoka predlagayt bol'she chem nado
        *difference_gb_minus = 0; ////plus-na skoka predlagayt men'she chem nado
    }
    if ((my_list.gb >= 1) && (my_list.gb <= 5)) {
        *difference_gb_plus = 1;
        *difference_gb_minus = 0;
    }
    if ((my_list.gb >= 6) && (my_list.gb <= 9)) {
        *difference_gb_plus = 2;
        *difference_gb_minus = 1;
    }
    if ((my_list.gb >= 10) && (my_list.gb <= 20)) {
        *difference_gb_plus = 4;
        *difference_gb_minus = 2;
    }
}
