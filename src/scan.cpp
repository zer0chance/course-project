#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n = 6;

typedef struct tarifbook {
    char company[10];
    char tarif[10];
    int gb;
    int min;
    int sms;
    int min_mezhgorod;
    int price;
} data;

int main()
{
    data list[n];
    int i = 0;
    FILE* input;

    input = fopen("input.txt", "r");
    while (fscanf(input, "%s %s %d %d %d %d %d", list[i].company, list[i].tarif, &list[i].gb, &list[i].min, &list[i].sms, &list[i].min_mezhgorod, &list[i].price) != EOF) {
        printf("\n %s %s %d %d %d %d %d\n\n", list[i].company, list[i].tarif, list[i].gb, list[i].min, list[i].sms, list[i].min_mezhgorod, list[i].price);
        i++;
    }

    fclose(input);
    return 0;
}
