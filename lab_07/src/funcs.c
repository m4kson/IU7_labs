#include "../inc/funcs.h"

static long get_file_len(FILE* file, int *rc);
static long get_numbers_amount(char *string, int *rc);
static long take_number(char *string, char **end_ptr);
static long new_arr_size_find (const int *data, const int *pend, const int **max_pointer, const int **min_pointer);
static int allocate_new_arr(int **date, long len);
static void index_sort(int **p_max, int **p_min);
static void fill_new_arr(int *p_max, int *p_min, int *new_data, const int *new_pend);
static void swap(int *max, int *min);

int check_args(int argc) //char** argv
{
    //todo мб добавить еще какие-то проверки???
    int rc = OK;

    if (argc != 4 && argc != 3)
        rc = ARGUMENT_ERROR;
        //exit(ARGUMENT_ERROR);

    return rc;
}

FILE * get_check_in_file(char* in_file_name, long* file_len, int *rc)
{
    FILE* file = fopen(in_file_name, "r");

    if (file == NULL)
        *rc = FILE_OPEN_ERROR;

    if (*rc == OK)
    {
        *file_len = get_file_len(file, rc);

        if (*file_len == 0 && *rc == OK)
            *rc = EMPTY_FILE_ERROR;

        if (*rc == OK)
        {
            fseek(file, 0, SEEK_SET);
        }

    }

    return file;
}

static long get_file_len(FILE* file, int *rc)
{
    //todo считываем целые числа пока не конец файла, их кол-во == "длине файла"
    char buffer[STRING_MAX_LEN] = {'\0'};
    long numbers_amount = 0;

    while (!feof(file)) //todo сделать только чтение одной строки
    {
        fgets(buffer, STRING_MAX_LEN, file);
        numbers_amount += get_numbers_amount(buffer, rc);
    }

    return numbers_amount;
}

static long get_numbers_amount(char *string, int *rc)
{
    long numbers_amount = 0;
    long i = 0;
    static char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    static char symbols[] = {' ', '\0'};
    static char signs[] = {'-', '+'};

    while (string[i] != '\0')
    {
        if (strchr(digits, string[i]) == NULL && strchr(symbols, string[i]) == NULL && strchr(signs, string[i]) ==NULL)
            *rc = BAD_FILE_CONTENT_ERROR;

        if (strchr(signs, string[i]) && strchr(digits, string[i + 1]) == NULL)
            *rc = BAD_FILE_CONTENT_ERROR;

        if (strchr(digits, string[i]) != NULL && strchr(symbols, string[i + 1]) != NULL)
            numbers_amount++;

        i++;
    }

    return numbers_amount;
}

int allocate_array(int **date, long len)
{
    int rc = OK;
    *date = calloc(len, sizeof(long));

    if (*date == NULL)
        rc = ALLOCATE_ERROR;

    return rc;
}

int read_array(FILE* file, int* data, const int *pend)
{
    int rc = OK;

    if (file == NULL)
        rc = FILE_OPEN_ERROR;

    else
    {
        if (data == NULL || pend == NULL)
            rc = ALLOCATE_ERROR;

        else
        {
            char string[STRING_MAX_LEN];
            fgets(string, STRING_MAX_LEN, file);
            get_numbers_amount(string, &rc);
            if (rc == OK)
            {
                char *end_ptr;
                for (; data < pend; data++)
                {
                    *data = take_number(string, &end_ptr);
                }
            }
        }
    }
    return rc;
}

static long take_number(char *string, char **end_ptr)
{
    long number = strtol(string, end_ptr, 10);
    strcpy(string, *end_ptr);
    return number;
}

void print_array(const int *data, const int *pend)
{
    for (; data < pend; data++)
        printf("%d ", *data);
    printf("\n");
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;

    if (pb_src == NULL || pe_src == NULL || pb_dst == NULL || pe_dst == NULL)
        rc = KEY_BAD_PARAMS;

    if (rc == OK)
    {
        int *p_max, *p_min;
        long new_arr_len = new_arr_size_find(pb_src, pe_src, (const int **) &p_max, (const int **) &p_min);
        if (new_arr_len == 0)
            rc = EMPTY_NEW_ARR;

        if (rc == OK)
        {
            rc = allocate_new_arr(pb_dst, new_arr_len);
            if (rc == OK)
            {
                *pe_dst = *pb_dst + new_arr_len;
                fill_new_arr(p_max, p_min, *pb_dst, *pe_dst);
            }
        }
    }

    return rc;
}

static long new_arr_size_find (const int *data, const int *pend, const int **max_pointer, const int **min_pointer)
{
    int min = *data, max = *data;
    *min_pointer = data;
    *max_pointer = data;

    for (; data < pend; data++)
    {
        if (*data < min)
        {
            min = *data;
            *min_pointer = data;
        }
        if (*data > max)
        {
            max = *data;
            *max_pointer = data;
        }
    }
    return (long) llabs(*max_pointer - *min_pointer) - 1;
}

static int allocate_new_arr(int **date, long len)
{
    //todo возможно то же что и allocate_array
    int rc = OK;
    *date = calloc(len, sizeof(long));

    if (*date == NULL)
        rc = ALLOCATE_ERROR;

    return rc;
}

static void fill_new_arr(int *p_max, int *p_min, int *new_data, const int *new_pend)
{
    index_sort(&p_max, &p_min);
    p_min++;

    for (; new_data < new_pend; new_data++)
    {
        *new_data = *p_min;
        p_min++;
    }
}

static void index_sort(int **p_max, int **p_min)
{
    int *buf;

    if (*p_min > *p_max)
    {
        buf = *p_max;
        *p_max = *p_min;
        *p_min = buf;
    }
}

void bubble_sort(int *p_start, const int *p_end)
{
    int *start = p_start;
    for (int i = 0; p_start < p_end; p_start++, i++)
        for (int *j = start;j < p_end - i - 1; j++)
            if (*j > *(j + 1))
               swap(j, j+1);
}

static void swap(int *max, int *min)
{
    int buff = *min;
    *min = *max;
    *max = buff;
}

void write_arr(char *file_name, int *p_start, const int *p_end)
{
    FILE *file = fopen(file_name, "w");

    for (; p_start < p_end; p_start++)
    {
        fprintf(file, "%d ", *p_start);
    }

    fclose(file);
}