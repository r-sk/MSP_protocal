#include <Arduino.h>
#include <Stream.h>

#define SET_RAW_RC      200
#define MSP_ATTITUDE    108


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

typedef struct
{
  float yaw;
  float pitch;
  float roll;
  
}orientation;


class MSP
{
  private:
    Stream* _stream;
    uint32_t _timeout;
    uint8_t data[20];
    uint8_t r_data[20];

  public:
    void begin(Stream& stream, uint32_t timeout=500);

    void command(uint8_t msgID, void * payload, uint8_t size);
    void request(uint8_t msgID);
    void response(void * payload);

    void set_raw_rc(rc_struct rc);

    orientation get_orientation();
    
};
