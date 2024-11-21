#include "assignment26.h"

namespace assignment26 {
    // Overload the equality operator (==)
    bool Point::operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload the stream insertion operator (<<)
    std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
}
