// assignment26.cpp
#include "assignment26.h"

// Equality operator overload
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
