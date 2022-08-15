/*
 * @Author: ����
 * @Date: 2022-08-14 15:40:17
 * @LastEditors: ����
 * @LastEditTime: 2022-08-14 16:22:06
 * @FilePath: \proj_8.14\User\src\usart.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include "stm32f4xx.h"
#include "stdio.h"
#include "stm32f4xx_rcc.h"
#include "delay.h"




void uart_init(unsigned int bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);      //ʹ�� GPIOA ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);     //ʹ�� USART1 ʱ��
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // PA9 ����Ϊ USART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // PA10����ΪUSART1

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; // GPIOA9 �� GPIOA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;            //���ù���
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       //�ٶ� 50MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //���츴�����
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //����
    GPIO_Init(GPIOA, &GPIO_InitStructure);                  //��ʼ�� PA9��PA10

    USART_InitStructure.USART_BaudRate = bound;                 //һ������Ϊ 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //�ֳ�Ϊ 8 λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;      //һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;         //����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //�շ�ģʽ
    USART_Init(USART1, &USART_InitStructure);                       //��ʼ������

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //�����ж�
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ� 2
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //��Ӧ���ȼ� 2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ ͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);                           //����ָ���Ĳ�����ʼ�� VIC �Ĵ���
    USART_Cmd(USART1, ENABLE);                                //ʹ�ܴ���
}

