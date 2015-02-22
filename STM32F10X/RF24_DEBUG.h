#ifndef RF24_STM32F10X_RF24_DEBUG_H_
#define RF24_STM32F10X_RF24_DEBUG_H_

class RF24_DEBUG {
public:
  RF24_DEBUG();
  virtual ~RF24_DEBUG();
  void print(const char* str);
};

#endif /* RF24_STM32F10X_RF24_DEBUG_H_ */
