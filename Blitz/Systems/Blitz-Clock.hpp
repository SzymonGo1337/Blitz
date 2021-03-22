#pragma once

#include "Blitz-Time.hpp"

namespace Blitz {
    class Clock {
    public:
        Clock();
        ~Clock();

        void Reset();
        Time& Get();

    private:
        Time m_time;
        Time m_resetTime;

    };
};