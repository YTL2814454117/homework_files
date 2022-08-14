/*
 * @Author: 睦疏
 * @Date: 2022-08-13 18:18:34
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-13 18:20:40
 * @FilePath: \F4\User\src\delay.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "delay.h"
void delay_ms(unsigned int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        int a = 42000;
        while (a--)
            ;
    }
}