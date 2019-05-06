#include "tarif.h"

void difference_sms(short* difference_sms_plus, short* difference_sms_minus, my_tarif my_list)
{
    if (my_list.sms == 0) {
        *difference_sms_plus = 0; //plus-na skoka predlagayt bol'she chem nado
        *difference_sms_minus = 0; ////plus-na skoka predlagayt men'she chem nado
    }
    if ((my_list.sms > 0) && (my_list.sms <= 5)) {
        *difference_sms_plus = 5;
        *difference_sms_minus = 0;
    }
    if ((my_list.sms > 5) && (my_list.sms <= 50)) {
        *difference_sms_plus = 10;
        *difference_sms_minus = 5;
    }
    if ((my_list.sms > 50) && (my_list.sms <= 150)) {
        *difference_sms_plus = 20;
        *difference_sms_minus = 5;
    }
    if ((my_list.sms > 150) && (my_list.sms <= 300)) {
        *difference_sms_plus = 30;
        *difference_sms_minus = 20;
    }
    if ((my_list.min > 300) && (my_list.sms <= 500)) {
        *difference_sms_plus = 40;
        *difference_sms_minus = 30;
    }
}