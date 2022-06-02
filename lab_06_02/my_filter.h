#ifndef LAB_06_02_MY_FILTER_H
#define LAB_06_02_MY_FILTER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define OK 0
#define file_open_error (-1)
#define incorrect_file_content (-2)
#define empty_item_name (-3)
#define item_name_too_long (-4)
#define argument_error (-5)


#define max_name_len 25
#define buffer_len 50
#define items_max_num 100
#define eps 0.00000001
#define True 1
#define False 0


typedef struct
{
    char name[max_name_len];
    double weight;
    double volume;
} item;

/**
 * read all items from file to structure array
 * @param f - file pointer
 * @param arr - array of structures
 * @return exit code (0 if everything's good
 */
int read_items(FILE* f, item* arr, int *item_counter);


/**
 * print structures whose name starts with a substring from array
 * @param arr - array of structures
 * @param prefix - filter substring
 */
void print_information(item* arr, char* prefix, int item_number);

void my_sort(item *arr, int item_number, int(*comp) (const void *, const void *));

#endif //LAB_06_02_MY_FILTER_H
