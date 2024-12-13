#ifndef TIME_HPP
#define TIME_HPP

class Time {
private:
    double hour;
    double minute;
    double second;
    double timeZoneOffset;  // Hours offset from UTC

public:
    Time(double h = 0, double m = 0, double s = 0, double tz = 0);
    double getHour() const;
    double getMinute() const;
    double getSecond() const;
    double getTimeZoneOffset() const;
    void adjustTimeZone(double newOffset);
    void applyDST(bool isDST);
};

#endif