#ifndef __ULTRASONIC_H
#define	__ULTRASONIC_H
#include "stm32f10x.h"
#include "adcx.h"
#include "delay.h"
#include "math.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	HC-SR04������������h�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.27
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/


/***************�����Լ��������****************/
// ULTRASONIC GPIO�궨��

#define		ULTRASONIC_GPIO_CLK								RCC_APB2Periph_GPIOA
#define 	ULTRASONIC_GPIO_PORT							GPIOA
#define 	ULTRASONIC_TRIG_GPIO_PIN					GPIO_Pin_0	
#define 	ULTRASONIC_ECHO_GPIO_PIN					GPIO_Pin_1	

#define 	TRIG_Send  PAout(0)
#define 	ECHO_Reci  PAin(1)

/*********************END**********************/

void Ultrasonic_Init(void);
float UltrasonicGetLength(void);

void OpenTimerForHc(void);
void CloseTimerForHc(void); 
u32 GetEchoTimer(void);

#endif /* __ADC_H */

