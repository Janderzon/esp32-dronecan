#pragma once
#include <Arduino.h>
#include <vector>
class TransferBase
{
public:
  TransferBase(
      std::vector<uint8_t> payload,
      uint16_t dataTypeId,
      uint8_t priority,
      uint8_t transferId)
      : _payload(payload),
        _dataTypeId(dataTypeId),
        _priority(priority),
        _transferId(transferId) {}
  std::vector<uint8_t> getPayload() const { return _payload; }
  uint16_t getDataTypeId() const { return _dataTypeId; }
  uint8_t getPriority() const { return _priority; }
  uint8_t getTransferId() const { return _transferId; }

private:
  const std::vector<uint8_t> _payload;
  const uint16_t _dataTypeId;
  const uint8_t _priority;
  const uint8_t _transferId;
};