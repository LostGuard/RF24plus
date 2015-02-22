#ifndef _GPIO_STM32F10X_H_
#define _GPIO_STM32F10X_H_

#include <stm32f10x.h>

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1
#define PER     2

class RF24_GPIO {
public:
    RF24_GPIO(void);
    uint8_t err = 0;

    void csn(uint8_t mode);

    void ce(uint8_t mode);

    void cleanup(void);
};

#endif
