#include "DateTime.h"
#include <iostream>

int main() {
    // Create two DateTime objects
    DateTime dt1(2024, 12, 13, 14, 30, 45);
    DateTime dt2(2023, 12, 14, 10, 25, 30);

    // Add to DateTime
    dt1.addDateTime(0, 0, 1, 10, 45, 50);

    // Calculate the difference
    dt1.difference(dt2);

    return 0;
}
