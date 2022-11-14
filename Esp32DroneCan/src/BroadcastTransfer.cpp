#include "BroadcastTransfer.h"

BroadcastTransfer::BroadcastTransfer(
    uint8_t *payload,
    uint16_t payloadLength,
    uint16_t dataTypeId,
    uint8_t sourceNodeId,
    uint8_t priority,
    uint8_t transferId)
    : TransferBase(payload, payloadLength, dataTypeId, priority, transferId),
      _sourceNodeId(sourceNodeId)
{
}

uint8_t BroadcastTransfer::getSourceNodeId() { return _sourceNodeId; }