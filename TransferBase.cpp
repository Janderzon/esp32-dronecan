#include "TransferBase.h"

TransferBase::TransferBase(
    int payload,
    int dataTypeId,
    uint8_t priority,
    uint8_t transferId)
{
  _payload = payload;
  _dataTypeId = dataTypeId;
  _priority = priority;
  _transferId = transferId;
}

int TransferBase::getPayload() { return _payload; }
int TransferBase::getDataTypeId() { return _dataTypeId; }
uint8_t TransferBase::getPriority() { return _priority; }
uint8_t TransferBase::getTransferId() { return _transferId; }