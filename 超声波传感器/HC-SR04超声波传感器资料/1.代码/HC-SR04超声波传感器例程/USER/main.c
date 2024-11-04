#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "ultrasonic.h"
#include "timer.h"

/*****************辰哥单片机设计******************
											STM32
 * 项目			:	HC-SR04超声波传感器实验                     
 * 版本			: V1.0
 * 日期			: 2024.8.27
 * MCU			:	STM32F103C8T6
 * 接口			:	参看ultrasonic.h							
 * BILIBILI	:	辰哥单片机设计
 * CSDN			:	辰哥单片机设计
 * 作者			:	辰哥 

**********************BEGIN***********************/

float distance;

int main(void)
{ 
	
  SystemInit();//配置系统时钟为72M	
	delay_init(72);
	LED_Init();
	LED_On();
	Ultrasonic_Init();
	USART1_Config();//串口初始化
	
	OLED_Init();
	printf("Start \n");
	delay_ms(1000);
	
	OLED_Clear();
	//显示“距离:”
	OLED_ShowChinese(0,0,0,16,1);
	OLED_ShowChinese(16,0,1,16,1);
	OLED_ShowChar(32,0,':',16,1);
	OLED_ShowString(60,20,"cm",16,1);

  while (1)
  {
		LED_Toggle();
		distance = UltrasonicGetLength();
		OLED_ShowNum(40,20,distance,2,16,1);
		delay_ms(50);	//延时50ms

  }
}





