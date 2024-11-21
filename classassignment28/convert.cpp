#include "convert.h"

std::string convertDoubleToString(double number) {
    // Create a stringstream object
    std::stringstream stream;

    // Format the double value
    stream << std::fixed << std::setprecision(1) << number;

    // Return the formatted string
    return stream.str();
}
