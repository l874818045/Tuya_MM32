/*
 * motor.c
 *
 *  Created on: Feb 1, 2021
 *      Author: Administrator
 */


#include "headfile.h"

uint16 duty = 10000;

/*电机正转*/
void  motor_flag1(void)
{

    pwm_duty(    PWM3_CH1_A6, 3000);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH2_A7, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH3_B0, 3000);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH4_B1, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100*/

}
/*电机反转*/
void  motor_flag2(void)
{

    pwm_duty(    PWM3_CH1_A6, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH2_A7, 5000);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH3_B0, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH4_B1, 5000);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100*/

}

/*电机停止*/
void  motor_flag3(void)
{

    pwm_duty(    PWM3_CH1_A6, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH2_A7, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH3_B0, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100
    pwm_duty(    PWM3_CH4_B1, 0);  //改变A15输出PWM的占空比为百分之 duty/PWM_DUTY_MAX*100*/

}
