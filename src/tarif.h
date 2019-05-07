#ifndef TARIF_H
#define TARIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n = 656;

typedef struct tarifbook {
    char company[10];
    char tarif[10];
    short gb;
    short min;
    short sms;
    short min_mezhgorod;
    int price;
    bool gb_b = false;
    bool min_b = false;
    bool sms_b = false;
    bool mezh_b = false;
} data;

typedef struct {
    short min;
    short sms;
    short gb;
    char min_mezhgorod;
} my_tarif;

void difference_gb(short* difference_gb_plus, short* difference_gb_minus, my_tarif my_list);
void difference_min(short* difference_min_plus, short* difference_min_minus, my_tarif my_list);
void difference_sms(short* difference_sms_plus, short* difference_sms_minus, my_tarif my_list);
void gb_for_me(short difference_gb_plus, short difference_gb_minus, my_tarif my_list, data* list, int i);
void min_for_me(short difference_min_plus, short difference_min_minus, my_tarif my_list, data* list, int i);
void sms_for_me(short difference_sms_plus, short difference_sms_minus, my_tarif my_list, data* list, int i);
void bool_for_me(short difference_gb_plus, short difference_gb_minus, short difference_min_plus, short difference_min_minus,
    short difference_sms_plus, short difference_sms_minus, my_tarif my_list, data* list);
int quantity_my_tarif(data* list);
void search_tarif(data* list, data* tarif_for_me);
void print_my_tarif(data* list, int m, FILE* output);
#endif
