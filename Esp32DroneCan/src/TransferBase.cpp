#include "TransferBase.h"

TransferBase::TransferBase(
    uint8_t *payload,
    uint16_t payloadLength,
    uint16_t dataTypeId,
    uint8_t priority,
    uint8_t transferId)
{
  _payload = payload;
  _payloadLength = payloadLength;
  _dataTypeId = dataTypeId;
  _priority = priority;
  _transferId = transferId;
}

uint8_t *TransferBase::getPayload() { return _payload; }
uint16_t TransferBase::getPayloadLength() { return _payloadLength; }
uint16_t TransferBase::getDataTypeId() { return _dataTypeId; }
uint8_t TransferBase::getPriority() { return _priority; }
uint8_t TransferBase::getTransferId() { return _transferId; }