#pragma once
#include "BroadcastTransfer.h"
#include <driver/gpio.h>
#include <driver/twai.h>
#include <soc/periph_defs.h>
class Esp32DroneCan
{
public:
    Esp32DroneCan(uint8_t, gpio_num_t, gpio_num_t);
    bool broadcast(BroadcastTransfer);
    void onReceive(void (*callback)(twai_message_t));

private:
    uint8_t _nodeId;
    gpio_num_t _txPin;
    gpio_num_t _rxPin;
    intr_handle_t _interuptHandle;
    bool sendCanMessage(uint32_t, uint8_t *, uint16_t);
    twai_message_t receiveCanMessage();
    static void onInterrupt(void *arg);
    void handleInterrupt();
    void (*_onReceive)(twai_message_t);
};