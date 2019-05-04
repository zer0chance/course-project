#include "tarif.h"


int main()
{
   my_tarif my_list;
 
 
    printf("Amount of GB of internet you spend every mounth\n");
    scanf("%hi", &my_list.gb);
    while(my_list.gb<0)
    {
        printf("Invalid input \nAmount of GB of internet you spend every mounth\n");
         scanf("%hi", &my_list.gb);
    }
 
 
    printf("Amount of minutes you speak every mounth\n");
    scanf("%hi", &my_list.min);
    while(my_list.min<0)
    {
        printf("Invalid input \nAmount of minutes you speak every mounth\n");
        scanf("%hi", &my_list.min);
    }
 
 
    printf("Amount of SMS you send every mounth\n");
    scanf("%hi", &my_list.sms);
    while(my_list.sms<0)
    {
        printf("Invalid input \nAmount of SMS you send every mounth\n");
        scanf("%hi", &my_list.sms);
    }
 
    printf("Do you want your tariff to include calls abroad? (y/n)\n");
    scanf("%s", &my_list.min_mezhgorod);
    while(my_list.min_mezhgorod!='y'&&my_list.min_mezhgorod!='n')
 
    {
        printf("Do you want your tariff to include calls abroad? (y/n)\n");
        scanf("%s", &my_list.min_mezhgorod);
    }

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