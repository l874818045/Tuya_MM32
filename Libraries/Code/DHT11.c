/*
 * Device.c
 *
 *  Created on: Jan 23, 2021
 *      Author: Administrator
 */
#include "headfile.h"

u8   buffer[6];
float Tem_Value;
float RH_Value;

//参数一 SHT30地址
//参数二 命令

void SHT3X_WriteCMD( u8 add ,u16 cmd)
{
  IIC_Start();
  IIC_Send_Byte(add);
  IIC_Wait_Ack();
  IIC_Send_Byte(cmd>>8);
  IIC_Wait_Ack();
  IIC_Send_Byte(cmd);
  IIC_Wait_Ack();
  IIC_Stop();
}




//参数一 SHT30地址
//参数二 命令
//参数三 数组，存放从SHT30读取的字节
void SHX3X_ReadResults(u8 add,u16 cmd,  u8 *p)
{
  IIC_Start();
  IIC_Send_Byte(add);      //0x8a,0x88
  IIC_Wait_Ack();
  IIC_Send_Byte(cmd>>8);
  IIC_Wait_Ack();
  IIC_Send_Byte(cmd);
  IIC_Wait_Ack();

  IIC_Start();
  IIC_Send_Byte(add+1);
  IIC_Wait_Ack();

  p[0]=IIC_Read_Byte(1);
  p[1]=IIC_Read_Byte(1);
  p[2]=IIC_Read_Byte(1);
  p[3]=IIC_Read_Byte(1);
  p[4]=IIC_Read_Byte(1);
  p[5]=IIC_Read_Byte(0);

  IIC_Stop();

}

//参数 从SHT30读取的表示温度值的16位数据
float SHT3X_CalcTemperature(uint16_t rawValue)
{
  float temp;
  temp=(175 * (float)rawValue / 65535 - 45) ; // T = -45 + 175 * rawValue / (2^16-1)
   return temp;
}


//参数 从SHT30读取的表示湿度值的16位数据
float SHT3X_CalcRH(uint16_t rawValue)
{
   // calculate relative humidity [%RH]
   float temp1 = (100 * (float)rawValue / 65535) ;  // RH = rawValue / (2^16-1) * 10
   return temp1;
}

//参数 SHT30地址
void SHT_GetValue(u8 add)
{
    u8 temp = 0;
    u16 dat;
    u8 p[3];

   SHX3X_ReadResults(add ,0xE000, buffer);
    p[0] = buffer[0];
    p[1] = buffer[1];
    p[2] = buffer[2];

  if(!temp)
  {
    dat = ((u16)buffer[0] << 8) | buffer[1];
    Tem_Value = SHT3X_CalcTemperature( dat );
  }
    p[0] = buffer[3];
    p[1] = buffer[4];
    p[2] = buffer[5];

  if(!temp)
  {
    dat = ((u16)p[0] << 8) | p[1];
    RH_Value = SHT3X_CalcRH( dat );
  }
}





void DHT11_TEST()
{


    SHT3X_WriteCMD(0x88,0x2236);  //发送周期性读数据命令
    systick_delay_ms(100);
    SHT_GetValue(0x88);   //获取温湿度值

    printf(" Input:%x\r\n",Tem_Value);
   // oled_printf_float(0,0,Tem_Value,3,2);

    //oled_printf_float(0,3,RH_Value,3,2);

    //0printf(" Input:%x\r\n",data_process.SHT30_temperature);
}
