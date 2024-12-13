#include "Time.hpp"

Time::Time(double h, double m, double s, double tz) {
    this->hour = h;
    this->minute = m;
    this->second = s;
    this->timeZoneOffset = tz;
}

double Time::getHour() const { return hour; }
double Time::getMinute() const { return minute; }
double Time::getSecond() const { return second; }
double Time::getTimeZoneOffset() const { return timeZoneOffset; }

void Time::adjustTimeZone(double newOffset) {
    double diff = newOffset - timeZoneOffset;
    hour += diff;
    
    // Handle day boundary crossings
    while (hour >= 24) hour -= 24;
    while (hour < 0) hour += 24;
    
    timeZoneOffset = newOffset;
}

void Time::applyDST(bool isDST) {
    if (isDST) {
        hour += 1;
        if (hour >= 24) hour -= 24;
    } else {
        hour -= 1;
        if (hour < 0) hour += 24;
    }
}