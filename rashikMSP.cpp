#include "rashikMSP.h"

void MSP::begin(Stream& stream, uint32_t timeout)
{
  _stream = &stream;
  _timeout = timeout;
}

void MSP::command(uint8_t msgID, void * payload, uint8_t size)
{
  _stream->write('$');
  _stream->write('M');
  _stream->write('<');
  _stream->write(size);
  
  _stream->write(msgID);
  uint8_t checksum = size ^ msgID;
  
  uint8_t * payloadPtr = (uint8_t*)payload;
  
  for (uint8_t i = 0; i < size; ++i)
  {
    uint8_t b = *(payloadPtr++);
    checksum ^= b;
    _stream->write(b);
  }
  
  _stream->write(checksum);
}

void MSP::set_raw_rc(rc_struct rc)
{
  data[0] = (rc.roll & 0x00FF);
  data[1] = (rc.roll & 0xFF00) >> 8;

  data[2] = (rc.pitch & 0x00FF);
  data[3] = (rc.pitch & 0xFF00) >> 8;

  data[4] = (rc.throttle & 0x00FF);
  data[5] = (rc.throttle & 0xFF00) >> 8;

  data[6] = (rc.yaw & 0x00FF);
  data[7] = (rc.yaw & 0xFF00) >> 8;

  data[8] = (rc.aux1 & 0x00FF);
  data[9] = (rc.aux1 & 0xFF00) >> 8;

  data[10] = (rc.aux2 & 0x00FF);
  data[11] = (rc.aux2 & 0xFF00) >> 8;

  data[12] = (rc.aux3 & 0x00FF);
  data[13] = (rc.aux3 & 0xFF00) >> 8;

  data[14] = (rc.aux4 & 0x00FF);
  data[15] = (rc.aux4 & 0xFF00) >> 8;

  command(SET_RAW_RC, data, sizeof(rc));
  
}

orientation MSP::get_orientation()
{
  orientation o;

  o.yaw = 0;
  o.pitch = 1;
  o.roll = 2;

  return o;
  
}
