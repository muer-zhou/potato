#include <iostream>
#include "assignment23.h"

int main() {
    Point p1{3.0, 4.5};
    Point p2{3.0, 4.5};
    Point p3{1.0, 2.0};

    // Test equality operator
    if (p1 == p2) {
        std::cout << "p1 and p2 are equal." << std::endl;
    } else {
        std::cout << "p1 and p2 are not equal." << std::endl;
    }

    if (p1 == p3) {
        std::cout << "p1 and p3 are equal." << std::endl;
    } else {
        std::cout << "p1 and p3 are not equal." << std::endl;
    }

    // Test stream insertion operator
    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p3: " << p3 << std::endl;

    return 0;
}
