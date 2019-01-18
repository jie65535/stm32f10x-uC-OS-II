#ifndef TEST_TASK_H_
#define TEST_TASK_H_

#include "includes.h"

#define TASK_TEST_PRIO		5u

#define TASK_TEST_STK_SIZE 		512u

extern OS_STK TASK_TEST_STK[TASK_TEST_STK_SIZE];

extern OS_EVENT *pMailBox;

void TaskTest(void *p_arg);

#endif
