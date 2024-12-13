// README.md
# DateTime Class Implementation

## Overview
This project implements a DateTime class hierarchy consisting of Date, Time, and DateTime classes. The implementation follows the UML diagram provided and handles date and time operations.

## Files
- `Date.hpp/cpp`: Implements the Date class with year, month, and day attributes
- `Time.hpp/cpp`: Implements the Time class with hour, minute, and second attributes
- `DateTime.hpp/cpp`: Implements the DateTime class that inherits from both Date and Time
- `main.cpp`: Contains test cases demonstrating the functionality

## Compilation
```bash
g++ -std=c++11 main.cpp DateTime.cpp Date.cpp Time.cpp -o datetime
```

## Usage
Run the compiled program:
```bash
./datetime
```

## Features
- Date class with year, month, and day attributes
- Time class with hour, minute, and second attributes
- DateTime class with format functionality
- Format strings support patterns like "YYYY-MM-DD HH:MM:SS"

## Format String Patterns
- YYYY: 4-digit year
- MM: 2-digit month
- DD: 2-digit day
- HH: 2-digit hour (24-hour format)
- MM: 2-digit minute
- SS: 2-digit second

Example:
```cpp
DateTime dt(2024, 3, 15, 14, 30, 45);
std::string formatted = dt.format("YYYY-MM-DD HH:MM:SS");
// Output: 2024-03-15 14:30:45
```

#include <iostream>
// #include <string>
// #include <iomanip>
// #include <sstream>

// class Time {
// private:
//     int hour;
//     int minute;
//     int second;

// public:
//     Time(int h = 0, int m = 0, int s = 0) {
//         setTime(h, m, s);
//     }

//     void setTime(int h, int m, int s) {
//         // Normalize seconds
//         m += s / 60;
//         second = s % 60;
//         if (second < 0) {
//             second += 60;
//             m--;
//         }

//         // Normalize minutes
//         h += m / 60;
//         minute = m % 60;
//         if (minute < 0) {
//             minute += 60;
//             h--;
//         }

//         // Normalize hours
//         hour = h % 24;
//         if (hour < 0) {
//             hour += 24;
//         }
//     }

//     void addSeconds(int s) {
//         setTime(hour, minute, second + s);
//     }

//     void addMinutes(int m) {
//         setTime(hour, minute + m, second);
//     }

//     void addHours(int h) {
//         setTime(hour + h, minute, second);
//     }

//     // Getter methods
//     int getHour() const { return hour; }
//     int getMinute() const { return minute; }
//     int getSecond() const { return second; }
// };

// class Date {
// private:
//     int year;
//     int month;
//     int day;
    
//     static const int daysInMonth[];

//     bool isLeapYear(int y) const {
//         return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
//     }

//     int getDaysInMonth(int m, int y) const {
//         if (m == 2 && isLeapYear(y)) return 29;
//         return daysInMonth[m - 1];
//     }

// public:
//     Date(int y = 1970, int m = 1, int d = 1) {
//         setDate(y, m, d);
//     }

//     void setDate(int y, int m, int d) {
//         year = y;
//         month = (m < 1) ? 1 : (m > 12) ? 12 : m;
//         day = (d < 1) ? 1 : (d > getDaysInMonth(month, year)) ? getDaysInMonth(month, year) : d;
//     }

//     void addDays(int d) {
//         while (d != 0) {
//             if (d > 0) {
//                 day++;
//                 if (day > getDaysInMonth(month, year)) {
//                     day = 1;
//                     month++;
//                     if (month > 12) {
//                         month = 1;
//                         year++;
//                     }
//                 }
//                 d--;
//             } else {
//                 day--;
//                 if (day < 1) {
//                     month--;
//                     if (month < 1) {
//                         month = 12;
//                         year--;
//                     }
//                     day = getDaysInMonth(month, year);
//                 }
//                 d++;
//             }
//         }
//     }

//     void addMonths(int m) {
//         year += m / 12;
//         month += m % 12;
//         if (month > 12) {
//             month -= 12;
//             year++;
//         } else if (month < 1) {
//             month += 12;
//             year--;
//         }
//         if (day > getDaysInMonth(month, year)) {
//             day = getDaysInMonth(month, year);
//         }
//     }

//     void addYears(int y) {
//         year += y;
//         if (month == 2 && day == 29 && !isLeapYear(year)) {
//             day = 28;
//         }
//     }

//     // Getter methods
//     int getYear() const { return year; }
//     int getMonth() const { return month; }
//     int getDay() const { return day; }
// };

// const int Date::daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// class DateTime : public Date, public Time {
// public:
//     DateTime(int year = 1970, int month = 1, int day = 1,
//             int hour = 0, int minute = 0, int second = 0)
//         : Date(year, month, day), Time(hour, minute, second) {}

//     // Calculate the difference between two DateTime objects
//     void difference(const DateTime& other, int& days, int& hours, int& minutes, int& seconds) const {
//         // Convert both dates to total seconds and find the difference
//         long long thisSeconds = (getYear() * 365LL + getMonth() * 30LL + getDay()) * 86400LL +
//                               getHour() * 3600LL + getMinute() * 60LL + getSecond();
        
//         long long otherSeconds = (other.getYear() * 365LL + other.getMonth() * 30LL + other.getDay()) * 86400LL +
//                                 other.getHour() * 3600LL + other.getMinute() * 60LL + other.getSecond();
        
//         long long diff = thisSeconds - otherSeconds;
        
//         // Convert back to days, hours, minutes, and seconds
//         days = diff / 86400;
//         diff %= 86400;
//         hours = diff / 3600;
//         diff %= 3600;
//         minutes = diff / 60;
//         seconds = diff % 60;
//     }

//     std::string format(const std::string& formatString) const {
//         std::stringstream result;
        
//         for (size_t i = 0; i < formatString.length(); i++) {
//             if (formatString[i] == 'Y') {
//                 result << std::setfill('0') << std::setw(4) << getYear();
//                 i += 3;  // Skip the rest of "YYYY"
//             } else if (formatString[i] == 'M' && formatString[i+1] == 'M') {
//                 result << std::setfill('0') << std::setw(2) << getMonth();
//                 i++;
//             } else if (formatString[i] == 'D' && formatString[i+1] == 'D') {
//                 result << std::setfill('0') << std::setw(2) << getDay();
//                 i++;
//             } else if (formatString[i] == 'H' && formatString[i+1] == 'H') {
//                 result << std::setfill('0') << std::setw(2) << getHour();
//                 i++;
//             } else if (formatString.substr(i, 2) == "MM" && i > 0 && formatString[i-1] != 'Y') {
//                 result << std::setfill('0') << std::setw(2) << getMinute();
//                 i++;
//             } else if (formatString.substr(i, 2) == "SS") {
//                 result << std::setfill('0') << std::setw(2) << getSecond();
//                 i++;
//             } else {
//                 result << formatString[i];
//             }
//         }
        
//         return result.str();
//     }
// };
