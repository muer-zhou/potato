// assignment26.h
#ifndef ASSIGNMENT26_H
#define ASSIGNMENT26_H

#include <iostream>

struct Point {
    int x;
    int y;

    // Equality operator overload
    bool operator==(const Point& other) const;
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Point& point);

#endif // ASSIGNMENT26_H
