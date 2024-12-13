#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
private:
    double year;
    double month;
    double day;
    bool isLeapYear(double year) const;

public:
    Date(double y = 0, double m = 0, double d = 0);
    double getYear() const;
    double getMonth() const;
    double getDay() const;
    
    // New calendar operations
    std::string getDayOfWeek() const;  // Returns day of week using Zeller's Congruence
    double getDaysInMonth() const;     // Returns number of days in the current month
};

#endif