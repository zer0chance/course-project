#include "tarif.h"

void difference_sms(short *difference_sms_plus, short *difference_sms_minus, my_tarif my_list) {
    if (my_list.sms == 0) {
        *difference_sms_plus = 0;  //plus-na skoka predlagayt bol'she chem nado
        *difference_sms_minus = 0;////plus-na skoka predlagayt men'she chem nado
    }
    if ((my_list.sms > 0) && (my_list.sms <= 15)) {
        *difference_sms_plus = 50;
        *difference_sms_minus = my_list.sms;
    }
    if ((my_list.sms > 15) && (my_list.sms <= 50)) {
        *difference_sms_plus = 50;
        *difference_sms_minus = 10;
    }
    if ((my_list.sms > 50) && (my_list.sms <= 200)) {
        *difference_sms_plus = 100;
        *difference_sms_minus = 20;
    }
    if ((my_list.sms > 200) && (my_list.sms <= 300)) {
        *difference_sms_plus = 100;
        *difference_sms_minus = 50;
    }
    if ((my_list.sms > 200) && (my_list.sms <= 300)) {
        *difference_sms_plus = 150;
        *difference_sms_minus = 50;
    }
 
 
}