#ifndef ServiceResponseTransfer_h
#define ServiceResponseTransfer_h
#include "TransferBase.h"
class ServiceResponseTransfer : public TransferBase
{
public:
    ServiceResponseTransfer(int, int, int, int, int, int);
    int getSourceNodeId();
    int getDestinationNodeId();

private:
    int _sourceNodeId;
    int _destinationNodeId;
};
#endif