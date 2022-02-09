#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <math.h>

#define MAX_STRING_LEN 250
#define MAX_ARR_LEN 10

#define OK 0
#define READ_ERROR 1

int main()
{
    int rc = OK;
    int  arr[MAX_ARR_LEN];
    int len = 0;

    rc = read_array(arr, &len);
    if (rc == OK)
    {
        for (int i = 0; i < len; i++)
        {
            if (is_palindrome(arr[i]))
            {
                delete_number(arr, &len, arr[i]);
                //todo then two palindromes are neighbours there is a problem with coefficient i! test: 12321 123321 122
            }
        }
        print_result(arr, len);
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

int is_palindrome(int num)
{
    int length = take_length(num);

    if (length <= 1)
        return 0;

    int times = ceil((double)length / 2);

    for (int i = 0; i < times; i++)
    {
        if ((int)(num / pow(10, length - 1)) % 10 != (num % ((int)pow(10, i + 1)) / (int)(pow(10, i))))
            return 0;
        length--;
    }

    return 1;
}

int take_length(int num)
{
    int length = 0;

    if (num == 0)
        return 1;

    while (num != 0)
    {
        length++;
        num /= 10;
    }

    return length;
}

void delete_number(int *arr, int *len, int num)
{
    for (int i = 0; i < *len; i++)
    {
        if (arr[i] == num)
        {
            move_arr(arr, i, len);
        }
    }
}

void move_arr(int *arr, int pos, int *length)
{
    for (; pos < *length - 1; pos++)
    {
        arr[pos] = arr[pos + 1];
    }
    arr[(*length)--] = '\0';
}

void print_result(int *arr, int len)
{
    printf("Result is: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}