#include "tarif.h"

int main()
{

    int n = 656;

    int *IndexArr, *IndexArrVerse;
    unsigned int sort_way, sort_field;
    my_tarif my_list;

    scan(my_list);

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
        difference_sms_minus, my_list, list, n);

    size = quantity_my_tarif(list, n);
    data* tarif_for_me;
    tarif_for_me = new data[size];
    IndexArr = new int[size];
    IndexArrVerse = new int[size];

    for (i = 0; i < size; i++)
        IndexArr[i] = i;

    search_tarif(list, tarif_for_me, n);

    FILE* output;
    output = fopen("output.txt", "w");
    print_my_tarif(tarif_for_me, size, output, IndexArr);
    fclose(output);

    char sort_field_char;
    do {
        printf("\nDo you want to sort suitable tariffs by price/relevance? (1/2)\n");
        scanf("%s", &sort_field_char);

    } while (sort_field_char != '1' && sort_field_char != '2');

    sort_field = sort_field_char - 48;

    if (sort_field == 1) {
        Sort_Price(tarif_for_me, IndexArr, size);
        for (i = 0; i < size; i++)
            IndexArrVerse[i] = IndexArr[size - 1 - i];

        char sort_way_char;
        do {

            printf("\nDo you want to sort by price up/down? (1/2)\n");
            scanf("%s", &sort_way_char);

        } while (sort_way_char != '1' && sort_way_char != '2');

        sort_way = sort_way_char - 48;

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

    printf("\n\n DONE!\nCheck output.txt\n\n");

    fclose(output);

    delete (tarif_for_me);
    delete (list);
    return 0;
}