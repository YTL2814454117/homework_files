/*
 * @Author: ����
 * @Date: 2022-08-14 08:01:01
 * @LastEditors: ����
 * @LastEditTime: 2022-08-15 14:49:51
 * @FilePath: \proj_8.14\User\src\main.c
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
#include "usart.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"

#define SEND_BUF_SIZE 2100
unsigned char SendBuff[SEND_BUF_SIZE]; //�������ݻ�����
	int n = 0;
const unsigned char TEXT_TO_SEND[] = {"whu whu whu whu whu"};

int main()
{
	SystemInit();
	unsigned short i;
	unsigned char t = 0, j, mask = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����ϵͳ�ж����ȼ����� 2d
	uart_init(115200);
	Led_Init();
	MYDMA_Config(DMA2_Stream7, DMA_Channel_4, (u32)&USART1->DR, (u32)SendBuff, SEND_BUF_SIZE);

	j = sizeof(TEXT_TO_SEND);
	for (i = 0; i < SEND_BUF_SIZE; i++) //��� ASCII �ַ�������
	{
		if (t >= j) //���뻻�з�
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
		else //���� TEXT_TO_SEND ���
		{
			mask = 0;
			SendBuff[i] = TEXT_TO_SEND[t];
			t++;
		}
	}
	while (1)
	{
	
		printf("\r\nDMA DATA:\r\n");
		USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE); //ʹ�ܴ��� 1 �� DMA ����
		MYDMA_Enable(DMA2_Stream7, SEND_BUF_SIZE);	   //��ʼһ�� DMA ���䣡
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
		i++;
		delay_ms(10);
		if (i == 20)
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_6);
			i = 0;
		}
	}
}

