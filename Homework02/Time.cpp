#include "Time.h"

Time::Time(int h, int m, int s) {
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}

int Time::getHours() const {
    return this->hours;
}

int Time::getMinutes() const {
    return this->minutes;
}

int Time::getSeconds() const {
    return this->seconds;
}

void Time::addSeconds(int s) {
    this->seconds += s;
    this->minutes += this->seconds / 60;
    this->seconds %= 60;
}

void Time::addMinutes(int m) {
    this->minutes += m;
    this->hours += this->minutes / 60;
    this->minutes %= 60;
}

void Time::addHours(int h) {
    this->hours += h;
    this->hours %= 24;
}

void Time::addTime(int h, int m, int s) {
    this->addSeconds(s);
    this->addMinutes(m);
    this->addHours(h);
}
