#include "Blitz-Time.hpp"

namespace Blitz {
    Time::Time(uint amount) {
        m_time = amount;
    }

    Time::~Time() {
        delete this;
    }

    void Time::Set(Time u_time) {
        m_time = u_time.AsMilliseconds();
    }

    void Time::Set(uint milliseconds) {
        m_time = milliseconds;
    }

    uint Time::AsMilliseconds() {
        return (uint)m_time;
    }

    uint Time::AsSeconds() {
        return (uint)m_time / 1000;
    }
};