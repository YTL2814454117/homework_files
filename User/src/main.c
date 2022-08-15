/*
 * @Author: 睦疏
 * @Date: 2022-08-14 08:01:01
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-15 20:29:18
 * @FilePath: \proj_8.14(2)\User\src\main.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "main.h"
#include <stdio.h>
#include <string.h>
#include "misc.h"
#include "led.h"
#include "delay.h"
#include "dma.h"
#include "tim3.h"
#include "usart.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"

unsigned char SendBuff[SEND_BUF_SIZE]; //发送数据缓冲区
const unsigned char TEXT_TO_SEND[] = {"whu whu whu whu whu"};

int main()
{
	SystemInit();
	unsigned short i;
	unsigned char t = 0, j, mask = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置系统中断优先级分组 2d
	uart_init(115200);
	Led_Init();
	MYDMA_Config(DMA2_Stream7, DMA_Channel_4, (u32)&USART1->DR, (u32)SendBuff, SEND_BUF_SIZE);
	TIM3_Int_Init(10000 - 1, 8400 - 1);
	

	j = sizeof(TEXT_TO_SEND);
	for (i = 0; i < SEND_BUF_SIZE; i++) //填充 ASCII 字符集数据
	{
		if (t >= j) //加入换行符
		{
			if (mask)
			{
				SendBuff[i] = 0x0a;
				t = 0;
			}
			else
			{
				SendBuff[i] = 0x0d;
				mask++;
			}
		}
		else //复制 TEXT_TO_SEND 语句
		{
			mask = 0;
			SendBuff[i] = TEXT_TO_SEND[t];
			t++;
		}
	}
	while (1)
	{
	}
}
