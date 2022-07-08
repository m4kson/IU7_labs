#ifndef LAB_MATRIX_TRANSFORMATION_H
#define LAB_MATRIX_TRANSFORMATION_H

#include "../inc/allocation.h"
#include "../inc/errors.h"
#include <stdio.h>
#include "errors.h"
#include <math.h>

int read_matrix(int *row, int *column, double ***data);
void print_matrix(double **data, int row, int column);
void make_square(double **data, int *row, int *column);
double **make_equal(double **data, int *row, int *column,  int needed_size);

#endif //LAB_MATRIX_TRANSFORMATION_H
