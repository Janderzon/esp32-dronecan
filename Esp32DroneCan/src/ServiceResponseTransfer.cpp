#include "ServiceResponseTransfer.h"

ServiceResponseTransfer::ServiceResponseTransfer(
    uint8_t *payload,
    uint16_t payloadLength,
    uint16_t dataTypeId,
    uint8_t sourceNodeId,
    uint8_t destinationNodeId,
    uint8_t priority,
    uint8_t transferId)
    : TransferBase(payload, payloadLength, dataTypeId, priority, transferId),
      _sourceNodeId(sourceNodeId),
      _destinationNodeId(destinationNodeId)
{
}

uint8_t ServiceResponseTransfer::getSourceNodeId() { return _sourceNodeId; }
uint8_t ServiceResponseTransfer::getDestinationNodeId() { return _destinationNodeId; }