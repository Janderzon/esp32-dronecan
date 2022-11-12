#include "BroadcastTransfer.h"

BroadcastTransfer::BroadcastTransfer(
    int payload,
    int dataTypeId,
    uint8_t sourceNodeId,
    uint8_t priority,
    uint8_t transferId)
    : TransferBase(payload, dataTypeId, priority, transferId)
{
    _sourceNodeId = sourceNodeId;
}

uint8_t BroadcastTransfer::getSourceNodeId() { return _sourceNodeId; }