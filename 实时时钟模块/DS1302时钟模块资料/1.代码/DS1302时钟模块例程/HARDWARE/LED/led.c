#include "led.h"
#include "delay.h"

void LED_Init(void)
{
	//����GPIOBʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	//����LED����Ϊģ�����ģʽ
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_PROT, &GPIO_InitStructure);
	GPIO_ResetBits(LED_GPIO_PROT, LED_GPIO_PIN);
}

void LED_Toggle(void)
{
	GPIO_WriteBit(LED_GPIO_PROT, LED_GPIO_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(LED_GPIO_PROT, LED_GPIO_PIN))));//led��ƽ��ת
}
void LED_On()
{
	GPIO_ResetBits(LED_GPIO_PROT, LED_GPIO_PIN);
}
void LED_Off()
{
	GPIO_SetBits(LED_GPIO_PROT, LED_GPIO_PIN);
}

void LED_Twinkle()
{
	LED_On();
	delay_ms(10);
	LED_Off();
}
