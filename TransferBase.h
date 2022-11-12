#ifndef TransferBase_h
#define TransferBase_h
#include "Arduino.h"
class TransferBase
{
public:
  TransferBase(uint8_t *, uint16_t, int, uint8_t, uint8_t);
  uint8_t *getPayload();
  uint16_t getPayloadLength();
  int getDataTypeId();
  uint8_t getPriority();
  uint8_t getTransferId();

private:
  uint8_t *_payload;
  uint16_t _payloadLength;
  int _dataTypeId;
  uint8_t _priority;
  uint8_t _transferId;
};
#endif