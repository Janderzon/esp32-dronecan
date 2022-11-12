#include "ServiceResponseTransfer.h"

ServiceResponseTransfer::ServiceResponseTransfer(
    int payload,
    int dataTypeId,
    int sourceNodeId,
    int destinationNodeId,
    int priority,
    int transferId)
    : TransferBase(payload, dataTypeId, priority, transferId)
{
    _sourceNodeId = sourceNodeId;
    _destinationNodeId = destinationNodeId;
}

int ServiceResponseTransfer::getSourceNodeId() { return _sourceNodeId; }
int ServiceResponseTransfer::getDestinationNodeId() { return _destinationNodeId; }