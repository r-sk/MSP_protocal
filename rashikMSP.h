#include <Stream.h>

#define set_rc_value 200

typedef struct
{
  uint16_t throttle;
  uint16_t roll;
  uint16_t pitch;
  uint16_t yaw;
  uint16_t aux1;
  uint16_t aux2;
  uint16_t aux3;
  uint16_t aux4;
  
  
}rc_struct;

class MSP
{
  private:
    Stream* _stream;
    uint32_t _timeout;
    uint8_t data[20];

  public:
    void begin(Stream& stream, uint32_t timeout=500);

    void command(uint8_t msgID, void * payload, uint8_t size);

    void set_rc_values(rc_struct rc);
};
