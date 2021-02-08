/*
 * iic.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Administrator
 */

#ifndef LIBRARIES_CODE_IIC_H_
#define LIBRARIES_CODE_IIC_H_



#endif /* LIBRARIES_CODE_IIC_H_ */

void IIC_Start(void);
void IIC_Stop(void);
void IIC_Ack(void);
void IIC_NAck(void);
u8 IIC_Wait_Ack(void);



void IIC_Send_Byte(u8 txd);
u8 IIC_Read_Byte(unsigned char ack);
void SHT_Init(void);
void sht30_read_temp_humi(u8 *p);
