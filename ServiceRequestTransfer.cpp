#include "ServiceRequestTransfer.h"

ServiceRequestTransfer::ServiceRequestTransfer(
    uint8_t *payload,
    uint16_t payloadLength,
    uint16_t dataTypeId,
    uint8_t sourceNodeId,
    uint8_t destinationNodeId,
    uint8_t priority,
    uint8_t transferId)
    : TransferBase(payload, payloadLength, dataTypeId, priority, transferId)
{
    _sourceNodeId = sourceNodeId;
    _destinationNodeId = destinationNodeId;
}

uint8_t ServiceRequestTransfer::getSourceNodeId() { return _sourceNodeId; }
uint8_t ServiceRequestTransfer::getDestinationNodeId() { return _destinationNodeId; }