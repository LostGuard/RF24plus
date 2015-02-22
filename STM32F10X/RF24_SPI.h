#ifndef RF24_SPI_H
#define	RF24_SPI_H

#include <stm32f10x.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

using namespace std;

class RF24_SPI {
public:
    RF24_SPI();
	uint8_t transfer(uint8_t tx_);
	virtual ~RF24_SPI();
private:
	uint8_t mode;
	uint8_t bits;
	uint32_t speed;
	int fd;
	void init();
};

#endif	/* SPI_H */
