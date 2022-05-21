#include "my_filter.h"

int main(int argc, char **argv)
{
    int rc = OK;

    if (argc < 2)
    {
        rc = argument_error;
    }

    item arr[items_max_num];
    FILE *f = fopen(argv[1], "r");


    rc = read_items(f, arr);
    return rc;
}
