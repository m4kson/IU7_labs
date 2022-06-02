//#include "func_test.h"
//
//int main()
//{
//    int rc = 0;
//
//}
//
//int pos_1()
//{
//    int rc = OK;
//    int item_number = 0;
//
//
//
//    if (argc < 2)
//    {
//        rc = argument_error;
//    }
//
//    item arr[items_max_num];
//    FILE *f = fopen(argv[1], "r");
//
//
//    rc = read_items(f, arr, &item_number);
//    if (rc == OK)
//    {
//        if (argc == 3)
//        {
//            print_information(arr, argv[2], item_number);
//        } else print_information(arr, "None", item_number);
//    }
//
//    return rc;
//}