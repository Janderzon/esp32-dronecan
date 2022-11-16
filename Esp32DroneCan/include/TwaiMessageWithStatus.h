#pragma once
#include <driver/twai.h>
class TwaiMessageWithStatus
{
public:
    TwaiMessageWithStatus(twai_message_t message, bool success)
        : _message(message), _success(success){};
    twai_message_t getMessage() const { return _message; }
    bool isSuccess() const { return _success; }

private:
    const twai_message_t _message;
    const bool _success;
};