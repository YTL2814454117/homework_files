/*
 * @Author: ����
 * @Date: 2022-08-15 20:09:42
 * @LastEditors: ����
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
//��׼����Ҫ��֧�ֺ���
struct __FILE
{
    int handle;
};
FILE __stdout;
//����_sys_exit()�Ա���ʹ�ð�����ģʽ
void _sys_exit(int x)
{
    x = x;
}
//�ض��� fputc ����
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
    NVIC_InitTypeDef NVIC_InitStructure;                        // �����жϳ�ʼ����
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);        // ʹ��TIM3ʱ��
    TIM_TimeBaseStructure.TIM_Period = 10000;                    // �����Զ����ؼ�������ֵ
    TIM_TimeBaseStructure.TIM_Prescaler = 7199;                 // ���÷�Ƶϵ��
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // ����ʱ�ӷ�Ƶ����
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ���ü���ģʽ
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             // ʵ��ʱ�ӳ�ʼ��
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);                  // ʹ��TIM3�ĸ����ж�
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);             // �����ж����ȼ�����

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;           // ��ʱ��3�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; // ��ռ���ȼ�Ϊ 1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        // ��Ӧ���ȼ�λ 2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ ͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);                           //��������ָ���Ĳ�����ʼ�� NVIC �Ĵ���
    TIM_Cmd(TIM3, ENABLE);                                    //ʹ�� TIMx ����
}

void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET) //����ж�
  {
    printf("\r\n\r\n");
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE); //ʹ�ܴ��� 1 �� DMA ����
    MYDMA_Enable(DMA2_Stream7, SEND_BUF_SIZE);     //��ʼһ�� DMA ���䣡
    printf("��%d��", ++n);
    while (1)
    {
        if (DMA_GetFlagStatus(DMA2_Stream7, DMA_FLAG_TCIF7) != RESET)
        //�ȴ� DMA2_Steam7 �������
        {
            DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_TCIF7); //�崫����ɱ�־
            break;
        }
    } 
	  TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //����жϱ�־λ
  }
}