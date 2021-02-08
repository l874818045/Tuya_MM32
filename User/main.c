/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file            main
 * @company         成都逐飞科技有限公司
 * @author          逐飞科技(QQ790875685)
 * @version         查看doc内version文件 版本说明
 * @Software        MounRiver Studio V1.3
 * @Target core     CH32V103R8T6
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-12-04
 ********************************************************************************************************************/
//整套推荐IO查看Projecct文件夹下的TXT文本

//打开新的工程或者工程移动了位置务必执行以下操作
//右键单击工程，选择刷新

#include "headfile.h"
//使用在线调试可以修改duty可以修改占空比的值
extern uint8_t value;
float Tem_Value;
float RH_Value;
float lx;
int main(void)
{
    DisableGlobalIRQ();
    board_init();           //务必保留，本函数用于初始化MPU 时钟 调试串口

    //此处编写用户代码(例如：外设初始化代码等)
    gpio_init(A8, GPO, 1, GPIO_PIN_CONFIG);
    gpio_init(C9, GPO, 1, GPIO_PIN_CONFIG);
    oled_init();
    simiic_init(); //模拟IICIO口初始化
    adc_init(ADC_IN4_A4);
    wifi_protocol_init();
    //总中断最后开启
    uart_rx_irq(DEBUG_UART, ENABLE);
    nvic_init(USART1_IRQn, 2, 1, ENABLE);

    EnableGlobalIRQ();

    SHT3X_WriteCMD(0x88,0x2236);  //发送周期性读数据命令


    while(1)
    {
        SHT_GetValue(0x88);   //获取温湿度值
        mcu_dp_value_update(1,Tem_Value*10);
        mcu_dp_value_update(2,RH_Value);
        lx=(adc_convert(ADC_IN4_A4,ADC_8BIT)*3.3/256.0);
        mcu_dp_value_update(16,(20-(lx*10.0)));
        oled_p6x8str(25,0,"Temp=");
        oled_printf_float(55,0,Tem_Value,5,2);
        oled_p6x8str(25,3,"humi=");
        oled_printf_float(55,3,RH_Value,5,2);
        oled_p6x8str(25,6,"lux=");
        oled_printf_float(55,6,lx,5,2);
        systick_delay_ms(500);
        wifi_uart_service();

        wifi_state_get();
    }
}

//A6

