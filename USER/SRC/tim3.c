#include "tim3.h"
#include "led.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void TIM3_Int_Init(unsigned short arr, unsigned short psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;              //
    NVIC_InitTypeDef NVIC_InitStructure;                        // 定义中断初始化类
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);        // 使能TIM3时钟
    TIM_TimeBaseStructure.TIM_Period = 5000;                    // 设置自动重载计数周期值
    TIM_TimeBaseStructure.TIM_Prescaler = 7199;                 // 设置分频系数
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // 设置时钟分频因子
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 设置计数模式
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             // 实现时钟初始化
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);                  // 使能TIM3的更新中断
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);             // 设置中断优先级分组

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;           // 计时器3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; // 抢占优先级为 1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        // 响应优先级位 2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ 通道使能
    NVIC_Init(&NVIC_InitStructure);                           //根据上面指定的参数初始化 NVIC 寄存器
    TIM_Cmd(TIM3, ENABLE);                                    //使能 TIMx 外设
}

void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET) //溢出中断
    {
        LED1 = !LED1;
    }
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除中断标志位
}