#include "Esp32DroneCan.h"

Esp32DroneCan::Esp32DroneCan(uint8_t nodeId, gpio_num_t txPin, gpio_num_t rxPin)
    : _nodeId(nodeId),
      _interuptHandle(NULL)
{
    twai_general_config_t gConfig = TWAI_GENERAL_CONFIG_DEFAULT(
        txPin,
        rxPin,
        TWAI_MODE_NORMAL);
    twai_timing_config_t tConfig = TWAI_TIMING_CONFIG_1MBITS();
    twai_filter_config_t fConfig = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    if (twai_driver_install(&gConfig, &tConfig, &fConfig) != ESP_OK)
    {
    }

    if (twai_start() != ESP_OK)
    {
    }
}

Esp32DroneCan::~Esp32DroneCan()
{
    if (twai_stop() == ESP_OK)
    {
    }

    if (twai_driver_uninstall() == ESP_OK)
    {
    }
}

bool Esp32DroneCan::broadcast(BroadcastTransfer broadcastTransfer, int timeout)
{
    if (broadcastTransfer.getPayload().size() == 0 ||
        broadcastTransfer.getPayload().size() > 7)
        return false;

    if (broadcastTransfer.getPriority() > 31)
        return false;

    uint32_t canId = ((uint32_t)broadcastTransfer.getPriority() << 24) |
                     ((uint32_t)broadcastTransfer.getDataTypeId() << 8) |
                     (uint32_t)_nodeId;

    std::vector<uint8_t> payloadWithTailByte(broadcastTransfer.getPayload());

    payloadWithTailByte.push_back(0xC0 | (broadcastTransfer.getTransferId() & 31));

    return this->sendTwaiMessage(
        canId,
        payloadWithTailByte,
        pdMS_TO_TICKS(timeout));
}

TwaiMessageWithStatus Esp32DroneCan::awaitTransfer()
{
    return this->receiveTwaiMessage(portMAX_DELAY);
}

TwaiMessageWithStatus Esp32DroneCan::awaitTransfer(int timeout)
{
    return this->receiveTwaiMessage(pdMS_TO_TICKS(timeout));
}

bool Esp32DroneCan::sendTwaiMessage(
    uint32_t canId,
    std::vector<uint8_t> payload,
    TickType_t ticksToWait)
{
    twai_message_t message;
    message.identifier = canId;
    message.extd = 1;
    message.data_length_code = payload.size();
    for (int i = 0; i < payload.size(); i++)
    {
        message.data[i] = payload[i];
    }

    return twai_transmit(&message, ticksToWait) == ESP_OK;
}

TwaiMessageWithStatus Esp32DroneCan::receiveTwaiMessage(TickType_t ticksToWait)
{
    twai_message_t message;
    if (twai_receive(&message, ticksToWait) == ESP_OK)
    {
        TwaiMessageWithStatus twaiMessageWithStatus(message, true);
        return twaiMessageWithStatus;
    }
    TwaiMessageWithStatus twaiMessageWithStatus(message, false);
    return twaiMessageWithStatus;
}