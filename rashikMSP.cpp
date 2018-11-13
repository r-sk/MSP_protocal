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
