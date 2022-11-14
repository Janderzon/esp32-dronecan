#pragma once
#include "BroadcastTransfer.h"
#include "driver/gpio.h"
#include "driver/twai.h"
class Esp32DroneCan
{
public:
    Esp32DroneCan(uint8_t);
    bool broadcast(BroadcastTransfer);

private:
    uint8_t _nodeId;
    bool sendCanMessage(uint32_t, uint8_t *, uint16_t);
};