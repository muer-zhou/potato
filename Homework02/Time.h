#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    void addTime(int h, int m, int s);
};

#endif // TIME_H
