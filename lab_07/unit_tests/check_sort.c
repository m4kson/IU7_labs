#include <check.h>
#include "../inc/sort.h"
#include <stdlib.h>


//comp_num

START_TEST(comp_num_simple_check_1)
{
    int num_1 = 1;
    int num_2 = 2;
    int rc;

    rc = comp_num(&num_1, &num_2);

    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(comp_num_simple_check_2)
{
    int num_1 = 2;
    int num_2 = 2;
    int rc;

    rc = comp_num(&num_1, &num_2);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(comp_num_simple_check_3)
{
    int num_1 = 2;
    int num_2 = 1;
    int rc;

    rc = comp_num(&num_1, &num_2);

    ck_assert_int_eq(rc, -1);
}
END_TEST

// mysort

START_TEST(my_sort_small_arr)
{
    int arr[10] = {3, -1, 2, 23, 0, -123, 22, 0, 22, -1000};
    int correct[10] = {-1000, -123, -1, 0, 0, 2, 3, 22, 22, 23};

    mysort(arr, 10, sizeof(int), (int (*)(const void*, const void*))(comp_num));

    for (int i = 0; i < 10; i++)
        ck_assert(arr[i] == correct[i]);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, my_sort_small_arr);

    suite_add_tcase(s, tc_pos);
    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    printf("\n\n");


    s = mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n\n");

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}