Firstly, you need to edit the "RF24_config.h" file for your processor type. 
To do this, you will most likely need to create the appropriate folder, following the example of the STM32F10X family.


---------------------------------sample main.cpp------------------------------------------------------
#include "RF24/RF24.h"

using namespace std;

RF24* radio;

int main(int argc, char** argv)
{
  RF24_GPIO* gpio = new RF24_GPIO();
  RF24_SPI* spi = new RF24_SPI();
  RF24_TIMER* timer = new RF24_TIMER();
  RF24_DEBUG* debug = 0;

  radio = new RF24(gpio, spi, timer, debug);

  radio->begin();
  radio->setPALevel(RF24_PA_MAX);
  radio->setDataRate(RF24_250KBPS);
  radio->setChannel(109);
  radio->setCRCLength(RF24_CRC_16);
  radio->setPayloadSize(2);
  radio->openReadingPipe(1,0x22222222);
  radio->setAutoAck(false);

  if (!radio->testRegister(0x10, 8))
  {
    return 0;
  }
  
  radio->startListening();

  while(1)
  {
      if(radio->available())
      {
          uint8_t buf[2];
          radio->read(&buf,2);
          //do something
      }
      timer->usleep(1);
  }

  return 0;
}
