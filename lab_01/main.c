#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define MAX_STRING_LEN 500

#define READ_ERROR -1
#define NOT_A_TRIANGLE -2

static int enter_coordinates(int *vertices);
static double perimetr_count(int *vertices);
static void result_print(int *vertices, double P);

int main()
{
    int rc = 0;
    int vertices[6];
    double P;

    rc = enter_coordinates(vertices);
    if (rc == OK)
    {
        P = perimetr_count(vertices);
        if (P > 0)
        {
            result_print(vertices, P);
        }
    }

    return rc;
}

static int enter_coordinates(int *vertices)
{
    int rc = OK;
    char string[MAX_STRING_LEN];
    char *end = string;

    printf("enter coordinates:");

    if (fgets(string, MAX_STRING_LEN, stdin) == NULL)
    {
        rc = READ_ERROR;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            vertices[i] = strtol(end, &end, 10);
            if (*end != ' ' && *end != '\n')
            {
                rc = READ_ERROR;
                break;
            }
        }
    }
    return rc;
}

static double perimetr_count(int *vertices)
{
    double rc = OK;
    if (0) //check if triangle
    {

    }
    else
    {
        rc = sqrt(pow(vertices[0] - vertices[2], 2) + pow(vertices[1] - vertices[3], 2)) + sqrt(pow(vertices[0]
        - vertices[4], 2) + pow(vertices[1] - vertices[5], 2)) + sqrt(pow(vertices[2] - vertices[4], 2) +
        pow(vertices[3] - vertices[5], 2));
    }

    return rc;
}

static void result_print(int *vertices, double P)
{
    printf("your coordinates is:\n x_1 - %d\n y_1 - %d\n x_2 - %d\n y_2 - %d\n x_3 - %d\n y_3 - %d\n",\
    vertices[0], vertices[1], vertices[2], vertices[3], vertices[4], vertices[5]);
    printf("AB - %lf\n", sqrt(pow(vertices[0] - vertices[2], 2) + pow(vertices[1] - vertices[3], 2)));
    printf("AC - %lf\n", sqrt(pow(vertices[0]- vertices[4], 2) + pow(vertices[1] - vertices[5], 2)));
    printf("BC - %lf\n", sqrt(pow(vertices[2] - vertices[4], 2) + pow(vertices[3] - vertices[5], 2)));
    printf("Result is: %lf\n", P);
}
