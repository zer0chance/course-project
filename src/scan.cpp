#include "tarif.h"

void scan(my_tarif& my_list)
{
    char* gb;
    gb = new char[3];
    char* min;
    min = new char[4];
    char* sms;
    sms = new char[4];

    int flag;

    do {
        flag = 0;
        printf("Amount of GB of internet you spend every mounth\n");
        scanf("%s", gb);
        char len = strlen(gb);
        for (int i = 0; i < len; i++) {
            if (('0' > gb[i]) || (gb[i] > '9')) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("Invalid input \n");
        }
    } while (flag == 1);

    sscanf(gb, "%hi", &my_list.gb);

    do {
        flag = 0;
        printf("Amount of minutes you speak every mounth\n");
        scanf("%s", min);
        char len = strlen(min);
        for (int i = 0; i < len; i++) {
            if (('0' > min[i]) || (min[i] > '9')) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("Invalid input \n");
        }
    } while (flag == 1);

    sscanf(min, "%hi", &my_list.min);

    do {
        flag = 0;
        printf("Amount of SMS you send every mounth\n");
        scanf("%s", sms);
        char len = strlen(sms);
        for (int i = 0; i < len; i++) {
            if (('0' > sms[i]) || (sms[i] > '9')) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("Invalid input \n");
        }
    } while (flag == 1);

    sscanf(sms, "%hi", &my_list.sms);

    printf("Do you want your tariff to include calls abroad? (y/n)\n");
    scanf("%s", &my_list.min_mezhgorod);
    while (my_list.min_mezhgorod != 'y' && my_list.min_mezhgorod != 'n')

    {
        printf("Do you want your tariff to include calls abroad? (y/n)\n");
        scanf("%s", &my_list.min_mezhgorod);
    }
}
