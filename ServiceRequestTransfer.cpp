#include "ServiceRequestTransfer.h"

ServiceRequestTransfer::ServiceRequestTransfer(
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

int ServiceRequestTransfer::getSourceNodeId() { return _sourceNodeId; }
int ServiceRequestTransfer::getDestinationNodeId() { return _destinationNodeId; }