#ifndef _zf_board_h
#define _zf_board_h

#include "common.h"
#include "stdio.h"
#include "ch32v10x.h"
#include "zf_uart.h"


#define PRINTF_ENABLE           1                   //printf使能

#define DEBUG_UART              UART_1              //DEBUG串口
#define DEBUG_UART_BAUD         115200              //DEBUG串口波特率
#define DEBUG_UART_TX_PIN       UART1_TX_A9         //DEBUG串口TX引脚
#define DEBUG_UART_RX_PIN       UART1_RX_A10        //DEBUG串口RX引脚

void board_init(void);



//关闭所有中断标志位
extern uint8 close_all_irq_flag ;
//摄像头类型
extern uint8 camera_type ;
//内核频率
extern uint32 sys_clk  ;
//中断状态
extern uint32 irq_status[2];

#endif
