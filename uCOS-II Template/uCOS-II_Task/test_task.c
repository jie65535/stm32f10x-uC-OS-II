#include "task.h"
#include "includes.h"
#include <stdio.h>

// 测试任务堆栈
OS_STK TASK_TEST_STK[TASK_TEST_STK_SIZE];

// 邮箱
OS_EVENT *pMailBox = 0;

// 测试任务
void TaskTest(void *p_arg)
{
	OS_CPU_SR cpu_sr = 0;
	INT8U err;
	const char *pstr;
	// 创建一个空的邮箱
	pMailBox = OSMboxCreate((void*)0);
	
	for (;;)
	{
		// 无期限等待邮箱，将获取到的message通过串口进行输出
		// 在此处邮箱中的数据由stm32f10x_it.c中的串口接收中断提供
		// 数据为以字符'\0'结尾的字符串
		pstr = (const char *)OSMboxPend(pMailBox, 0, &err);
		
		OS_ENTER_CRITICAL();
		puts(pstr);
		OS_EXIT_CRITICAL();
	}
}
