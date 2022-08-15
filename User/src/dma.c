/*
 * @Author: 睦疏
 * @Date: 2022-08-14 15:13:57
 * @LastEditors: 睦疏
 * @LastEditTime: 2022-08-14 15:26:51
 * @FilePath: \proj_8.14\User\src\dma.c
 * @Description:
 *
 * Copyright (c) 2022 by YTL2814454117 2814454117@qq.com, All Rights Reserved.
 */
#include "dma.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"

void MYDMA_Config(DMA_Stream_TypeDef *DMA_Streamx, unsigned int chx, unsigned int par, unsigned int mar, unsigned short ndtr)
{
    DMA_InitTypeDef DMA_InitStructure;
    if ((unsigned int)DMA_Streamx > (unsigned int)DMA2) //得到当前 stream 是属于 DMA2 还是 DMA1
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE); // DMA2 时钟使能
    }
    else
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE); // DMA1 时钟使能
    }
    DMA_DeInit(DMA_Streamx);
    while (DMA_GetCmdStatus(DMA_Streamx) != DISABLE)
    {
    } //等待 DMA 可配置
    /* 配置 DMA Stream */
    DMA_InitStructure.DMA_Channel = chx;                    //通道选择
    DMA_InitStructure.DMA_PeripheralBaseAddr = par;         // DMA 外设地址
    DMA_InitStructure.DMA_Memory0BaseAddr = mar;            // DMA 存储器 0 地址
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral; //存储器到外设模式
    DMA_InitStructure.DMA_BufferSize = ndtr;                //数据传输量
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    //外设非增量模式
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //存储器增量模式
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    //外设数据长度:8 位
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    //存储器数据长度:8 位
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                 // 使用普通模式
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;         //中等优先级
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;        // FIFO 模式禁止
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full; // FIFO 阈值
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    //存储器突发单次传输
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    //外设突发单次传输
    DMA_Init(DMA_Streamx, &DMA_InitStructure); //初始化 DMA Stream
}

void MYDMA_Enable(DMA_Stream_TypeDef *DMA_Streamx, unsigned short ndtr)
{
    DMA_Cmd(DMA_Streamx, DISABLE); //关闭 DMA 传输
    while (DMA_GetCmdStatus(DMA_Streamx) != DISABLE)
    {
    }                                          //确保 DMA 可以被设置
    DMA_SetCurrDataCounter(DMA_Streamx, ndtr); //数据传输量
    DMA_Cmd(DMA_Streamx, ENABLE);              //开启 DMA 传输
}