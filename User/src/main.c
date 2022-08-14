/*
 * @Author: 睦疏
 * @Date: 2022-08-11 19:10:00
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-13 18:21:06
 * @FilePath: \F4\User\src\main.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */

#include "main.h"
#include "misc.h"
#include "led.h"
#include "usart.h"
#include "stdio.h"
#include "delay.h"

short int USART_RX_STA = 0;
char USART_RX_BUF[100] = {0};

int main()
{
	SystemInit();
	unsigned char t, len;
  int  times = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置系统中断优先级分组 2
	uart_init(115200);								//串口初始化波特率为 115200
	Led_Init();										//初始化与 LED 连接的硬件接口

	while (1)
	{
		if (USART_RX_STA & 0x8000)
		{
			len = USART_RX_STA & 0x3fff; //得到此次接收到的数据长度
			printf("\r\n 您发送的消息为:\r\n");
			for (t = 0; t < len; t++)
			{
				USART1->DR = USART_RX_BUF[t];
				while ((USART1->SR & 0X40) == 0)
					; //等待发送结束
			}
			printf("\r\n\r\n"); //插入换行
			
			USART_RX_STA = 0;
		}
		else
		{
			times++;
			if (times % 5000 == 0)
			{
				printf("\r\nSTM32F405 开发板 串口实验\r\n");
			}
			if (times % 200 == 0)
			printf("请输入数据,以回车键结束\r\n");
			if (times % 30== 0)
			{
				GPIO_ResetBits(GPIOA, GPIO_Pin_6);
				delay_ms(1000);	
				

			

			}
		}
	}
}
