#include "includes.h"
#include "task.h"
#include "SerialPort.h"

// 板子初始化
void BSP_Initializes(void)
{
	// 以9600波特率初始化串口
	SerialPortInit(9600);
}

int main(void)
{
	// uC/OS-II 初始化
	OSInit();
	// 初始化板子
	BSP_Initializes();
	// 创建启动任务
	OSTaskCreate(TaskStart, (void *)0, &TASK_START_STK[TASK_START_STK_SIZE - 1], TASK_START_PRIO);
	// uC/OS-II 启动
	OSStart();
}
