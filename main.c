#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 30
#define MAX_EXP_DIGITS 5

/*
todo Смоделировать операцию деления действительного числа
 в форме  ±m.n Е ±K, где (m+n) – суммарная длина мантиссы до 30 значащих цифр;
 K –  величина порядка до 5 цифр – на целое число длиной до 30 десятичных цифр.
 Результат выдать в форме  ±0.m1 Е ±K1, где число m1 определено до 30 значащих цифр, а K1 – до 5 цифр.
*/

typedef int LongNum[MAX_DIGITS];
typedef char LongExp[MAX_EXP_DIGITS];

int compare (LongNum a, LongNum b, int len_a, int len_b);
int sum(LongNum a, LongNum b, int len_a, int len_b, LongNum result);
int diff(LongNum a, LongNum b, int len_a, int len_b, LongNum result);
int mul(LongNum a, LongNum b);
int divv(LongNum a, LongNum b);
int read_arr(LongNum arr);
void print_arr(LongNum arr, int len_arr);

struct {
    LongNum m;
    LongExp e;
}Number;

int main()
{
    LongNum a,b;
    int len_a, len_b;
    LongNum result;
    int res_compare;

    len_a = read_arr(a);
    len_b = read_arr(b);

    printf("a: ");
    print_arr(a, len_a);
    printf("b: ");
    print_arr(b, len_b);

    // compare
    res_compare = compare(a, b, len_a, len_b);
    if (res_compare == -1)
        printf("a > b");
    if (res_compare == 1)
        printf("b > a");
    if (res_compare == 0)
        printf("a == b");
    printf("\n");

    //sum
    if (len_a > len_b)
        sum(a, b, len_a, len_b, result);
    else
        sum(b, a, len_b, len_a, result);

    //diff

    printf("a - b = ");
    diff(a, b, len_a, len_b, result);

    return 0;
}

int read_arr(LongNum arr)
{
    int len_arr = 0;
    char end;

    printf("Enter arr: ");

    while (scanf("%d", &arr[len_arr]))
    {
        scanf("%c", &end);

        len_arr++;
        if (len_arr > MAX_DIGITS)
            return -1;
        if (end == '\n')
        {
            break;
        }
    }
    return len_arr;
}

void print_arr(LongNum arr, int len_arr)
{
    for (int j = 0; j < len_arr; j++)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
}

int compare (LongNum a, LongNum b, int len_a, int len_b)
{
    if (len_a > len_b)
        return -1;
    if (len_b > len_a)
        return 1;
    else
    {
        for (int i = 0; i < len_a; i++)
        {
            if (a[i] > b[i])
                return -1;
            if (b[i] > a[i])
                return 1;
        }

        return 0;
    }
}

int sum(LongNum a, LongNum b, int len_a, int len_b, LongNum result)
{
    int dif = len_a - len_b;
    int fl = 0;

    for (len_b; (len_b - 1) >= 0; len_b--)
    {
        result[len_b + dif] = a[len_b + dif - 1] + b[len_b - 1] + fl;

        if (result[len_b + dif] >= 10)
            fl = 1;
        else
            fl = 0;

        if (fl)
            result[len_b + dif] -= 10;
    }

    for (dif; dif > 0; dif--)
    {
        result[dif] = a[dif - 1] + fl;

        if (result[dif] >= 10)
            fl = 1;
        else
            fl = 0;

        if (fl)
            result[dif] -= 10;
    }

    //todo


    printf("a + b = ");

    int i = 1;

    if (fl)
    {
        result[0] = 1;
        i = 0;
    }


    for (i; i < (len_a + 1); i++)
        printf("%d", result[i]);
    printf("\n");
}

int diff(LongNum a, LongNum b, int len_a, int len_b, LongNum result)
{
    int fl = 0;
    int len_max;
    int dif = abs(len_a - len_b);
    int sign = 0;
    int p = 1;

    if (len_a >= len_b)
    {
        len_max = len_a;

        for (int i = len_b - 1; i >= 0; i--)
        {
            result[i + dif + 1] = a[i + dif] - b[i] - fl;

            if (result[i + dif + 1] < 0)
            {
                result[i + dif + 1] += 10;
                fl = 1;
            }
            else
                fl = 0;
        }

        for (int i = len_a - len_b - 1; i >= 0; i--)
        {
            result[i + 1] = a[i] - fl;

            if (result[i + 1] < 0)
            {
                result[i + 1] += 10;
                fl = 1;
            }
            else
                fl = 0;
        }
    }

    if (len_a < len_b)
    {
        sign = 1;
        len_max = len_b;

        for (int i = len_a - 1; i >= 0; i--)
        {
            result[i + dif + 1] = b[i + dif] - a[i] - fl;

            if (result[i + dif + 1] < 0)
            {
                result[i + dif + 1] += 10;
                fl = 1;
            }
            else
                fl = 0;
        }

        for (int i = len_b - len_a - 1; i >= 0; i--)
        {
            result[i + 1] = b[i] - fl;

            if (result[i + 1] < 0)
            {
                result[i + 1] += 10;
                fl = 1;
            }
            else
                fl = 0;
        }
    }

    if (fl == 1)
    {
        sign = 1;
        p = 0;
    }

    if (sign)
    {
        result[0] = -0;
        printf("-");
    }

    for (int i = 1; i <= len_max; i++)
    {
        if (result[i] == 0)
        {
            for(int j = i; j < len_max; j++)
            {
                result[j] = result[j + 1];
            }
            len_max--;
        }
        else
            break;
    }

    for (p; p <= len_max; p++)
    {
        printf("%d", result[p]);
    }
    printf("\n");
}
