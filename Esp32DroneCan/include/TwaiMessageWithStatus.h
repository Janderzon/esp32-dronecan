#pragma once
#include <driver/twai.h>
class TwaiMessageWithStatus
{
public:
    TwaiMessageWithStatus(twai_message_t message, bool success)
        : _message(message), _success(success){};
    twai_message_t getMessage() { return _message; }
    bool isSuccess() { return _success; }

private:
    twai_message_t _message;
    bool _success;
};