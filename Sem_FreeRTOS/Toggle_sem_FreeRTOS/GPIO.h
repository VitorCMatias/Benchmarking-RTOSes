#ifndef GPIO_H
#define GPIO_H

#include<Arduino.h>

class GPIO {
  private:
    int port;
    int pin_mode;
  public:
    GPIO (int port, int pin_mode);
    void toggle();
    void toogle(uint32_t time_hight, uint32_t time_low);
    void toogle(uint32_t pulse_period);
    
    void analog_write(float local_escrita);
    int analog_read();
    bool digital_read();
    void digital_write(int port_state);
};
#endif
