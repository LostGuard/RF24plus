#include "RF24_TIMER.h"

RF24_TIMER::RF24_TIMER()
{

}

void RF24_TIMER::msleep(int milisec)
{
  usleep(milisec * 1000);
}

void RF24_TIMER::usleep(int microsec)
{
  microsec = microsec * (CoreClock / 1000000);

  volatile int i = 0;
  for (i; i < microsec; i++);
}

void RF24_TIMER::InitTimeOut(int msec)
{//!!!!! NOT CORRECT
  _timeOut = (CoreClock / 10) / 1000 * msec;
}

bool RF24_TIMER::CheckForTimeOut()
{//!!!!! NOT CORRECT
  if (_timeOut == 0)
  {
    return true;
  }
  else
  {
    _timeOut--;
    return false;
  }
}
