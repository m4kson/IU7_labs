#include "funcs.h"

int main(int argc, char **argv)
{
    double p;
    int recors_no;
    product arr[ARR_MAX_LEN];
    int res;

    if (argc != 3)
    {
        printf("ARG_ERROR");
        return ARGUMENT_ERROR;
    }

    // app.exe my_folder\ttt.txt

    if (strlen(argv[1]) > MAX_FILE_NAME_LEN)
    {
        printf("FILE_NAME_TOO_LONG");
        return FILE_NAME_TOO_LONG_ERROR;
    }

    FILE* f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("FILE cant be opened\n");
        return FILE_OPEN_ERROR;
    }

    fseek(f,0,SEEK_END);
    long pos=ftell(f);
    if(pos <= 0)
    {
        printf("EMPTY_FILE");
        return EMPTY_FILE_ERROR;
    }
    fseek(f,0,SEEK_SET);

    char* end_of_string;
    p = strtod(argv[2], &end_of_string);

    if (*end_of_string != ' ' && *end_of_string != '\0' && *end_of_string != '\n' && *end_of_string != '\t')
    {
        printf("INCORRECT_NUMBER_FORM\n");
        return INCORRECT_NUMBER_FORMAT;
    }
//123de
    res = read_array(f, &recors_no, arr);
    if (res != 0)
    {
        return res;
    }

    find(p, recors_no, arr);

    fclose(f);
    return OK;
}