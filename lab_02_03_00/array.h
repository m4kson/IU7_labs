#ifndef LAB_02_03_00_ARRAY_H
#define LAB_02_03_00_ARRAY_H

/**
 * function read a string from stdin and fullfill the array
 * @param arr - array
 * @param len - size of array
 * @return - exit code (0 if everything OK)
 */
int read_array(int *arr, int *len);

/**
 * boolian function, tell if number is number-polyndrom
 * @param num - number
 * @return 1 - if yes, 0 - if no
 */
int is_palindrome(int num);

/**
 * function deletes number from array
 * @param arr - array
 * @param num - number to delete
 */
void delete_number(int *arr, int *len, int num);

/**
 * move every element of attay left, starts with pos
 * @param arr - array
 * @param pos - position
 */
void move_arr(int *arr, int pos, int *length);

/**
 * function find out length of number
 * @param num
 * @return length
 */
int take_length(int num);

void print_result(int *arr, int len);

#endif //LAB_02_03_00_ARRAY_H
