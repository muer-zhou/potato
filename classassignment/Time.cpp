// Time.cpp
#include "Time.hpp"

Time::Time(double h, double m, double s) {
    this->hour = h;
    this->minute = m;
    this->second = s;
}

double Time::getHour() const {
    return hour;
}

double Time::getMinute() const {
    return minute;
}

double Time::getSecond() const {
    return second;
}

// DateTime.hpp
#ifndef DATETIME_HPP
#define DATETIME_HPP