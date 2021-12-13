#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    int rc = OK;
    rc = check_args(argc);
    if (rc == OK)
    {
        long array_len;
        FILE* input_file = get_check_in_file(argv[1], &array_len, &rc);
        if (rc == OK)
        {
            int *data;
            rc = allocate_array(&data, array_len);
            if (rc == OK)
            {
                int *pend = data + array_len;
                rc = read_array(input_file, data, pend);
                if (rc == OK)
                {
                    print_array(data, pend); // массив в файле

                    if (strcmp(argv[3], "f") == 0)
                    {
                        int *new_data, *new_pend;
                        rc = key(data, pend, &new_data, &new_pend);

                        if (rc == OK)
                        {
                            bubble_sort(new_data, new_pend);
                            print_array(new_data, new_pend);
                            write_arr(argv[2], new_data, new_pend);

                            free(new_data);
                            free(data);
                        }
                    }
                    else
                    {
                        bubble_sort(data, pend);
                        print_array(data, pend);
                        write_arr(argv[2], data, pend);

                        free(data);
                    }
                }
            }
        }
        if (rc != FILE_OPEN_ERROR)
            fclose(input_file);
    }
    printf("%d", rc);
    return rc;
}