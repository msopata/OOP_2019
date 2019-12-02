#pragma once

#include <gmock/gmock-generated-function-mockers.h>
#include "../../include/Time.h"

class TimeMock : public Time{
public:
    MOCK_METHOD1(create, void(bool endless));
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0_T(flow, void());
};
