#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "ultrasonic.h"
#include "timer.h"

/*****************���絥Ƭ�����******************
											STM32
 * ��Ŀ			:	HC-SR04������������ʵ��                     
 * �汾			: V1.0
 * ����			: 2024.8.27
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	�ο�ultrasonic.h							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/

float distance;

int main(void)
{ 
	
  SystemInit();//����ϵͳʱ��Ϊ72M	
	delay_init(72);
	LED_Init();
	LED_On();
	Ultrasonic_Init();
	USART1_Config();//���ڳ�ʼ��
	
	OLED_Init();
	printf("Start \n");
	delay_ms(1000);
	
	OLED_Clear();
	//��ʾ������:��
	OLED_ShowChinese(0,0,0,16,1);
	OLED_ShowChinese(16,0,1,16,1);
	OLED_ShowChar(32,0,':',16,1);
	OLED_ShowString(60,20,"cm",16,1);

  while (1)
  {
		LED_Toggle();
		distance = UltrasonicGetLength();
		OLED_ShowNum(40,20,distance,2,16,1);
		delay_ms(50);	//��ʱ50ms

  }
}





