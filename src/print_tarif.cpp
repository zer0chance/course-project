#include "tarif.h"

void print_my_tarif(data* list, int m)
{
    for (int i = 0; i < m; i++) {

        if ((list[i].gb == -1) && (list[i].sms == -1)) {
            printf("%s %s gb:unlimited, min:%hi, sms:unlimited, mezhg=%hi, price:%d\n", list[i].company, list[i].tarif,
                list[i].min, list[i].min_mezhgorod, list[i].price);
        } else {
            if (list[i].gb == -1) {
                printf("%s %s gb:unlimited, min:%hi, sms:%hi, mezhg=%hi, price:%d\n", list[i].company, list[i].tarif,
                    list[i].min, list[i].sms, list[i].min_mezhgorod, list[i].price);
            }
            if (list[i].sms == -1) {
                printf("%s %s gb:%hi, min:%hi, sms:unlimited, mezhg=%hi, price:%d\n", list[i].company, list[i].tarif,
                    list[i].gb,
                    list[i].min, list[i].min_mezhgorod, list[i].price);
            }
        }

        if ((list[i].gb != -1) && (list[i].sms != -1)) {
            printf("%s %s gb:%hi, min:%hi, sms:%hi, mezhg=%hi, price:%d\n", list[i].company, list[i].tarif,
                list[i].gb,
                list[i].min, list[i].sms, list[i].min_mezhgorod, list[i].price);
        }
    }
}