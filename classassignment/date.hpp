// Date.hpp
#ifndef DATE_HPP
#define DATE_HPP

class Date {
private:
    double year;
    double month;
    double day;
public:
    Date(double y = 0, double m = 0, double d = 0);
    double getYear() const;
    double getMonth() const;
    double getDay() const;
};

#endif