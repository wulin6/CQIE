#include "ultrasonic.h"
#include "timer.h"

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	HC-SR04������������c�ļ�                   
 * �汾			: V1.0
 * ����			: 2024.8.27
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	����

**********************BEGIN***********************/

//����������
u16 msHcCount;

void Ultrasonic_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd (ULTRASONIC_GPIO_CLK, ENABLE );			// ������ ������������ �ĵ�Ƭ�����Ŷ˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = ULTRASONIC_TRIG_GPIO_PIN;			// �������� ������TRIG �ĵ�Ƭ������ģʽ
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;						// ����Ϊ�������
		GPIO_Init(ULTRASONIC_GPIO_PORT, &GPIO_InitStructure);				// ��ʼ�� 

		GPIO_InitStructure.GPIO_Pin = ULTRASONIC_ECHO_GPIO_PIN;			// �������� ������ECHO �ĵ�Ƭ������ģʽ
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;				// ����Ϊ������������
		GPIO_Init(ULTRASONIC_GPIO_PORT, &GPIO_InitStructure);				// ��ʼ�� 
	
		TIM4_Int_Init(1000-1,72-1);
}


//�򿪶�ʱ��4
static void OpenTimerForHc()  
{
   TIM_SetCounter(TIM4,0);
   msHcCount = 0;
   TIM_Cmd(TIM4, ENABLE); 
}

//�رն�ʱ��4
static void CloseTimerForHc()    
{
   TIM_Cmd(TIM4, DISABLE); 
}



//��ȡ��ʱ��4������ֵ
u32 GetEchoTimer(void)
{
   u32 t = 0;
   t = msHcCount*1000;
   t += TIM_GetCounter(TIM4);
   TIM4->CNT = 0;  
   delay_ms(50);
   return t;
}
 


//ͨ����ʱ��4������ֵ�������
float UltrasonicGetLength(void)
{
   u32 t = 0;
   int i = 0;
   float lengthTemp = 0;
   float sum = 0;
   while(i!=5)
   {
      TRIG_Send = 1;      
      delay_us(20);
      TRIG_Send = 0;
      while(ECHO_Reci == 0);      
      OpenTimerForHc();        
      i = i + 1;
      while(ECHO_Reci == 1);
      CloseTimerForHc();        
      t = GetEchoTimer();        
      lengthTemp = ((float)t/58.0);//cm
      sum = lengthTemp + sum ;
        
    }
    lengthTemp = sum/5.0;
    return lengthTemp;
}


