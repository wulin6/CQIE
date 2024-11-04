#include "hx711.h"
#include "delay.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	HX711���ӳ�ģ��c�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.9.11
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/

/**
  * @brief  PM25��ʼ������
  * @param  ��
  * @retval ��
  */

void HX711_Init(void)
{
		/*����һ��HX711_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*������ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd(HX711_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Pin = HX711_SCK_GPIO_PIN;
		GPIO_Init(HX711_SCK_GPIO_PORT, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin = HX711_DT_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		GPIO_Init(HX711_DT_GPIO_PORT, &GPIO_InitStructure);	

	
}
	
unsigned long HX711_GetData(void)
{
		unsigned long Count;
		unsigned char i;
		HX711_SCK_L;
	  delay_us(1);
		Count=0;
		while(HX711_DT);
		for (i=0;i<24;i++)
	 {
				HX711_SCK_H;
				delay_us(1);
				Count=Count<<1;
				HX711_SCK_L;
				delay_us(1);
				if(HX711_DT) Count++;
		}
		HX711_SCK_H;
		delay_us(1);
		Count=Count^0x800000;//���λȡ��������λ����
	                      //��HX71оƬ�У�count��һ��32λ���з������������ڴ洢���ش������Ķ�����
	                      //��count�����λΪ1ʱ����ʾ����Ϊ��������HX711оƬ��֧�ָ����Ķ�����
	                      //��ˣ�Ϊ�˽�����ת��Ϊ��������Ҫ��count�����λȡ��������count��0x800000������������
                          //������˵��0x800000�Ķ����Ʊ�ʾΪ100000000000000000000000����count������������
	                      //���Խ�count�����λ��1��Ϊ0���Ӷ��õ���Ӧ������������
		HX711_SCK_L;
		delay_us(1);
		
		return(Count);
}

