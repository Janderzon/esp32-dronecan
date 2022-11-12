#include "ServiceResponseTransfer.h"

ServiceResponseTransfer::ServiceResponseTransfer(
    int payload,
    int dataTypeId,
    uint8_t sourceNodeId,
    uint8_t destinationNodeId,
    uint8_t priority,
    uint8_t transferId)
    : TransferBase(payload, dataTypeId, priority, transferId)
{
    _sourceNodeId = sourceNodeId;
    _destinationNodeId = destinationNodeId;
}

uint8_t ServiceResponseTransfer::getSourceNodeId() { return _sourceNodeId; }
uint8_t ServiceResponseTransfer::getDestinationNodeId() { return _destinationNodeId; }