#include "tarif.h"

void search_tarif(data* list, data* tarif_for_me, int n)
{

    int j = 0;
    for (int i = 0; i < n; i++) {
        if ((list[i].gb_b) && (list[i].sms_b) && (list[i].min_b)) {
            strcpy(tarif_for_me[j].company, list[i].company);
            strcpy(tarif_for_me[j].tarif, list[i].tarif);
            tarif_for_me[j].gb = list[i].gb;
            tarif_for_me[j].min = list[i].min;
            tarif_for_me[j].sms = list[i].sms;
            tarif_for_me[j].min_mezhgorod = list[i].min_mezhgorod;
            tarif_for_me[j].price = list[i].price;
            j = j + 1;
        }
    }
}