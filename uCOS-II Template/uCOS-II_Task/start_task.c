#include "task.h"
#include "includes.h"
#include <stdio.h>

// 起始任务堆栈
OS_STK TASK_START_STK[TASK_START_STK_SIZE];

// 启动任务，用于初始化并启动其它任务
void TaskStart(void *p_arg)
{
	OS_CPU_SR cpu_sr = 0;
	
	// 开始时钟
	OSTick_Init();
	
	// 进入临界区创建任务
	OS_ENTER_CRITICAL();
	
	// 在这里创建其它任务...
	OSTaskCreate(TaskTest, (void *)0, &TASK_TEST_STK[TASK_TEST_STK_SIZE - 1], TASK_TEST_PRIO);
	
	
	// 退出临界区
	OS_EXIT_CRITICAL();
	
	// 启动任务完成，删除启动任务
	OSTaskDel(TASK_START_PRIO);
}
