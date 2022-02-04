#ifndef LAB_02_02_00_ARRAY_H
#define LAB_02_02_00_ARRAY_H

/**
 * read string from stdin and fulfill the int array
 * @param arr - array
 * @param len - array size (number of elements)
 * @return exit code (0 if everything is OK)
 */
int read_array(int *arr, int *len);

/**
 * fulfill new array with elements witch is bigger than average of old array
 * @param new_array - new array
 * @param old_array - old array
 * @param len - size of old array
 * @return size of new array or exit code if something wrong
 */
int create_new_array(int *new_array, const int *old_array, int len, double average);

/**
 * count average of all array members
 * @param arr - array
 * @len - array size
 * @return average
 */
double average_of_array(const int *arr, int len);

/**
 * print results
 * @param arr - new array
 * @param len - size of new array
 * @param average - average
 */
void print_result(int *arr, int len, double average);

#endif //LAB_02_02_00_ARRAY_H
