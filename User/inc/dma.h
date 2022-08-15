/*
 * @Author: 睦疏
 * @Date: 2022-08-14 15:14:06
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-15 20:27:00
 * @FilePath: \proj_8.14(2)\User\inc\dma.h
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#ifndef _DMA_H
#define _DMA_H
#define SEND_BUF_SIZE 19
#include "stm32f4xx_dma.h"

void MYDMA_Config(DMA_Stream_TypeDef *DMA_Streamx, unsigned int chx, unsigned int par, unsigned int mar, unsigned short ndtr);
void MYDMA_Enable(DMA_Stream_TypeDef *DMA_Streamx, unsigned short ndtr);
#endif