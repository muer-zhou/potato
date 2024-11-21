#ifndef ASSIGNMENT26_H
#define ASSIGNMENT26_H

#include <iostream>

namespace assignment26 {
    // Define a structure for representing a point
    struct Point {
        double x;
        double y;

        // Overload the equality operator (==)
        bool operator==(const Point& other) const;

        // Overload the stream insertion operator (<<)
        friend std::ostream& operator<<(std::ostream& os, const Point& point);
    };
}

#endif // ASSIGNMENT26_H
