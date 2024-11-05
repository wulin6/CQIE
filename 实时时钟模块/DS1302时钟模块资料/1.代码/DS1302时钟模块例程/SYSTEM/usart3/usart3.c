#include "usart3.h"	

/*****************���絥Ƭ�����******************
											STM32
 * ��Ŀ			:	����ģ��ͨ��ʵ��                     
 * �汾			: V1.0
 * ����			: 2024.10.2
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	����3						
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/

//����1�жϷ������
	//��ʼ�� IO ���� 3
	//pclk1:PCLK1 ʱ��Ƶ��(Mhz)
	//bound:������  
void USART3_Config()
{ 
			NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
		USART_InitTypeDef USART_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//GPIOB ʱ��
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE); //���� 3 ʱ��ʹ USART_DeInit(USART3); //��λ���� 3
		//USART3_TX PB10
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10; //PB10
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
		GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ�� PB10
		
		//USART3_RX PB11
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING; //��������
		GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ�� PB11
	
		USART_InitStructure.USART_BaudRate= 9600; //��������
		USART_InitStructure.USART_WordLength=USART_WordLength_8b; //8 λ���ݸ�
		USART_InitStructure.USART_StopBits = USART_StopBits_1; //һ��ֹͣ
		USART_InitStructure.USART_Parity = USART_Parity_No; //����żУ��
		USART_InitStructure.USART_HardwareFlowControl=
		USART_HardwareFlowControl_None;
		//��Ӳ��������
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  //�շ�ģʽ
	  USART_Init(USART3, &USART_InitStructure); //��ʼ������ 3
	  USART_Cmd(USART3, ENABLE);//ʹ�ܴ���
	  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//ʹ�ܽ����ж� 
	  //�����ж����ȼ�
	  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//��ռ���ȼ� 2
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority =0; //�����ȼ� 3
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ ͨ��ʹ��
	  NVIC_Init(&NVIC_InitStructure); //����ָ���Ĳ�����ʼ�� NVIC �Ĵ���
}
extern u8 Flag_dakai,dakai;

void USART3_IRQHandler(void)
{ u8 Res; 
  if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//���յ�����
  { 
		Res =USART_ReceiveData(USART3);
		if(Res=='1')
		{
			dakai=1;
			Res='5';
		}			
		if(Res=='2')
		{
			dakai=0;
			Res='5';
		}						
  } 
} 
