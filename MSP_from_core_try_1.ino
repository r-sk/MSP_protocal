#include "rashikMSP.h"
#include <SoftwareSerial.h>

SoftwareSerial naze_serial(D2, D3); // RX TX

rc_struct rc;
orientation ori;

MSP naze;

void setup()
{
  Serial.begin(9600);
  
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
  //naze.set_raw_rc(rc);
  delay(100);
  
  ori = naze.get_orientation();

//  Serial.print("Yaw:  " + String(ori.yaw) + "\t");
//  Serial.print("Pitch:  " + String(ori.pitch) + "\t");
//  Serial.println("Roll:  " + String(ori.roll));
}
