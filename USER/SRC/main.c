#include "main.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "tim3.h"
#include "stm32f4xx_gpio.h"

int main(void)
{
	SystemInit();									// ϵͳ��ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����ϵͳ�ж����ȼ����� 2
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // GPIOA enable
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	 // GPIO Output Mode
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;	 // push-pull momde
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; // low speed
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	 // not up or down
	GPIO_Init(GPIOA, &GPIO_InitStructure);			 // configuration of GPIOA
	GPIO_SetBits(GPIOA, GPIO_Pin_4);

	TIM3_Int_Init(5000 - 1, 8400 - 1); //��ʱ��ʱ��84M����Ƶϵ��8400������84M/8400=10Khz

	//�ļ���Ƶ�ʣ����� 5000 ��Ϊ 500ms
	while (1)
	{
		TIM3_IRQHandler();
	}
	return 0;
}
/**
 * @brief  ��ʼ����
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
