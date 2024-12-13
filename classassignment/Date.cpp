// Date.cpp
#include "Date.hpp"

Date::Date(double y, double m, double d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

double Date::getYear() const {
    return year;
}

double Date::getMonth() const {
    return month;
}

double Date::getDay() const {
    return day;
}