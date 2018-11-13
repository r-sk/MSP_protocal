#include "rashikMSP.h"
#include <SoftwareSerial.h>

SoftwareSerial naze_serial(D2, D3); // RX TX

rc_struct rc;
MSP naze;

void setup()
{
  rc.roll = 1100;
  rc.pitch = 1200;
  rc.yaw = 1300;
  rc.throttle = 1400;
  rc.aux1 = 1500;
  rc.aux2 = 1600;
  rc.aux3 = 1700;
  rc.aux4 = 1800;

  naze_serial.begin(9600);
  naze.begin(naze_serial);
  

}

void loop()
{
  naze.set_rc_values(rc);
  delay(10);
  

}
