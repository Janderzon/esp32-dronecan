#ifndef ServiceRequestTransfer_h
#define ServiceRequestTransfer_h
#include "TransferBase.h"
class ServiceRequestTransfer : public TransferBase
{
public:
    ServiceRequestTransfer(int, int, int, int, int, int);
    int getSourceNodeId();
    int getDestinationNodeId();

private:
    int _sourceNodeId;
    int _destinationNodeId;
};
#endif