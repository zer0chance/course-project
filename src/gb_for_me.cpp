#include "tarif.h"

void gb_for_me(short difference_gb_plus, short difference_gb_minus, my_tarif my_list, data* list, int i)
{
    if (list[i].gb != -1) {
        if ((((list[i].gb - my_list.gb) <= difference_gb_plus) && ((list[i].gb - my_list.gb) >= 0)) || (((list[i].gb - my_list.gb >= (-1) * difference_gb_minus) && (list[i].gb - my_list.gb) <= 0))) {
            list[i].gb_b = true;
        }
    } else {
        if (my_list.gb > 20) {

            list[i].gb_b = true;
        }
    }
}