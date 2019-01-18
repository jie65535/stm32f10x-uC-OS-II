#include "includes.h"
#include "task.h"
#include "SerialPort.h"

// ���ӳ�ʼ��
void BSP_Initializes(void)
{
	// ��9600�����ʳ�ʼ������
	SerialPortInit(9600);
}

int main(void)
{
	// uC/OS-II ��ʼ��
	OSInit();
	// ��ʼ������
	BSP_Initializes();
	// ������������
	OSTaskCreate(TaskStart, (void *)0, &TASK_START_STK[TASK_START_STK_SIZE - 1], TASK_START_PRIO);
	// uC/OS-II ����
	OSStart();
}
