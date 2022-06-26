//лаба №8 вариант 1

#include "../inc/matrix_transformation.h"

int main()
{
    int n, m, p, q;
    //unsigned int f, g;
    double **arrayA = NULL, **arrayB = NULL;

    read_matrix(&n, &m, &arrayA);
    read_matrix(&p, &q, &arrayB);

    make_square(arrayA, &n, &m);
    make_square(arrayB, &p, &q);

    print_matrix(arrayA, n, m);
    printf("\n");
    print_matrix(arrayB, p, q);

    return 0;
}