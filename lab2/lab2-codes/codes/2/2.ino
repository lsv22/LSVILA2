#include <SPI.h>
const int REG_SELECT = 8;
void setup()
{
  SPI.begin();
  pinMode(REG_SELECT, OUTPUT);
}
void rotateLeft(uint16_t &bits)
{
  bits = (bits << 1) | (bits >> 15);
}
void loop()
{
  static uint16_t nomad = 1;
  digitalWrite(REG_SELECT, LOW);
  SPI.transfer16(nomad);
  digitalWrite(REG_SELECT, HIGH);
  rotateLeft(nomad);
  delay(200);
}