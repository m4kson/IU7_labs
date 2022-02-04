#include <stdio.h>
#include <stdlib.h>

#define bool int

#define OK 0
#define READ_ERROR 1

#define MAX_STRING_LEN 250
#define MAX_ARRAY_SIZE 10

int read_array(int *arr, int *len);
bool is_even(int number);
int even_sum_count(int *arr, int len);
void print_result(int sum);

int main()
{
    int arr[MAX_ARRAY_SIZE];
    int rc = OK;
    int len = 0;
    int sum = 0;

    rc = read_array(arr, &len);

    if (rc == OK)
    {
        sum = even_sum_count(arr, len);
        print_result(sum);
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

bool is_even(int number)
{
    int rc;

    if (number % 2 == 0)
        rc = 1;
    else
        rc = 0;

    return rc;
}

int even_sum_count(int *arr, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (is_even(arr[i]))
            sum += arr[i];
    }

    return sum;
}

void print_result(int sum)
{
    printf("Answer is: %d", sum);
}