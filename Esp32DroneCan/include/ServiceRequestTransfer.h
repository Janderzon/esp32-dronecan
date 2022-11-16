#pragma once
#include "TransferBase.h"
class ServiceRequestTransfer : public TransferBase
{
public:
    ServiceRequestTransfer(
        std::vector<uint8_t> payload,
        uint16_t dataTypeId,
        uint8_t priority,
        uint8_t transferId,
        uint8_t sourceNodeId,
        uint8_t destinationNodeId)
        : TransferBase(
              payload,
              dataTypeId,
              priority,
              transferId),
          _sourceNodeId(sourceNodeId),
          _destinationNodeId(destinationNodeId) {}
    uint8_t getSourceNodeId() const { return _sourceNodeId; }
    uint8_t getDestinationNodeId() const { return _destinationNodeId; }

private:
    const uint8_t _sourceNodeId;
    const uint8_t _destinationNodeId;
};