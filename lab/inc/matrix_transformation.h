#ifndef LAB_MATRIX_TRANSFORMATION_H
#define LAB_MATRIX_TRANSFORMATION_H

#include "../inc/allocation.h"
#include "../inc/errors.h"
#include <stdio.h>

int read_matrix(int *row, int *column, double ***data);
void print_matrix(double **data, int row, int column);

#endif //LAB_MATRIX_TRANSFORMATION_H
