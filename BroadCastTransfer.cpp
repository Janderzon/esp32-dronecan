#include "BroadcastTransfer.h"

BroadcastTransfer::BroadcastTransfer(
    int payload,
    int dataTypeId,
    int sourceNodeId,
    int priority,
    int transferId)
    : TransferBase(payload, dataTypeId, priority, transferId)
{
    _sourceNodeId = sourceNodeId;
}

int BroadcastTransfer::getSourceNodeId() { return _sourceNodeId; }