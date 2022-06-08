#include "../inc/matrix_transformation.h"

int main()
{
    int n, m, p, q;
    //unsigned int f, g;
    double **arrayA, **arrayB;

    take_matrix(&n, &m, arrayA); //takes A matrix
    take_matrix(&p, &q, arrayB); //takes B matrix

    //make_square(); //makes square A
    //make_square(); //makes square B

    //make_same_size(); //make matrix size equal

    //exponentiation_matrix(); //exponent A to f
    //exponentiation_matrix(); //exponent B to g

    //multiply_matrix(); //multiply A on B

    print_matrix(arrayA, n, m); //print result

    return 0;
}
