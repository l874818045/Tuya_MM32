/*
 * Device.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Administrator
 */

void SHT_Init(void);
void DHT11_TEST();
void SHT3X_WriteCMD( u8 add ,u16 cmd);
void SHT_GetValue(u8 add);

