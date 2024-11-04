#ifndef __HX711_H
#define	__HX711_H
#include "stm32f10x.h"
#include "delay.h"
#include "math.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	HX711���ӳ�ģ��h�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.9.11
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/

/***************�����Լ��������****************/
// HX711 GPIO�궨��
#define		HX711_GPIO_CLK									RCC_APB2Periph_GPIOA
#define 	HX711_SCK_GPIO_PORT							GPIOA
#define 	HX711_SCK_GPIO_PIN							GPIO_Pin_0
#define 	HX711_DT_GPIO_PORT							GPIOA
#define 	HX711_DT_GPIO_PIN								GPIO_Pin_1
/*********************END**********************/

#define HX711_SCK_H				GPIO_SetBits(HX711_SCK_GPIO_PORT,HX711_SCK_GPIO_PIN);
#define HX711_SCK_L				GPIO_ResetBits(HX711_SCK_GPIO_PORT,HX711_SCK_GPIO_PIN);

#define HX711_DT					GPIO_ReadInputDataBit(HX711_DT_GPIO_PORT, HX711_DT_GPIO_PIN)



void HX711_Init(void);
unsigned long HX711_GetData(void);

#endif /* __ADC_H */

