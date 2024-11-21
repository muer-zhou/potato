#include <iostream>
#include "convert.h"

int main() {
    double number = 12.34;

    // Use the reusable function to convert the double to a string
    std::string convertedString = convertDoubleToString(number);

    // Print the result
    std::cout << "Converted string: " << convertedString << std::endl;

    return 0;
}
