#include "TransferBase.h"

TransferBase::TransferBase(
    int payload,
    int dataTypeId,
    int priority,
    int transferId)
{
  _payload = payload;
  _dataTypeId = dataTypeId;
  _priority = priority;
  _transferId = transferId;
}

int TransferBase::getPayload() { return _payload; }
int TransferBase::getDataTypeId() { return _dataTypeId; }
int TransferBase::getPriority() { return _priority; }
int TransferBase::getTransferId() { return _transferId; }