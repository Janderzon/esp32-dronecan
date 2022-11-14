#pragma once
#include "Arduino.h"
class TransferBase
{
public:
  TransferBase(uint8_t *, uint16_t, uint16_t, uint8_t, uint8_t);
  uint8_t *getPayload();
  uint16_t getPayloadLength();
  uint16_t getDataTypeId();
  uint8_t getPriority();
  uint8_t getTransferId();

private:
  uint8_t *_payload;
  uint16_t _payloadLength;
  uint16_t _dataTypeId;
  uint8_t _priority;
  uint8_t _transferId;
};