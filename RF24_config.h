/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.

 */
#ifndef __RF24_CONFIG_H__
#define __RF24_CONFIG_H__

#define STM32F10X
#define SERIAL_DEBUG

#ifdef STM32F10X
    #include "STM32F10X/RF24_GPIO.h"
    #include "STM32F10X/RF24_SPI.h"
    #include "STM32F10X/RF24_TIMER.h"
    #include "STM32F10X/RF24_DEBUG.h"
#endif

#define _BV(x) (1<<(x))


#define pgm_read_word(p) (*(p))

#endif // __RF24_CONFIG_H__
