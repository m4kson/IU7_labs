#include "../inc/matrix_transformation.h"

static int take_size(int *row, int *column);
static int take_row(double *row, int columns);

int read_matrix(int *row, int *column, double ***data)
{
    int rc = OK;

    rc = take_size(row, column);

    if (rc == 0)
    {
        *data = allocate_matrix(*row, *column);

        if (!(*data))
            rc = ALLOCATION_ERROR;

        else
        {
            for (int i = 0; i < *row; i++)
            {
                rc = take_row((*data)[i], *column);
                if (rc  != 0)
                    break;
            }
        }
    }
    return rc;
}

static int take_size(int *row, int *column)
{
    int rc = OK;
    char buffer[255];
    char *end = NULL;

    printf("enter size of matrix: \n");

    if (fgets(buffer, 255, stdin) != NULL)
    {
        *row = strtol(buffer, &end, 10);
        if (*row == 0 && end == NULL)
            rc = ENTER_ERROR;
        else
        {
            *column = strtol(end, &end, 10);
            if (*column == 0 && end == NULL)
                rc = ENTER_ERROR;
        }
    }
    return rc;
}

static int take_row(double *row, int columns)
{
    int rc = OK;
    char buffer[255];
    char *end = NULL;

    if (fgets(buffer, 255, stdin) != NULL)
    {
        row[0] = strtod(buffer, &end);
        for (int i = 1; i < columns; i++)
        {
            row[i] = strtod(end, &end);
        }
    }
    else
        rc = ENTER_ERROR;

    return rc;
}

void print_matrix(double **data, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%lf ", data[i][j]);
        }
        printf("\n");
    }
}