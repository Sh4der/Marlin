#ifndef ADAFRUIT_MAX6675_H
#define ADAFRUIT_MAX6675_H
#include "Arduino.h"

class MAX6675
{
private:
    int sclk;
    int cs;
    int miso; 
public:
    MAX6675(int cs, int miso, int sclk){
        this->cs = cs;
        this->sclk = sclk;
        this->miso = miso;
    };
    void begin(void);
    uint16_t readRaw16(void);
};

#endif