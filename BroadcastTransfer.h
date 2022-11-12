#ifndef BroadcastTransfer_h
#define BroadcastTransfer_h
#include "TransferBase.h"
class BroadcastTransfer : public TransferBase
{
public:
  BroadcastTransfer(int, int, int, int, int);
  int getSourceNodeId();

private:
  int _sourceNodeId;
};
#endif