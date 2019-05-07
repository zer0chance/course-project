#include "tarif.h"
void bool_for_me(short difference_gb_plus, short difference_gb_minus, short difference_min_plus, short difference_min_minus,
    short difference_sms_plus, short difference_sms_minus, my_tarif my_list, data* list)
{

    for (int i = 0; i < n; i++) {
        {
            gb_for_me(difference_gb_plus, difference_gb_minus, my_list, list, i);
            min_for_me(difference_min_plus, difference_min_minus, my_list, list, i);
            sms_for_me(difference_sms_plus, difference_sms_minus, my_list, list, i);
            // mezh_for_me(my_list, list, i);
        }
    }
}