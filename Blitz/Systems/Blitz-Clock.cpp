#include "Blitz-Clock.hpp"

namespace Blitz {
    Clock::Clock() {
        m_time.Set(0);
    }

    Clock::~Clock() {
        delete this;
    }

    void Clock::Reset() {
        m_time.Set(0);
        m_resetTime.Set(clock());
    }

    Time& Clock::Get() {
        m_time.Set(clock() - m_resetTime.AsMilliseconds());
        return (Time&)m_time;
    }
};