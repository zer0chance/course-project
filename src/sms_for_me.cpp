#include "tarif.h"
void sms_for_me(short difference_sms_plus, short difference_sms_minus, my_tarif my_list, data* list, int i)
{
    if (list[i].sms != -1) {
        if ((((list[i].sms - my_list.sms) <= difference_sms_plus) && ((list[i].sms - my_list.sms) >= 0)) || (((list[i].sms - my_list.sms >= (-1) * difference_sms_minus) && (list[i].sms - my_list.sms) <= 0))) {
            list[i].sms_b = true;
        }
    } else {
        if (my_list.sms > 500) //bezlimit
        {
            list[i].sms_b = true;
        }
    }
}