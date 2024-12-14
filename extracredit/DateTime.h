#ifndef DATETIME_H
#define DATETIME_H

#include "Time.h"
#include "Date.h"
#include <string>

class DateTime : public Time, public Date {
private:
    int timeZoneOffset; // Time zone offset in hours from UTC

public:
    DateTime(int y = 0, int m = 1, int d = 1, int h = 0, int mi = 0, int s = 0, int tz = 0);

    // Time Zone Conversion
    void adjustTimeZone(int newOffset);
    void applyDaylightSaving(bool addOneHour);

    // Calendar Operations
    std::string getDayOfWeek() const; // Zeller's Congruence
    int daysInMonth() const;          // Number of days in the current month

    // Serialization and Deserialization
    std::string serialize() const;
    static DateTime deserialize(const std::string &data);

    void addDateTime(int y, int m, int d, int h, int mi, int s);
    void difference(const DateTime& other);
    int timeToSeconds() const;
};

#endif // DATETIME_H
