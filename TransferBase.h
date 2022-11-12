#ifndef TransferBase_h
#define TransferBase_h
#include "Arduino.h"
class TransferBase
{
public:
  TransferBase(int, int, uint8_t, uint8_t);
  int getPayload();
  int getDataTypeId();
  uint8_t getPriority();
  uint8_t getTransferId();

private:
  int _payload;
  int _dataTypeId;
  uint8_t _priority;
  uint8_t _transferId;
};
#endif