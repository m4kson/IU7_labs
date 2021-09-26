#include "funcs.h"

int read_array(FILE* f, int* records_no, product* arr)
{
    char *res;
    char buffer[BUFFER_LENGTH];

    // reading no of records
    res = fgets(buffer, BUFFER_LENGTH, f);

    if (res == NULL || feof(f))
    {
        printf("INCORRECT_FILE_CONTENT");
        return INCORRECT_FILE_CONTENT;
    }
    *records_no = strtol(buffer, &res, 10);

    if (*res != '\n')
    {
        printf("INCORRECT_FILE_CONTENT");
        return INCORRECT_FILE_CONTENT;
    }

    if (*records_no > ARR_MAX_LEN)
    {
        printf("MAX_LEN_STRUCTS_ERROR");
        return TOO_MANY_STRUCTS_ERROR;
    }

    // reading all records
    for (int i = 0; i < *records_no; i++)
    {
        arr[i].name[0] = 0;
        arr[i].price = -1;

        // reading name

        res = fgets(buffer, BUFFER_LENGTH, f);

        if (res == NULL || feof(f) || strlen(buffer) == 0) {
            printf("INCORRECT_FILE_CONTENT");
            return INCORRECT_FILE_CONTENT;
        }

        if (strcmp(buffer, "\n") == 0)
        {
            printf("EMPTY_STRING");
            return EMPTY_PRODUCT_NAME_ERROR;
        }

        if (strstr(buffer, "\n") == NULL)
        {
            printf("NAME_IS_TOO_LONG");
            return PRODUCT_NAME_TOO_LONG_ERROR;
        }

        buffer[strcspn(buffer, "\n\r")] = 0;

        if (strlen(buffer) > NAME_MAX_LEN)
        {
            printf("NAME TOO LONG");
            return PRODUCT_NAME_TOO_LONG_ERROR;
        }

        strcpy(arr[i].name, buffer);

        // reading price
        res = fgets(buffer, BUFFER_LENGTH, f);

        if (res == NULL || strlen(buffer) == 0) {
            printf("INCORRECT_FILE_CONTENT");
            return INCORRECT_FILE_CONTENT;
        }

        arr[i].price = strtol(buffer, &res, 10);

        if (*res != '\n')
        {
            if (*res != '\0')
            {
                printf("INCORRECT_FILE_CONTENT");
                return INCORRECT_FILE_CONTENT;
            }

        }

        if (arr[i].price <= 0) {
            printf("INCORRECT_PRICE");
            return INCORRECT_PRICE_ERROR;
        }

    }//for

    if (!feof(f))
    {
        printf("INCORRECT_FILE_CONTENT");
        return INCORRECT_FILE_CONTENT;
    }

    return OK;
}

void find(double p, int file_len, product arr[ARR_MAX_LEN])
{
    for (int i = 0; i < file_len; i++)
    {
        if (arr[i].price < p)
        {
            printf("%s\n", arr[i].name);
            printf("%d\n", arr[i].price);
        }
    }
}
