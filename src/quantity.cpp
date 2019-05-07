#include "tarif.h"
int quantity_my_tarif(data* list)
{
    int m = 0;
    for (int i = 0; i < n; i++) {
        if ((list[i].gb_b) && (list[i].sms_b) && (list[i].min_b))
            m++;
    }
    return m;
}