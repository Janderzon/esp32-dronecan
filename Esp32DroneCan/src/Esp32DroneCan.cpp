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

bool Esp32DroneCan::broadcast(BroadcastTransfer transfer, int timeout)
{
    if (transfer.getPayload().size() == 0)
        return false;

    return this->sendFrames(
        this->getMessageFrameId(transfer),
        transfer.getPayload(),
        transfer.getTransferId(),
        pdMS_TO_TICKS(timeout));
}

int32_t Esp32DroneCan::getMessageFrameId(BroadcastTransfer transfer)
{
    if (transfer.getPriority() > 31)
        Serial.println("Priority should not be above 31");

    return ((uint32_t)transfer.getPriority() << 24) |
           ((uint32_t)transfer.getDataTypeId() << 8) |
           (uint32_t)_nodeId;
}

int32_t Esp32DroneCan::getServiceFrameId(ServiceRequestTransfer transfer)
{
    if (transfer.getPriority() > 31)
        Serial.println("Priority should not be above 31");

    if (transfer.getDataTypeId() > 256)
        Serial.println("DataTypeId should not be above 256 for ServiceRequestTransfer");

    if (transfer.getDestinationNodeId() > 127 ||
        transfer.getDestinationNodeId() == 0)
        Serial.println("DestinationNodeId must be between 1 and 127 inclusive.");

    return ((uint32_t)transfer.getPriority() << 24) |
           ((uint32_t)transfer.getDataTypeId() << 16) |
           ((uint32_t)1 << 15) |
           ((uint32_t)transfer.getDestinationNodeId() << 8) |
           ((uint32_t)1 << 7) |
           (uint32_t)_nodeId;
}

int32_t Esp32DroneCan::getServiceFrameId(ServiceResponseTransfer transfer)
{
    if (transfer.getPriority() > 31)
        Serial.println("Priority should not be above 31");

    if (transfer.getDataTypeId() > 256)
        Serial.println("DataTypeId should not be above 256 for ServiceRequestTransfer");

    if (transfer.getDestinationNodeId() > 127 ||
        transfer.getDestinationNodeId() == 0)
        Serial.println("DestinationNodeId must be between 1 and 127 inclusive.");

    return ((uint32_t)transfer.getPriority() << 24) |
           ((uint32_t)transfer.getDataTypeId() << 16) |
           ((uint32_t)0 << 15) |
           ((uint32_t)transfer.getDestinationNodeId() << 8) |
           ((uint32_t)1 << 7) |
           (uint32_t)_nodeId;
}

TwaiMessageWithStatus Esp32DroneCan::awaitTransfer()
{
    return this->receiveFrame(portMAX_DELAY);
}

TwaiMessageWithStatus Esp32DroneCan::awaitTransfer(int timeout)
{
    return this->receiveFrame(pdMS_TO_TICKS(timeout));
}

bool Esp32DroneCan::sendFrames(
    uint32_t frameId,
    std::vector<uint8_t> payload,
    uint8_t transferId,
    TickType_t ticksToWait)
{
    const size_t maxDataBytesPerFrame = 7;
    if (payload.size() > maxDataBytesPerFrame)
    {
        uint16_t crc = getTransferCrc(payload);
        payload.insert(payload.begin(), crc & 0xFF);
        payload.insert(payload.begin(), (crc >> 8) & 0xFF);
    }

    size_t bytesSent = 0;
    bool toggle = false;
    while (bytesSent < payload.size())
    {
        size_t bytesLeft = payload.size() - bytesSent;

        uint8_t tailByte = 0;
        if (bytesSent == 0)
            tailByte |= 1 << 7;
        if (bytesLeft <= maxDataBytesPerFrame)
            tailByte |= 1 << 6;
        tailByte |= toggle << 5;
        tailByte |= transferId;

        std::vector<uint8_t> framePayload;
        size_t framePayloadSize = min(bytesLeft, maxDataBytesPerFrame);
        for (int i = 0; i < framePayloadSize; i++)
        {
            framePayload.push_back(payload[i + bytesSent]);
        }
        framePayload.push_back(tailByte);

        if (!this->sendFrame(frameId, framePayload, ticksToWait))
            continue;

        toggle = !toggle;
        bytesSent += framePayload.size() - 1;
    }

    return true;
}

uint16_t Esp32DroneCan::getTransferCrc(std::vector<uint8_t> payload)
{
    uint16_t crc = 0xFFFFU;

    for (uint8_t byte : payload)
    {
        crc ^= static_cast<uint16_t>(byte) << 8;
        for (std::uint8_t bit = 8; bit > 0; --bit)
        {
            if (crc & 0x8000U)
                crc = (crc << 1) ^ 0x1021U;
            else
                crc = (crc << 1);
        }
    }

    return crc;
}

bool Esp32DroneCan::sendFrame(
    uint32_t id,
    std::vector<uint8_t> payload,
    TickType_t ticksToWait)
{
    twai_message_t message;
    message.identifier = id;
    message.extd = 1;
    message.data_length_code = payload.size();
    for (int i = 0; i < payload.size(); i++)
    {
        message.data[i] = payload[i];
    }

    return twai_transmit(&message, ticksToWait) == ESP_OK;
}

TwaiMessageWithStatus Esp32DroneCan::receiveFrame(TickType_t ticksToWait)
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