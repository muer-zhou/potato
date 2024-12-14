#ifndef DATE_H
#define DATE_H

class Date {
protected:
    int year;
    int month;
    int day;

    int daysInMonth(int m, int y) const;

public:
    Date(int y = 0, int m = 1, int d = 1);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void addDays(int d);
    void addMonths(int m);
    void addYears(int y);
    void addDate(int y, int m, int d);

    int toDays() const;
};

#endif // DATE_H
