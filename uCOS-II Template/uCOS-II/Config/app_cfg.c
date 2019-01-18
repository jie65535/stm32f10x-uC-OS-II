#include "stm32f10x.h"
#include "os_cfg.h"

// 系统时钟启动
void OSTick_Init(void)
{
	RCC_ClocksTypeDef RCC_ClocksStructure;
	RCC_GetClocksFreq(&RCC_ClocksStructure);
	SysTick_Config(RCC_ClocksStructure.HCLK_Frequency / OS_TICKS_PER_SEC );
}
