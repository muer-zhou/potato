#ifndef DATETIME_H
#define DATETIME_H

#include "Time.h"
#include "Date.h"

class DateTime : public Time, public Date {
public:
    DateTime(int y = 0, int m = 1, int d = 1, int h = 0, int mi = 0, int s = 0);

    void addDateTime(int y, int m, int d, int h, int mi, int s);
    void difference(const DateTime& other);
    int timeToSeconds() const;
};

#endif // DATETIME_H
