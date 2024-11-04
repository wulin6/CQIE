#include "key.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd (KEY_GPIO_CLK, ENABLE );				// ������ ��Ƭ�����Ŷ˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = KEY_GPIO_PIN;				// �������� ��Ƭ������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;					// ����Ϊ�������
	
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);					// ��ʼ�� 
	
}

uint16_t Key_GetData()
{
	static u8 key_up=1;//�������ɿ���־
	if(key_up&&(KEY==0))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY==0)return KEY_PRES;
	}else if(KEY==1)key_up=1; 	    
 	return 0;// �ް�������
}
