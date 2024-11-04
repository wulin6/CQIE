#ifndef __BUMP_H
#define	__BUMP_H
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	5Vˮ��ģ��h�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.9.22
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/


/***************�����Լ��������****************/
// ˮ��ģ�� GPIO�궨��

#define	BUMP_CLK							RCC_APB2Periph_GPIOA

#define BUMP_GPIO_PIN 				GPIO_Pin_0

#define BUMP_GPIO_PROT 				GPIOA

#define BUMP_ON 		GPIO_SetBits(BUMP_GPIO_PROT,BUMP_GPIO_PIN)
#define BUMP_OFF 	GPIO_ResetBits(BUMP_GPIO_PROT,BUMP_GPIO_PIN)

/*********************END**********************/

void BUMP_Init(void);

#endif



