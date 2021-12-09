#ifndef LAB_07_1_1_FUNCS_H
#define LAB_07_1_1_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define OK 0
#define ARGUMENT_ERROR -1
#define FILE_OPEN_ERROR -2
#define EMPTY_FILE_ERROR -3
#define BAD_FILE_CONTENT_ERROR -4
#define ALLOCATE_ERROR -5
#define EMPTY_NEW_ARR -6
#define NO_NUMBERS_IN_FILE -7
#define KEY_BAD_PARAMS -8

#define STRING_MAX_LEN 250

/**
 * check correct number of arguments
 * @param argc
 * @param argv
 */
int check_args(int argc);

/**
 * check if file exist and not empty
 * get number of numbers in file
 * @param in_file_name
 * @param file_len
 * @return "in" file pointer
 */
FILE * get_check_in_file(char* in_file_name, long* file_len, int *rc);

/**
 * allocate memory for "in file" array
 * @param date
 * @param len
 */
int allocate_array(int **date, long len);

/**
 * read array from file
 * @param file
 * @param data start of array pointer
 * @param pend end of array pointer
 */
int read_array(FILE* file, int* data, const int *pend);

/**
 * prints array in console
 * @param data
 * @param pend
 */
void print_array(const int *data, const int *pend);

/**
 * filtr function, create new arr of "needed" numbers
 * @param pb_src start of old array
 * @param pe_src end of old array
 * @param pb_dst start of new array
 * @param pe_dst end of new array
 * @return new array length
 */
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

/**
 * bubble sort for array
 * @param p_start
 * @param p_end
 */
void bubble_sort(int *p_start, const int *p_end);

/**
 * write down sorted array in out file
 * @param file_name
 * @param p_start
 * @param p_end
 */
void write_arr(char *file_name, int *p_start, const int *p_end);

#endif //LAB_07_1_1_FUNCS_H
