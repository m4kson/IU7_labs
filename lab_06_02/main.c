#include "my_filter.h"

int main(int argc, char **argv)
{
    int rc = OK;
    int item_number = 0;

    if (argc < 2)
    {
        rc = argument_error;
    }

    if (argc >3)
    {
        rc = argument_error;
    }

    if (rc == OK)
    {
        item arr[items_max_num];
        FILE *f = fopen(argv[1], "r");

        if (f == NULL)
        {
            f = fopen(strcat(argv[1], ".txt"), "r");
        }


        rc = read_items(f, arr, &item_number);
        if (rc == OK)
        {
            if (argc == 3)
            {
                print_information(arr, argv[2], item_number);
            } else print_information(arr, "None", item_number);
        }

    }

    return rc;
}
