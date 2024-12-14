#include "DateTime.h"
#include <iostream>
#include <cmath> // For abs()

DateTime::DateTime(int y, int m, int d, int h, int mi, int s)
    : Date(y, m, d), Time(h, mi, s) {}

void DateTime::addDateTime(int y, int m, int d, int h, int mi, int s) {
    this->addDate(y, m, d);
    this->addTime(h, mi, s);
}

void DateTime::difference(const DateTime& other) {
    int totalSecondsThis = this->toDays() * 86400 + this->timeToSeconds();
    int totalSecondsOther = other.toDays() * 86400 + other.timeToSeconds();

    int diffSeconds = std::abs(totalSecondsThis - totalSecondsOther);

    int days = diffSeconds / 86400;
    diffSeconds %= 86400;

    int hours = diffSeconds / 3600;
    diffSeconds %= 3600;

    int minutes = diffSeconds / 60;
    int seconds = diffSeconds % 60;

    std::cout << "Difference: "
              << days << " days, "
              << hours << " hours, "
              << minutes << " minutes, "
              << seconds << " seconds.\n";
}

int DateTime::timeToSeconds() const {
    return this->hours * 3600 + this->minutes * 60 + this->seconds;
}
