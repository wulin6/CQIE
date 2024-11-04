#include "bump.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	5Vˮ��ģ��c�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.9.22
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/


void BUMP_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(BUMP_CLK, ENABLE ); //����ʱ��
	
	GPIO_InitStructure.GPIO_Pin = BUMP_GPIO_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(BUMP_GPIO_PROT,&GPIO_InitStructure);

	BUMP_OFF;
}

