#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define MAX_STRING_LEN 50

#define READ_ERROR -1
#define NON_A_TRIANGLE -2

static int enter_coordinates(int *x_1, int *y_1, int *x_2, int *y_2, int *x_3, int *y_3);
static int perimetr_count(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3);
static void result_print(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int P);
static int read_number(int *x);

int main()
{
    int rc = 0;
    int x_1, y_1, x_2, y_2, x_3, y_3;

    rc = enter_coordinates(&x_1, &y_1, &x_2, &y_2, &x_3, &y_3);
    if (rc == OK)
    {
        rc = perimetr_count(x_1, y_1, x_2, y_2, x_3, y_3);
        if (rc >= 0)
        {
            result_print(x_1, y_1, x_2, y_2, x_3, y_3, rc);
            rc = OK;
        }
    }

    return rc;
}

static int enter_coordinates(int *x_1, int *y_1, int *x_2, int *y_2, int *x_3, int *y_3)
{
    int rc = OK;

    printf("enter coordinates:");
    rc = read_number(x_1);
    if (rc != OK)
    {
        return rc;
    }
    rc = read_number(y_1);
    if (rc != OK)
    {
        return rc;
    }
    rc = read_number(x_2);
    if (rc != OK)
    {
        return rc;
    }
    rc = read_number(y_2);
    if (rc != OK)
    {
        return rc;
    }
    rc = read_number(x_3);
    if (rc != OK)
    {
        return rc;
    }
    rc = read_number(y_3);
    if (rc != OK)
    {
        return rc;
    }

    return rc;
}

static int read_number(int *x)
{
  int rc = OK;
  char *string = "";
  char *end;

    fgets(string, MAX_STRING_LEN, stdin);
    *x = strtol(string, &end, 10);

    if (*end != ' ' && *end != '\n')
    {
        rc = READ_ERROR;
        *x = 0234002;
    }
    return rc;
}

static int perimetr_count(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
    int rc = OK;
    if (x_1 == x_2 == x_3 || y_1 == y_2 == y_3)
    {
        rc = NON_A_TRIANGLE;
    }
    else
    {
        rc = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2)) + sqrt(pow(x_1 - x_3, 2) + pow(y_1 - y_3, 2)) + \
        + sqrt(pow(x_2 - x_3, 2) + pow(y_2 - y_3, 2));
    }

    return rc;
}

static void result_print(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int P)
{
    printf("your coordinates is:\n x_1 - %d\n y_1 - %d\n x_2 - %d\n y_2 - %d\n x_3 - %d\n y_3 - %d\n",\
    x_1, y_1, x_2, y_2, x_3, y_3);
    printf("AB - %d", (int)sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2)));
    printf("AC - %d", (int)sqrt(pow(x_1 - x_3, 2) + pow(y_1 - y_3, 2)));
    printf("BC - %d", (int)sqrt(pow(x_2 - x_3, 2) + pow(y_2 - y_3, 2)));
    printf("Result is: %d", P);
}