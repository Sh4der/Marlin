
#include "max6675.h"

inline void nop() {
        asm volatile("nop"::);
        asm volatile("nop"::);
        asm volatile("nop"::);
        asm volatile("nop"::);
        asm volatile("nop"::);
}

void MAX6675::begin(void){
    pinMode(cs, OUTPUT);
    pinMode(sclk, OUTPUT);
    pinMode(miso, INPUT);
    digitalWrite(cs, HIGH);
}
uint16_t MAX6675::readRaw16(void){
    digitalWrite(cs, LOW);
    nop();

    uint16_t raw = 0;
    for (int8_t i = 15; i >= 0; i--) {
        digitalWrite(sclk, LOW);
        nop();
        if (digitalRead(miso)) 
            raw |= (1<<i);
        digitalWrite(sclk, HIGH);
        nop();
    }

    digitalWrite(cs, HIGH);

    return raw;
}