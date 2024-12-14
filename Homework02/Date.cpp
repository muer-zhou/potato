#include "Date.h"

Date::Date(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

int Date::getYear() const {
    return this->year;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getDay() const {
    return this->day;
}

int Date::daysInMonth(int m, int y) const {
    if (m == 2) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    }
    return (m == 4 || m == 6 || m == 9 || m == 11) ? 30 : 31;
}

void Date::addDays(int d) {
    this->day += d;
    while (this->day > this->daysInMonth(this->month, this->year)) {
        this->day -= this->daysInMonth(this->month, this->year);
        this->addMonths(1);
    }
}

void Date::addMonths(int m) {
    this->month += m;
    while (this->month > 12) {
        this->month -= 12;
        this->addYears(1);
    }
}

void Date::addYears(int y) {
    this->year += y;
}

void Date::addDate(int y, int m, int d) {
    this->addDays(d);
    this->addMonths(m);
    this->addYears(y);
}

int Date::toDays() const {
    int totalDays = this->year * 365 + this->day;

    for (int i = 1; i < this->month; ++i) {
        totalDays += this->daysInMonth(i, this->year);
    }

    return totalDays;
}
