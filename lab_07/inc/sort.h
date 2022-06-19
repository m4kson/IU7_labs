#ifndef LAB_07_1_1_SORT_H
#define LAB_07_1_1_SORT_H

#include <string.h>
#include <stdio.h>


/**
 * modified bubble sort
 * @param p_start pointer to first element of array
 * @param count   number of elements
 * @param size    size of one element
 * @param comp    pointer to compare function
 */
void mysort(void *p_start, size_t count, size_t size, int (*comp)(const void *, const void *));

/**
 * compare two int numbers
 * @param v1 pointer to first number
 * @param v2 pointer to second number
 * @return -1 if > 0 if = 1 if <
 */
int comp_num(const void *v1, const void *v2);

#endif //LAB_07_1_1_SORT_H
