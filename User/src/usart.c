/*
 * @Author: 睦疏
 * @Date: 2022-08-14 15:40:17
 * @LastEditors: 睦疏
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

void uart_init(unsigned int bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);      //使能 GPIOA 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);     //使能 USART1 时钟
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // PA9 复用为 USART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // PA10复用为USART1

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; // GPIOA9 与 GPIOA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;            //复用功能
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       //速度 50MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //推挽复用输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //上拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);                  //初始化 PA9，PA10

    USART_InitStructure.USART_BaudRate = bound;                 //一般设置为 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //字长为 8 位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;      //一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;         //无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //收发模式
    USART_Init(USART1, &USART_InitStructure);                       //初始化串口

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //开启中断
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //抢占优先级 2
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级 2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ 通道使能
    NVIC_Init(&NVIC_InitStructure);                           //根据指定的参数初始化 VIC 寄存器
    USART_Cmd(USART1, ENABLE);                                //使能串口
}

void USART1_IRQHandler(void) //串口 1 中断服务程序
{
	
		delay_ms(1000);
}
