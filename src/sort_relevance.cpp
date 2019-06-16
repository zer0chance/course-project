#include "tarif.h"

void Relevance_Sort(my_tarif my_list, data* list, int* A, int size)
{
    int Total, i, j, temp, index, i_sum, j_sum;

    Total = my_list.gb * 25 + my_list.sms + my_list.min;

    for (i = 0; i < size - 1; i++) {
        index = i;
        i_sum = list[A[i]].gb * 25 + list[A[i]].sms + list[A[i]].min;

        if (list[A[i]].gb == -1)
            i_sum = 500 + list[A[i]].sms + list[A[i]].min;
        if (list[A[i]].sms == -1)
            i_sum = list[A[i]].gb * 25 + 500 + list[A[i]].min;
        if ((list[A[i]].sms == -1) && (list[A[i]].gb == -1))
            i_sum = 1000 + list[A[i]].min;

        for (j = i + 1; j < size; j++) {
            j_sum = list[A[j]].gb * 25 + list[A[j]].sms + list[A[j]].min;

            if (list[A[j]].gb == -1)
                j_sum = 500 + list[A[j]].sms + list[A[j]].min;
            if (list[A[j]].sms == -1)
                j_sum = list[A[j]].gb * 25 + 500 + list[A[j]].min;
            if ((list[A[j]].sms == -1) && (list[A[j]].gb == -1))
                j_sum = 1000 + list[A[j]].min;

            if (((Total - j_sum)*(Total - j_sum)) <= ((Total - i_sum)*(Total - i_sum)))
            {    
                index = j;
                i_sum = j_sum;
            }   
        }

        if (index != i) {
            temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}