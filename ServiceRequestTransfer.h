#ifndef ServiceRequestTransfer_h
#define ServiceRequestTransfer_h
#include "TransferBase.h"
class ServiceRequestTransfer : public TransferBase
{
public:
    ServiceRequestTransfer(int, int, uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t getSourceNodeId();
    uint8_t getDestinationNodeId();

private:
    uint8_t _sourceNodeId;
    uint8_t _destinationNodeId;
};
#endif