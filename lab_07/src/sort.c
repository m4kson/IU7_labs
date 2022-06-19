#include "../inc/sort.h"

// void qsort( void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *) );

static void swap(void *v1, void *v2, size_t size);   //swap two elements of array


void mysort(void *p_start, size_t count, size_t size, int (*comp)(const void *, const void *))
{
    char *p_last = (char*)p_start + count * size;
    char *p_last_swap = p_last - size;
    char *last_swap_tmp = p_last_swap;

    for (char *i = p_start; i < p_last; i += size)
    {
        for (char *j = p_start; j < p_last_swap; j += size)
            if (comp(j, j + size) > 0) {
                swap(j, j + size, size);
                last_swap_tmp = j;
            }
        p_last_swap = last_swap_tmp;
    }
}

int comp_num(const void *v1, const void *v2)
{
    int *a = (int*)v1;
    int *b = (int*)v2;
    if ((*a) > (*b))
        return 1;
    else if ((*a) < (*b))
        return -1;
    else
        return 0;
}

static void swap(void *v1, void *v2, size_t size)
{
    char buffer[size];

    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}


//static void swap1(int *max, int *min)
//{
//    int buff = *min;
//    *min = *max;
//    *max = buff;
//}

//void bubble_sort(int *p_start, const int *p_end) //todo прототип должен совпадать с библиотечной qsort
//{
//    int *start = p_start;
//    for (int i = 0; p_start < p_end; p_start++, i++)
//        for (int *j = start;j < p_end - i - 1; j++)
//            if (*j > *(j + 1))
//                swap1(j, j+1);
//}

