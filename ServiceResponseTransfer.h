#ifndef ServiceResponseTransfer_h
#define ServiceResponseTransfer_h
#include "TransferBase.h"
class ServiceResponseTransfer : public TransferBase
{
public:
    ServiceResponseTransfer(int, int, uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t getSourceNodeId();
    uint8_t getDestinationNodeId();

private:
    uint8_t _sourceNodeId;
    uint8_t _destinationNodeId;
};
#endif