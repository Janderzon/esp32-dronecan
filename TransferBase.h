#ifndef TransferBase_h
#define TransferBase_h
class TransferBase
{
public:
  TransferBase(int, int, int, int);
  int getPayload();
  int getDataTypeId();
  int getPriority();
  int getTransferId();

private:
  int _payload;
  int _dataTypeId;
  int _priority;
  int _transferId;
};
#endif