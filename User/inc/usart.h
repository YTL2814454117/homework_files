/*
 * @Author: 睦疏
 * @Date: 2022-08-14 15:40:28
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-14 16:33:02
 * @FilePath: \proj_8.14\User\inc\usart.h
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#ifndef _USAT_H
#define _USART_H
void uart_init(unsigned int bound);
void USART1_IRQHandler(void); //串口 1 中断服务程序

#endif