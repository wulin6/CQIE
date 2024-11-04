#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "bump.h"
#include "key.h"

/*****************���絥Ƭ�����******************
											STM32
 * ��Ŀ			:	5Vˮ��ģ��ʵ��                     
 * �汾			: V1.0
 * ����			: 2024.9.22
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	�ο�bump.h							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/

int key = 0;
int key_state = 0;

int main(void)
{ 
	
  SystemInit();//����ϵͳʱ��Ϊ72M	
	delay_init(72);
	LED_Init();
	LED_On();
	BUMP_Init();
	USART1_Config();//���ڳ�ʼ��
	Key_Init();
	OLED_Init();
	printf("Start \n");
	delay_ms(1000);
	
	OLED_Clear();
	//��ʾ��ˮ��״̬:��
	OLED_ShowChinese(0,0,0,16,1);
	OLED_ShowChinese(16,0,1,16,1);
	OLED_ShowChinese(32,0,2,16,1);
	OLED_ShowChinese(48,0,3,16,1);
	OLED_ShowChar(64,0,':',16,1);

  while (1)
  {
		key = Key_GetData();

		if(key)
			key_state++;
		if(key_state%2==1)
		{
			BUMP_ON;
			LED_On();
			//OLED_ShowChinese(56,24,4,16,1);		//��
			}
		
		if(key_state%2==0)
		{
			BUMP_OFF;
			LED_Off();
		//OLED_ShowChinese(56,24,5,16,1);		//��
		}

  }
}


