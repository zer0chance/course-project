#include "tarif.h"

void Sort_Price(data* list, int* A, int size)
{
    int i, j, temp, index;

    for (i = 0; i < size - 1; i++) {
        index = i;

        for (j = i + 1; j < size; j++)
            if (list[A[j]].price < list[A[index]].price)
                index = j;

        if (index != i) {
            temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}