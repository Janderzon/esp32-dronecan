#pragma once
#include "TransferBase.h"
class BroadcastTransfer : public TransferBase
{
public:
  BroadcastTransfer(
      std::vector<uint8_t> payload,
      uint16_t dataTypeId,
      uint8_t priority,
      uint8_t transferId,
      uint8_t sourceNodeId)
      : TransferBase(
            payload,
            dataTypeId,
            priority,
            transferId),
        _sourceNodeId(sourceNodeId) {}
  uint8_t getSourceNodeId() const { return _sourceNodeId; }

private:
  const uint8_t _sourceNodeId;
};