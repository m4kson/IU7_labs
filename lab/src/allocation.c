#include "../inc/allocation.h"

double** allocate_matrix(int n, int m)
{
    double **data = calloc(n, sizeof(double*));

    if(!data)
        return NULL;

    for(int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(double));

        if (!data[i])
        {
            free_matrix(data, n);
            return NULL;
        }
    }
    return data;
}

void free_matrix(double **data, int n)
{
    for(int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}