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
    int rc = OK;
    char buffer[255];

    fgets(buffer, 255, stdin);
    *row = atoi(buffer);

    if (*row == 0)
        rc = ENTER_ERROR;

    else
    {
        fgets(buffer, 255, stdin);
         *column = atoi(buffer);

        if (*column == 1)
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

void print_matrix(double **arr, int row, int column)
{
    for (int i = 0, i < row, i++)
    {
        for (int j = 0, j < column, j++)
            printf("%lf ", arr[i][j]);
        printf("\n");
    }
}