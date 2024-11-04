#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "hx711.h"

/*****************���絥Ƭ�����******************
											STM32
 * ��Ŀ			:	HX711���ӳ�ģ��ʵ��                     
 * �汾			: V1.0
 * ����			: 2024.9.11
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	�ο�HX711.h							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/

int value;
float weight;
int32_t reset;
u8 buff[30];

float Weights=100.0;  //100g
int32_t Weights_100=8493860;  //100g

int main(void)
{ 
	
  SystemInit();//����ϵͳʱ��Ϊ72M	
	delay_init(72);
	LED_Init();
	LED_On();
	HX711_Init();
	USART1_Config();//���ڳ�ʼ��
	
	OLED_Init();
	printf("Start \n");
	delay_ms(1000);
	//��ʾ������:��
	OLED_ShowChinese(0,0,0,16,1);
	OLED_ShowChinese(16,0,1,16,1);
	OLED_ShowChar(32,0,':',16,1);
	
	reset = HX711_GetData();

  while (1)
  {
		LED_Toggle();
		value = HX711_GetData();
		
		weight=(float)(value-reset)*Weights/(float)(Weights_100-reset);
		
		sprintf((char*)buff,"%.1f   ",weight);
		
		printf("����: %f\r\n",weight);
		
		//OLED_ShowString(50,30,buff,16,1);

		delay_ms(5000);
  }
}




