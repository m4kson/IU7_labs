Tests


Negatives

1 неверное кол-во аргументов                                            ARGUMENT_ERROR 1                    done
2 файл не существует                                                    FILE_OPEN_ERROR 2                   done
3 файл пуст                                                             EMPTY_FILE_ERROR 3                  done
4 превышена длина имени продукта                                        PRODUCT_NAME_TOO_LONG_ERROR 7       done
5 превышено кол-во структур                                             TOO_MANY_STRUCTS_ERROR 4            done     
6 слишком длинное имя файла                                             FILE_NAME_TOO_LONG_ERROR 5          done
7 некорректное содержимое файла (кол-во строк не кратно 2)              INCORRECT_FILE_CONTENT 9            
8 строка с именем продукта состоит из пробелов
9 строка с именем продукта пустая                                       EMPTY_PRODUCT_NAME_ERROR 6          done
10 нет подходящих продуктов (ошибка или сообщение?)
11 цена меньше или равна 0                                              INCORRECT_PRICE_ERROR 8             done
12 некорректное число структур (records_no не целочисленное)
13 некорректная цена

Positives

pos.txt                                                                                                     done