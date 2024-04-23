#include <SPI.h>
const uint8_t REG_SELECT = 8;
void setup() {
    SPI.begin();
    pinMode(REG_SELECT, OUTPUT);
}
inline void rotateLeft(uint8_t &bits) {
    bits = (bits << 1) | (bits >> 7);
}
void loop() {
    static uint8_t nomad = 1;
    digitalWrite(REG_SELECT, LOW);
    SPI.transfer(nomad);
    digitalWrite(REG_SELECT, HIGH);
    rotateLeft(nomad);
    delay(125);
}