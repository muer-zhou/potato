#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <string>
#include "Date.hpp"
#include "Time.hpp"

class DateTime : public Date, public Time {
public:
    DateTime(double y = 0, double m = 0, double d = 0, 
            double h = 0, double min = 0, double s = 0, 
            double tz = 0);
    
    std::string format(std::string formatString);
    
    // Serialization methods
    std::string serialize() const;
    static DateTime deserialize(const std::string& str);
};

#endif