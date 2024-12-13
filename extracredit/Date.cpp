#include "Date.hpp"
#include <cmath>

Date::Date(double y, double m, double d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

double Date::getYear() const { return year; }
double Date::getMonth() const { return month; }
double Date::getDay() const { return day; }

bool Date::isLeapYear(double year) const {
    int intYear = static_cast<int>(year);
    return (intYear % 4 == 0 && intYear % 100 != 0) || (intYear % 400 == 0);
}

std::string Date::getDayOfWeek() const {
    // Zeller's Congruence implementation
    int y = static_cast<int>(year);
    int m = static_cast<int>(month);
    int d = static_cast<int>(day);
    
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    
    int k = y % 100;
    int j = y / 100;
    
    int h = (d + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    
    const std::string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", 
                               "Wednesday", "Thursday", "Friday"};
    return days[(h + 5) % 7];
}

double Date::getDaysInMonth() const {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthIndex = static_cast<int>(month) - 1;
    
    if (monthIndex == 1 && isLeapYear(year)) {  // February in leap year
        return 29;
    }
    return daysInMonth[monthIndex];
}