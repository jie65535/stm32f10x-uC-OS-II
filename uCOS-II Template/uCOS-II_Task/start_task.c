#include "task.h"
#include "includes.h"
#include <stdio.h>

// ��ʼ�����ջ
OS_STK TASK_START_STK[TASK_START_STK_SIZE];

// �����������ڳ�ʼ����������������
void TaskStart(void *p_arg)
{
	OS_CPU_SR cpu_sr = 0;
	
	// ��ʼʱ��
	OSTick_Init();
	
	// �����ٽ�����������
	OS_ENTER_CRITICAL();
	
	// �����ﴴ����������...
	OSTaskCreate(TaskTest, (void *)0, &TASK_TEST_STK[TASK_TEST_STK_SIZE - 1], TASK_TEST_PRIO);
	
	
	// �˳��ٽ���
	OS_EXIT_CRITICAL();
	
	// ����������ɣ�ɾ����������
	OSTaskDel(TASK_START_PRIO);
}
