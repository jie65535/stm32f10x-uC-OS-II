该模板以stm32f103zet6为基础，移植uC/OS-II为内核

使用模板者仅需要关心以下目录：

App  应用程序目录
用于存放应用程序模块的目录，例如串口通讯、ADC函数等，供任务使用

Project 工程目录，内包含main.c
用于工程文件存放目录，同时包含main.c

uCOS-II_Task  任务目录
用于存放所有任务文件
内涵启动任务，其它任务统一从启动任务中启动，启动任务由main函数启动

uCOS-II\Config  uCOS配置目录
用于配置uC/OS-II各项参数

STM32F10x\CONFIG  中断函数目录
用于编写硬件中断函数

Doc 文档目录
用于存放程序文档、说明、Readme等

Object 为输出对象目录
编译过程中产生的中间文件或目标文件都在该目录下




模板说明：

通过main函数初始化uC/OS-II与板子，然后创建TaskStart任务

TaskStart将启动时钟，且初始化并创建其他任务，然后删除启动任务

程序正式启动





创建任务过程：
1.在uCOS-II_Task目录中新建该任务的文件(xxx_task.c  xxx_task.h)
2.在task.h中添加#include "xxx_task.h"
3.在xxx_task.c中编写任务函数TaskXxx（注意，任务的命名规范以Task开始，使用大驼峰命名法）
4.在xxx_task.h中添加相应的函数声明与全局变量引用、宏等
5.在start_task.c中的TaskStart函数内启动TaskXxx任务
完成任务的创建
