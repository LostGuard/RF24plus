#ifndef RF24_time_stm32f10x_H
#define RF24_time_stm32f10x_H

#define CoreClock 80000000

class RF24_TIMER {
public:
    RF24_TIMER();
    //virtual ~RF24_SPI();
    void msleep(int milisec);
    void usleep(int microsec);
    void InitTimeOut(int msec);
    bool CheckForTimeOut();
 private:
    unsigned int _timeOut = 0;

};

#endif
