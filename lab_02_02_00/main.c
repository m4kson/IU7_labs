#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define OK 0
#define READ_ERROR 1

#define MAX_STRING_LEN 250
#define MAX_ARR_SIZE 10

int main()
{
    int rc = OK;
    int arr[MAX_ARR_SIZE], new_arr[MAX_ARR_SIZE];
    int len = 0, new_len = 0;
    double average = 0;

    rc = read_array(arr, &len);
    if (rc == OK)
    {
        average = average_of_array(arr, len);
        new_len = create_new_array(new_arr, arr, len, average);
        if (new_len == 0)
        {
            printf("The average is: %lf\n", average);
            printf("There isn't any elements in new array\n");
        }
        else
            print_result(new_arr, new_len, average);
    }

    return rc;
}

int read_array(int *arr, int *len)
{
    char string[MAX_STRING_LEN];
    int rc = OK;
    char *end_ptr;
    *len = 0;

    printf("Please enter int array: ");

    fgets(string, MAX_STRING_LEN, stdin);

    arr[*len] = (int)strtol(string, &end_ptr, 10);
    (*len)++;

    if (end_ptr[0] != '\n' && end_ptr[0] != ' ')
    {
        rc = READ_ERROR;
    }
    else
    {
        while (*end_ptr != '\n')
        {
            if (end_ptr[0] == ' ')
            {
                end_ptr++;
            }

            if (*end_ptr == '\n')
                break;

            arr[*len] = (int)strtol(end_ptr, &end_ptr, 10);
            (*len)++;

            if (end_ptr[0] != '\n' && end_ptr[0] != ' ')
            {
                rc = READ_ERROR;
                break;
            }
        }
    }

    return rc;
}

int create_new_array(int *new_array, const int *old_array, int len, double average)
{
    int new_arr_len = 0;

    for (int i = 0; i < len; i++)
    {
        if (old_array[i] > average)
        {
            new_array[new_arr_len++] = old_array[i];
        }
    }
    return new_arr_len;
}

double average_of_array(const int *arr, int len)
{
    int sum = 0;
    double average = 0;

    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    average = (double)sum / len;

    return average;
}

void print_result(int *arr, int len, double average)
{
    printf("The average is: %lf\n", average);
    printf("The new array is: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
