#include "tarif.h"

void Relevance_Sort(my_tarif my_list, data* list, int* A, int size)
{
    int Total, i, j, temp, index, i_sum, j_sum;

    Total = my_list.gb * 25 + my_list.sms + my_list.min;

    for (i = 0; i < size - 1; i++) {
        index = i;
        i_sum = list[i].gb * 25 + list[i].sms + list[i].min;

        if (list[i].gb == -1)
            i_sum = 500 + list[i].sms + list[i].min;
        if (list[i].sms == -1)
            i_sum = list[i].gb * 25 + 500 + list[i].min;
        if ((list[i].sms == -1) && (list[i].gb == -1))
            i_sum = 1000 + list[i].min;

        for (j = i + 1; j < size; j++) {
            j_sum = list[j].gb * 25 + list[j].sms + list[j].min;

            if (list[j].gb == -1)
                j_sum = 500 + list[j].sms + list[j].min;
            if (list[j].sms == -1)
                j_sum = list[j].gb * 25 + 500 + list[j].min;
            if ((list[j].sms == -1) && (list[j].gb == -1))
                j_sum = 1000 + list[j].min;

            if (((Total - j_sum)*(Total - j_sum)) <= ((Total - i_sum)*(Total - i_sum)))
                index = j;
        }

        if (index != i) {
            temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}