#ifndef START_TASK_H_
#define START_TASK_H_

#include "includes.h"

#define TASK_START_PRIO		0u

#define TASK_START_STK_SIZE 		512u

extern OS_STK TASK_START_STK[TASK_START_STK_SIZE];

void TaskStart(void *p_arg);

#endif
