#include "assignment22.h"
#include <cctype> // For isspace
#include <string>

std::string extractFirstName(const std::string& fullName) {
    size_t spaceIndex = fullName.find(' ');
    if (spaceIndex != std::string::npos) {
        return fullName.substr(0, spaceIndex); 
    }
    return ""; 
}

std::string extractLastName(const std::string& fullName) {
    size_t spaceIndex = fullName.find(' ');
    if (spaceIndex != std::string::npos) {
        return fullName.substr(spaceIndex + 1); 
    }
    return ""; 
}
