#pragma once

#include <ctime>
#include "../Blitz-Core.hpp"

namespace Blitz {
    class Time {
    public:
        Time(uint amount = 0);
        ~Time();

        void Set(Time time);
        void Set(uint milliseconds);

        uint AsMilliseconds();
        uint AsSeconds();

        Time operator=(Time& i) { return Time((uint)i.m_time); }
        Time operator+(Time& i) { return Time((uint)(this->m_time + i.m_time)); }
        Time operator-(Time& i) { return Time((uint)(this->m_time - i.m_time)); }
        Time operator*(Time& i) { return Time((uint)(this->m_time * i.m_time)); }
        Time operator/(Time& i) { return Time((uint)(this->m_time / i.m_time)); }
        Time operator%(Time& i) { return Time((uint)(this->m_time % i.m_time)); }
        Time operator^(Time& i) { return Time((uint)(this->m_time ^ i.m_time)); }
        Time operator&(Time& i) { return Time((uint)(this->m_time & i.m_time)); }

        Time& operator+=(Time& i) {
            this->m_time += i.m_time;
            return* this;
        }
        Time& operator-=(Time& i) {
            this->m_time -= i.m_time;
            return* this;
        }
        Time& operator*=(Time& i) {
            this->m_time *= i.m_time;
            return* this;
        }
        Time& operator/=(Time& i) {
            this->m_time /= i.m_time;
            return* this;
        }
        Time& operator%=(Time& i) {
            this->m_time %= i.m_time;
            return* this;
        }
        Time& operator^=(Time& i) {
            this->m_time ^= i.m_time;
            return* this;
        }
        Time& operator&=(Time& i) {
            this->m_time &= i.m_time;
            return* this;
        }

        Time operator++() { return Time((uint)m_time++); }
        Time operator--() { return Time((uint)m_time--); }
        Time operator!() { return Time((uint)-m_time); }

        bool operator==(Time& i) {
            if(this->m_time == i.m_time)
                return true;
            return false;
        }

        bool operator!=(Time& i) {
            if(this->m_time != i.m_time)
                return true;
            return false;
        }

        bool operator<(Time& i) {
            if(this->m_time < i.m_time)
                return true;
            return false;
        }

        bool operator>(Time& i) {
            if(this->m_time > i.m_time)
                return true;
            return false;
        }

        bool operator<=(Time& i) {
            if(this->m_time <= i.m_time)
                return true;
            return false;
        }

        bool operator>=(Time& i) {
            if(this->m_time >= i.m_time)
                return true;
            return false;
        }

    private:
        time_t m_time;
    
    };
};