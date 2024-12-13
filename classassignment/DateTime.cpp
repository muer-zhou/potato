// DateTime.cpp
#include "DateTime.hpp"
#include <sstream>
#include <iomanip>

DateTime::DateTime(double y, double m, double d, double h, double min, double s)
    : Date(y, m, d), Time(h, min, s) {
}

std::string DateTime::format(std::string formatString) {
    std::stringstream result;
    
    for (size_t i = 0; i < formatString.length(); i++) {
        if (formatString[i] == 'Y' && formatString.substr(i, 4) == "YYYY") {
            result << std::setfill('0') << std::setw(4) << getYear();
            i += 3;
        } else if (formatString[i] == 'M' && formatString.substr(i, 2) == "MM" && 
                  (i == 0 || formatString[i-1] != 'Y')) {
            result << std::setfill('0') << std::setw(2) << getMonth();
            i++;
        } else if (formatString[i] == 'D' && formatString.substr(i, 2) == "DD") {
            result << std::setfill('0') << std::setw(2) << getDay();
            i++;
        } else if (formatString[i] == 'H' && formatString.substr(i, 2) == "HH") {
            result << std::setfill('0') << std::setw(2) << getHour();
            i++;
        } else if (formatString.substr(i, 2) == "MM" && 
                  (i == 0 || formatString[i-1] != ':')) {
            result << std::setfill('0') << std::setw(2) << getMinute();
            i++;
        } else if (formatString.substr(i, 2) == "SS") {
            result << std::setfill('0') << std::setw(2) << getSecond();
            i++;
        } else {
            result << formatString[i];
        }
    }
    
    return result.str();
}
