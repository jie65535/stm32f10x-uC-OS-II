#include "task.h"
#include "includes.h"
#include <stdio.h>

// ���������ջ
OS_STK TASK_TEST_STK[TASK_TEST_STK_SIZE];

// ����
OS_EVENT *pMailBox = 0;

// ��������
void TaskTest(void *p_arg)
{
	OS_CPU_SR cpu_sr = 0;
	INT8U err;
	const char *pstr;
	// ����һ���յ�����
	pMailBox = OSMboxCreate((void*)0);
	
	for (;;)
	{
		// �����޵ȴ����䣬����ȡ����messageͨ�����ڽ������
		// �ڴ˴������е�������stm32f10x_it.c�еĴ��ڽ����ж��ṩ
		// ����Ϊ���ַ�'\0'��β���ַ���
		pstr = (const char *)OSMboxPend(pMailBox, 0, &err);
		
		OS_ENTER_CRITICAL();
		puts(pstr);
		OS_EXIT_CRITICAL();
	}
}
