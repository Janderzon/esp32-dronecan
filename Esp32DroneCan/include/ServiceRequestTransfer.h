#pragma once
#include "TransferBase.h"
class ServiceRequestTransfer : public TransferBase
{
public:
    ServiceRequestTransfer(uint8_t *, uint16_t, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t getSourceNodeId();
    uint8_t getDestinationNodeId();

private:
    uint8_t _sourceNodeId;
    uint8_t _destinationNodeId;
};