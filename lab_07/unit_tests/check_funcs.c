#include <stdlib.h>
#include <check.h>
#include "../inc/funcs.h"

////check_args
//START_TEST(test_check_args_wrong_args_number)
//{
//    int rc;
//
//    rc = check_args(5);
//
//    ck_assert_int_eq(rc, ARGUMENT_ERROR);
//}
//END_TEST

//get_check_in_file
START_TEST(test_get_check_in_file_open_error)
{
    int rc;
    long file_len;

    get_check_in_file("non_exist", &file_len, &rc);

    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
}
END_TEST

START_TEST(test_get_check_in_file_empty)
{
    int rc;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/empty_file.txt", &file_len, &rc);

    ck_assert_int_eq(rc, EMPTY_FILE_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_float)
{
    int rc;
    long file_len;
    FILE *f =get_check_in_file("./unit_tests/test_files/get_file_check_float.txt", &file_len, &rc);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_bad_content)
{
    int rc;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_bad_content.txt", &file_len, &rc);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_no_numbers)
{
    int rc;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_no_numbers.txt", &file_len, &rc);

    ck_assert_int_eq(rc, NO_NUMBERS_IN_FILE);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_correct)
{
    int rc;
    long file_len;

    printf("6");
    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_correct.txt", &file_len, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(file_len, 3);
    fclose(f);
}
END_TEST

////todo allocate_array ?
//
////read_array
//
//START_TEST(test_read_array_null_file_pointer)
//{
//    int rc;
//    int *data;
//    int *end_ptr;
//    allocate_array(&data, 3);
//    end_ptr = data + 3;
//
//    rc = read_array(NULL, data, end_ptr);
//
//    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
//    free(data);
//}
//END_TEST
//
//START_TEST(test_read_array_null_data_pointer)
//{
//    int rc;
//    int *data;
//    int *end_ptr;
//    allocate_array(&data, 3);
//    end_ptr = data + 3;
//    FILE *f = fopen("test_files/get_file_check_correct.txt", "r");
//
//    rc = read_array(f, NULL, end_ptr);
//
//    ck_assert_int_eq(rc, ALLOCATE_ERROR);
//
//    fclose(f);
//    free(data);
//}
//END_TEST
//
//START_TEST(test_read_array_null_end_pointer)
//{
//    int rc;
//    int *data;
//    allocate_array(&data, 3);
//    FILE *f = fopen("test_files/get_file_check_correct.txt", "r");
//
//    rc = read_array(f, data, NULL);
//
//    ck_assert_int_eq(rc, ALLOCATE_ERROR);
//
//    fclose(f);
//    free(data);
//}
//END_TEST
//
//START_TEST(test_read_array_bad_content)
//{
//    int rc;
//    int *data;
//    int *end_ptr;
//    allocate_array(&data, 3);
//    end_ptr = data + 3;
//    FILE *f = fopen("test_files/get_file_check_bad_content.txt", "r");
//
//    rc = read_array(f, data, end_ptr);
//
//    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
//
//    fclose(f);
//    free(data);
//}
//END_TEST
//
//START_TEST(test_read_array_correct)
//{
//    int rc;
//    int *data;
//    int *end_ptr;
//    allocate_array(&data, 3);
//    end_ptr = data + 3;
//    FILE *f = fopen("test_files/get_file_check_correct.txt", "r");
//
//    rc = read_array(f, data, end_ptr);
//
//    ck_assert_int_eq(rc, OK);
//    ck_assert_int_eq(*data, 1);
//    ck_assert_int_eq(*data + 1, -2);
//    ck_assert_int_eq(*data + 2, 3333);
//
//    fclose(f);
//    free(data);
//}
//END_TEST

//key   int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)

//START_TEST(test_key_null_pointer_on_array_start)
//{
//    int rc = OK;
//    int *data;
//    allocate_array(&data, 3);
//
//    rc = key(NULL, )
//}

Suite* get_check_in_file_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("get_check_in_file");


    tc_neg = tcase_create("negatives");

    //test_get_check_in_file_open_error
    tcase_add_test(tc_neg, test_get_check_in_file_open_error);
    tcase_add_test(tc_neg, test_get_check_in_file_empty);
    tcase_add_test(tc_neg, test_get_check_in_file_float);
    tcase_add_test(tc_neg, test_get_check_in_file_bad_content);
    tcase_add_test(tc_neg, test_get_check_in_file_no_numbers);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_get_check_in_file_correct);

    suite_add_tcase(s, tc_pos);
    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = get_check_in_file_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}