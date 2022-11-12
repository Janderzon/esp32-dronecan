#ifndef BroadcastTransfer_h
#define BroadcastTransfer_h
#include "TransferBase.h"
class BroadcastTransfer : public TransferBase
{
public:
  BroadcastTransfer(uint8_t *, uint16_t, int, uint8_t, uint8_t, uint8_t);
  uint8_t getSourceNodeId();

private:
  uint8_t _sourceNodeId;
};
#endif