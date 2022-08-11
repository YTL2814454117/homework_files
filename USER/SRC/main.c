#include "main.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "tim3.h"
#include "stm32f4xx_gpio.h"

int main(void)
{
	SystemInit();									// 系统初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置系统中断优先级分组 2
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // GPIOA enable
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	 // GPIO Output Mode
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	 // push-pull momde
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; // low speed
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	 // not up or down
	GPIO_Init(GPIOA, &GPIO_InitStructure);			 // configuration of GPIOA
	GPIO_SetBits(GPIOA, GPIO_Pin_4);

	TIM3_Int_Init(5000 - 1, 8400 - 1); //定时器时钟84M，分频系数8400，所以84M/8400=10Khz

	//的计数频率，计数 5000 次为 500ms
	while (1)
	{
		TIM3_IRQHandler();
	}
	return 0;
}
/**
 * @brief  起始任务
 */
static void TaskStart(void *pdata)
{
	pdata = pdata;
	OS_CPU_SysTickInit();

	for (;;)
	{
		OSTimeDly(10000);
	}
}
