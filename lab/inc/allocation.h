#ifndef LAB_ALLOCATION_H
#define LAB_ALLOCATION_H

#include "stdlib.h"
#include "../inc/errors.h"

/**
 *
 * @param n -row number
 * @param m -column number
 * @return  -array of string pointers ot NULL
 */
double** allocate_matrix(int n, int m);

void free_matrix(double **data, int n);

#endif //LAB_ALLOCATION_H
