#ifndef funcs_h
#define funcs_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX_LEN 25
#define ARR_MAX_LEN 15
#define MAX_FILE_NAME_LEN 255
#define BUFFER_LENGTH (NAME_MAX_LEN + 2 + 1)

#define OK 0
#define ARGUMENT_ERROR 1
#define FILE_OPEN_ERROR 2
#define EMPTY_FILE_ERROR 3
#define TOO_MANY_STRUCTS_ERROR 4
#define FILE_NAME_TOO_LONG_ERROR 5
#define EMPTY_PRODUCT_NAME_ERROR 6
#define PRODUCT_NAME_TOO_LONG_ERROR 7
#define INCORRECT_PRICE_ERROR 8
#define INCORRECT_FILE_CONTENT 9
#define INCORRECT_NUMBER_FORMAT 10

typedef struct
{
    char name[NAME_MAX_LEN];
    int price;
} product;

int read_array(FILE* f, int* records_no, product* arr);
void find(double p, int file_len, product arr[ARR_MAX_LEN]);

#endif /* funcs_h */
