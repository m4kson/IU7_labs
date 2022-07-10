//лаба №8 вариант 1

#include "../inc/matrix_transformation.h"

int main()
{
    int n, m, p, q;
    unsigned int f, g;
    double **arrayA = NULL, **arrayB = NULL, **arrayA2 = NULL, **arrayB2 = NULL, **arrayRes = NULL;
    int rc = OK;

    rc = read_matrix(&n, &m, &arrayA);
    if (rc == OK)
    {
        rc = read_matrix(&p, &q, &arrayB);
        if (rc == OK)
        {
            make_square(arrayA, &n, &m);
            make_square(arrayB, &p, &q);

            if (n < p)
            {
                arrayA = make_equal(arrayA, &n, &m, p);
            }

            else if (p < n)
            {
                arrayB = make_equal(arrayB, &p, &q, n);
            }

            char buffer1[255];
            char buffer2[255];
            char *end = NULL;

            printf("enter ρ: ");
            if (fgets(buffer1, 255, stdin) != NULL)
            {
                f = strtoul(buffer1, &end, 10); //todo check if enter is wrong

                printf("enter ϒ: ");
                if (fgets(buffer2, 255, stdin) != NULL)
                {
                    g = strtoul(buffer2, &end, 10); //todo check if enter is wrong
                    arrayA2 = matrix_exp(arrayA, n, m, f);
                    arrayB2 = matrix_exp(arrayB, p, q, g);

                    arrayRes = multiply_equal_matrix(arrayA2, arrayB2, n);

                    print_matrix(arrayA, n, m);
                    printf("\n");
                    print_matrix(arrayB, p, q);

                    printf("\n");
                    print_matrix(arrayA2, n, m);

                    printf("\n");
                    print_matrix(arrayB2, p, q);

                    printf("\n");
                    print_matrix(arrayRes, p, q);
                }
            } else
                rc = ENTER_ERROR;
        }

    }

    return rc;
}