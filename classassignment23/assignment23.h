#ifndef ASSIGNMENT23_H
#define ASSIGNMENT23_H

#include <iostream>

struct Point {
    double x;
    double y;

    // Overloading equality operator
    bool operator==(const Point& other) const;

    // Overloading stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif // ASSIGNMENT23_H
