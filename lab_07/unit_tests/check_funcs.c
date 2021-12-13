#include <stdlib.h>
#include <check.h>
#include "../inc/funcs.h"

//check_args
START_TEST(test_check_args_wrong_args_number)
{
    int rc = OK;

    rc = check_args(5);

    ck_assert_int_eq(rc, ARGUMENT_ERROR);
}
END_TEST

START_TEST(test_check_args_correct)
{
    int rc = OK;

    rc = check_args(4);

    ck_assert_int_eq(rc, OK);
}

//get_check_in_file
START_TEST(test_get_check_in_file_open_error)
{
    int rc = OK;
    long file_len;

    get_check_in_file("non_exist", &file_len, &rc);

    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
}
END_TEST

START_TEST(test_get_check_in_file_empty)
{
    int rc = OK;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/empty_file.txt", &file_len, &rc);

    ck_assert_int_eq(rc, EMPTY_FILE_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_float)
{
    int rc = OK;
    long file_len;
    FILE *f =get_check_in_file("./unit_tests/test_files/get_file_check_float.txt", &file_len, &rc);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_bad_content)
{
    int rc = OK;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_bad_content.txt", &file_len, &rc);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_no_numbers)
{
    int rc = OK;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_no_numbers.txt", &file_len, &rc);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_get_check_in_file_correct)
{
    int rc = OK;
    long file_len;

    FILE *f = get_check_in_file("./unit_tests/test_files/get_file_check_correct.txt", &file_len, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(file_len, 3);
    fclose(f);
}
END_TEST

//todo allocate_array ?

//read_array

START_TEST(test_read_array_null_file_pointer)
{
    int rc;
    int *data;
    int *end_ptr;
    allocate_array(&data, 3);
    end_ptr = data + 3;

    rc = read_array(NULL, data, end_ptr);

    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
    free(data);
}
END_TEST

START_TEST(test_read_array_null_data_pointer)
{
    int rc;
    int *data;
    int *end_ptr;
    allocate_array(&data, 3);
    end_ptr = data + 3;
    FILE *f = fopen("./unit_tests/test_files/get_file_check_correct.txt", "r");

    rc = read_array(f, NULL, end_ptr);

    ck_assert_int_eq(rc, ALLOCATE_ERROR);

    fclose(f);
    free(data);
}
END_TEST

START_TEST(test_read_array_null_end_pointer)
{
    int rc;
    int *data;
    allocate_array(&data, 3);
    FILE *f = fopen("./unit_tests/test_files/get_file_check_correct.txt", "r");

    rc = read_array(f, data, NULL);

    ck_assert_int_eq(rc, ALLOCATE_ERROR);

    fclose(f);
    free(data);
}
END_TEST

START_TEST(test_read_array_bad_content)
{
    int rc;
    int *data;
    int *end_ptr;
    allocate_array(&data, 3);
    end_ptr = data + 3;
    FILE *f = fopen("./unit_tests/test_files/get_file_check_bad_content.txt", "r");

    rc = read_array(f, data, end_ptr);

    ck_assert_int_eq(rc, BAD_FILE_CONTENT_ERROR);

    fclose(f);
    free(data);
}
END_TEST

START_TEST(test_read_array_correct)
{
    int rc;
    int *data;
    int *end_ptr;
    allocate_array(&data, 3);
    end_ptr = data + 3;
    FILE *f = fopen("./unit_tests/test_files/get_file_check_correct.txt", "r");

    rc = read_array(f, data, end_ptr);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(*data, 1);
    ck_assert_int_eq(*(data + 1), -2);
    ck_assert_int_eq(*(data + 2), 3333);

    fclose(f);
    free(data);
}
END_TEST

//key   int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)

START_TEST(test_key_null_pointer_on_array_start)
{
    int rc = OK;
    int *data;
    allocate_array(&data, 3);
    const int *pe_src = data + 3;
    int *pb_dst, *pe_dst;

    rc = key(NULL, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, KEY_BAD_PARAMS);
}

START_TEST(test_key_null_pointer_on_array_end)
{
    int rc = OK;
    int *data;
    allocate_array(&data, 3);
    int *pb_dst, *pe_dst;

    rc = key(data, NULL, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, KEY_BAD_PARAMS);
}


START_TEST(test_key_new_arr_len_zero)
{
    int rc = OK;
    int *data;
    allocate_array(&data, 3);
    const int *pe_src = data + 3;
    int *pb_dst, *pe_dst;

    *data = -1;
    *(data + 1) = 20;
    *(data + 2) = 3;

    rc = key(data, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, EMPTY_NEW_ARR);
}

START_TEST(test_key_pointer_on_array_end)
{
    int rc = OK;
    int *data;
    allocate_array(&data, 3);
    const int *pe_src = data + 3;
    int *pb_dst, *pe_dst;

    *data = 1;
    *(data + 1) = 2;
    *(data + 2) = 3;

    rc = key(data, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_eq(pe_dst, pb_dst + 1);
    ck_assert_int_eq(*pb_dst, 2);
}

START_TEST(test_key_memory)
{
    int rc = OK;
    int *data;
    allocate_array(&data, 3);
    const int *pe_src = data + 3;
    int *pb_dst = NULL, *pe_dst = NULL;

    *data = 100;
    *(data + 1) = 20;
    *(data + 2) = -300;

    rc = key(data, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, OK);
    ck_assert_ptr_ne(pb_dst, NULL);
    ck_assert_ptr_ne(pe_dst, NULL);
}

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    //test_get_check_in_file_open_error
    tcase_add_test(tc_neg, test_key_null_pointer_on_array_start);
    tcase_add_test(tc_neg, test_key_null_pointer_on_array_end);
    tcase_add_test(tc_neg, test_key_new_arr_len_zero);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_pointer_on_array_end);
    tcase_add_test(tc_pos, test_key_memory);

    suite_add_tcase(s, tc_pos);
    return s;
}

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

Suite* test_check_args_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("check_args");


    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_check_args_wrong_args_number);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_check_args_correct);

    suite_add_tcase(s, tc_pos);
    return s;
}

Suite* test_read_array_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("read_array");


    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_read_array_null_file_pointer);
    tcase_add_test(tc_neg, test_read_array_bad_content);
    tcase_add_test(tc_neg, test_read_array_null_data_pointer);
    tcase_add_test(tc_neg, test_read_array_null_end_pointer);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_read_array_correct);

    suite_add_tcase(s, tc_pos);
    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    printf("\n\n");

    s = get_check_in_file_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n\n");

    s = test_check_args_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n\n");

    s = test_read_array_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n\n");

    s = key_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n\n");

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}