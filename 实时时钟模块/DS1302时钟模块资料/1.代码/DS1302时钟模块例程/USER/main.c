#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "ds1302.h"
#include "timer.h"


/*****************辰哥单片机设计******************
											STM32
 * 项目			:	DS1302时钟模块实验                     
 * 版本			: V1.0
 * 日期			: 2024.10.3
 * MCU			:	STM32F103C8T6
 * 接口			:	参看ds1302.h							
 * BILIBILI	:	辰哥单片机设计
 * CSDN			:	辰哥单片机设计
 * 作者			:	辰哥 

**********************BEGIN***********************/

char st[50];	
int main(void)
{ 
	
  u16 ii=0;
	delay_init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	DS1302_GPIO_Init();	
	//DS1302_Init();						//时间设置
  DS1302_read_realTime();   //读取实时数据 
	LED_Init();
	OLED_Init();                                  //屏幕初始化

	OLED_Clear();

    
  while(1)
  {
		DS1302_read_realTime();    //读取此时时刻
		sprintf(st,"%d  ",TimeData.year);
		OLED_ShowString(8,0,st,16,1);
		OLED_ShowChinese(40,0,9,16,1);//年
		sprintf(st,"%d  ",TimeData.month);
		OLED_ShowString(56,0,st,16,1);
		OLED_ShowChinese(72,0,10,16,1);//月
		sprintf(st,"%d  ",TimeData.day);
		OLED_ShowString(88,0,st,16,1);
		OLED_ShowChinese(104,0,11,16,1);//日
		sprintf(st,"%d  ",TimeData.hour);
		OLED_ShowString(48+8,16,st,16,1);
		OLED_ShowString(48+8+16,16,"-",16,1);
		sprintf(st,"%d  ",TimeData.minute);
		OLED_ShowString(48+8+16+8,16,st,16,1);
		OLED_ShowString(48+8+16+16+8,16,"-",16,1);
		sprintf(st,"%d  ",TimeData.second);
		OLED_ShowString(48+8+16+16+16,16,st,16,1);
		OLED_ShowChinese(0,16,0,16,1);//星期
		OLED_ShowChinese(16,16,1,16,1);
	
		switch(TimeData.week)
		{
			case 1:
			{
				OLED_ShowChinese(32,16,2,16,1);
			}break;
			case 2:
			{
				OLED_ShowChinese(32,16,3,16,1);
			}break;
			case 3:
			{
				OLED_ShowChinese(32,16,4,16,1);
			}break;
			case 4:
			{
				OLED_ShowChinese(32,16,5,16,1);
			}break;
			case 5:
			{
				OLED_ShowChinese(32,16,6,16,1);
			}break;
			case 6:
			{
				OLED_ShowChinese(32,16,7,16,1);
			}break;
			case 7:
			{
				OLED_ShowChinese(32,16,8,16,1);
			}
		
		}
		OLED_Refresh();
	}
}




