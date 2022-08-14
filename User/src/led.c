/*
 * @Author: 睦疏
 * @Date: 2022-08-13 10:37:00
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-13 16:14:53
 * @FilePath: \工程模板F4\User\src\led.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "led.h"
#include "stm32f4xx_gpio.h"

void Led_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // GPIOA enable

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;    // GPIO Output Mode
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;   // push-pull momde
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; // low speed
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    ;                                      // not up or down
    GPIO_Init(GPIOA, &GPIO_InitStructure); // configuration of GPIOA
}