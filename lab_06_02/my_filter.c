#include "my_filter.h"

static void read_name(FILE *f, char **name, int *rc);
static int read_weight(double weight, int *rc);
static int read_volume(double volume, int *rc);
static int read_structure();

int read_items(FILE* f, item* arr)
{
    int rc = OK;

    if (f != NULL)
    {
        int item_counter = 0;
        while (!feof(f))
        {

            //todo read structure
            item_counter++;
        }
    } else  rc = file_open_error;


    return rc;
}

static int read_structure(FILE *f,char *name, int *rc)
{

    read_name(f, &name, rc);
    read_weight();
    read_volume();

}

static void read_name(FILE *f, char **name, int *rc)
{
    char *res;
    name[0] = 0;
    char buffer[buffer_len];

    res = fgets(buffer, buffer_len, f);

    if (res == NULL || feof(f) || strlen(buffer) == 0)
    {
        printf("INCORRECT_FILE_CONTENT");
         *rc = incorrect_file_content;
    }

    if (strcmp(buffer, "\n") == 0)
    {
        printf("EMPTY_STRING");
        *rc = empty_item_name;
    }

    if (strstr(buffer, "\n") == NULL)
    {
        printf("NAME_IS_TOO_LONG");
        *rc = item_name_too_long;
    }

    buffer[strcspn(buffer, "\n\r")] = 0;

    if (strlen(buffer) > max_name_len)
    {
        printf("NAME TOO LONG");
        *rc = item_name_too_long;
    }

    strcpy(*name, buffer);
}
