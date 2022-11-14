#pragma once
#include "TransferBase.h"
class BroadcastTransfer : public TransferBase
{
public:
  BroadcastTransfer(uint8_t *, uint16_t, uint16_t, uint8_t, uint8_t, uint8_t);
  uint8_t getSourceNodeId();

private:
  uint8_t _sourceNodeId;
};