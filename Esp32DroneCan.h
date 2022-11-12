#ifndef Esp32DroneCan_h
#define Esp32DroneCan_h
#include "BroadcastTransfer.h"
#include "driver/gpio.h"
#include "driver/twai.h"
class Esp32DroneCan
{
public:
    Esp32DroneCan(uint8_t);
    bool Broadcast(BroadcastTransfer);

private:
    uint8_t _nodeId;
    bool SendCanMessage(uint32_t, uint8_t *, uint16_t);
};
#endif