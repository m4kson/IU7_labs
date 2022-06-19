#include "../inc/time_tracker.h"

static int* arr_generator(size_t size);

int main(void)
{
    int count = 10;

    int *arr1 = arr_generator(count);
    int *arr2 = arr_generator(count * 10);
    int *arr3 = arr_generator(count * 100);
    int *arr4 = arr_generator(count * 1000);

    int *arr11 = arr_generator(count);
    int *arr22 = arr_generator(count * 10);
    int *arr33= arr_generator(count * 100);
    int *arr44 = arr_generator(count * 1000);


    printf("\n For mysort: \n");
    check_time(arr1, count, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(mysort));
    check_time(arr2, count * 10, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(mysort));
    check_time(arr3, count * 100, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(mysort));
    check_time(arr4, count * 1000, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(mysort));

    printf("\n For qsort: \n");
    check_time(arr11, count, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(qsort));
    check_time(arr22, count * 10, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(qsort));
    check_time(arr33, count * 100, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(qsort));
    check_time(arr44, count * 1000, sizeof(int), (void (*)(void *, size_t , size_t , int (*comp)(const void *, const void *)))(qsort));


}

// void mysort(void *p_start, size_t count, size_t size, int (*comp)(const void *, const void *))
// (int (*)(const void*, const void*))(comp_num)  - vizov

int64_t check_time(void *p_start, size_t count, size_t size,  void (*sort)(void *p_start, size_t count, size_t size, int (*comp)(const void *, const void *)))
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;

    gettimeofday(&tv_start, NULL);

    sort(p_start, count, size, (int (*)(const void*, const void*))(comp_num));

    gettimeofday(&tv_stop, NULL);
    elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    printf("\n\t For %lld elements result: ", count);
    printf("%" PRId64 " us\n", elapsed_time);
    return elapsed_time;
}

static int* arr_generator(size_t size)
{
    int *data = NULL;
    data = malloc(size * sizeof(int));

    if (data == NULL)
        return 0;

    for (int i = 0; i < size; i++)
        data[i] = rand();

    return data;
}
