// main.cpp
#include <iostream>
#include "DateTime.hpp"

int main() {
    // Test constructor and getters
    DateTime dt(2024, 3, 15, 14, 30, 45);
    
    // Test format method with different format strings
    std::cout << "Full date and time: " 
              << dt.format("YYYY-MM-DD HH:MM:SS") << std::endl;
    
    std::cout << "Date only: " 
              << dt.format("YYYY-MM-DD") << std::endl;
    
    std::cout << "Time only: " 
              << dt.format("HH:MM:SS") << std::endl;
    
    std::cout << "Custom format: " 
              << dt.format("Today is YYYY-MM-DD, and the time is HH:MM") << std::endl;
    
    return 0;
}
