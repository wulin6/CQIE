#ifndef __DS1302_H 
#define __DS1302_H  
 
#include "sys.h" 

/*****************���絥Ƭ�����******************
											STM32
 * �ļ�			:	DS1302ʱ��ģ��h�ļ�                     
 * �汾			: V1.0
 * ����			: 2024.10.3
 * MCU			:	STM32F103C8T6
 * �ӿ�			:	������							
 * BILIBILI	:	���絥Ƭ�����
 * CSDN			:	���絥Ƭ�����
 * ����			:	���� 

**********************BEGIN***********************/
 
//---------------DS1302�˿ڶ���----------------- 
/***************�����Լ��������****************/
#define DS1302_CLK  						RCC_APB2Periph_GPIOA
#define DS1302_CE_PORT  				GPIOA
#define DS1302_CE_PIN						GPIO_Pin_5
#define DS1302_DATA_PORT				GPIOA
#define DS1302_DATA_PIN   			GPIO_Pin_6
#define DS1302_SCLK_PORT   			GPIOA
#define DS1302_SCLK_PIN  				GPIO_Pin_7

/*********************END**********************/

 
#define CE_L				 GPIO_ResetBits(DS1302_CE_PORT,DS1302_CE_PIN)//CE
#define CE_H				 GPIO_SetBits(DS1302_CE_PORT,DS1302_CE_PIN)

#define DATA_L			 GPIO_ResetBits(DS1302_SCLK_PORT,DS1302_DATA_PIN)//DATA
#define DATA_H			 GPIO_SetBits(DS1302_SCLK_PORT,DS1302_DATA_PIN)

#define SCLK_L			 GPIO_ResetBits(DS1302_DATA_PORT,DS1302_SCLK_PIN)//SCLK
#define SCLK_H			 GPIO_SetBits(DS1302_DATA_PORT,DS1302_SCLK_PIN)
 
struct TIMEData
{
	u16 year;
	u8  month;
	u8  day;
	u8  hour;
	u8  minute;
	u8  second;
	u8  week;
};//����TIMEData�ṹ�巽��洢ʱ����������

struct TIMERAM
{
	u8  hour_kai;
	u8  minute_kai;
	u8  hour_guan;
	u8  minute_guan;
	u8  kai;
	u8  guan;
};//����TIMEData�ṹ�巽��洢ʱ����������

extern struct TIMERAM TimeRAM;
extern struct TIMEData TimeData;//ȫ�ֱ���

void DS1302_GPIO_Init(void);//ds1302�˿ڳ�ʼ��
void DS1302_write_onebyte(u8 data);//��ds1302����һ�ֽ�����
void DS1302_wirte_rig(u8 address,u8 data);//��ָ���Ĵ���дһ�ֽ�����
u8 	 DS1302_read_rig(u8 address);//��ָ���Ĵ�����һ�ֽ�����
void DS1302_Init(void);//ds1302��ʼ������
void DS1302_DATAOUT_init(void);//IO�˿�����Ϊ���
void DS1302_DATAINPUT_init(void);//IO�˿�����Ϊ����
void DS1302_read_time(void);//��ds1302��ȡʵʱʱ�䣨BCD�룩
void DS1302_read_realTime(void);//��BCD��ת��Ϊʮ��������
void DS1302_wirteRAM(void);
void DS1302_readRAM(void);
 
#endif






