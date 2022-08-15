/*
 * @Author: 睦疏
 * @Date: 2022-08-15 20:09:42
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-15 20:30:40
 * @FilePath: \proj_8.14(2)\User\src\tim3.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "tim3.h"
#include "stm32f4xx_tim.h"
#include "led.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"
#include "dma.h"
#include "stdio.h"
#include "stm32f4xx_usart.h"

#if 1
#pragma import(__use_no_semihosting)
//标准库需要的支持函数
struct __FILE
{
    int handle;
};
FILE __stdout;
//定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x)
{
    x = x;
}
//重定义 fputc 函数
int fputc(int ch, FILE *f)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
        ;
    USART_SendData(USART1, (uint8_t)ch);
    return ch;
}
#endif

int n = 0;

void TIM3_Int_Init(unsigned short arr, unsigned short psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;              //
    NVIC_InitTypeDef NVIC_InitStructure;                        // 定义中断初始化类
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);        // 使能TIM3时钟
    TIM_TimeBaseStructure.TIM_Period = 10000;                    // 设置自动重载计数周期值
    TIM_TimeBaseStructure.TIM_Prescaler = 7199;                 // 设置分频系数
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // 设置时钟分频因子
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 设置计数模式
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             // 实现时钟初始化
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);                  // 使能TIM3的更新中断
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);             // 设置中断优先级分组

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
    printf("\r\n\r\n");
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE); //使能串口 1 的 DMA 发送
    MYDMA_Enable(DMA2_Stream7, SEND_BUF_SIZE);     //开始一次 DMA 传输！
    printf("第%d次", ++n);
    while (1)
    {
        if (DMA_GetFlagStatus(DMA2_Stream7, DMA_FLAG_TCIF7) != RESET)
        //等待 DMA2_Steam7 传输完成
        {
            DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_TCIF7); //清传输完成标志
            break;
        }
    } 
	  TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除中断标志位
  }
}