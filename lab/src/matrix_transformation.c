#include "../inc/matrix_transformation.h"

static int take_size(int *row, int *column);
static int take_row(double *row, int columns);

static void delete_row(double ***data, int delete_num, int *row);
static void delete_column(double ***data, int delete_num, int row, int *column);
static int find_max_row(double **data, int row, int column);
static int find_max_column(double **data, int row, int column);

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

void make_square(double **data, int *row, int *column)
{
    int delete_num;
    if (*row > *column)
    {
        while (*row != *column)
        {
            delete_num = find_max_row(data, *row, *column);
            delete_row(&data, delete_num, row);
        }
    }

    else if (*row < *column)
    {
        while (*row != *column)
        {
            delete_num = find_max_column(data, *row, *column);
            delete_column(&data, delete_num, *row, column);
        }
    }
}

static void delete_row(double ***data, int delete_num, int *row)
{
    for (int i = delete_num; i < *row - 1; i++)
    {
        (*data)[i] = (*data)[i + 1];
    }
    //(*data)[*row] = NULL;
    (*row)--;

//    for (int i = 0; i < *row; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            printf("%lf ", (*data)[i][j]);
//        }
//        printf("\n");
//    }

}

static void delete_column(double ***data, int delete_num, int row, int *column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = delete_num; j < *column - 1; j++)
        {
            (*data)[i][j] = (*data)[i][j + 1];
        }
        //(*data)[i][*column] = '\0';
    }
    (*column)--;
}

static int find_max_row(double **data, int row, int column)
{
    int max_row = 0;
    double max_num = data[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (fabs(data[i][j] - max_num) > eps && data[i][j] > max_num)
            {
                max_num = data[i][j];
                max_row = i;
            }
        }
    }
    return max_row;
}

static int find_max_column(double **data, int row, int column)
{
    int max_column = 0;
    double max_num = data[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (fabs(data[i][j] - max_num) > eps && data[i][j] > max_num)
            {
                max_num = data[i][j];
                max_column = j;
            }
        }
    }
    return max_column;
}

