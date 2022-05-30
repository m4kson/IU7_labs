#include "my_filter.h"

static void read_name(FILE *f, char *name, int *rc);
static void read_weight(FILE *f, double *weight, int *rc);
static void read_volume(FILE *f, double *volume, int *rc);
static void read_structure(FILE *f, item *item, int *rc);
static void print_arr_of_structures(item *arr, int item_number);
static int comp(const item *arg1, const item *arg2);

int read_items(FILE* f, item* arr, int *item_counter)
{
    int rc = OK;


    if (f != NULL)
    {
        *item_counter = 0;
        while (!feof(f))
        {

            read_structure(f, &arr[*item_counter], &rc);
            (*item_counter)++;
            if (rc != OK)
                break;
        }
    } else  rc = file_open_error;

//    for (int i = 0; i < 3; i++)
//    {
//        printf("%lf \n", arr[i].weight);
//    }


    return rc;
}

static void read_structure(FILE *f, item *item, int *rc)
{

    read_name(f, item->name, rc);
    read_weight(f, &item->weight, rc);
    read_volume(f, &item->volume, rc);

}

static void read_name(FILE *f, char *name, int *rc)
{
    char *res;
    name[0] = 0;
    char buffer[buffer_len];

    res = fgets(buffer, buffer_len, f);

    if (res == NULL || feof(f) || strlen(buffer) == 0)
    {
         *rc = incorrect_file_content;
    }

    if (strcmp(buffer, "\n") == 0)
    {
        *rc = empty_item_name;
    }

    if (strstr(buffer, "\n") == NULL)
    {
        *rc = item_name_too_long;
    }

    buffer[strcspn(buffer, "\n\r")] = 0;

    if (strlen(buffer) > max_name_len)
    {
        *rc = item_name_too_long;
    }

    strcpy(name, buffer);
}

static void read_weight(FILE *f, double *weight, int *rc)
{
    char *res;
    *weight = 0;
    char buffer[buffer_len];

    res = fgets(buffer, buffer_len, f);

    if (res == NULL || strlen(buffer) == 0)
    {
        *rc = incorrect_file_content;
    }

    *weight = strtod(buffer, &res);

    if (*res != '\n' && *res !='\0')
    {
        *rc = incorrect_file_content;
    }

    if (*weight <= 0)
    {
        *rc = incorrect_file_content;
    }
}

static void read_volume(FILE *f, double *volume, int *rc)
{
    char *res;
    *volume = 0;
    char buffer[buffer_len];

    res = fgets(buffer, buffer_len, f);

    if (res == NULL || strlen(buffer) == 0)
    {
        *rc = incorrect_file_content;
    }

    *volume = strtod(buffer, &res);

    if (*res != '\n' && *res !='\0')
    {
        *rc = incorrect_file_content;
    }

    if (*volume <= 0)
    {
        *rc = incorrect_file_content;
    }
}

void print_information(item* arr, char* prefix, int item_number)
{
    if (strcmp(prefix, "None") == 0)
    {
        qsort(arr, item_number,sizeof(item), (int(*) (const void *, const void *)) comp);
        print_arr_of_structures(arr, item_number);
    }

    else if (strcmp(prefix, "ALL") == 0)
    {
        print_arr_of_structures(arr, item_number);
    }

    else
    {
        for (int i = 0; i < item_number; i++)
        {
            if (strstr(arr[i].name, prefix) == arr[i].name)
            {
                printf("%s\n", arr[i].name);
                printf("%lf\n", arr[i].weight);
                printf("%lf\n", arr[i].volume);
            }
        }
    }
}

static void print_arr_of_structures(item *arr, int item_number)
{
    for (int i = 0; i < item_number; i++)
    {
        printf("%s\n", arr[i].name);
        printf("%lf\n", arr[i].weight);
        printf("%lf\n", arr[i].volume);
    }
}

static int comp(const item *arg1, const item *arg2)
{
    int res;

    if ((arg1->weight / arg1->volume - arg2->weight / arg2->volume) < eps)
        res = 0;

    else if (arg1->weight / arg1->volume - arg2->weight / arg2->volume < 0)
        res = -1;

    else
        res = 1;

    return res;
}