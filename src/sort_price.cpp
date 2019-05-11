#include "tarif.h"

void Sort_Price(data *list, int *A, int size)
{
	int i, j, temp, index;

	for (i = 0; i<size; i++) A[i] = i;

	for (i = 0; i < size-1; i++)
	{
		index = i;

		for (j = i+1; j < size; j++)
			if (list[A[j]].price < list[A[index]].price)
				index = j;


		if (index != i)
		{
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
		}	
	}

	/*for (i = 0; i<size; i++)
		printf("\n%-8s %-10s gb: %-8hi min: %-8hi sms: %-8hi mezhg: %-4hi price: %d\n", list[A[i]].company, list[A[i]].tarif,
                list[A[i]].gb,
                list[A[i]].min, list[A[i]].sms, list[A[i]].min_mezhgorod, list[A[i]].price);
*/}