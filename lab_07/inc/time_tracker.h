#ifndef LAB_07_1_1_TIME_TRACKER_H
#define LAB_07_1_1_TIME_TRACKER_H

#include "sort.h"
#include <inttypes.h>
#include <sys/time.h>
#include "stdlib.h"


int64_t check_time(void *p_start, size_t count, size_t size,  void (*sort)(void *p_start, size_t count, size_t size, int (*comp)(const void *, const void *)));

#endif //LAB_07_1_1_TIME_TRACKER_H
