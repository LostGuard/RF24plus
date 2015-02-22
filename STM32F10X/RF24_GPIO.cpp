#include "RF24_GPIO.h"

#include <stm32f10x.h>
#include <stm32f10x_gpio.h>


#define CE_PORT GPIOA
#define CE_PIN GPIO_Pin_3

#define CS_PORT GPIOA
#define CS_PIN GPIO_Pin_4

#define IRQ_PORT GPIOA
#define IRQ_PIN GPIO_Pin_8


RF24_GPIO::RF24_GPIO(void)
{

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  //RCC-----------
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  //Config the CE && CSN pin
  GPIO_InitStructure.GPIO_Pin = CE_PIN | CS_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void RF24_GPIO::csn(uint8_t mode)
{
  if (mode == HIGH)
    GPIO_SetBits(CS_PORT, CS_PIN);
  else
    GPIO_ResetBits(CS_PORT, CS_PIN);
}

void RF24_GPIO::ce(uint8_t mode)
{
  if (mode == HIGH)
    GPIO_SetBits(CE_PORT, CE_PIN);
  else
    GPIO_ResetBits(CE_PORT, CE_PIN);
}

