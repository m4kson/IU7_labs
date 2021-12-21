#include "../inc/matrix_transformation.h"

static int take_size(int *row, int *column);
static int take_row(double *p_row, int columns);

int take_matrix(int *row, int *column, double **data)
{
    int rc = OK;

    take_size(row, column);
    data = allocate_matrix(*row, *column);

    if(!data)
        rc = ALLOCATION_ERROR;

    for(int i = 0; i < n; i++)
    {
        take_row(data[i]);
    }

    return rc;
}

static int take_size(int *row, int *column)
{
    //todo remake func, need too read as a string and check all symbols
    int rc = OK;

    rc = scanf("Enter n: %d", row);

    if (rc != 1)
        rc = ENTER_ERROR;

    else
    {
        rc = scanf("Enter m: %d", column);

        if (rc != 1)
            rc = ENTER_ERROR;
    }

    return rc;
}

static int take_row(double *p_row, int columns)
{
    char buffer[MAX_STRING_LEN];
    char **end_pointer;

    fgets(buffer, MAX_STRING_LEN, stdin);

    for(int i = 0; i < columns; i++)
    {
        *(p_row + i) = strtod(buffer, end_pointer); //todo if can't take a double retutns zero(
    }

}
