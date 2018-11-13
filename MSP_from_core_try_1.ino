#include "rashikMSP.h"
#include <SoftwareSerial.h>

SoftwareSerial naze_serial(D2, D3); // RX TX

uint16_t throttle = 1500;
uint16_t roll = 1500;
uint16_t pitch = 1400;
uint16_t yaw = 1200;
uint16_t aux = 0;

uint8_t data[16] = {220,05,120,05,220,05,176,04,0,0,0,0,0,0,0,0};

MSP naze;

void setup()
{
  naze_serial.begin(9600);
  naze.begin(naze_serial);
  

}

void loop()
{

  naze.command((uint8_t)200, data,(uint8_t)16);
  delay(10);
  

}
