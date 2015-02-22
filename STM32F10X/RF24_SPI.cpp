#include "RF24_SPI.h"

RF24_SPI::RF24_SPI()
{
  this->init();
}

void RF24_SPI::init()
{
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

  /* SPI configuration */
  SPI_InitTypeDef SPI_InitStructure;
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);

  //SPI_InitTypeDef SPI_InitStructureSlave = SPI_InitStructure;
  //SPI_InitStructureSlave.SPI_Mode = SPI_Mode_Slave;
  //SPI_Init(SPI2, &SPI_InitStructureSlave);

  //Config the NSS(CSN) pin
  SPI_SSOutputCmd(SPI1, ENABLE);


  SPI_Cmd(SPI1, ENABLE);

}

uint8_t RF24_SPI::transfer(uint8_t tx_)
{
  while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) == RESET); // Wait while DR register is not empty
  SPI_I2S_SendData(SPI1,tx_); // Send byte to SPI
  while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) == RESET); // Wait to receive byte
  return SPI_I2S_ReceiveData(SPI1); // Read byte from SPI bus
}

RF24_SPI::~RF24_SPI() {

}
