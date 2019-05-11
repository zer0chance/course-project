#include "tarif.h"

void print_my_tarif(data* list, int m, FILE* output, int* A)
{
    for (int i = 0; i < m; i++) {

        if ((list[i].gb == -1) && (list[i].sms == -1)) {
            fprintf(output, "%s %s gb:unlimited, min:%hi, sms:unlimited, mezhg=%hi, price:%d\n", list[A[i]].company,
                list[A[i]].tarif,
                list[A[i]].min, list[A[i]].min_mezhgorod, list[A[i]].price);
        } else {
            if (list[A[i]].gb == -1) {
                fprintf(output, "%s %s gb:unlimited, min:%hi, sms:%hi, mezhg=%hi, price:%d\n", list[A[i]].company,
                    list[A[i]].tarif,
                    list[A[i]].min, list[A[i]].sms, list[A[i]].min_mezhgorod, list[A[i]].price);
            }
            if (list[A[i]].sms == -1) {
                fprintf(output, "%s %s gb:%hi, min:%hi, sms:unlimited, mezhg=%hi, price:%d\n", list[A[i]].company,
                    list[A[i]].tarif,
                    list[A[i]].gb,
                    list[A[i]].min, list[A[i]].min_mezhgorod, list[A[i]].price);
            }
        }

        if ((list[A[i]].gb != -1) && (list[A[i]].sms != -1)) {
            fprintf(output, "%s %s gb:%hi, min:%hi, sms:%hi, mezhg=%hi, price:%d\n", list[A[i]].company, list[A[i]].tarif,
                list[A[i]].gb,
                list[A[i]].min, list[A[i]].sms, list[A[i]].min_mezhgorod, list[A[i]].price);
        }
    }
}
