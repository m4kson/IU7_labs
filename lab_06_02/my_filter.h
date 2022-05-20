#ifndef LAB_06_02_MY_FILTER_H
#define LAB_06_02_MY_FILTER_H

#include <stdio.h>
#include <string.h>


#define OK 0
#define file_open_error -1
#define incorrect_file_content -2
#define empty_item_name -3
#define item_name_too_long -4


#define max_name_len 26
#define buffer_len 50


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
int read_items(FILE* f, item* arr);

/**
 * ascending sort of array by density
 * @param arr - array of structures
 */
void my_sort(item* arr);

/**
 * print structures whose name starts with a substring from array
 * @param arr - array of structures
 * @param prefix - filter substring
 */
void print_information(item* arr, char* prefix);

#endif //LAB_06_02_MY_FILTER_H
