#include "../inc/funcs.h"
#include "../inc/sort.h"

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
                        int new_arr_len = (int)(new_pend - new_data);

                        if (rc == OK)
                        {
                            mysort(new_data, new_arr_len, sizeof(int), (int (*)(const void*, const void*))(comp_num));
                            print_array(new_data, new_pend);
                            write_arr(argv[2], new_data, new_pend);

                            free(new_data);
                            free(data);
                        }
                        else
                        {
                            if (data != NULL)
                                free(data);
                            if (new_data != NULL)
                                free(new_data);
                        }

                    }
                    else
                    {
                        mysort(data, array_len, sizeof(int), (int (*)(const void*, const void*))(comp_num));
                        print_array(data, pend);
                        write_arr(argv[2], data, pend);

                        free(data);
                    }
                }
                else
                    if (data != NULL)
                        free(data);

            }
        }
        if (rc != FILE_OPEN_ERROR)
            fclose(input_file);
    }

    return rc;
}