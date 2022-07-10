#include "../inc/matrix_transformation.h"

static int take_size(int *row, int *column);
static int take_row(double *row, int columns);

static void delete_row(double ***data, int delete_num, int *row);
static void delete_column(double ***data, int delete_num, int row, int *column);
static int find_max_row(double **data, int row, int column);
static int find_max_column(double **data, int row, int column);
static double find_middle(double **data, int row, int column);
static double find_max(double **data, int row, int column);

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

double **make_equal(double **data, int *row, int *column,  int needed_size)
{
    double **new_data = allocate_matrix(needed_size, needed_size);

    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *column; j++)
        {
            new_data[i][j] = data[i][j];
        }
    }

    for (int i = *row; i < needed_size; i++)
    {
        for (int j = 0; j < *column; j++)
        {
            new_data[i][j] = (int) find_middle(new_data, *row, j);
        }
    }
    *row = needed_size;

    for (int i = 0; i < *row; i++)
    {
        for (int j = *column; j < needed_size; j++)
        {
            new_data[i][j] = find_max(new_data, i, *column);
        }
    }

    *column = needed_size;

    return new_data;
}

static double find_middle(double **data, int row, int column)
{
    double sum = 0;

    for (int j = 0; j < row; j++)
    {
        sum += data[j][column];
    }

    return sum / row;
}

static double find_max(double **data, int row, int column)
{
    double max = data[row][0];
    for (int j = 0; j < column; j++)
    {
        if (data[row][j] > max)
            max = data[row][j];
    }

    return max;
}

double **matrix_exp(double **data, int row, int column, unsigned int pow)
{
    double **new_data = allocate_matrix(row, column);
    double **new_data_tmp = allocate_matrix(row, column);

    for (int i = 0; i < column; i++)
        for (int j = 0; j < column; j++)
            new_data[i][j] = data[i][j];

    for (int q = 0; q < pow - 1; q++)
    {
        for(int i = 0; i < column; i++)
            for(int j = 0; j < column; j++)
            {
                new_data_tmp[i][j] = 0;
                for(int k = 0; k < column; k++)
                    new_data_tmp[i][j] += new_data[i][k] * data[k][j];
            }

        for (int i = 0; i < column; i++)
            for (int j = 0; j < column; j++)
                new_data[i][j] = new_data_tmp[i][j];
    }

    free_matrix(new_data_tmp, row);
    return new_data;
}
