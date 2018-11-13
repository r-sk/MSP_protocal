#include <Stream.h>

class MSP
{
  private:
    Stream* _stream;
    uint32_t _timeout;

  public:
    void begin(Stream& stream, uint32_t timeout=500);

    void command(uint8_t msgID, void * payload, uint8_t size);
    
};
