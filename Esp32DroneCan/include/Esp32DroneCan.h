#pragma once
#include "BroadcastTransfer.h"
#include <driver/gpio.h>
#include <driver/twai.h>
#include "ServiceRequestTransfer.h"
#include "ServiceResponseTransfer.h"
#include <soc/periph_defs.h>
#include "TwaiMessageWithStatus.h"
class Esp32DroneCan
{
public:
    Esp32DroneCan(uint8_t, gpio_num_t, gpio_num_t);
    ~Esp32DroneCan();
    bool broadcast(BroadcastTransfer, int);
    TwaiMessageWithStatus awaitTransfer();
    TwaiMessageWithStatus awaitTransfer(int);

private:
    uint8_t _nodeId;
    intr_handle_t _interuptHandle;
    int32_t getMessageFrameId(BroadcastTransfer);
    int32_t Esp32DroneCan::getServiceFrameId(ServiceRequestTransfer);
    int32_t Esp32DroneCan::getServiceFrameId(ServiceResponseTransfer);
    bool sendTwaiMessage(uint32_t, std::vector<uint8_t>, TickType_t);
    TwaiMessageWithStatus receiveTwaiMessage(TickType_t);
};