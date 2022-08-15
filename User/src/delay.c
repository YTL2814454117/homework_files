/*
 * @Author: 睦疏
 * @Date: 2022-08-14 16:25:52
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-14 16:26:53
 * @FilePath: \proj_8.14\User\src\delay.c
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