#include "tarif.h"

int main()
{
    int *IndexArr, *IndexArrVerse;
    unsigned int sort_way, sort_field;
    my_tarif my_list;

    printf("Amount of GB of internet you spend every mounth\n");
    scanf("%hi", &my_list.gb);
    while (my_list.gb < 0) {
        printf("Invalid input \nAmount of GB of internet you spend every mounth\n");
        scanf("%hi", &my_list.gb);
    }

    printf("Amount of minutes you speak every mounth\n");
    scanf("%hi", &my_list.min);
    while (my_list.min < 0) {
        printf("Invalid input \nAmount of minutes you speak every mounth\n");
        scanf("%hi", &my_list.min);
    }

    printf("Amount of SMS you send every mounth\n");
    scanf("%hi", &my_list.sms);
    while (my_list.sms < 0) {
        printf("Invalid input \nAmount of SMS you send every mounth\n");
        scanf("%hi", &my_list.sms);
    }

    printf("Do you want your tariff to include calls abroad? (y/n)\n");
    scanf("%s", &my_list.min_mezhgorod);
    while (my_list.min_mezhgorod != 'y' && my_list.min_mezhgorod != 'n')

    {
        printf("Do you want your tariff to include calls abroad? (y/n)\n");
        scanf("%s", &my_list.min_mezhgorod);
    }

    data* list;
    list = new data[n];
    int i = 0, size;
    FILE* input;

    if (my_list.min_mezhgorod == 'n')
        input = fopen("input.txt", "r");
    else
        input = fopen("input2.txt", "r");

    while (fscanf(input, "%s %s %hi %hi %hi %hi %d", list[i].company, list[i].tarif, &list[i].gb, &list[i].min,
               &list[i].sms, &list[i].min_mezhgorod, &list[i].price)
        != EOF) {

        if (list[i].gb < -1 || list[i].min < 0 || list[i].sms < -1 || list[i].min_mezhgorod < 0 || list[i].price < 0) {
            printf("%d,Invalid input in %s %s\n", i, list[i].company, list[i].tarif);
            return 0;
        }
        i++;
    }

    short difference_gb_plus = 0;
    short difference_gb_minus = 0;
    difference_gb(&difference_gb_plus, &difference_gb_minus, my_list);

    short difference_min_plus = 0;
    short difference_min_minus = 0;
    difference_min(&difference_min_plus, &difference_min_minus, my_list);

    short difference_sms_plus = 0;
    short difference_sms_minus = 0;
    difference_sms(&difference_sms_plus, &difference_sms_minus, my_list);
    bool_for_me(difference_gb_plus, difference_gb_minus, difference_min_plus, difference_min_minus, difference_sms_plus,
        difference_sms_minus, my_list, list);

    size = quantity_my_tarif(list);
    data* tarif_for_me;
    tarif_for_me = new data[size];
    IndexArr = new int[size];
    IndexArrVerse = new int[size];

    for (i = 0; i < size; i++)
        IndexArr[i] = i;

    search_tarif(list, tarif_for_me);

    FILE* output;
    output = fopen("output.txt", "w");
    print_my_tarif(tarif_for_me, size, output, IndexArr);
    fclose(output);

    printf("\nDo you want to sort suitable tariffs by price/relevance? (1/2)\n");
    while (sort_field != 1 && sort_field != 2) {
        scanf("%u", &sort_field);
    }

    if (sort_field == 1) {
        Sort_Price(tarif_for_me, IndexArr, size);
        for (i = 0; i < size; i++)
            IndexArrVerse[i] = IndexArr[size - 1 - i];

        printf("\nDo you want to sort by price up/down? (1/2)\n");
        while (sort_way != 1 && sort_way != 2) {
            scanf("%u", &sort_way);
        }

        output = fopen("output.txt", "w");

        if (sort_way == 1)
            print_my_tarif(tarif_for_me, size, output, IndexArr);

        if (sort_way == 2)
            print_my_tarif(tarif_for_me, size, output, IndexArrVerse);
    }

    if (sort_field == 2) {
        Relevance_Sort(my_list, tarif_for_me, IndexArr, size);

        output = fopen("output.txt", "w");

        print_my_tarif(tarif_for_me, size, output, IndexArr);
    }

    printf("\n\n DONE!\nCheck output.txt");

    fclose(output);

    delete (tarif_for_me);
    delete (list);
    return 0;
}