 #include "tarif.h"
 
void min_for_me(short difference_min_plus, short difference_min_minus, my_tarif my_list, data *list, int i) {
    if (my_list.min <= 500) {
        if ((((list[i].min - my_list.min) <= difference_min_plus) && ((list[i].min - my_list.min) >= 0)) ||
            (((list[i].min - my_list.min >= (-1) * difference_min_minus) &&
              (list[i].min - my_list.min <= 0)))) {
            list[i].min_b = true;
 
 
        }
    } else {
        if ((list[i].min > 500) && (my_list.min > 500))//bezlimit
        {
            list[i].min_b = true;
        }
    }
}